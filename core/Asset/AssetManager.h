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
#ifndef FACTORY2D_ASSET_ASSETMANAGER_H_
#define FACTORY2D_ASSET_ASSETMANAGER_H_

#include <string>
#include <map>
#include <vector> 

#include "Asset.h"
#include "PictureAsset.h"

namespace F2D
{
	class AssetManager {
	private:
		static std::map <std::string, Asset*> __assets;

		// load picture asset
		static bool LoadAsset(PictureAsset * asset, std::string path);

		// manage assets inside the manager
		static void Push(std::string key, Asset *asset);
		static void Pop(std::string key);
		static Asset * Get(std::string key);

	public:
		template<typename T>
		static T * Load(std::string path) {
			T * asset = new T();

			if(LoadAsset(asset, path)) {
				return asset;
			}

			return nullptr;
		}
	};
}

#endif