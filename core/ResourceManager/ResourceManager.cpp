#include <locale>

#include "ResourceManager.h"

void * ResourceManager::Load(std::string name) {
	//	get file extension to know what type of file it is
	std::string ext = name.substr(name.find_last_of(".") + 1);

	return nullptr;
}
