#ifndef ENTRYPOINT_H
#define ENTRYPOINT_H

#ifdef PROTEA_PLATFORM_WINDOWS

// extern Protea::Application* Protea::CreateApplication();

int main(int argc, char **argv) {
    Protea::Log::Init();

    const auto application = Protea::CreateApplication();
    application->Run();
    delete application;
}

#endif

#endif //ENTRYPOINT_H
