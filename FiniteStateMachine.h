#pragma once
#include <iostream>
#include "ReservedWordsList.h"
#include "SymbolType.h"
#include <Windows.h>

class FiniteStateMachine {
	public:
		void run(const std::string&, System::Windows::Forms::TextBox^);
		FiniteStateMachine();
	private:
		enum State{
			WAIT_ID1,
			READ_ID1,
			WAIT_ASSIGMENT,
			CHECK_ID1,
			WAIT_ID2,
			READ_ID2,
			WAIT_OP_BRACKET,
			CHECK_ID2,
			WAIT_ARGUMENT,
			READ_NUMBER,
			READ_ID3,
			WAIT_CL_BRACKET,
			CHECK_ID3,
			WAIT_SEMICOLON,
			END,
			_ERROR
		};
		static State transitionTable[8][16];
		static std::string informAboutState[16];
		State currentState;

};


