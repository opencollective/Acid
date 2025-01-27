#include "CameraFps.hpp"

#include <Scenes/Scenes.hpp>
#include <Devices/Mouse.hpp>
#include <Maths/Maths.hpp>
#include <Graphics/Graphics.hpp>
#include <Physics/CollisionObject.hpp>
#include "PlayerFps.hpp"

namespace test {
static const Vector3f ViewOffset(0.0f, 1.8f, 0.0f);
static const Vector2f SensitivityJoystick(-0.06f);
static const Vector2f SensitivityMouse(0.15f);

CameraFps::CameraFps() :
	m_sensitivity(1.0f),
	m_joystickVertical(0, 3),
	m_joystickHorizontal(0, 2) {
	m_nearPlane = 0.1f;
	m_farPlane = 4098.0f;
	m_fieldOfView = Maths::Radians(70.0f);
}

void CameraFps::Start() {
}

void CameraFps::Update() {
	auto delta = Engine::Get()->GetDelta().AsSeconds();

	if (auto scenePlayer = Scenes::Get()->GetStructure()->GetComponent<PlayerFps>(); scenePlayer) {
		if (auto transformPlayer = scenePlayer->GetEntity()->GetComponent<Transform>(); transformPlayer) {
			m_velocity = (transformPlayer->GetPosition() - m_position) / delta;
			m_position = transformPlayer->GetPosition() + ViewOffset;
		}
	}

	if (!Scenes::Get()->IsPaused()) {
		auto rotationDelta = Mouse::Get()->GetPositionDelta() * Mouse::Get()->IsCursorHidden() * SensitivityMouse;

		if (m_joystickVertical.IsConnected()) {
			rotationDelta += Vector2f(m_joystickHorizontal.GetAmount(), m_joystickVertical.GetAmount()) * SensitivityJoystick;
		}

		m_rotation.m_y += rotationDelta.m_x * m_sensitivity;
		m_rotation.m_x += rotationDelta.m_y * m_sensitivity;
		m_rotation.m_x = std::clamp(m_rotation.m_x, Maths::Radians(90.0f), Maths::Radians(270.0f));
	}

	m_viewMatrix = Matrix4::ViewMatrix(m_position, m_rotation);
	m_projectionMatrix = Matrix4::PerspectiveMatrix(GetFieldOfView(), Window::Get()->GetAspectRatio(), GetNearPlane(), GetFarPlane());

	m_viewFrustum.Update(m_viewMatrix, m_projectionMatrix);
	m_viewRay.Update(m_position, {0.5f, 0.5f}, m_viewMatrix, m_projectionMatrix);
}
}
