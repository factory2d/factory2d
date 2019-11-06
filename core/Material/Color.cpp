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
  * @fileoverview Color.cpp
  *
  * --- FILE NOTES ---
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#include "Color.h"

namespace F2D
{
	const Color Color::black = { 0.0f, 0.0f, 0.0f, 1.0f };
	const Color Color::blue = { 0.0f, 0.0f, 1.0f, 1.0f };
	const Color Color::clear = { 0.0f, 0.0f, 0.0f, 0.0f };
	const Color Color::cyan = { 0.0f, 1.0f, 1.0f, 1.0f };
	const Color Color::gray = { 0.5f, 0.5f, 0.5f, 1.0f };
	const Color Color::green = { 0.0f, 1.0f, 0.0f, 1.0f };
	const Color Color::grey = { 0.5f, 0.5f, 0.5f, 1.0f };
	const Color Color::magenta = { 1.0f, 0.0f, 1.0f, 1.0f };
	const Color Color::red = { 1.0f, 0.0f, 0.0f, 1.0f };
	const Color Color::white = { 1.0f, 1.0f, 1.0f, 1.0f };
	const Color Color::yellow = { 1.0f, 1.0f, 0.0f, 1.0f };

	Color::Color() {}
	Color::Color(float R, float G, float B, float A) {
		r = R;
		g = G;
		b = B;
		a = A;
	}
	Color::~Color() {}
}
