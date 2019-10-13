#include "Transform.h"

#include "GameTime.h"

namespace F2D
{

	Transform::Transform(FactoryObject* factoryObject) {
		__factoryObject = factoryObject;
		__position->x = __position->y = __position->z = 0.0f;
		__rotate->x = __rotate->y = __rotate->z = 0.0f;
	}

	Transform::~Transform() {}

	void Transform::Translate(float x, float y, float z) {
		__position->x += x * GameTime::Delta();
		__position->y += y * GameTime::Delta();
		__position->z += z * GameTime::Delta();
	}

	void Transform::Rotate(float x, float y, float z) {
		if(x != 0.0f) { __rotate->x += x * GameTime::Delta(); }
		if(y != 0.0f) { __rotate->y += y * GameTime::Delta(); }
		if(z != 0.0f) { __rotate->z += z * GameTime::Delta(); }
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