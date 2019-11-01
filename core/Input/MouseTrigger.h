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
  * @fileoverview MouseTriggerObject.h
  *
  * --- FILE NOTES ---
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#ifndef FACTORY2D_INPUT_MOUSETRIGGER_H_
#define FACTORY2D_INPUT_MOUSETRIGGER_H_

#include "Trigger.h"

// debug
#include "../Debug.h"

namespace F2D
{
	// Button
	class MouseTrigger :
		public F2D::Trigger {
	private:
		unsigned char negative = 0;
		unsigned char positive = 0;

	public:
		MouseTrigger(std::string name, unsigned char key);
		MouseTrigger(std::string name, unsigned char negative, unsigned char positive);
		~MouseTrigger();

		float GetAxis() override;
		bool GetButton() override;
	};
}

#endif // FACTORY2D_INPUT_MOUSETRIGGER_H_
