#pragma once

#include <Maths/Colour.hpp>
#include <Models/Shapes/MeshSimple.hpp>
#include <Maths/Maths.hpp>

using namespace acid;

namespace test {
class MeshTerrain : public MeshSimple {
public:
	MeshTerrain(const std::vector<float> &heightmap, float sideLength, float squareSize, uint32_t vertexCount, float textureScale);

protected:
	VertexDefault GetVertex(uint32_t col, uint32_t row) override;

private:
	Vector3f GetPosition(float x, float z);
	Vector3f GetNormal(float x, float z);
	Colour GetColour(const Vector3f &normal);

	std::vector<float> m_heightmap;
};
}
