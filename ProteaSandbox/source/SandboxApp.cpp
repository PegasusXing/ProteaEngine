#include "Protea.h"

class SandboxApp : public Protea::Application {
    public:
    SandboxApp() {

    }
    ~SandboxApp() {

    }
};

Protea::Application* Protea::CreateApplication() {
    return new SandboxApp();
}