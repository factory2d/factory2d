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
  * @fileoverview SpriteBehaviour.h
  *
  * --- FILE NOTES ---
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#ifndef FACTORY2D_BEHAVIOUR_SPRITEBEHAVIOUR_H_
#define FACTORY2D_BEHAVIOUR_SPRITEBEHAVIOUR_H_

#include "Behaviour.h"
#include "../Renderer.h"
#include "../Material/Material.h"
#include "../Asset/PictureAsset.h"

namespace F2D
{
	class SpriteBehaviour :
		public Behaviour {
	private:
		Material * __material;
		int __animation = 0;		// current animation
		int __animationFrame = 0;	// current animation frame
		int __frame = 0;			// spritesheet frame
		float __interval = 1.0f;	// spritesheet intervar;

		unsigned int __frameVBO = 0;
		unsigned int __frameIBO = 0;
		Vertex **__framesVertex;// [][][];
		unsigned int __vao = 0;			// Vertex array object
		unsigned int __index_vbo = 0;	// Index buffer object

	public:
		SpriteAsset *picture = nullptr;
		
		SpriteBehaviour();
		SpriteBehaviour(std::string path);
		SpriteBehaviour(SpriteAsset * picture);
		~SpriteBehaviour();

		bool Play(std::string animation);
		bool Stop();

		void Update() override;
		void Draw() override;
	};
}

#endif // FACTORY2D_BEHAVIOUR_SPRITEBEHAVIOUR_H_
