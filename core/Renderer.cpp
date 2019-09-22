#include "SDL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>

#include "Renderer.h"
#include "FactoryObjects/CameraObject.h"

namespace F2D
{
	Window* Renderer::window = NULL;
	bool Renderer::integerPosition = false;

	Renderer::Renderer() {}

	Renderer::~Renderer() {}

	void Renderer::Begin() {
		CameraObject *c = CameraObject::GetActiveCamera();

		//Set the viewport
		glViewport(window->Width()*c->viewport->x,
			window->Height()*c->viewport->y,
			window->Width()*c->viewport->width,
			window->Height()*c->viewport->height);

		//Initialize Projection Matrix
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0, window->Width()*c->viewport->width, window->Height()*c->viewport->height, 0.0, 1.0, -1.0);



		glTranslatef(-c->transform->position->x, -c->transform->position->y, -c->transform->position->z);

		//Initialize Modelview Matrix
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();

		//Initialize clear color
		//glClearColor(1.0f, 0.0f, 0.0f, 1.f);
		//glClear(GL_COLOR_BUFFER_BIT);
	}

	void Renderer::End() {}
}