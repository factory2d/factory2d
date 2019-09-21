#pragma once
#include "TextureObject.h"
	
class Texture2D :
	public TextureObject {
private:
	unsigned int *__texture;

public:
	Texture2D();
	~Texture2D();
};
