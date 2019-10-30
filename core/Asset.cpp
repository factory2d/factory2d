/**
 * @license
 */

 /**
  * @fileoverview Asset
  *
  * Base Asset Object
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#include "Asset.h"

namespace F2D
{
	Asset::Asset() {}

	Asset::~Asset() {}

	void *Asset::Data() {
		return __data;
	}

	bool Asset::Load(std::string asset) { return false; }

	bool Asset::LoadFromFile(std::string path) { return false; }
}