#include "AxisButton.hpp"

namespace acid {
AxisButton::AxisButton(std::unique_ptr<Button> &&negative, std::unique_ptr<Button> &&positive) :
	m_negative(std::move(negative)),
	m_positive(std::move(positive)) {
	m_negative->OnButton().Add([this](InputAction action, BitMask<InputMod> mods) {
		m_onAxis(GetAmount());
	}, this);
	m_positive->OnButton().Add([this](InputAction action, BitMask<InputMod> mods) {
		m_onAxis(GetAmount());
	}, this);
}

float AxisButton::GetAmount() const {
	float amount = 0.0f;

	if (m_positive->IsDown()) {
		amount += 1.0f;
	}

	if (m_negative->IsDown()) {
		amount -= 1.0f;
	}

	return amount;
}
}
