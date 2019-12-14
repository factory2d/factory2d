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
  * @fileoverview Material.cpp
  *
  * Base game object
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#include "../gl.h"

#include "Material.h"

namespace F2D
{
	Material::Material() {}
	Material::~Material() {}

	void Material::Apply() {
		if(texture == 0) {
			glDisable(GL_TEXTURE_2D);
			return;
		}

		// apply texture
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);

		// apply texture blend
		glEnable(GL_BLEND);
		switch(blend) {
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
	
	}
}
