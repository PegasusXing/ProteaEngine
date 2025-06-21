//
// Created by Alex on 21/06/2025.
//

#ifndef RENDERERAPI_H
#define RENDERERAPI_H

#include <glm/glm.hpp>

#include "VertexArray.h"

namespace Protea {
    class RendererAPI {
    public:
        enum class API {
            None = 0, OpenGL = 1
        };

        virtual void Init() = 0;

        virtual void SetClearColor(const glm::vec4 &color) = 0;

        virtual void Clear() = 0;

        virtual void DrawIndexed(const std::shared_ptr<VertexArray> &vertexArray) = 0;

        inline static API GetAPI() { return s_API; }

    private:
        static API s_API;
    };
}


#endif //RENDERERAPI_H
