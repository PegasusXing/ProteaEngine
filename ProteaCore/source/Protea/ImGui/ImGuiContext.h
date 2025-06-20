//
// Created by Alex on 20/06/2025.
//

#ifndef IMGUICONTEXT_H
#define IMGUICONTEXT_H

#include "Protea/Core.h"

struct ImGuiContext;

namespace Protea {
    class PROTEA_API ImGuiContextManager {
    public:
        static ImGuiContext* GetCurrentContext();
        static void SetCurrentContext(ImGuiContext* context);
    };
}

#endif //IMGUICONTEXT_H
