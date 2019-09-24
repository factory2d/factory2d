#include <SDL.h>
#include <SDL_image.h>
#include <SDL_opengl.h>

#include "AssetManager.h"
#include "Picture.h"
#include "../Debug.h"

namespace F2D
{
	void Picture::Load(std::string asset) {
		Asset::Load(asset);

		Picture *p = (Picture*)AssetManager::PullAsset(asset);

		if(p == NULL) {
			// load picture file
			SDL_Surface *surface;

			if((surface = IMG_Load(asset.c_str()))) {
				GLuint t;
				// create the texture
				glGenTextures(1, &t);
				glBindTexture(GL_TEXTURE_2D, t);

				glTexImage2D(GL_TEXTURE_2D, 0, 3, surface->w,
					surface->h, 0, GL_RGB,
					GL_UNSIGNED_BYTE, surface->pixels);

				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

				__data = (void*)t;

				AssetManager::PushAsset(asset, this);
			}
			else {
				ERROR(IMG_GetError());
			}
		}
		else {
			__data = p->Data();
		}
	}
}