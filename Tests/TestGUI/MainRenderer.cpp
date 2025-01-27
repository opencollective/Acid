#include "MainRenderer.hpp"

#include <Fonts/SubrenderFonts.hpp>
#include <Fonts/SubrenderFonts2.hpp>
#include <Guis/SubrenderGuis.hpp>
#include <Graphics/Graphics.hpp>
#include <Scenes/Scenes.hpp>

namespace test {
MainRenderer::MainRenderer() {
	std::vector<Attachment> renderpassAttachments0 = {
		{0, "depth", Attachment::Type::Depth},
		{1, "swapchain", Attachment::Type::Swapchain}
	};
	std::vector<SubpassType> renderpassSubpasses0 = {
		{0, {0, 1}}
	};
	AddRenderStage(std::make_unique<RenderStage>(renderpassAttachments0, renderpassSubpasses0));
}

void MainRenderer::Start() {
	AddSubrender<SubrenderGuis>({0, 0});
	AddSubrender<SubrenderFonts>({0, 0});
	AddSubrender<SubrenderFonts2>({0, 0});
}

void MainRenderer::Update() {
}
}
