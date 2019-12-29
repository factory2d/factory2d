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
  * @author Alexandre Ribeiro de S� (@alexribeirodesa)
  */

#include "../gl.h"

#include "SpriteBehaviour.h"
#include "../Timer/TimeManager.h"
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
		float w, h;
		float minX, maxX, minY, maxY;
		/*
		float minX = (float)picture->sprites[__frame].x / (float)picture->Width();
		float maxX = minX + (float)picture->sprites[__frame].width / (float)picture->Width();
		float minY = (float)picture->sprites[__frame].y / (float)picture->Height();
		float maxY = minY + (float)picture->sprites[__frame].height / (float)picture->Height();
		*/

		// cache sprite vertex
		__framesVertex = new Vertex*[p->sprites.size()];
		for(int x = 0; x < p->sprites.size(); x++) {
			w = picture->sprites[__frame].width;
			h = picture->sprites[__frame].height;
			minX = (float)picture->sprites[x].x / (float)picture->Width();
			maxX = minX + w / (float)picture->Width();
			minY = (float)picture->sprites[x].y / (float)picture->Height();
			maxY = minY + h / (float)picture->Height();

			__framesVertex[x] = new Vertex[4];
			__framesVertex[x][0] = { 0, 0, 0.0f, minX, minY };
			__framesVertex[x][1] = { w, 0, 0.0f, maxX, minY };
			__framesVertex[x][2] = { w, h, 0.0f, maxX, maxY };
			__framesVertex[x][3] = { 0, h, 0.0f, minX, maxY };
			/*__framesVertex[x][0].vertex[0] = 0.0f; __framesVertex[x][0].vertex[1] = 0.0f; __framesVertex[x][0].vertex[2] = 0.0f;
			__framesVertex[x][1].vertex[0] = 10.0f; __framesVertex[x][1].vertex[1] = 0.0f; __framesVertex[x][1].vertex[2] = 0.0f;
			__framesVertex[x][2].vertex[0] = 10.0f; __framesVertex[x][2].vertex[1] = 10.0f; __framesVertex[x][2].vertex[2] = 0.0f;*/
			//&__framesVertex[x][0][0] = &({ 0.0f,0.0f,0.0f,1.0f,1.0f,2.0f,2.0f,2.0f });
			//p->sprites[x].width/
		}
		//picture->sprites.size()

		return;
		//VBO data
		GLfloat vertexData[] = {
			0.0f, 0.0f,
			50.0f, 0.0f,
			50.0f, 50.0f,
			0.0f, 50.0f
		};

		//IBO data
		/*
		GLuint indexData[] = { 0, 1, 2, 0, 2, 3 };

		//Create VBO
		glGenBuffers(1, &__frameVBO);
		glBindBuffer(GL_ARRAY_BUFFER, __frameVBO);
		glBufferData(GL_ARRAY_BUFFER, 9 * sizeof(GLfloat), vertexData, GL_STATIC_DRAW);

		//Create IBO
		glGenBuffers(1, &__frameIBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, __frameIBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLuint), indexData, GL_STATIC_DRAW);
		*/
	}

	SpriteBehaviour::~SpriteBehaviour() {}

	bool SpriteBehaviour::Play(std::string animation) {
		for(int x = 0; x < picture->animation.size(); x++) {
			if(picture->animation[x].name == animation) {
				__animation = x;
				__animationFrame = 0;
				__frame = picture->animation[__animation].frames[__animationFrame].frame;
				__interval = picture->animation[__animation].frames[__animationFrame].interval;
			}
		}
		return false;
	}

	void SpriteBehaviour::Update() {
	}

	// TODO:
	// this place is a little nightmare, need lots of
	// optimizations!!
	// I'm commentint everything, or I can get lost xD
	void SpriteBehaviour::Draw() {
		__material = &transform->GetFactoryObject()->material;
		__material->texture = (GLuint)picture->Data();

		// get material properties
		// TODO:
		// send this stuff to material object, so I'll didn't have to
		// apply this code when we create another draw behaviour		

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

		// apply material
		__material->Apply();

		// render current sprite frame
		// TODO:
		// use VBO
		int index[6] = { 0, 1, 2, 0, 2, 3 };
    
    Renderer::Render(__framesVertex[__frame], index, 6);

    /*
		glGenBuffers(1, &__vao);
		glBindBuffer(GL_ARRAY_BUFFER, __vao);
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 4, &__framesVertex[0][0].x, GL_STATIC_DRAW);

		glGenBuffers(1, &__index_vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, __index_vbo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * 6, index, GL_STATIC_DRAW);

		glBindBuffer(GL_ARRAY_BUFFER, __vao);
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));		// The starting point of the VBO, for the vertices
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glClientActiveTexture(GL_TEXTURE0);
		glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(12)); // The starting point of texcoords, 24 bytes away
		//glEnableClientState(GL_NORMAL_ARRAY);
		//glNormalPointer(GL_FLOAT, sizeof(MyVertex), BUFFER_OFFSET(12));      // The starting point of normals, 12 bytes away
		//glClientActiveTexture(GL_TEXTURE0);
		//glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		//

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, __index_vbo);

		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_SHORT, BUFFER_OFFSET(0));
		return;
    */
	}
}
