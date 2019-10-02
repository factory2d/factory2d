/**
 * @license
 */

 /**
  * @fileoverview Asset Manager Header for Factory2D Game Engine.
  *
  * Here we manage the assets to make sure we didn't load more than one
  * instance of each files to make the memory happy :)
  *
  * @author @alexribeirodesa (Alexandre Ribeiro de Sá)
  */

#ifndef __FACTORY2D_ASSETMANAGER
#define __FACTORY2D_ASSETMANAGER

#include <string>
#include <map>
#include <vector> 

#include "../Asset.h"
#include "Picture.h"

namespace F2D
{
	class AssetManager {
	private:
		static std::map <std::string, Asset*> __assets;

		static bool LoadAsset(Picture * asset, std::string path);

	public:
		template<typename T>
		static T * Load(std::string path) {
			T * asset = new T();

			if(LoadAsset(asset, path)) {
				return asset;
			}

			return NULL;
		}

		static void PushAsset(std::string key, Asset *asset);
		static Asset * PullAsset(std::string key);
	};
}

#endif