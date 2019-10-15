/**
* @license
* F2D are available under the zlib license :
*
* This software is provided 'as-is', without any express or implied
* warranty.In no event will the authors be held liable for any damages
* varising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
*including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions :
*
* 1. The origin of this software must not be misrepresented; you must not
*    claim that you wrote the original software.If you use this software
*    in a product, an acknowledgment in the product documentation would be
*    appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
*    misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
* /

/**
 * @fileoverview Window.h
 *
 * Create and manage the game window
 *
 * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
 */

#ifndef FACTORY2D_WINDOW_WINDOWMANAGER_H_
#define FACTORY2D_WINDOW_WINDOWMANAGER_H_

#include "SDL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>
#include <string>

namespace F2D {
	class WindowManager {
	private:
		static std::string __title;
		static bool __allowUserResize;
		static bool __allowVSync;
		static SDL_Window* __sdl_window;
		static SDL_GLContext __sdl_context;
		static int __width;
		static int __height;

	public:
		static bool Initialize();
		static void Update(void *event);
		static void Draw();

		static std::string Title();	static void Title(std::string title);
		static bool Resizable(); static void Resizable(bool value);
		static bool VSync(); static void VSync(bool value);
		static int Width(); static void Width(int value);
		static int Height(); static void Height(int value);
	};
}

#endif // FACTORY2D_WINDOW_WINDOWMANAGER_H_