//
// Created by Alex on 20/06/2025.
//

#ifndef GRAPHICSCONTEXT_H
#define GRAPHICSCONTEXT_H

namespace Protea {
    class GraphicsContext {
        public:
        virtual void Init() = 0;
        virtual void SwapBuffers() = 0;
    };
}

#endif //GRAPHICSCONTEXT_H
