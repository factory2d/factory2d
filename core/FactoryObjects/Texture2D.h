#pragma once
#include "TextureObject.h"
	
namespace F2D
{
	class Texture2D :
		public TextureObject {
	private:
		unsigned int *__texture;

	public:
		Texture2D();
		~Texture2D();
	};
}