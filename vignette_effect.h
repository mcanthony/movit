#ifndef _MOVIT_VIGNETTE_EFFECT_H
#define _MOVIT_VIGNETTE_EFFECT_H 1

// A circular vignette, falling off as cos² of the distance from the center
// (the classic formula for approximating a real lens).

#include <GL/glew.h>
#include <string>

#include "effect.h"

namespace movit {

class VignetteEffect : public Effect {
public:
	VignetteEffect();
	virtual std::string effect_type_id() const { return "VignetteEffect"; }
	std::string output_fragment_shader();

	virtual bool needs_srgb_primaries() const { return false; }
	virtual AlphaHandling alpha_handling() const { return DONT_CARE_ALPHA_TYPE; }

	virtual void inform_input_size(unsigned input_num, unsigned width, unsigned height);
	void set_gl_state(GLuint glsl_program_num, const std::string &prefix, unsigned *sampler_num);

private:
	Point2D center, aspect_correction;
	float radius, inner_radius;
};

}  // namespace movit

#endif // !defined(_MOVIT_VIGNETTE_EFFECT_H)
