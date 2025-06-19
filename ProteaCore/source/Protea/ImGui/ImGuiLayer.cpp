#include "ProteaPCH.h"
#include "ImGuiLayer.h"
#include "Protea/Application.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "GLFW/glfw3.h"
#include <glad/glad.h>

namespace Protea {

    ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") {
    }

    ImGuiLayer::~ImGuiLayer() {
    }

    void ImGuiLayer::OnAttach() {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGuiIO& io = ImGui::GetIO();

        /// Config flags ////////////////////////////////////////////////////////////////////
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

        // Setup Platform/Renderer backends
        Application& app = Application::Get();
        GLFWwindow* window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());

        // Initialize ImGui backends - they handle all the input for us
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiLayer::OnDetach() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayer::OnUpdate() {
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::Get();
        io.DisplaySize = ImVec2(static_cast<float>(app.GetWindow().GetWidth()),
                               static_cast<float>(app.GetWindow().GetHeight()));

        float time = static_cast<float>(glfwGetTime());
        io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
        m_Time = time;

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Demo window for testing - remove in production
        #ifdef PROTEA_DEBUG
        static bool show = true;
        ImGui::ShowDemoWindow(&show);
        #endif

        // Render
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Update and Render additional Platform Windows
        // (Platform functions may change the current OpenGL context, so we save/restore it)
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
    }

    void ImGuiLayer::OnEvent(Event& event) {
        // Let ImGui handle input events first
        ImGuiIO& io = ImGui::GetIO();

        // If ImGui wants to capture input, block it from propagating
        // to the rest of the application
        if (m_BlockEvents) {
            if (event.GetEventType() == EventType::MouseButtonPressed ||
                event.GetEventType() == EventType::MouseButtonReleased ||
                event.GetEventType() == EventType::MouseMoved ||
                event.GetEventType() == EventType::MouseScrolled) {
                if (io.WantCaptureMouse)
                    event.Handled = true;
            }

            if (event.GetEventType() == EventType::KeyPressed ||
                event.GetEventType() == EventType::KeyReleased ||
                event.GetEventType() == EventType::KeyTyped) {
                if (io.WantCaptureKeyboard)
                    event.Handled = true;
            }
        }
        //

        // Handle window resize events that affect rendering
        if (event.GetEventType() == EventType::WindowResize) {
            EventDispatcher dispatcher(event);
            dispatcher.Dispatch<WindowResizeEvent>(PROTEA_BIND_EVENT_FN(ImGuiLayer::OnWindowResizeEvent));
        }
    }

    bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& e) {
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(static_cast<float>(e.GetWidth()), static_cast<float>(e.GetHeight()));
        io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);

        return false;
    }

}