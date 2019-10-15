#include "TagManager.h"

namespace F2D
{
	std::map <std::string, std::vector<FactoryObject*>*> TagManager::__tags = {};
	//std::map <std::string, int> TagManager::__tags = { {"a", 1}, {"b", 2} };

	void TagManager::SetTag(std::string tag, FactoryObject * object) {
		std::vector<FactoryObject*> objects = {};
		__tags[tag] = &objects;
		__tags[tag]->push_back(object);
	}
}