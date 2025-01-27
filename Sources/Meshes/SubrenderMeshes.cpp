#include "SubrenderMeshes.hpp"

#include "Scenes/Scenes.hpp"
#include "MeshRender.hpp"

namespace acid {
SubrenderMeshes::SubrenderMeshes(const Pipeline::Stage &pipelineStage, Sort sort) :
	Subrender(pipelineStage),
	m_sort(sort),
	m_uniformScene(true) {
}

void SubrenderMeshes::Render(const CommandBuffer &commandBuffer) {
	auto camera = Scenes::Get()->GetCamera();
	m_uniformScene.Push("projection", camera->GetProjectionMatrix());
	m_uniformScene.Push("view", camera->GetViewMatrix());
	m_uniformScene.Push("cameraPos", camera->GetPosition());

	auto sceneMeshRenders = Scenes::Get()->GetStructure()->QueryComponents<MeshRender>();

	if (m_sort != Sort::None) {
		std::sort(sceneMeshRenders.begin(), sceneMeshRenders.end());

		if (m_sort == Sort::Front) {
			std::reverse(sceneMeshRenders.begin(), sceneMeshRenders.end());
		}
	}

	for (const auto &meshRender : sceneMeshRenders) {
		meshRender->CmdRender(commandBuffer, m_uniformScene, GetStage());
	}
}
}
