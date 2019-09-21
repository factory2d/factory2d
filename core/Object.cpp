#include "Object.h"
#include <iostream>
#include <iomanip>
#include <sstream>

Object::Object() {
	std::stringstream hexuuid;
	
	__uuid = (unsigned int)this;
	
	hexuuid << std::hex << __uuid;
	name = hexuuid.str();
}

Object::~Object() {
}

unsigned int Object::GetUUID() {
	return __uuid;
}
