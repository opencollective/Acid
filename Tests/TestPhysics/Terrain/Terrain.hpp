#pragma once

#include <Scenes/Component.hpp>
#include <Scenes/Entity.hpp>
#include <Models/Model.hpp>
#include <Maths/Noise/Noise.hpp>
#include "MeshTerrain.hpp"

using namespace acid;

namespace test {
class Terrain : public Component {
public:
	explicit Terrain(float sideLength = 200.0f, float squareSize = 2.0f);

	void Start() override;
	void Update() override;

	friend const Node &operator>>(const Node &node, Terrain &terrain);
	friend Node &operator<<(Node &node, const Terrain &terrain);

private:
	static uint32_t CalculateVertexCount(float sideLength, float squareSize);
	static float CalculateTextureScale(float sideLength);
	std::vector<float> GenerateHeightmap(uint32_t vertexCount);

	Noise m_noise;
	std::vector<float> m_heightmap;

	float m_sideLength;
	float m_squareSize;

	float m_minHeight;
	float m_maxHeight;
};
}
