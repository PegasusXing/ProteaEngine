#include "Application.h"
#include "Protea/Log.h"
#include "Protea/Events/ApplicationEvent.h"
#include "Protea/Events/EventFormatter.h"

namespace Protea {
    Application::Application() {
    }

    Application::~Application() {
    }

    void Application::Run() {
        WindowResizeEvent event(1280, 720);

        if (event.IsInCategory(EventCategoryApplication)) {
            PROTEA_TRACE("{}", event);
        }
        if (event.IsInCategory(EventCategoryInput)) {
            PROTEA_TRACE("{}", event);
        }

        while (true) {
        }
    }
}
