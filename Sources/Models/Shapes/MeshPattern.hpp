#pragma once

#include "Models/Model.hpp"
#include "Models/VertexDefault.hpp"

namespace acid {
class ACID_EXPORT MeshPattern : public Model {
public:
	MeshPattern(float sideLength, float squareSize, uint32_t vertexCount, float uvScale);

protected:
	virtual VertexDefault GetVertex(uint32_t col, uint32_t row);

	void GenerateMesh();

	float m_sideLength;
	float m_squareSize;
	uint32_t m_vertexCount;
	float m_uvScale;
};
}
