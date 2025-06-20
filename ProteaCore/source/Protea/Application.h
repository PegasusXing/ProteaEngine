#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"
#include "Window.h"
#include "Protea/LayerStack.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Protea/ImGui/ImGuiLayer.h"

#include "Protea/Renderer/Shader.h"
#include "Protea/Renderer/Buffer.h"

namespace Protea {
    class PROTEA_API Application {
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

        unsigned int m_VertexArray;
        std::unique_ptr<Shader> m_Shader;
        std::unique_ptr<VertexBuffer> m_VertexBuffer;
        std::unique_ptr<IndexBuffer> m_IndexBuffer;
        static Application* s_Instance;
    };

    // To be defined in CLIENT
    Application *CreateApplication();
}

#endif //APPLICATION_H
