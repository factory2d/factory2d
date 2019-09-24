#ifndef FACTORY2D_RESOURCEMANAGER_RESOURCE_H_
#define FACTORY2D_RESOURCEMANAGER_RESOURCE_H_

#include <string>

namespace F2D
{
	enum AssetTypes {
		IMAGE = 0,
		SPRITE,
		SOUND,
		MUSIC,
		VIDEO,
		FONT,
	};

	/*enum ImagesTypes {
		PNG = 0,
		JPG,
	};*/

	class Asset {
	public:
		AssetTypes __type;
		void *__data;

	public:
		Asset();
		~Asset();
			
		void *Data();
		virtual void Load(std::string asset);
		virtual void LoadFromFile(std::string path);
	};
}

#endif // FACTORY2D_RESOURCEMANAGER_RESOURCE_H_