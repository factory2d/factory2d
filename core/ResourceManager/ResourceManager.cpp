#include <locale>
#include <algorithm>

#include "ResourceManager.h"

namespace F2D
{
	void * ResourceManager::Load(std::string name) {
		// get file extension to know what type of file it is
		std::string ext = name.substr(name.find_last_of(".") + 1);
		std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);


		//for(std::string::size_type i = 0; i < ext.length(); ++i)
		//	std::cout << std::tolower(str[i], loc);

		// pictures jpg, jpeg, png

		// sound wav, ogg
		return nullptr;
	}

	/*void * F2D::ResourceManager::LoadImage(std::string name, int type) {
		std::string key = name;
		std::transform(key.begin(), key.end(), key.begin(), ::tolower);

		// check if resource already loaded
		if(__resources.find(key) == __resources.end()) {
			// not found
		}
		else {
			// found
		}

		return nullptr;
	}
	*/
}