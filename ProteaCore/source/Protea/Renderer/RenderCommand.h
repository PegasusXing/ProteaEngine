//
// Created by Alex on 21/06/2025.
//

#ifndef RENDERCOMMAND_H
#define RENDERCOMMAND_H

#include "RendererAPI.h"

namespace Protea {
    class RenderCommand {
    public:
        inline static void Init() {
            s_RendererAPI->Init();
        }
        inline static void SetClearColor(const glm::vec4 &color) {
            s_RendererAPI->SetClearColor(color);
        }

        inline static void Clear() {
            s_RendererAPI->Clear();
        }

        inline static void DrawIndexed(const std::shared_ptr<VertexArray> &vertexArray) {
            s_RendererAPI->DrawIndexed(vertexArray);
        }

    private:
        static RendererAPI *s_RendererAPI;
    };
}


#endif //RENDERCOMMAND_H
