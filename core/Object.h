#ifndef __FACTORY2D_OBJECT
#define __FACTORY2D_OBJECT

#include <string>

namespace F2D
{
	class Object {
	private:
		bool __destroy = false;
		unsigned int __uuid = 0;

	public:
		std::string name;
		bool enabled = true;

		static bool Destroy() {};

		Object();
		~Object();
		unsigned int GetUUID();
	};
}

#endif