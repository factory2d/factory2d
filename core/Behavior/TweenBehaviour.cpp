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
	float TweenBehaviour::__Linear(float t) {
		return t;
	}

	float TweenBehaviour::__Quadratic(float t) {
		return powf(t, 2.0f);
	}

	float TweenBehaviour::__Cubic(float t) {
		return powf(t, 3.0f);
	}

	float TweenBehaviour::__Quart(float t) {
		return powf(t, 4);
	}

	float TweenBehaviour::__Quint(float t) {
		return powf(t, 5);
	}

	float TweenBehaviour::__Sine(float t) {
		return (1.0f - cosf(t * 3.1415f / 2.0f));
	}

	float TweenBehaviour::__Back(float t) {
		float s = 1.70158f;
		return t * t * ((s + 1.0f) * t - s);
	}

	float TweenBehaviour::__Bounce(float t) {
		float ret = 0.0f;
		t = 1.0f - t;


		if(t < (1 / 2.75f)) {
			ret = 7.5625f * t * t;
		}
		else if(t < (2.0f / 2.75f)) {
			t = t - (1.5f / 2.75f);
			ret = 7.5625f * t * t + 0.75f;
		}
		else if(t < (2.5f / 2.75f)) {
			t = t - (2.25f / 2.75f);
			ret = 7.5625f * t * t + 0.9375f;
		}
		else {
			t = t - (2.625 / 2.75);
			ret = 7.5625 * t * t + 0.984375;
		}

		return 1 - ret;
	}

	float TweenBehaviour::__TweenOut(float t) {
		return (1.0f - __TweenIn(1.0f - t));
	}

	float TweenBehaviour::__TweenInOut(float t) {
		return (t < 0.5f) ? (__TweenIn(t * 2.0f) / 2.0f) : (1.0f - __TweenIn((1.0f - t) * 2.0f) / 2.0f);;
	}

	float TweenBehaviour::__Tween() {
		switch(__ease) {
		case F2D_TWEEN_EASEIN:
			return __TweenIn(__value);
		case F2D_TWEEN_EASEOUT:
			return __TweenOut(__value);
		case F2D_TWEEN_EASEINOUT:
			return __TweenInOut(__value);
		}

		return 0.0f;
	}

	TweenBehaviour::TweenBehaviour(std::vector<Tween> tweens, float interval) {
		__tweens = std::vector<Tween>(tweens);
		__interval = interval;
	}

	void TweenBehaviour::Update() {
		__value += TimeManager::Delta() / __interval;
		if(__value > 1.0f) {
			__value = 0.0f;
			std::cout << "FIM" << std::endl;
		}

		for(int x = 0; x < __tweens.size(); x++) {
			switch(__tweens[x].tween) {
			case F2D_TWEEN_QUADRATIC:
				__TweenIn = &TweenBehaviour::__Quadratic; break;
			case F2D_TWEEN_CUBIC:
				__TweenIn = &TweenBehaviour::__Cubic; break;
			case F2D_TWEEN_QUART:
				__TweenIn = &TweenBehaviour::__Quart; break;
			case F2D_TWEEN_QUINT:
				__TweenIn = &TweenBehaviour::__Quint; break;
			case F2D_TWEEN_SINE:
				__TweenIn = &TweenBehaviour::__Sine; break;
			case F2D_TWEEN_BOUNCE:
				__TweenIn = &TweenBehaviour::__Bounce; break;
			case F2D_TWEEN_BACK:
				__TweenIn = &TweenBehaviour::__Back; break;
			default:
				__TweenIn = &TweenBehaviour::__Linear; break;
			}

			__ease = __tweens[x].ease;
			__tweens[x].value = __tweens[x].from + (__tweens[x].to - __tweens[x].from)*__Tween();
		}
	}
}
