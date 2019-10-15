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
  * @fileoverview Object.h
  *
  * --- FILE NOTES ---
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#include <iostream>
#include <iomanip>
#include <sstream>

#include "Object.h"

namespace F2D
{
	Object::Object() {
		std::stringstream hexuuid;

		__uuid = (unsigned int)this;

		hexuuid << std::hex << __uuid;
		name = hexuuid.str();
	}

	Object::~Object() {}

	unsigned int Object::GetUUID() {
		return __uuid;
	}
}
