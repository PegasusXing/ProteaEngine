#include "Protea.h"

// TODO: Move to ImGuiLayer.h - Same inheritance
#include "imgui.h"

class ExampleLayer : public Protea::Layer {
public:
    ExampleLayer() : Layer("ExampleLayer") {
    }

    void OnUpdate() override {
        if (Protea::Input::IsKeyPressed(PROTEA_KEY_TAB)) {
            PROTEA_TRACE("Tab key is pressed (poll)!");
        }
    }

    virtual void OnImGuiRender() override {
        ImGui::Begin("Test");
        ImGui::Text("Hello World");
        ImGui::End();
    }

    void OnEvent(Protea::Event &event) override {
        if (event.GetEventType() == Protea::EventType::KeyPressed) {
            const auto &e = dynamic_cast<Protea::KeyPressedEvent &>(event);

            if (e.GetKeyCode() == PROTEA_KEY_TAB) {
                PROTEA_TRACE("Tab key is pressed (event)!");
            }

            PROTEA_TRACE("{0}", (char) e.GetKeyCode());
        }
    }
};

class SandboxApp : public Protea::Application {
public:
    SandboxApp() {
        PushLayer(new ExampleLayer());
    }

    ~SandboxApp() override {
    }
};

Protea::Application *Protea::CreateApplication() {
    return new SandboxApp();
}
