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
  * @fileoverview TweenBehaviour.cpp
  *
  * --- FILE NOTES ---
  *
  * @author Alexandre Ribeiro de Sá (@alexribeirodesa)
  */

#include "TweenBehaviour.h"

#include <iostream>
#include "../Time/TimeManager.h"

namespace F2D
{
	// linear
	float TweenBehaviour::__Linear() {
		return __value;
	}

	// quadratic
	float TWEEN_QUADIN(float t) {
		return std::powf(t, 2.0f);
	}
	float TWEEN_QUADOUT(float t) {
		return  (1 - TWEEN_QUADIN(1 - t));
	}
	float TWEEN_QUADINOUT(float t) {
		return (t < 0.5) ? (TWEEN_QUADIN(t * 2.0) / 2.0) : (1 - TWEEN_QUADIN((1 - t) * 2) / 2);
	}

	float TweenBehaviour::__Quadratic() {
		__ease = F2D_TWEEN_EASEINOUT;
		switch(__ease) {
		case F2D_TWEEN_EASEIN:
			return TWEEN_QUADIN(__value);
		case F2D_TWEEN_EASEOUT:
			return TWEEN_QUADOUT(__value);
		case F2D_TWEEN_EASEINOUT:
			return TWEEN_QUADINOUT(__value);
		}

		return 0.0f;
	}

	// back
	float TWEEN_BACKIN(float t) {
		float s = 1.70158;
		return t * t * ((s + 1) * t - s);
	}
	float TWEEN_BACKOUT(float t) {
		return  (1 - TWEEN_BACKIN(1 - t));
	}
	float TWEEN_BACKINOUT(float t) {
		return (t < 0.5) ? (TWEEN_BACKIN(t * 2.0) / 2.0) : (1 - TWEEN_BACKIN((1 - t) * 2) / 2);
	}

	float TweenBehaviour::__Back() {
		__ease = F2D_TWEEN_EASEINOUT;
		switch(__ease) {
		case F2D_TWEEN_EASEIN:
			return TWEEN_BACKIN(__value);
		case F2D_TWEEN_EASEOUT:
			return TWEEN_BACKOUT(__value);
		case F2D_TWEEN_EASEINOUT:
			return TWEEN_BACKINOUT(__value);
		}

		return 0.0f;
	}

	TweenBehaviour::TweenBehaviour(std::vector<Tween> tweens) {
		__tweens = std::vector<Tween>(tweens);
	}

	void TweenBehaviour::Update() {
		__value += TimeManager::Delta()*0.5f;
		if(__value > 1.0f)
			__value -= 1.0f;

		for(int x = 0; x < __tweens.size(); x++) {
			__tweens[x].value = __tweens[x].to*__Back();
		}
	}
}