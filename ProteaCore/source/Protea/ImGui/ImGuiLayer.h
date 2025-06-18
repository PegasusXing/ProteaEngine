#ifndef IMGUILAYER_H
#define IMGUILAYER_H

#include "Protea/Layer.h"

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
        float m_Time = 0.0f;
    };
}


#endif //IMGUILAYER_H
