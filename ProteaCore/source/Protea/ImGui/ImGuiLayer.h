#ifndef IMGUILAYER_H
#define IMGUILAYER_H

#include "Protea/Layer.h"

#include "Protea/Events/ApplicationEvent.h"
#include "Protea/Events/KeyEvent.h"
#include "Protea/Events/MouseEvent.h"

namespace Protea {
    class PROTEA_API ImGuiLayer : public Layer {
    public:
        ImGuiLayer();

        ~ImGuiLayer();

        void OnAttach();

        void OnDetach();

        void OnUpdate();

        void OnEvent(Event &event);

    private:
        bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e);
        bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
        bool OnMouseMovedEvent(MouseMovedEvent& e);
        bool OnMouseScrolledEvent(MouseScrolledEvent& e);
        bool OnKeyPressedEvent(KeyPressedEvent& e);
        bool OnKeyReleasedEvent(KeyReleasedEvent& e);
        bool OnKeyTypedEvent(KeyTypedEvent& e);
        bool OnWindowResizeEvent(WindowResizeEvent& e);

        float m_Time = 0.0f;
    };
}


#endif //IMGUILAYER_H
