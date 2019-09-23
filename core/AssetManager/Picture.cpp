#include <SDL.h>
#include <SDL_image.h>

#include "AssetManager.h"
#include "Picture.h"

namespace F2D
{
	Picture::Picture() {}
	Picture::~Picture() {}
	void Picture::Load(std::string asset) {
		Asset::Load(asset);

	}
}