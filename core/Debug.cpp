#include <iostream>

#include "Debug.h"

namespace F2D
{
	void Debug::Write(std::string file, unsigned int line, std::string string, std::string color) {
		if(enabled == false)
			return;

		std::cout << color << file << " [" << line << "] : " << string << COLOR_CONSOLE << std::endl;
	}

	/*void Debug::Log(std::string string, std::string file) {
		Write(string, 0);
	}

	void Debug::Warning(std::string string, std::string file) {
		Write(string, 1);
	}

	void Debug::Error(std::string string, std::string file) {
		Write(string, 2);
	}*/
}