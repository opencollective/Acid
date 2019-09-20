﻿#pragma once

#include "Scenes/Component.hpp"
#include "Emitter.hpp"

namespace acid {
class ACID_EXPORT EmitterSphere : public Component::Registrar<EmitterSphere>, public Emitter {
public:
	explicit EmitterSphere(float radius = 1.0f);

	void Start() override;
	void Update() override;
	Vector3f GeneratePosition() const override;

	float GetRadius() const { return m_radius; }
	void SetRadius(float radius) { m_radius = radius; }

	friend const Node &operator>>(const Node &node, EmitterSphere &emitter);
	friend Node &operator<<(Node &node, const EmitterSphere &emitter);

private:
	float m_radius;
};
}
