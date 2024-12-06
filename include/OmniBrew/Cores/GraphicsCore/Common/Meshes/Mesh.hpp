#pragma once

#include <string>

namespace OmniBrew::Core::GraphicsCore {


	struct VertexDataStream {
		std::string inputName;
		int size;
		float data[];
	};

	class Mesh {
		
	};
}