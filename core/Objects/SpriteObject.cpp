#include "SDL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>

#include "SpriteObject.h"

namespace F2D
{
	SpriteObject::SpriteObject(std::string name) : FactoryObject(name) {}

	SpriteObject::~SpriteObject() {}

	void SpriteObject::Update() {
		FactoryObject::Update();
	}

	void SpriteObject::Draw() {
		//glLoadIdentity();

		//glEnable(GL_TEXTURE_2D);
		//glBindTexture(GL_TEXTURE_2D, (GLuint)p->Data());

		//glBegin(GL_QUADS);
		//glTexCoord2f(0.f, 0.f); glColor3f(1.f, 1.f, 1.f); glVertex2f(0.0f, 0.0f);
		//glTexCoord2f(1.f, 0.f); glColor3f(1.f, 1.f, 1.f); glVertex2f(64.0f, 0.0f);
		//glTexCoord2f(1.f, 1.f); glColor3f(1.f, 1.f, 1.f); glVertex2f(64.0f, 64.0f);
		//glTexCoord2f(0.f, 1.f); glColor3f(1.f, 1.f, 1.f); glVertex2f(0.0f, 64.0f);
		//glEnd();

		FactoryObject::Draw();
	}
}
