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
  * @fileoverview Color.h
  *
  * --- FILE NOTES ---
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#ifndef FACTORY2D_COLOR_H_
#define FACTORY2D_COLOR_H_

namespace F2D
{
	class Color {
	public:
		static const Color black;		// (0, 0, 0, 1)
		static const Color blue;		// (0, 0, 1, 1)
		static const Color clear;		// (0, 0, 0, 0)
		static const Color cyan;		// (0, 1, 1, 1)
		static const Color gray;		// (0.5, 0.5, 0.5, 1)
		static const Color green;		// (0, 1, 0, 1)
		static const Color grey;		// (0.5, 0.5, 0.5, 1)
		static const Color magenta;		// (1, 0, 1, 1)
		static const Color red;			// (1, 0, 0, 1)
		static const Color white;		// (1, 1, 1, 1)
		static const Color yellow;		// (1, 1, 0, 1)

		Color();
		Color(float r, float g, float b, float a = 1.0f);
		~Color();

		float r = 1.0f;
		float g = 1.0f;
		float b = 1.0f;
		float a = 1.0f;

		//Color operator = (Color lhs, Color rhs);
	};
}

#endif // FACTORY2D_COLOR_H_
