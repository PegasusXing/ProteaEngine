#include "ProteaPCH.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Protea {

    VertexArray* VertexArray::Create()
    {
        switch (Renderer::GetAPI())
        {
            case RendererAPI::None:    PROTEA_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
            case RendererAPI::OpenGL:  return new OpenGLVertexArray();
        }

        PROTEA_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}