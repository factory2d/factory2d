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
  * @fileoverview TweenBehaviour.h
  *
  * --- FILE NOTES ---
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#ifndef FACTORY2D_BEHAVIOUR_TWEENBEHAVIOUR_H_
#define FACTORY2D_BEHAVIOUR_TWEENBEHAVIOUR_H_

#include <vector>
#include "Behaviour.h"

namespace F2D
{
	enum {
		F2D_TWEEN_LINEAR,
		F2D_TWEEN_QUADRATIC,
		F2D_TWEEN_CUBIC,
		F2D_TWEEN_QUART,
		F2D_TWEEN_QUINT,
		F2D_TWEEN_SINE,
		F2D_TWEEN_CIRCULAR,
		F2D_TWEEN_BACK,
		F2D_TWEEN_BOUNCE,
		F2D_TWEEN_ELASTIC,

		F2D_TWEEN_EASEIN,
		F2D_TWEEN_EASEOUT,
		F2D_TWEEN_EASEINOUT,
	};

	struct Tween {
		float &value;
		float from;
		float to;
	};

	class TweenBehaviour :
		public Behaviour {
	private:
		std::vector<Tween> __tweens;
		float __value = 0.0f;
		int __tween = F2D_TWEEN_LINEAR;
		int __ease = F2D_TWEEN_EASEIN;

		float __Linear();
		float __Quadratic();
		float __Back();

	public:
		TweenBehaviour(std::vector<Tween> tweens);
		~TweenBehaviour();

		void Update() override;
	};
}

#endif // FACTORY2D_BEHAVIOUR_TWEENBEHAVIOUR_H_
