#ifndef OPENGLCONTEXT_H
#define OPENGLCONTEXT_H

#include "Protea/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Protea {
    class OpenGLContext : public GraphicsContext {
    public:
        OpenGLContext(GLFWwindow *windowHandle);

        virtual void Init() override;

        virtual void SwapBuffers() override;

    private:
        GLFWwindow *m_WindowHandle;
    };
}


#endif //OPENGLCONTEXT_H
