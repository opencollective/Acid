#version 450
#extension GL_ARB_separate_shader_objects : enable
#extension GL_ARB_shading_language_420pack : enable

layout(binding = 0) uniform UniformObject {
	mat4 modelView;
	float alpha;

	vec4 colour;
	vec4 borderColour;
	vec2 borderSizes;
	vec2 edgeData;
} object;

layout(binding = 2) uniform sampler2D samplerColour;

layout(location = 0) in vec2 inUV;

layout(location = 0) out vec4 outColour;

void main() {
	float distance = texture(samplerColour, inUV).a;
	float alpha = smoothstep((1.0f - object.edgeData.x) - object.edgeData.y, 1.0f - object.edgeData.x, distance);
	float outlineAlpha = smoothstep((1.0f - object.borderSizes.x) - object.borderSizes.y, 1.0f - object.borderSizes.x, distance);
	float overallAlpha = alpha + (1.0f - alpha) * outlineAlpha;
	vec3 overallColour = mix(object.borderColour.rgb, object.colour.rgb, alpha / overallAlpha);

	outColour = vec4(overallColour, overallAlpha);
	outColour.a *= object.alpha;

	if (outColour.a < 0.05f) {
		outColour = vec4(0.0f);
		discard;
	}
}
