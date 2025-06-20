#ifndef LAYER_H
#define LAYER_H

#include "Protea/Core.h"
#include "Protea/Events/Event.h"


namespace Protea {
    class PROTEA_API Layer {
    public:
        Layer(const std::string &name = "Layer");

        virtual ~Layer() = default;

        virtual void OnAttach() {
        }

        virtual void OnDetach() {
        }

        virtual void OnUpdate() {
        }

        virtual void OnImGuiRender() {
        }

        virtual void OnEvent(Event &event) {
        }

        inline const std::string &GetName() const { return m_DebugName; }

    protected:
        std::string m_DebugName;
    };
}


#endif //LAYER_H
