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
  * @fileoverview Picture.h
  *
  * --- FILE NOTES ---
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#ifndef FACTORY2D_ASSET_PICTUREASSET_H_
#define FACTORY2D_ASSET_PICTUREASSET_H_

#include <SDL_opengl.h>
#include <vector>
#include "Asset.h"

namespace F2D
{
	// I'll use YAML to store this data as a asset
	struct SpriteSheet {
		unsigned short x;
		unsigned short y;
		unsigned short width;
		unsigned short height;
		unsigned short originx = 0;
		unsigned short originy = 0;
	};

	// I'll use YAML to store this data as a asset too
	struct SpriteFrame {
		int frame;
		float interval = 1.0f;
	};

	struct SpriteAnimation {
		std::string name = "no name";
		std::vector<SpriteFrame> frames;
	};

	class SpriteAsset :
		public Asset {
	private:
		unsigned short __width = 0;
		unsigned short __height = 0;

	public:
		std::vector<SpriteSheet> sprites;
		std::vector<SpriteAnimation> animation;

		virtual bool Load(std::string path);
		unsigned short Width() { return __width; }
		unsigned short Height() { return __height; }
	};
}

#endif // FACTORY2D_ASSET_PICTUREASSET_H_