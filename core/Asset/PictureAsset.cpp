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
  * @fileoverview InputTrigger.h
  *
  * --- FILE NOTES ---
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_opengl.h>

#include "AssetManager.h"
#include "PictureAsset.h"

namespace F2D
{
	bool PictureAsset::Load(std::string path) {
		Asset::Load(path);

		// load picture file
		SDL_Surface *surface;

		if((surface = IMG_Load(path.c_str()))) {
			GLuint t;

			// create the texture
			glGenTextures(1, &t);
			glBindTexture(GL_TEXTURE_2D, t);

			GLenum bytesPerPixel = GL_RGB;

			if(surface->format->BytesPerPixel == 4)
				bytesPerPixel = GL_RGBA;

			glTexImage2D(GL_TEXTURE_2D, 0, 3, 
				surface->w, surface->h, 0, bytesPerPixel,
				GL_UNSIGNED_BYTE, surface->pixels);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			__data = (void*)t;

			return true;
		}

		_ERROR(IMG_GetError());

		return false;
	}
}