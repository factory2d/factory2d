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
  * @fileoverview Transform.cpp
  *
  * --- FILE NOTES ---
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#include "Transform.h"

#include "Time/TimeManager.h"

#include "SDL_opengl.h"
#include <GL\GLU.h>

namespace F2D
{
	float dt = 0.0f; 

	Transform::Transform(FactoryObject* factoryObject) {
		__factoryObject = factoryObject;
		__position.x = __position.y = __position.z = 0.0f;
		__rotate.x = __rotate.y = __rotate.z = 0.0f;
	}

	Transform::~Transform() {}

	void Transform::SetPosition(glm::vec3 value) {
		__position = value;

		//__localPosition = glm::translate(glm::mat4(1.0f), value);
		__matrixUpdate = true;
	}

	void Transform::Translate(glm::vec3 value) {
		dt = TimeManager::Delta();
		__position.x += value.x * dt;
		__position.y += value.y * dt;
		__position.z += value.z * dt;

		//__localPosition = glm::translate(__localPosition, (value*dt));
		__matrixUpdate = true;
	}

	void Transform::SetOrigin(glm::vec3 value) {
		__origin = value;
		
		//__localOrigin = glm::translate(glm::mat4(1.0f), -value);
		__matrixUpdate = true;
	}

	void Transform::SetRotate(glm::vec3 value) {
		__rotate = value;

		//__localAngle = glm::rotate(glm::mat4(1.0f), 6.28319f, value);
		__matrixUpdate = true;
	}

	void Transform::Rotate(glm::vec3 value) {
		dt = TimeManager::Delta();
		__rotate += value * dt;
		//if(x != 0.0f) { __rotate.x += x * dt; }
		//if(y != 0.0f) { __rotate.y += y * dt; }
		//if(z != 0.0f) { __rotate.z += z * dt; }

		//__localAngle = glm::rotate(glm::mat4(1.0f), 0.0174533f, (value*dt));
		__matrixUpdate = true;
	}

	void Transform::ApplyTransform(bool childUpdate) {
		//glm::mat4 projection = glm::perspective(70.0f, ((float)800) / (float)600, 1.0f, 1000.0f);
		//glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		// local transform matrix cache
		if(__matrixUpdate || childUpdate) {
			__localTransform = glm::mat4(1.0f);

			if(__parent != nullptr )
				__localTransform = glm::translate(__localTransform, __parent->GetOrigin());

			__localTransform = glm::translate(__localTransform, __position);
			__localTransform = glm::rotate(__localTransform, __rotate.y * 0.0174533f, glm::vec3(0.0f, 0.0f, 1.0f));
			__localTransform = glm::translate(__localTransform, -__origin);

			childUpdate = true;
			__matrixUpdate = false;

			if(__parent == nullptr)
				__worldTransform = __localTransform;
			else
				__worldTransform = (-__parent->GetWorldTransform());// *__localTransform;
		}
		
		// update child matrix
		if(childUpdate){
			for(unsigned int x = 0; x < __childs.size(); x++) {
				__childs[x]->ApplyTransform(childUpdate);
			}
		}


		//model = scale * translate * rotate;
		//__localTransform = __localScale * __localPosition * __localAngle;
		//glMultMatrixf(Transform.M);

		//glUniformMatrix4fv(glGetUniformLocation(programID, "MV"), 1, GL_TRUE, glm::value_ptr(ModelViewMatrix));
		//glUniformMatrix4fv(glGetUniformLocation(programID, "MVP"), 1, GL_TRUE, glm::value_ptr(ModelViewProjectionMatrix));
		
	}

	unsigned int Transform::GetChildCount() {
		return __childs.size();
	}

	FactoryObject* Transform::GetFactoryObject() {
		return __factoryObject;
	}

	Transform* Transform::GetParent() {
		return __parent;
	}

	void Transform::SetParent(Transform* parent) {
		if(parent == __parent)
			return;

		//	remove this object from the old parent
		if(__parent != parent) {
			parent->DetachChild(this);
		}

		//	add this object to the parent if it exists
		if(parent != NULL) {
			__parent = parent;
			parent->AttachChild(this);
			__matrixUpdate = true;
		}
	}

	void Transform::AttachChild(Transform* child) {
		if(child == NULL)
			return;

		__childs.push_back(child);
		child->SetParent(this);
	}

	void Transform::DetachChild(Transform* child) {
		if(child == NULL)
			return;

		for(unsigned int x = 0; x < __childs.size(); x++) {
			if(__childs[x] == child) {
				__childs.erase(__childs.begin() + x);
				break;
			}
		}

		child->SetParent(NULL);
	}

	Transform* Transform::GetChild(int index) {
		return __childs[index];
	}

	Transform* Transform::GetChilds() {
		//int output[];// = new Transform*[this->GetChildCount()];
		//std::copy(v.begin(), v.end(), arr);
		return NULL;// output;
	}
}