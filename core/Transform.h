#ifndef __FACTORY2D_TRANSFORM
#define __FACTORY2D_TRANSFORM

#include <vector> 
#include "Math.h"
#include "FactoryObjects/FactoryObject.h"

namespace F2D {
	class FactoryObject;

	class Transform {
	private:
		Transform* __parent = nullptr;
		std::vector <Transform*> __childs = {};
		FactoryObject* __factoryObject;


		glm::vec3* __position = new glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3* __origin = new glm::vec3(0.0f, 0.0f, 0.0f);
		glm::vec3* __scale = new glm::vec3(1.0f, 1.0f, 1.0f);
		glm::vec3* __rotate = new glm::vec3(0.0f, 0.0f, 0.0f);

		glm::mat4x4* __localTransform = new glm::mat4x4();
		glm::mat4x4* __worldTransform = new glm::mat4x4();

	public:
		glm::vec3* position = __position;
		glm::vec3* origin = __origin;
		glm::vec3* scale = __scale;
		glm::vec3* rotate = __rotate;

		Transform(FactoryObject* factoryObject);
		~Transform();

		glm::vec3* GetPosition() { return __position; };
		void SetPosition(glm::vec3 *value) { __position = value; };
		void SetPosition(float x, float y, float z) { SetPosition(new glm::vec3(x, y, z)); };

		glm::vec3* GetOrigin() { return __origin; };
		void SetOrigin(glm::vec3 *value) { __origin = value; };
		void SetOrigin(float x, float y, float z) { SetOrigin(new glm::vec3(x, y, z)); };

		glm::vec3* GetScale() { return __scale; };
		void SetScale(glm::vec3 *value) { __scale = value; };
		void SetScale(float x, float y, float z) { SetOrigin(new glm::vec3(x, y, z)); };

		glm::vec3* GetRotate() { return __rotate; };
		void SetRotate(glm::vec3 *value) { __rotate = value; };
		void SetRotate(float x, float y, float z) { SetRotate(new glm::vec3(x, y, z)); };

		unsigned int GetChildCount();
		FactoryObject* GetFactoryObject();
		Transform* GetParent();
		void SetParent(Transform* parent);
		void AttachChild(Transform* child);
		void DetachChild(Transform* child);
		Transform* GetChild(int index);
		Transform* GetChilds();
	};
}

#endif