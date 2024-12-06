#pragma once

#include "OmniBrew/Cores/GraphicsCore/Common/Meshes/Mesh.hpp"

namespace OmniBrew::Core::GraphicsCore {
    class MeshWindows : public Mesh {
    public:
        unsigned int VAO;
        unsigned int VBO;
        unsigned int EBO;

        MeshWindows(unsigned int VAO, unsigned int VBO, unsigned int EBO);
        ~MeshWindows();

    };
}