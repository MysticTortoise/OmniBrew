#include "OmniBrew/Cores/GraphicsCore/WindowsGL/Meshes/MeshWindows.hpp"

#include "OmniBrew/PlatformIncludes/OpenGL.hpp"

using namespace OmniBrew::Core::GraphicsCore;


MeshWindows::MeshWindows(unsigned int VAO, unsigned int VBO, unsigned int EBO) :
	VAO(VAO),
	VBO(VBO),
	EBO(EBO)
{
	
}

MeshWindows::~MeshWindows() {
	glDeleteVertexArrays(1, &VAO);

	unsigned int* buffers[] = { &VBO, &EBO };
	glDeleteBuffers(2, *buffers);
}