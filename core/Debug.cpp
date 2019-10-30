/**
 * @license
 * F2D are available under the zlib license:
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * varising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

 /**
  * @fileoverview Debug.cpp
  *
  * Debug output
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

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