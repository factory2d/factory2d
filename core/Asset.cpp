#include "Asset.h"

namespace F2D
{
	Asset::Asset() {}

	Asset::~Asset() {}

	void *Asset::Data() {
		return __data;
	}

	void Asset::Load(std::string asset) {}

	void Asset::LoadFromFile(std::string path) {}

	
}