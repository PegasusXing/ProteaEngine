
#ifndef OPENGLRENDERERAPI_H
#define OPENGLRENDERERAPI_H


#include "Protea/Renderer/RendererAPI.h"

namespace Protea {

    class OpenGLRendererAPI : public RendererAPI
    {
    public:
        virtual void SetClearColor(const glm::vec4& color) override;
        virtual void Clear() override;

        virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
    };


}



#endif //OPENGLRENDERERAPI_H
