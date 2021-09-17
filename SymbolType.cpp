#include "SymbolType.h" 

namespace SymbolType {
	enum SymbolType {
		LETTER_AND_UNDERSCORE,
		NUMERAL,
		OPENING_BRACKET,
		CLOSING_BRACKET,
		SEPARATOR,
		SEMILOCON,
		ASSIGNMENT,
		OTHER
	};

	SymbolType getSymbolType(const char& symbol) {
		SymbolType type;
		if (symbol <= 'Z' && symbol >= 'A' || symbol <= 'z' && symbol >= 'a' || symbol == '_') {
			type = LETTER_AND_UNDERSCORE;
		}
		else if (symbol >= '0' && symbol <= '9') {
			type = NUMERAL;
		}
		else if (symbol == '(') {
			type = OPENING_BRACKET;
		}
		else if (symbol == ')') {
			type = CLOSING_BRACKET;
		}
		else if (symbol == ' ' || symbol == '\n' || symbol == '\r') {
			type = SEPARATOR;
		}
		else if (symbol == ';') {
			type = SEMILOCON;
		}
		else if (symbol == '=') {
			type = ASSIGNMENT;
		}
		else {
			type = OTHER;
		}
		return type;
	}
}