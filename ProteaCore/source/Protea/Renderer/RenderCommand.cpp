#include "ProteaPCH.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Protea {

    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}