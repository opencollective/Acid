#include "MainApp.hpp"

#include <Files/Files.hpp>
#include <Inputs/ButtonKeyboard.hpp>
#include <Devices/Mouse.hpp>
#include <Graphics/Graphics.hpp>
#include <Scenes/Scenes.hpp>
#include <Timers/Timers.hpp>
#include "Behaviours/HeightDespawn.hpp"
#include "Behaviours/NameTag.hpp"
#include "MainRenderer.hpp"
#include "Scenes/PlayerFps.hpp"
#include "Scenes/Scene1.hpp"
#include "Skybox/CelestialBody.hpp"
#include "Skybox/SkyboxCycle.hpp"
#include "Terrain/MaterialTerrain.hpp"
#include "Terrain/Terrain.hpp"
#include "World/World.hpp"
#include "Resources/Resources.hpp"

int main(int argc, char **argv) {
	using namespace test;

	// Creates the engine.
	auto engine = std::make_unique<Engine>(argv[0]);
	engine->SetApp(std::make_unique<MainApp>());

	// Runs the game loop.
	auto exitCode = engine->Run();

	// Pauses the console.
	std::cout << "Press enter to continue...";
	std::cin.get();
	return exitCode;
}

namespace test {
MainApp::MainApp() :
	App("Test Physics", {1, 0, 0}),
	m_buttonFullscreen(Key::F11),
	m_buttonScreenshot(Key::F9),
	m_buttonExit(Key::Delete) {
	// Registers file search paths.
#if defined(ACID_PACKED_RESOURCES)
	for (auto &file : FileSystem::FilesInPath(std::filesystem::current_path(), false)) {
		if (String::Contains(file, "data-"))
			Files::Get()->AddSearchPath(String::ReplaceFirst(file, FileSystem::GetWorkingDirectory() + FileSystem::Separator, ""));
	}
#else
	Files::Get()->AddSearchPath("Resources/Engine");
#endif

	m_buttonFullscreen.OnButton().Add([this](InputAction action, BitMask<InputMod> mods) {
		if (action == InputAction::Press) {
			Window::Get()->SetFullscreen(!Window::Get()->IsFullscreen());
		}
	});
	m_buttonScreenshot.OnButton().Add([this](InputAction action, BitMask<InputMod> mods) {
		if (action == InputAction::Press) {
			Resources::Get()->GetThreadPool().Enqueue([]() {
				Graphics::Get()->CaptureScreenshot(Time::GetDateTime("Screenshots/%Y%m%d%H%M%S.png"));
			});
		}
	});
	m_buttonExit.OnButton().Add([this](InputAction action, BitMask<InputMod> mods) {
		if (action == InputAction::Press) {
			Engine::Get()->RequestClose();
		}
	});

	// Registers modules.
	World::Register(ModuleStage::Always);
	//Shadows::Deregister();

	// Registers components.
	auto &componentRegister = Scenes::Get()->GetComponentRegister();
	componentRegister.Add<HeightDespawn>("heightDespawn");
	componentRegister.Add<NameTag>("nameTag");
	componentRegister.Add<PlayerFps>("playerFps");
	componentRegister.Add<CelestialBody>("celestialBody");
	componentRegister.Add<SkyboxCycle>("skyboxCycle");
	componentRegister.Add<MaterialTerrain>("materialTerrain");
	componentRegister.Add<Terrain>("terrain");
}

MainApp::~MainApp() {
	m_configs.Save();
	// TODO: Only clear our search paths (leave Engine resources alone!)
	Files::Get()->ClearSearchPath();

	Graphics::Get()->SetRenderer(nullptr);
	Scenes::Get()->SetScene(nullptr);
}

void MainApp::Start() {
	m_configs.Load();
	Log::Out("Current DateTime: ", Time::GetDateTime(), '\n');
	Log::Out("Working Directory: ", std::filesystem::current_path(), '\n');

	Timers::Get()->Once(0.333s, []() {
		Log::Out("Timer Hello World!\n");
	});
	Timers::Get()->Every(3s, []() {
		Log::Out(Engine::Get()->GetFps(), " fps, ", Engine::Get()->GetUps(), " ups\n");
	});
	Timers::Get()->Repeat(2s, 3, []() {
		static uint32_t i = 0;
		Log::Out("Timer Repeat Tick #", i, '\n');
		i++;
	});

	// Sets values to modules.
	Window::Get()->SetTitle("Test Physics");
	Window::Get()->SetIcons({
		"Icons/Icon-16.png", "Icons/Icon-24.png", "Icons/Icon-32.png", "Icons/Icon-48.png", "Icons/Icon-64.png", "Icons/Icon-96.png",
		"Icons/Icon-128.png", "Icons/Icon-192.png", "Icons/Icon-256.png"
		});
	//Mouse::Get()->SetCursor("Guis/Cursor.png", CursorHotspot::UpperLeft);
	Graphics::Get()->SetRenderer(std::make_unique<MainRenderer>());
	Scenes::Get()->SetScene(std::make_unique<Scene1>());
}

void MainApp::Update() {
}
}
