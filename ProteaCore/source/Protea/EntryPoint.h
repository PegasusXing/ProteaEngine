

#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#ifdef PROTEA_PLATFORM_WINDOWS
#include "Protea.h"

extern Protea::Application* Protea::CreateApplication();

int main(int argc, char **argv) {

    auto application = Protea::CreateApplication();
    application->Run();
    delete application;
}

#endif

#endif //ENTRYPOINT_H
