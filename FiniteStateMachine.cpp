#include "FiniteStateMachine.h"

FiniteStateMachine::State FiniteStateMachine::transitionTable[8][16]{
			{READ_ID1, READ_ID1,       _ERROR,         READ_ID2, READ_ID2, READ_ID2,        _ERROR,          READ_ID3,      READ_ID3,      _ERROR,          READ_ID3,        _ERROR,          _ERROR,         _ERROR},
			{_ERROR,   READ_ID1,       _ERROR,         _ERROR,   _ERROR,   READ_ID2,        _ERROR,          READ_NUMBER,   READ_NUMBER,   READ_NUMBER,     READ_ID3,        _ERROR,          _ERROR,         _ERROR},
			{_ERROR,   _ERROR,         _ERROR,         _ERROR,   _ERROR,   CHECK_ID2,       CHECK_ID2,       _ERROR,        _ERROR,        _ERROR,          _ERROR,          _ERROR,          _ERROR,         _ERROR},
			{_ERROR,   _ERROR,         _ERROR,         _ERROR,   _ERROR,   _ERROR,          _ERROR,          _ERROR,        _ERROR,         WAIT_SEMICOLON, CHECK_ID3,       CHECK_ID3,       _ERROR,         _ERROR},
			{WAIT_ID1, WAIT_ASSIGMENT, WAIT_ASSIGMENT, WAIT_ID2, WAIT_ID2, WAIT_OP_BRACKET, WAIT_OP_BRACKET, WAIT_ARGUMENT, WAIT_ARGUMENT, WAIT_CL_BRACKET, WAIT_CL_BRACKET, WAIT_CL_BRACKET, WAIT_SEMICOLON, WAIT_SEMICOLON,},
			{_ERROR,   _ERROR,         _ERROR,         _ERROR,   _ERROR,   _ERROR,          _ERROR,          _ERROR,        _ERROR,        _ERROR,          _ERROR,          _ERROR,          END,            END},
			{_ERROR,   CHECK_ID1,      CHECK_ID1,      _ERROR,   _ERROR,   _ERROR,          _ERROR,          _ERROR,        _ERROR,        _ERROR,          _ERROR,          _ERROR,          _ERROR,         _ERROR},
			{_ERROR,   _ERROR,         _ERROR,         _ERROR,   _ERROR,   _ERROR,          _ERROR,          _ERROR,        _ERROR,        _ERROR,          _ERROR,          _ERROR,          _ERROR,         _ERROR}
};

std::string FiniteStateMachine::informAboutState[16]{
			"...Ожидание первого идентификатора.",
			"...Чтение первого идентификатора.",
			"...Ожидание знака равно.",
			"...Проверка первого идентификатора на зарезервированность.",
			"...Ожидание второго идентификатора.",
			"...Чтение второго идентификатора.",
			"...Ожидание открывающей скобки.",
			"...Проверка второго идентификатора на зарезервированность.",
			"...Ожидание аргумента функции.",
			"...Чтение целого числа.",
			"...Чтение третьего идентификатора.",
			"...Ожидание закрывающей скобки.",
			"...Проверка третьего идентификатора на зарезервированность.",
			"...Ожидание точки с запятой.",
			"...Синтаксическая конструкция корректна.",
			"...Ошибка. Некорректная синтаксическая конструкция." };


FiniteStateMachine::FiniteStateMachine() : currentState(WAIT_ID1) {}

void FiniteStateMachine::run(const std::string& codeLine, System::Windows::Forms::TextBox^ outputBox) {

	std::string identifier = "";
	State previousState;

	for (std::string::const_iterator currentSymbol = codeLine.begin(); currentSymbol != codeLine.end() && currentState != _ERROR; ++currentSymbol) {
		previousState = currentState;
		currentState = transitionTable[SymbolType::getSymbolType(*currentSymbol)][currentState];
		if (currentState != previousState) {
			outputBox->Text += gcnew System::String(informAboutState[currentState].c_str()) + "\r\n";
		}
		if (currentState == READ_ID1 || currentState == READ_ID2 || currentState == READ_ID3) {
			identifier += *currentSymbol;
		}
		else if (currentState == CHECK_ID1 || currentState == CHECK_ID2 || currentState == CHECK_ID3) {
			if (ReservedWordsList::isReservedWord(identifier)) {
				outputBox->Text += "...Ошибка. Идентификатор совпадает с зарезервированным словом." + "\r\n";
				currentState = _ERROR;
			}
			identifier.erase();
		}
	}
	if (currentState != END && currentState != _ERROR) {
		outputBox->Text += "...Ошибка. Неполная синтаксическая конструкция." + "\r\n";
	}
}
