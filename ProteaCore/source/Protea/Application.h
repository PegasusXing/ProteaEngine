#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"
#include "Window.h"
#include "Protea/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

#include "Protea/Core/Timestep.h"
#include "Protea/ImGui/ImGuiLayer.h"

namespace Protea {
    class Application {
    public:
        Application();

        virtual ~Application() = default;

        void Run();

        void OnEvent(Event& e);

        void PushLayer(Layer* layer);
        void PushOverlay(Layer* layer);

        inline Window& GetWindow() { return *m_Window; }

        inline static Application& Get() { return *s_Instance; }

    private:
        bool OnWindowClose(WindowCloseEvent& e);

        std::unique_ptr<Window> m_Window;
        ImGuiLayer* m_ImGuiLayer;
        bool m_Running = true;
        LayerStack m_LayerStack;

        float m_LastFrameTime = 0.0f;

        static Application* s_Instance;
    };

    // To be defined in CLIENT
    Application *CreateApplication();
}

#endif //APPLICATION_H