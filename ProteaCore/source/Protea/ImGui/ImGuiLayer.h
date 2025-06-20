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

        virtual void OnAttach() override;
        virtual void OnDetach() override;
        virtual void OnImGuiRender() override;

        void Begin();
        void End();

    private:

        float m_Time = 0.0f;
    };
}


#endif //IMGUILAYER_H
