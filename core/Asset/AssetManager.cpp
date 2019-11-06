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
  * @fileoverview AssetManager.h
  *
  * --- FILE NOTES ---
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#include <locale>
#include <algorithm>

#include "AssetManager.h"

namespace F2D
{
	std::map <std::string, Asset*> AssetManager::__assets = {};

	bool AssetManager::LoadAsset(SpriteAsset * asset, std::string path) {
		SpriteAsset *p = (SpriteAsset*)AssetManager::Get(path);

		if(p == nullptr) {
			if(asset->Load(path)) {
				Push(path, asset);
				return true;
			}
			else {
				_ERROR("PICTURE NOT FOUND");
				return false;
			}
		}

		// get the picture from cache
		_LOG("%u LOADED FROM CACHE", 123);
		*asset = *p;
		return true;
	}

	void AssetManager::Push(std::string key, Asset * asset) {
		// we use lower case for the key
		std::string k = key;
		std::transform(k.begin(), k.end(), k.begin(), ::tolower);

		// if we didn't have this asset yet we register it
		if(__assets[k] == nullptr) {
			__assets[k] = asset;
		}
	}

	Asset * AssetManager::Get(std::string key) {
		// we use lower case for the key
		std::string k = key;
		std::transform(k.begin(), k.end(), k.begin(), ::tolower);

		// get the asset from our "cache"
		return __assets[k];
	}
}