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

namespace F2D
{
	float dt = 0.0f; 

	Transform::Transform(FactoryObject* factoryObject) {
		__factoryObject = factoryObject;
		__position->x = __position->y = __position->z = 0.0f;
		__rotate->x = __rotate->y = __rotate->z = 0.0f;
	}

	Transform::~Transform() {}

	void Transform::Translate(float x, float y, float z) {
		dt = TimeManager::Delta();
		__position->x += x * dt;
		__position->y += y * dt;
		__position->z += z * dt;
	}

	void Transform::Rotate(float x, float y, float z) {
		dt = TimeManager::Delta();
		if(x != 0.0f) { __rotate->x += x * dt; }
		if(y != 0.0f) { __rotate->y += y * dt; }
		if(z != 0.0f) { __rotate->z += z * dt; }
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