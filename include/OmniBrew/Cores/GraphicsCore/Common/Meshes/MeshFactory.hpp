#pragma once

#include "OmniBrew/Cores/GraphicsCore/Common/Meshes/Mesh.hpp"
#include "OmniBrew/Math/Vector3.hpp"

#include <vector> // Required for 2d arrays. A vector of arrays (still somewhat performant but not great)


namespace OmniBrew::Core::GraphicsCore::MeshFactory {
	Mesh* CreateFromVerticesAndFaces(const Math::Vector3 vertices[], const unsigned int vertexCount, const int indices[], const std::vector<VertexDataStream> vertexAttributes);
}