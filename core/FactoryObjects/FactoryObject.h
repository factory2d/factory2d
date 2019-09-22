#ifndef __FACTORY2D_FACTORYOBJECT
#define __FACTORY2D_FACTORYOBJECT

#include <string>

#include "../Object.h"
#include "../Transform.h"

namespace F2D
{
	class Transform;

	class FactoryObject :
		public Object {
	private:
		std::string __tag;

	public:
		Transform* transform;

		FactoryObject() {};
		FactoryObject(std::string name);
		~FactoryObject();

		virtual void Update();
		virtual void Draw();
		std::string GetTag();
		void SetTag(std::string tag);
		void RemoveTag();
	};
}

#endif