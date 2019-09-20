#pragma once

#include "Engine/Engine.hpp"
#include "Models/ModelRegister.hpp"
#include "Scene.hpp"
#include "SceneStructure.hpp"

namespace acid {
/**
 * @brief Module used for managing game scenes.
 */
class ACID_EXPORT Scenes : public Module::Registrar<Scenes> {
public:
	Scenes();

	void Update() override;

	/**
	 * Gets the current scene.
	 * @return The current scene.
	 */
	Scene *GetScene() const { return m_scene.get(); }

	/**
	 * Sets the current scene to a new scene.
	 * @param scene The new scene.
	 */
	void SetScene(std::unique_ptr<Scene> &&scene) { m_scene = std::move(scene); }

	/**
	 * Gets the model register used by the engine. The register can be used to register/deregister model types.
	 * @return The model register.
	 */
	ModelRegister &GetModelRegister() { return m_modelRegister; }

	/**
	 * Gets the current camera object.
	 * @return The current camera.
	 */
	Camera *GetCamera() const { return m_scene ? m_scene->GetCamera() : nullptr; }

	/**
	 * Gets the scene physics system.
	 * @return The scenes physics system.
	 */
	ScenePhysics *GetPhysics() const { return m_scene ? m_scene->GetPhysics() : nullptr; }

	/**
	 * Gets the scene object structure.
	 * @return The scene object structure.
	 */
	SceneStructure *GetStructure() const { return m_scene ? m_scene->GetStructure() : nullptr; }

	/**
	 * Gets if the scene is paused.
	 * @return If the scene is paused.
	 */
	bool IsPaused() const { return m_scene ? m_scene->IsPaused() : false; }

private:
	std::unique_ptr<Scene> m_scene;

	ModelRegister m_modelRegister;
};
}
