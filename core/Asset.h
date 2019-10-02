/**
 * @license
 */

 /**
  * @fileoverview Asset Header
  *
  * Base Asset Object
  *
  * @author @alexribeirodesa (Alexandre Ribeiro de Sá)
  */

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

	class Asset {
	protected:
		AssetTypes __type;
		void *__data;

	public:
		Asset();
		~Asset();
			
		void *Data();
		virtual bool Load(std::string asset);
		virtual bool LoadFromFile(std::string path);
	};
}

#endif // FACTORY2D_RESOURCEMANAGER_RESOURCE_H_