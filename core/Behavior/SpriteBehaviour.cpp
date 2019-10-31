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
  * @fileoverview FactoryObject.h
  *
  * --- FILE NOTES ---
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#include "SDL.h"
#include "SDL_opengl.h"
#include <GL\GLU.h>

#include "SpriteBehaviour.h"
#include "../Asset/AssetManager.h"

namespace F2D
{
	SpriteBehaviour::SpriteBehaviour() {
	}

	SpriteBehaviour::SpriteBehaviour(std::string name) {
		SpriteBehaviour(AssetManager::Load<F2D::PictureAsset>(name));
	}

	SpriteBehaviour::SpriteBehaviour(PictureAsset * p) {
		// set picture asset inside sprite behaviour
		picture = p;
		
		// cace picture width and height (in pixel);
		width = picture->Width(); 
		height = picture->Height();
	}

	SpriteBehaviour::~SpriteBehaviour() {}

	void SpriteBehaviour::Update() {
	}

	void SpriteBehaviour::Draw() {
		if(picture == nullptr) {
			glDisable(GL_TEXTURE_2D);
		}
		else {
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, (GLuint)picture->Data());
		}

		

		glBegin(GL_QUADS);
		glTexCoord2f(0.f, 0.f); glColor3f(1.f, 1.f, 1.f); glVertex2f(0.0f, 0.0f);
		glTexCoord2f(1.f, 0.f); glColor3f(1.f, 1.f, 1.f); glVertex2f(width, 0.0f);
		glTexCoord2f(1.f, 1.f); glColor3f(1.f, 1.f, 1.f); glVertex2f(width, height);
		glTexCoord2f(0.f, 1.f); glColor3f(1.f, 1.f, 1.f); glVertex2f(0.0f, height);
		glEnd();
	}
}
