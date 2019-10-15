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
  * @fileoverview Debug.h
  *
  * Debug output
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#ifndef FACTORY2D_DEBUG_H_
#define FACTORY2D_DEBUG_H_

#include <string>
#include <iostream>

#define TYPE_CONSOLE 1
#define TYPE_WARNING 2
#define TYPE_ERROR 3

#define COLOR_CONSOLE "\033[39m"
#define COLOR_WARNING "\033[33m"
#define COLOR_ERROR "\033[31m"

/*
enum DebugTypes {
	CONSOLE = 0,
	_WARNING,
	_ERROR
};
*/
#define _LOG(message, ...) Debug::Write(__FUNCTION__, __LINE__, message, COLOR_CONSOLE)
#define _WARNING(message, ...) Debug::Write(__FUNCTION__, __LINE__,  message, COLOR_WARNING)
#define _ERROR(message, ...) Debug::Write(__FUNCTION__, __LINE__, message, COLOR_ERROR)

namespace F2D
{
	class Debug {
	public:
		static const bool enabled = true;
		static const bool output = true;

		static void Write(std::string file, unsigned int line, std::string string, std::string color);
	};
}

#endif // FACTORY2D_DEBUG_H_
