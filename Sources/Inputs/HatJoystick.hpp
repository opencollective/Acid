#pragma once

#include "Devices/Joysticks.hpp"
#include "Axis.hpp"
#include "Button.hpp"

namespace acid {
/**
 * @brief Button from a joystick.
 */
class ACID_EXPORT HatJoystick : public Axis, public Button {
public:
	/**
	 * Creates a new joystick button.
	 * @param port The joystick port.
	 * @param hat The hat that will be checked.
	 * @param hatFlags If this bit is found the hat will trigger {@link HatJoystick#IsDown}.
	 */
	HatJoystick(uint32_t port, uint32_t hat, const BitMask<JoystickHat> &hatFlags = JoystickHat::Centered);

	float GetAmount() const override;
	bool IsDown() const override;

	uint32_t GetPort() const { return m_port; }
	void SetPort(uint32_t port) { m_port = port; }

	uint32_t GetHat() const { return m_hat; }
	void SetHat(uint32_t hat) { m_hat = hat; }

	const BitMask<JoystickHat> &GetHatFlags() const { return m_hatFlags; }
	void SetHatFlags(JoystickHat hatFlags) { m_hatFlags = hatFlags; }

private:
	uint32_t m_port;
	uint32_t m_hat;
	BitMask<JoystickHat> m_hatFlags;
	bool m_lastDown = false;
};
}
