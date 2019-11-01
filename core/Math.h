#ifndef __FACTORY2D_MATH
#define __FACTORY2D_MATH

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Properties.h"

/*
#include <glm/vec3.hpp>					//	glm::vec3
#include <glm/vec4.hpp>					//	glm::vec4
#include <glm/mat4x4.hpp>				//	glm::mat4
#include <glm/gtc/matrix_transform.hpp> //	glm::translate, glm::rotate, glm::scale, glm::perspective
*/

namespace F2D
{
	class Rect {
	public:
		Rect() {}
		Rect(glm::vec2 *position, glm::vec2 *size) : x(position->x), y(position->y), width(size->x), height(size->y) {};
		Rect(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {}
		~Rect() {};

		float x = 0.0f;
		float y = 0.0f;
		float width = 0.0f;
		float height = 0.0f;
	};

	class MyClass :
		public glm::vec3 {
	private:
		int _attribute;

	public:
		GETSET(MyClass, int, x, {
		  std::clog << "Getting attribute equals to " << _attribute << std::endl;
		  return _attribute;
			}, {
			  std::clog << "Setting attribute to " << value << std::endl;
			  _attribute = value;
			});

		MyClass()
			: _attribute(0),
			x(this) {}
	};
}

#endif
