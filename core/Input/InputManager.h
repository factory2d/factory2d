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
  * @fileoverview InputManager.h
  *
  * Here we manage our input, I'm using my old UTools plugin as referenct
  * (https://pt.slideshare.net/alexrdes/u-tools-unite-brasil-42578443)
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#ifndef FACTORY2D_INPUT_INPUTMANAGER_H_
#define FACTORY2D_INPUT_INPUTMANAGER_H_

/*
a little about my UTools (https://pt.slideshare.net/alexrdes/u-tools-unite-brasil-42578443)

- input manager
  - player
    - x [typeAxis]
	  - joystick X
	  - keyboard button +/-
    - y [typeAxis]
	  - joystick Y
	  - keyboard button +/-
	- attack
	  - joystick button
	  - keyboard button
	  - mouse button
*/

#include <string>
#include <vector> 
#include <map>
#include "SDL.h"
#include "ControllerObject.h"

namespace F2D
{
	enum {
		F2D_UNKNOWN = 0,

		// keyboard (this is just a mask to OGL/DX
		// yes, I'll need to port the core to DX in the future to build for 
		// Xbox and Windows Universal
		F2D_KEYBOARD_ESCAPE = SDLK_ESCAPE,
		F2D_KEYBOARD_RETURN = SDLK_RETURN,
		F2D_KEYBOARD_TAB = SDLK_TAB,
		F2D_KEYBOARD_0 = SDLK_0,
		F2D_KEYBOARD_1 = SDLK_1,
		F2D_KEYBOARD_2 = SDLK_2,
		F2D_KEYBOARD_3 = SDLK_3,
		F2D_KEYBOARD_4 = SDLK_4,
		F2D_KEYBOARD_5 = SDLK_5,
		F2D_KEYBOARD_6 = SDLK_6,
		F2D_KEYBOARD_7 = SDLK_7,
		F2D_KEYBOARD_8 = SDLK_8,
		F2D_KEYBOARD_9 = SDLK_9,
		F2D_KEYBOARD_A = SDLK_a,
		F2D_KEYBOARD_B = SDLK_b,
		F2D_KEYBOARD_C = SDLK_c,
		F2D_KEYBOARD_D = SDLK_d,
		F2D_KEYBOARD_E = SDLK_e,
		F2D_KEYBOARD_F = SDLK_f,
		F2D_KEYBOARD_G = SDLK_g,
		F2D_KEYBOARD_H = SDLK_h,
		F2D_KEYBOARD_I = SDLK_i,
		F2D_KEYBOARD_J = SDLK_j,
		F2D_KEYBOARD_K = SDLK_k,
		F2D_KEYBOARD_L = SDLK_l,
		F2D_KEYBOARD_M = SDLK_m,
		F2D_KEYBOARD_N = SDLK_n,
		F2D_KEYBOARD_O = SDLK_o,
		F2D_KEYBOARD_P = SDLK_p,
		F2D_KEYBOARD_Q = SDLK_q,
		F2D_KEYBOARD_R = SDLK_r,
		F2D_KEYBOARD_S = SDLK_s,
		F2D_KEYBOARD_T = SDLK_t,
		F2D_KEYBOARD_U = SDLK_u,
		F2D_KEYBOARD_V = SDLK_v,
		F2D_KEYBOARD_W = SDLK_w,
		F2D_KEYBOARD_X = SDLK_x,
		F2D_KEYBOARD_Y = SDLK_y,
		F2D_KEYBOARD_Z = SDLK_z,
		F2D_KEYBOARD_MINUS = SDLK_MINUS,
		F2D_KEYBOARD_PLUS = SDLK_PLUS,
		F2D_KEYBOARD_EQUALS = SDLK_EQUALS,
		F2D_KEYBOARD_BACKSPACE = SDLK_BACKSPACE,
		F2D_KEYBOARD_LBRACKET = SDLK_LEFTBRACKET,
		F2D_KEYBOARD_RBRACKET = SDLK_RIGHTBRACKET,
		F2D_KEYBOARD_LCTRL = SDLK_LCTRL,
		F2D_KEYBOARD_RCTRL = SDLK_RCTRL,
		F2D_KEYBOARD_LSHIFT = SDLK_LSHIFT,
		F2D_KEYBOARD_RSHIFT = SDLK_RSHIFT,
		F2D_KEYBOARD_LALT = SDLK_LALT,
		F2D_KEYBOARD_RALT = SDLK_RALT,
		F2D_KEYBOARD_UP = SDLK_UP,
		F2D_KEYBOARD_DOWN = SDLK_DOWN,
		F2D_KEYBOARD_LEFT = SDLK_LEFT,
		F2D_KEYBOARD_RIGHT = SDLK_RIGHT,

		// mouse (I created these codes)
		// mouse button codes
		F2D_MOUSE_LEFT		= 10001,
		F2D_MOUSE_MIDDLE	= 10002,
		F2D_MOUSE_WHEEL		= 10003,
		F2D_MOUSE_RIGHT		= 10004,

		// mouse axis codes (this is a conversion from axis to button)
		F2D_MOUSE_MUP		= 10011,
		F2D_MOUSE_MDOWN		= 10012,
		F2D_MOUSE_MLEFT		= 10013,
		F2D_MOUSE_MRIGHT	= 10014,
		F2D_MOUSE_WUP		= 10021,
		F2D_MOUSE_WDOWN		= 10022,
		F2D_MOUSE_WLEFT		= 10023,
		F2D_MOUSE_WRIGHT	= 10024,
	};

	class InputManager {
	private:
		static std::vector <ControllerObject*> __controllers;
		static std::map <unsigned char, bool> __keyboardKeys;
		static long __lastUpdate;

	public:
		// controller manager
		static float GetAxis(std::string controller, std::string action);
		static bool GetButton(std::string controller, std::string action);
		static bool GetButtonUp(std::string controller, std::string action);
		static bool GetButtonDown(std::string controller, std::string action);

		static bool GetKeyboardKey(unsigned char key);

		// generic stuff
		static void Update(void *event);
		static ControllerObject* Push(ControllerObject* controller);
		static void Pop(std::string key);
	};
}

#endif // FACTORY2D_INPUT_INPUTMANAGER_H_
