#ifndef APPLICATION_H
#define APPLICATION_H

#include "Core.h"
#include "Events/Event.h"

namespace Protea {
    class PROTEA_API Application {
    public:
        Application();

        virtual ~Application();

        void Run();
    };

    // To be defined in CLIENT
    Application *CreateApplication();
}

#endif //APPLICATION_H
