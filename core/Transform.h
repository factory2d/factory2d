/**
 * @license
 * F2D are available under the zlib license:
 *
 * This software is provided 'as-is', without any express or implied
 * warranty.  In no event will the authors be held liable for any damages
 * varising from the use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software. If you use this software
 *    in a product, an acknowledgment in the product documentation would be
 *    appreciated but is not required.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 */

 /**
  * @fileoverview Transform.h
  *
  * --- FILE NOTES ---
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#ifndef FACTORY2D_TRANSFORM_H_
#define FACTORY2D_TRANSFORM_H_

#include <vector> 
#include "Math.h"
#include "Objects/FactoryObject.h"

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
		/*
		glm::vec3* position = __position;
		glm::vec3* origin = __origin;
		glm::vec3* scale = __scale;
		glm::vec3* rotate = __rotate;
		*/

		Transform(FactoryObject* factoryObject);
		~Transform();

		glm::vec3* GetPosition() { return __position; };
		void SetPosition(glm::vec3 *value) { __position = value; };
		void SetPosition(float x, float y, float z) { SetPosition(new glm::vec3(x, y, z)); };
		void Translate(float x, float y, float z);

		glm::vec3* GetOrigin() { return __origin; };
		void SetOrigin(glm::vec3 *value) { __origin = value; };
		void SetOrigin(float x, float y, float z) { SetOrigin(new glm::vec3(x, y, z)); };

		glm::vec3* GetScale() { return __scale; };
		void SetScale(glm::vec3 *value) { __scale = value; };
		void SetScale(float x, float y, float z) { SetOrigin(new glm::vec3(x, y, z)); };

		glm::vec3* GetRotate() { return __rotate; };
		void SetRotate(glm::vec3 *value) { __rotate = value; };
		void SetRotate(float x, float y, float z) { SetRotate(new glm::vec3(x, y, z)); };
		void Rotate(float x, float y, float z);

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

#endif // FACTORY2D_TRANSFORM_H_