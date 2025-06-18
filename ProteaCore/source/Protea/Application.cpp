#include "ProteaPCH.h"
#include "Application.h"

#include <GLFW/glfw3.h>

namespace Protea {
    Application::Application() {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application() {
    }

    void Application::Run() {
        while (m_Running) {
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
            m_Window->OnUpdate();
        }
    }
}
