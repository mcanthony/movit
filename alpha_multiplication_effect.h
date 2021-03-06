#ifndef _MOVIT_ALPHA_MULTIPLICATION_EFFECT_H
#define _MOVIT_ALPHA_MULTIPLICATION_EFFECT_H 1

// Convert postmultiplied alpha to premultiplied alpha, simply by multiplying.

#include <string>

#include "effect.h"

namespace movit {

class AlphaMultiplicationEffect : public Effect {
public:
	AlphaMultiplicationEffect() {}
	virtual std::string effect_type_id() const { return "AlphaMultiplicationEffect"; }
	std::string output_fragment_shader();
};

}  // namespace movit

#endif // !defined(_MOVIT_ALPHA_MULTIPLICATION_EFFECT_H)
