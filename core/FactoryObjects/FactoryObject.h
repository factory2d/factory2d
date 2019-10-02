/**
 * @license
 */

 /**
  * @fileoverview Base Factory2D Objects Header
  *
  * Base scene objects
  *
  * @author @alexribeirodesa (Alexandre Ribeiro de Sá)
  */

#ifndef FACTORY2D_FACTORYOBJECT_FACTORYOBJECT_H_
#define FACTORY2D_FACTORYOBJECT_FACTORYOBJECT_H_

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

		virtual std::string Serialize();
		virtual bool Deserialize();
	};
}

#endif // FACTORY2D_FACTORYOBJECT_FACTORYOBJECT_H_