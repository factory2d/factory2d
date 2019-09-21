#include "Transform.h"

Transform::Transform(FactoryObject* factoryObject) {
	__factoryObject = factoryObject;
}

Transform::~Transform() {}

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
			__childs.erase(__childs.begin()+x);
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
