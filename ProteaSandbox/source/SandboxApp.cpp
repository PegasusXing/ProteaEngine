#include "Protea.h"

class ExampleLayer : public Protea::Layer {

    public:
    ExampleLayer() : Layer("ExampleLayer") {}

    void OnUpdate() override {
        // PROTEA_INFO("Example Layer::OnUpdate");
    }

    void OnEvent(Protea::Event& event) override {
        PROTEA_TRACE("{0}", event);
    }
};

class SandboxApp : public Protea::Application {
    public:
    SandboxApp() {
        PushLayer(new ExampleLayer());
        PushOverlay(new Protea::ImGuiLayer());
    }
    ~SandboxApp() override {

    }
};

Protea::Application* Protea::CreateApplication() {
    return new SandboxApp();
}