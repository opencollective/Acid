#include "World.hpp"

#include <Post/Deferred/SubrenderDeferred.hpp>
#include <Post/Filters/FilterLensflare.hpp>
#include <Graphics/Graphics.hpp>
#include <Scenes/Scenes.hpp>
#include <Shadows/Shadows.hpp>

namespace test {
static const Colour FOG_COLOUR_SUNRISE("#ee9a90");
static const Colour FOG_COLOUR_NIGHT("#0D0D1A");
static const Colour FOG_COLOUR_DAY("#e6e6e6");

World::World() :
	m_driverDay(DriverLinear<float>(0.0f, 1.0f, 300s)),
	m_factorDay(0.0f),
	m_fog(Colour::White, 0.001f, 2.0f, -0.1f, 0.3f) {
	m_driverDay.Update(50s); // Starts during daytime.
}

void World::Update() {
	m_factorDay = m_driverDay.Update(Engine::Get()->GetDelta());

	m_skyboxRotation = {360.0f * m_factorDay, 0.0f, 0.0f};
	m_lightDirection = {0.154303f, 0.771517f, -0.617213f};

	auto fogColour = FOG_COLOUR_SUNRISE.Lerp(FOG_COLOUR_NIGHT, GetSunriseFactor());
	fogColour = fogColour.Lerp(FOG_COLOUR_DAY, GetShadowFactor());
	m_fog.SetColour(fogColour);
	m_fog.SetDensity(0.002f + ((1.0f - GetShadowFactor()) * 0.002f));
	m_fog.SetGradient(2.0f - ((1.0f - GetShadowFactor()) * 0.380f));
	m_fog.SetLowerLimit(0.0f);
	m_fog.SetUpperLimit(0.15f - ((1.0f - GetShadowFactor()) * 0.03f));

	/*
	if (auto lensflare = Graphics::Get()->GetSubrender<FilterLensflare>())
	{
		lensflare->SetSunPosition(Vector3f(1000.0f, 5000.0f, -4000.0f));
		lensflare->SetSunHeight(1000.0f);
	}*/

	if (auto deferred = Graphics::Get()->GetRenderer()->GetSubrender<SubrenderDeferred>()) {
		deferred->SetFog(m_fog);
	}

	if (Shadows::Get()) {
		Shadows::Get()->SetLightDirection(-m_lightDirection);
		//Shadows::Get()->SetShadowBoxOffset((4.0f * (1.0f - GetShadowFactor())) + 10.0f);
		//Shadows::Get()->SetShadowBoxDistance(40.0f);
		//Shadows::Get()->SetShadowTransition(5.0f);
		//Shadows::Get()->SetShadowDarkness(0.6f * GetShadowFactor());
	}
}

float World::GetDayFactor() const {
	return m_factorDay;
}

float World::GetSunriseFactor() const {
	return std::clamp(-(std::sin(2.0f * Maths::Pi<float> * GetDayFactor()) - 1.0f) / 2.0f, 0.0f, 1.0f);
}

float World::GetShadowFactor() const {
	return std::clamp(1.7f * std::sin(2.0f * Maths::Pi<float> * GetDayFactor()), 0.0f, 1.0f);
}

float World::GetStarIntensity() const {
	return std::clamp(1.0f - GetShadowFactor(), 0.0f, 1.0f);
}
}
