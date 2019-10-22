
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
  * @fileoverview Renderer.cpp
  *
  * --- FILE NOTES ---
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */
#define GL_GLEXT_PROTOTYPES

#include "SDL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>

#include "Renderer.h"
#include "Objects/CameraObject.h"
#include "Debug.h"

namespace F2D
{
	GLuint pbo;
	bool start = false;
	bool Renderer::integerPosition = false;
	bool Renderer::__allowVSync = true; // allow user use monitor vsync

	void Renderer::Begin() {
		CameraObject *c = CameraObject::GetActiveCamera();
		int w = WindowManager::Width(); int h = WindowManager::Height();

		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Set the viewport
		glViewport(WindowManager::Width()*c->viewport->x,
			WindowManager::Height()*c->viewport->y,
			WindowManager::Width()*c->viewport->width,
			WindowManager::Height()*c->viewport->height);

		//Initialize Projection Matrix
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0, WindowManager::Width()*c->viewport->width, WindowManager::Height()*c->viewport->height, 0.0, 1.0, -1.0);
		//glOrtho(0.0, w, h, 0.0, 1.0, -1.0);

		glTranslatef(-c->transform->GetPosition()->x, 
					 -c->transform->GetPosition()->y, 
					 -c->transform->GetPosition()->z);

		//Initialize Modelview Matrix
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		//glBlitFramebuffer(0, 0, 640, 480, 0, 0, 320, 240, GL_COLOR_BUFFER_BIT, GL_NEAREST);

		//Initialize clear color
		//glClearColor(1.0f, 0.0f, 0.0f, 1.f);
		//glClear(GL_COLOR_BUFFER_BIT);

	}

	void Renderer::End() {}

	bool Renderer::VSync() {
		return __allowVSync;
	}

	// send it to renderer
	void Renderer::VSync(bool value) {
		__allowVSync = value;
		if(SDL_GL_SetSwapInterval(__allowVSync) < 0) {
			_ERROR(SDL_GetError());
			//printf("Warning: Unable to set VSync! SDL Error: %s\n", SDL_GetError());
		}
	}
}
