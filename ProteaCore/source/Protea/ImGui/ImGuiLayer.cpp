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
        /// Backend flags ///////////////////////////////////////////////////////////////////
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
        /// Config flags ////////////////////////////////////////////////////////////////////
        io.ConfigFlags  |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags  |= ImGuiConfigFlags_NavEnableGamepad;
        io.ConfigFlags  |= ImGuiConfigFlags_DockingEnable;

        // ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void ImGuiLayer::OnDetach() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui::DestroyContext();
    }

    void ImGuiLayer::OnUpdate() {
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::Get();
        io.DisplaySize = ImVec2(static_cast<float>(app.GetWindow().GetWidth()), static_cast<float>(app.GetWindow().GetHeight()));

        float time = static_cast<float>(glfwGetTime());
        io.DeltaTime = m_Time > 0.0f ? (time - m_Time) : (1.0f / 60.0f);
        m_Time = time;

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        static bool show = true;
        ImGui::ShowDemoWindow(&show);


        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        ImGui::SaveIniSettingsToDisk(io.IniFilename);

    }

    void ImGuiLayer::OnEvent(Event& event) {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<MouseButtonPressedEvent>(PROTEA_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));
        dispatcher.Dispatch<MouseButtonReleasedEvent>(PROTEA_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));
        dispatcher.Dispatch<MouseMovedEvent>(PROTEA_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));
        dispatcher.Dispatch<MouseScrolledEvent>(PROTEA_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));
        dispatcher.Dispatch<KeyPressedEvent>(PROTEA_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));
        dispatcher.Dispatch<KeyTypedEvent>(PROTEA_BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));
        dispatcher.Dispatch<KeyReleasedEvent>(PROTEA_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));
        dispatcher.Dispatch<WindowResizeEvent>(PROTEA_BIND_EVENT_FN(ImGuiLayer::OnWindowResizeEvent));
    }

    ImGuiKey ImGuiLayer::ConvertGLFWKeyToImGuiKey(int glfwKey) {
        switch (glfwKey) {
            // Letters
        case GLFW_KEY_A: return ImGuiKey_A;
        case GLFW_KEY_B: return ImGuiKey_B;
        case GLFW_KEY_C: return ImGuiKey_C;
        case GLFW_KEY_D: return ImGuiKey_D;
        case GLFW_KEY_E: return ImGuiKey_E;
        case GLFW_KEY_F: return ImGuiKey_F;
        case GLFW_KEY_G: return ImGuiKey_G;
        case GLFW_KEY_H: return ImGuiKey_H;
        case GLFW_KEY_I: return ImGuiKey_I;
        case GLFW_KEY_J: return ImGuiKey_J;
        case GLFW_KEY_K: return ImGuiKey_K;
        case GLFW_KEY_L: return ImGuiKey_L;
        case GLFW_KEY_M: return ImGuiKey_M;
        case GLFW_KEY_N: return ImGuiKey_N;
        case GLFW_KEY_O: return ImGuiKey_O;
        case GLFW_KEY_P: return ImGuiKey_P;
        case GLFW_KEY_Q: return ImGuiKey_Q;
        case GLFW_KEY_R: return ImGuiKey_R;
        case GLFW_KEY_S: return ImGuiKey_S;
        case GLFW_KEY_T: return ImGuiKey_T;
        case GLFW_KEY_U: return ImGuiKey_U;
        case GLFW_KEY_V: return ImGuiKey_V;
        case GLFW_KEY_W: return ImGuiKey_W;
        case GLFW_KEY_X: return ImGuiKey_X;
        case GLFW_KEY_Y: return ImGuiKey_Y;
        case GLFW_KEY_Z: return ImGuiKey_Z;

        // Numbers (top row)
        case GLFW_KEY_0: return ImGuiKey_0;
        case GLFW_KEY_1: return ImGuiKey_1;
        case GLFW_KEY_2: return ImGuiKey_2;
        case GLFW_KEY_3: return ImGuiKey_3;
        case GLFW_KEY_4: return ImGuiKey_4;
        case GLFW_KEY_5: return ImGuiKey_5;
        case GLFW_KEY_6: return ImGuiKey_6;
        case GLFW_KEY_7: return ImGuiKey_7;
        case GLFW_KEY_8: return ImGuiKey_8;
        case GLFW_KEY_9: return ImGuiKey_9;

        // Function keys
        case GLFW_KEY_F1:  return ImGuiKey_F1;
        case GLFW_KEY_F2:  return ImGuiKey_F2;
        case GLFW_KEY_F3:  return ImGuiKey_F3;
        case GLFW_KEY_F4:  return ImGuiKey_F4;
        case GLFW_KEY_F5:  return ImGuiKey_F5;
        case GLFW_KEY_F6:  return ImGuiKey_F6;
        case GLFW_KEY_F7:  return ImGuiKey_F7;
        case GLFW_KEY_F8:  return ImGuiKey_F8;
        case GLFW_KEY_F9:  return ImGuiKey_F9;
        case GLFW_KEY_F10: return ImGuiKey_F10;
        case GLFW_KEY_F11: return ImGuiKey_F11;
        case GLFW_KEY_F12: return ImGuiKey_F12;

        // Navigation keys
        case GLFW_KEY_LEFT:       return ImGuiKey_LeftArrow;
        case GLFW_KEY_RIGHT:      return ImGuiKey_RightArrow;
        case GLFW_KEY_UP:         return ImGuiKey_UpArrow;
        case GLFW_KEY_DOWN:       return ImGuiKey_DownArrow;
        case GLFW_KEY_PAGE_UP:    return ImGuiKey_PageUp;
        case GLFW_KEY_PAGE_DOWN:  return ImGuiKey_PageDown;
        case GLFW_KEY_HOME:       return ImGuiKey_Home;
        case GLFW_KEY_END:        return ImGuiKey_End;
        case GLFW_KEY_INSERT:     return ImGuiKey_Insert;
        case GLFW_KEY_DELETE:     return ImGuiKey_Delete;
        case GLFW_KEY_BACKSPACE:  return ImGuiKey_Backspace;
        case GLFW_KEY_SPACE:      return ImGuiKey_Space;
        case GLFW_KEY_ENTER:      return ImGuiKey_Enter;
        case GLFW_KEY_ESCAPE:     return ImGuiKey_Escape;
        case GLFW_KEY_TAB:        return ImGuiKey_Tab;

        // Symbols and punctuation
        case GLFW_KEY_GRAVE_ACCENT:      return ImGuiKey_GraveAccent;
        case GLFW_KEY_MINUS:             return ImGuiKey_Minus;
        case GLFW_KEY_EQUAL:             return ImGuiKey_Equal;
        case GLFW_KEY_LEFT_BRACKET:      return ImGuiKey_LeftBracket;
        case GLFW_KEY_RIGHT_BRACKET:     return ImGuiKey_RightBracket;
        case GLFW_KEY_BACKSLASH:         return ImGuiKey_Backslash;
        case GLFW_KEY_SEMICOLON:         return ImGuiKey_Semicolon;
        case GLFW_KEY_APOSTROPHE:        return ImGuiKey_Apostrophe;
        case GLFW_KEY_COMMA:             return ImGuiKey_Comma;
        case GLFW_KEY_PERIOD:            return ImGuiKey_Period;
        case GLFW_KEY_SLASH:             return ImGuiKey_Slash;

        // Keypad (optional: ImGui doesn’t use all of these directly)
        case GLFW_KEY_KP_0: return ImGuiKey_Keypad0;
        case GLFW_KEY_KP_1: return ImGuiKey_Keypad1;
        case GLFW_KEY_KP_2: return ImGuiKey_Keypad2;
        case GLFW_KEY_KP_3: return ImGuiKey_Keypad3;
        case GLFW_KEY_KP_4: return ImGuiKey_Keypad4;
        case GLFW_KEY_KP_5: return ImGuiKey_Keypad5;
        case GLFW_KEY_KP_6: return ImGuiKey_Keypad6;
        case GLFW_KEY_KP_7: return ImGuiKey_Keypad7;
        case GLFW_KEY_KP_8: return ImGuiKey_Keypad8;
        case GLFW_KEY_KP_9: return ImGuiKey_Keypad9;
        case GLFW_KEY_KP_DECIMAL: return ImGuiKey_KeypadDecimal;
        case GLFW_KEY_KP_DIVIDE:  return ImGuiKey_KeypadDivide;
        case GLFW_KEY_KP_MULTIPLY:return ImGuiKey_KeypadMultiply;
        case GLFW_KEY_KP_SUBTRACT:return ImGuiKey_KeypadSubtract;
        case GLFW_KEY_KP_ADD:     return ImGuiKey_KeypadAdd;
        case GLFW_KEY_KP_ENTER:   return ImGuiKey_KeypadEnter;
        case GLFW_KEY_KP_EQUAL:   return ImGuiKey_KeypadEqual;

        // Default
        default: return ImGuiKey_None;
        }
    }

    bool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[e.GetMouseButton()] = true;

        return false;
    }

    bool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseDown[e.GetMouseButton()] = false;

        return false;
    }

    bool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MousePos = ImVec2(e.GetX(), e.GetY());

        return false;
    }

    bool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.MouseWheelH += e.GetXOffset();
        io.MouseWheel += e.GetYOffset();

        return false;
    }

    bool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        Application& app = Application::Get();
        const auto window = static_cast<GLFWwindow*>(app.GetWindow().GetNativeWindow());
        ImGuiKey imguiKey = ConvertGLFWKeyToImGuiKey(e.GetKeyCode());
        io.AddKeyEvent(imguiKey, true);

        bool ctrl   = glfwGetKey(window, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT_CONTROL) == GLFW_PRESS;
        bool shift  = glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT) == GLFW_PRESS;
        bool alt    = glfwGetKey(window, GLFW_KEY_LEFT_ALT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT_ALT) == GLFW_PRESS;
        bool super  = glfwGetKey(window, GLFW_KEY_LEFT_SUPER) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_RIGHT_SUPER) == GLFW_PRESS;

        io.AddKeyEvent(ImGuiKey_ModCtrl, ctrl);
        io.AddKeyEvent(ImGuiKey_ModShift, shift);
        io.AddKeyEvent(ImGuiKey_ModAlt, alt);
        io.AddKeyEvent(ImGuiKey_ModSuper, super);

        return false;
    }

    bool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        ImGuiKey imguiKey = ConvertGLFWKeyToImGuiKey(e.GetKeyCode());
        io.AddKeyEvent(imguiKey, false);

        return false;
    }

    bool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        int keycode = e.GetKeyCode();
        if (keycode > 0 && keycode < 0x10000)
            io.AddInputCharacter((unsigned short)keycode);

        return false;
    }

    bool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& e)
    {
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());
        io.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);
        glViewport(0, 0, e.GetWidth(), e.GetHeight());

        return false;
    }




}
