#pragma once

#include <Engine/App.hpp>
#include <Inputs/ButtonKeyboard.hpp>
#include <Inputs/ButtonCompound.hpp>

using namespace acid;

namespace test {
class MainApp : public App {
public:
	MainApp();

	~MainApp();

	void Start() override;
	void Update() override;

private:
	ButtonKeyboard m_buttonFullscreen;
	ButtonKeyboard m_buttonScreenshot;
	ButtonKeyboard m_buttonExit;
};
}
