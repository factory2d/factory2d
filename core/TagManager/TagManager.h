#ifndef FACTORY2D_TAGMANAGER_TAGMANAGER_H_
#define FACTORY2D_TAGMANAGER_TAGMANAGER_H_

#include "../Debug.h"
#include "../FactoryObjects/SceneObject.h"

#include <string>
#include <map>
#include <vector>

namespace F2D
{
	class TagManager {
	private:
		static std::map <std::string, std::vector<SceneObject*>*> __tags;
		//static std::map <std::string, int> __tags;

	public:
		static void SetTag(std::string tag, SceneObject* object);
	};
}

#endif // FACTORY2D_TAGMANAGER_TAGMANAGER_H_