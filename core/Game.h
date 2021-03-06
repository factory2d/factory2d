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
  * @fileoverview Game.h
  *
  * Base game object
  *
  * @author Alexandre Ribeiro de S� (@alexribeirodesa)
  */

#ifndef __FACTORY2D_GAME
#define __FACTORY2D_GAME

#include "Debug.h"

namespace F2D
{
	class Game {
	private:
		bool __quit = false;

	public:
		Game();
		~Game();

		virtual bool Initialize();
		virtual void Update();
		virtual void Draw();

		void Run();
	};
}

#endif