#include "AxisJoystick.hpp"

#include "Devices/Joysticks.hpp"

namespace acid {
AxisJoystick::AxisJoystick(uint32_t port, uint32_t axis, bool inverted) :
	m_port(port),
	m_axis(axis),
	m_inverted(inverted) {
	Joysticks::Get()->OnAxis().Add([this](uint32_t axis, uint32_t port, float value) {
		if (port == m_port && axis == m_axis) {
			m_onAxis(value);
		}
	}, this);
}

float AxisJoystick::GetAmount() const {
	return Joysticks::Get()->GetAxis(m_port, m_axis) * (m_inverted ? -1.0f : 1.0f);
}

bool AxisJoystick::IsConnected() const {
	return Joysticks::Get()->IsConnected(m_port);
}
}
