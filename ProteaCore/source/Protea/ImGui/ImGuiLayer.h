#ifndef IMGUILAYER_H
#define IMGUILAYER_H

#include "Protea/Layer.h"

#include "Protea/Events/ApplicationEvent.h"
#include "Protea/Events/KeyEvent.h"
#include "Protea/Events/MouseEvent.h"

#include "imgui.h"

namespace Protea {
    class PROTEA_API ImGuiLayer : public Layer {
    public:
        ImGuiLayer();

        ~ImGuiLayer();

        void OnAttach();

        void OnDetach();

        void OnUpdate();

        void OnEvent(Event &event);

        void SetEventBlocking(bool enabled) { m_BlockEvents = enabled; }
        bool IsEventBlockingEnabled() const { return m_BlockEvents; }

    private:
        bool OnWindowResizeEvent(WindowResizeEvent& e);


        bool m_BlockEvents = true;
        float m_Time = 0.0f;
    };
}


#endif //IMGUILAYER_H
