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
#include "../Time/TimeManager.h"
#include "../Asset/AssetManager.h"
#include "../Material/Material.h"

namespace F2D
{
	SpriteBehaviour::SpriteBehaviour() {}

	SpriteBehaviour::SpriteBehaviour(std::string path) :
		SpriteBehaviour(AssetManager::Load<F2D::SpriteAsset>(path)) {}

	SpriteBehaviour::SpriteBehaviour(SpriteAsset * p) {
		// set picture asset inside sprite behaviour
		picture = p;
		
		// cache picture width and height (in pixel);
	}

	SpriteBehaviour::~SpriteBehaviour() {}

	void SpriteBehaviour::Update() {
	}


	// TODO:
	// this place is a little nightmare, need lots of
	// optimizations!!
	// I'm commentint everything, or I can get lost xD
	void SpriteBehaviour::Draw() {
		// apply the texture
		if(picture == nullptr) {
			glDisable(GL_TEXTURE_2D);
		}
		else {
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, (GLuint)picture->Data());
		}

		// get material properties
		// send this stuff to material object, so I'll didn't have to
		// apply this code when we create another draw behaviour
		Material *material = &transform->GetFactoryObject()->material;

		// apply the material properties
		glEnable(GL_BLEND);
		switch(material->blend) {
		case F2D_BLEND_MULTIPLY:
			glBlendFunc(GL_DST_COLOR, GL_ONE_MINUS_SRC_ALPHA);
			break;
		case F2D_BLEND_ALPHA:
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			break;
		default:
			glDisable(GL_BLEND);
			break;
		}

		// update sprite animation
		if(picture->animation.size() == 0) {
			// if we didn't have any animation we will 
			// always use sprite sheet frame 0
			__animation = 0;
			__frame = 0;
		}
		else {
			// update animation interval based on frame interval
			__interval -= TimeManager::Delta();
			if(__interval <= 0.0f) {
				// go to the next frame
				__animationFrame++;
				if(__animationFrame >= picture->animation[__animation].frames.size()) {
					// loop the animation when finished
					__animationFrame = 0;
				}

				__frame = picture->animation[__animation].frames[__animationFrame].frame;
				__interval = picture->animation[__animation].frames[__animationFrame].interval;
			}
		}

		// will cache with vertex buffes
		// with vertex buffer I can allocate the sprite
		// mesh in video memory, making it faster to load
		// and draw in opengl video buffer.
		float width = picture->sprites[__frame].width;
		float height = picture->sprites[__frame].height;

		float coordWidth = width / (float)picture->Width();
		float coordHeight = height / (float)picture->Height();
		float minX = (float)picture->sprites[__frame].x / (float)picture->Width();
		float maxX = minX + (float)picture->sprites[__frame].width / (float)picture->Width();
		float minY = (float)picture->sprites[__frame].y / (float)picture->Height();
		float maxY = minY + (float)picture->sprites[__frame].height / (float)picture->Height();

		glBegin(GL_QUADS);
		// left top
		glTexCoord2f(minX, minY); 
		glColor4f(material->color.r, material->color.g, material->color.b, material->color.a); 
		glVertex2f(0.0f, 0.0f);

		// right top
		glTexCoord2f(maxX, minY); 
		glColor4f(material->color.r, material->color.g, material->color.b, material->color.a); 
		glVertex2f(width, 0.0f);

		// right bottom
		glTexCoord2f(maxX, maxY); 
		glColor4f(material->color.r, material->color.g, material->color.b, material->color.a); 
		glVertex2f(width, height);

		// left bottom
		glTexCoord2f(minX, maxY); 
		glColor4f(material->color.r, material->color.g, material->color.b, material->color.a); 
		glVertex2f(0.0f, height);
		glEnd();
	}
}
