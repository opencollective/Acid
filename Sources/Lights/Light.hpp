#pragma once

#include "Maths/Colour.hpp"
#include "Maths/Vector3.hpp"
#include "Scenes/Component.hpp"

namespace acid {
/**
 * @brief Component that represents a point light.
 */
class ACID_EXPORT Light : public Component::Registrar<Light> {
public:
	/**
	 * Creates a new point light.
	 * @param colour The colour of the light.
	 * @param radius How far the light will have influence (-1 sets this to a directional light).
	 */
	explicit Light(const Colour &colour = Colour::White, float radius = -1.0f);

	void Start() override;
	void Update() override;

	const Colour &GetColour() const { return m_colour; }
	void SetColour(const Colour &colour) { m_colour = colour; }

	float GetRadius() const { return m_radius; }
	void SetRadius(float radius) { m_radius = radius; }

	friend const Node &operator>>(const Node &node, Light &light);
	friend Node &operator<<(Node &node, const Light &light);

private:
	Colour m_colour;
	Vector3f m_position;
	float m_radius;
};
}
