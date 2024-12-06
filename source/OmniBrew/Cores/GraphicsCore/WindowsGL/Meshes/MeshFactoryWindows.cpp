#include "OmniBrew/Cores/GraphicsCore/Common/Meshes/MeshFactory.hpp"

#include "OmniBrew/Cores/GraphicsCore/Common/ResourceManager.hpp"
#include "OmniBrew/Cores/GraphicsCore/WindowsGL/Meshes/MeshWindows.hpp"

#include "OmniBrew/PlatformIncludes/OpenGL.hpp"

#include <vector>

using namespace OmniBrew;
using namespace OmniBrew::Core::GraphicsCore;

// need to replace this with named shit
Mesh* CreateFromVerticesAndFaces(const Math::Vector3 vertices[], const unsigned int vertexCount, const int indices[], const std::vector<VertexDataStream> vertexAttributes){
	// Create buffers
	unsigned int VBO, VAO, EBO;
	unsigned int* buffers[] = {&VBO, &EBO};
	glGenBuffers(2, *buffers);

	// Calculate vertex buffer data
	unsigned int sizeOfOneVertex = 3;

	unsigned int attributeCount = vertexAttributes.size();
	for (unsigned int i = 0; i < attributeCount; i++)
		sizeOfOneVertex += vertexAttributes[i].size;

	std::vector<float> vertexData(sizeOfOneVertex * vertexCount);
	for (unsigned int i = 0; i < vertexCount; i++) {
		unsigned int curVDP = i * sizeOfOneVertex; // current vertex data pointer
		Math::Vector3 vertexPos = vertices[i];
		vertexData[curVDP] = vertexPos.x;
		vertexData[curVDP + 1] = vertexPos.y;
		vertexData[curVDP + 2] = vertexPos.z;

		unsigned int aPointer = curVDP + 3; // Current attribute pointer (faster and simpler than recalculating each time)
		for (unsigned int attr = 0; attr < attributeCount; attr++) {
			const VertexDataStream* vertData = vertexAttributes.data();
			for (int val = 0; val < vertData->size; val++) {
				vertexData[aPointer] = vertData->data[i * vertData->size + val];
				aPointer++;
			}
		}
	}
	float* vertexDataRaw = &vertexData[0];

	// Buffer vertex data
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertexData.size(), vertexDataRaw, GL_STATIC_DRAW);

	// Buffer element buffer data
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// Generate vertex array object
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	// Set pointers n shit
	glVertexAttribPointer(0, sizeOfOneVertex, GL_FLOAT, GL_FALSE, sizeOfOneVertex * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	MeshWindows* mesh = new MeshWindows(VAO, VBO, EBO);
	ResourceManager::meshList.push_back(mesh);
	return mesh;
}