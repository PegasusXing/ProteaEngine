#ifndef WINDOWSWINDOW_H
#define WINDOWSWINDOW_H

#include "Protea/Window.h"

#include "Protea/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace Protea {
    class WindowsWindow : public Window {
    public:
        WindowsWindow(const WindowProps &props);

        virtual ~WindowsWindow();

        void OnUpdate() override;

        inline unsigned int GetWidth() const override { return m_Data.Width; }
        inline unsigned int GetHeight() const override { return m_Data.Height; }
        inline void SetEventCallback(const EventCallbackFn &callback) override { m_Data.EventCallback = callback; }

        void SetVSync(bool enabled) override;

        bool IsVSync() const override;

        virtual void* GetNativeWindow() const override { return m_Window; }

    private:
        virtual void Init(const WindowProps &props);

        virtual void Shutdown();

        GLFWwindow *m_Window{};
        GraphicsContext* m_Context;

        struct WindowData {
            std::string Title;
            unsigned int Width;
            unsigned int Height;
            bool VSync;

            EventCallbackFn EventCallback;
        };

        WindowData m_Data;

        void SetWindowIconFromFile(GLFWwindow* window, const std::vector<std::string>& filepaths);
    };
}

#endif //WINDOWSWINDOW_H
