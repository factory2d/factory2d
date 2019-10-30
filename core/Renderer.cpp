
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
		glm::mat4 wT;
		CameraObject *c = CameraObject::GetActiveCamera();
		int windowWidth = WindowManager::Width(); int windowHeight = WindowManager::Height();

		// set the viewport
		glViewport(windowWidth*c->viewport->x,
				   windowHeight*c->viewport->y,
				   windowWidth*c->viewport->width,
				   windowHeight*c->viewport->height);
		
		// cut the window area to clear and render
		glScissor(windowWidth*c->viewport->x,
			windowHeight*c->viewport->y,
			windowWidth*c->viewport->width,
			windowHeight*c->viewport->height);
		
		glEnable(GL_SCISSOR_TEST);
		if(c->clearColor) {
			glClearColor(c->backgroundColor.r, c->backgroundColor.g, c->backgroundColor.b, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		//Initialize Projection Matrix
		glMatrixMode(GL_PROJECTION);

		glLoadIdentity();
		glOrtho(0.0, windowWidth, windowHeight, 0.0, 1.0, -1.0);
		
		// camera matrix test 1
		// this one is working, but I really really really 
		// like to use matrix transformation. (cam mat tst 2)
		glTranslatef(windowWidth * 0.5f, 
					 windowHeight * 0.5f, 
					 0.0f);
		
		wT = -c->transform->GetWorldTransform();
		glRotatef((glm::atan(wT[0][1], wT[0][0])*-57.2958f)-180.0f, 0.0f, 0.0f, 1.0f);
		glTranslatef(wT[3][0], wT[3][1], wT[3][2]);
		
		//Initialize Modelview Matrix
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		// camera matrix test 2
		//c->transform->SetOrigin(windowWidth * 0.5f, windowHeight * 0.5f, 0.0f);
		//wT = c->transform->GetWorldTransform();
		//wT[3][0] = -wT[3][0];
		//wT[3][1] = -wT[3][1];
		//wT[3][2] = -wT[3][2];
		//glMultMatrixf(glm::value_ptr(wT));

		/*glTranslatef(c->transform->GetOrigin().x,
			c->transform->GetOrigin().y,
			c->transform->GetOrigin().z);
		glTranslatef(c->transform->GetPosition().x,
			c->transform->GetPosition().y,
			c->transform->GetPosition().z);*/
			//glTranslatef(wT[3][0], wT[3][1], wT[3][2]);


		//glBlitFramebuffer(0, 0, 640, 480, 0, 0, 320, 240, GL_COLOR_BUFFER_BIT, GL_NEAREST);

		//Initialize clear color
		//glClearColor(1.0f, 0.0f, 0.0f, 1.f);
		//glClear(GL_COLOR_BUFFER_BIT);
	}

	void Renderer::End() {
		glDisable(GL_SCISSOR_TEST);
	}

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
