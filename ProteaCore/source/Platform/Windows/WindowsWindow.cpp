#include "ProteaPCH.h"
#include "WindowsWindow.h"

#include <glad/glad.h>

#include "Protea/Events/ApplicationEvent.h"
#include "Protea/Events/MouseEvent.h"
#include "Protea/Events/KeyEvent.h"


namespace Protea {
    static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int error, const char *description) {
        PROTEA_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    Window *Window::Create(const WindowProps &props) {
        return new WindowsWindow(props);
    }

    WindowsWindow::WindowsWindow(const WindowProps &props) {
        WindowsWindow::Init(props);
    }

    WindowsWindow::~WindowsWindow() {
        WindowsWindow::Shutdown();
    }

    void WindowsWindow::Init(const WindowProps &props) {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        PROTEA_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);


        if (!s_GLFWInitialized) {
            // TODO: glfwTerminate on system shutdown
            int success = glfwInit();
            PROTEA_CORE_ASSERT(success, "Could not initialize GLFW!");

            glfwSetErrorCallback(GLFWErrorCallback);
            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int) props.Width, (int) props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);

        SetWindowIconFromFile(m_Window, {
            "../../../ProteaCore/resources/icons/protea_icon_16.png",
            "../../../ProteaCore/resources/icons/protea_icon_24.png",
            "../../../ProteaCore/resources/icons/protea_icon_32.png",
            "../../../ProteaCore/resources/icons/protea_icon_48.png",
            "../../../ProteaCore/resources/icons/protea_icon_64.png",
            "../../../ProteaCore/resources/icons/protea_icon_128.png",
            "../../../ProteaCore/resources/icons/protea_icon_256.png"
        });

        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        PROTEA_CORE_ASSERT(status, "Failed to initialize Glad!");
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

        ///////////////////////////////
        /// GLFW Callbacks: ///////////
        ///////////////////////////////

        glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *window, int width, int height) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);
            data.Width = width;
            data.Height = height;

            WindowResizeEvent event(width, height);
            data.EventCallback(event);
        });

        glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data.EventCallback(event);
        });

        glfwSetKeyCallback(m_Window, [](GLFWwindow *window, int key, int scancode, int action, int mods) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);
            switch (action) {
                case GLFW_PRESS: {
                    KeyPressedEvent event(key, 0);
                    data.EventCallback(event);
                    break;
                }

                case GLFW_RELEASE: {
                    KeyReleasedEvent event(key);
                    data.EventCallback(event);
                    break;
                }

                case GLFW_REPEAT: {
                    KeyPressedEvent event(key, 1);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            KeyTypedEvent event(keycode);
            data.EventCallback(event);
        });


        glfwSetMouseButtonCallback(m_Window, [](GLFWwindow *window, int button, int action, int mods) {
            WindowData &data = *(WindowData *) glfwGetWindowUserPointer(window);
            switch (action) {
                case GLFW_PRESS: {
                    MouseButtonPressedEvent event(button);
                    data.EventCallback(event);
                    break;
                }


                case GLFW_RELEASE: {
                    MouseButtonReleasedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset){
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseScrolledEvent event((float)xOffset, (float)yOffset);
            data.EventCallback(event);
        });

        glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos){
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            MouseMovedEvent event((float)xPos, (float)yPos);
            data.EventCallback(event);
        });

    }

    void WindowsWindow::Shutdown() {
        glfwDestroyWindow(m_Window);
    }

    void WindowsWindow::SetWindowIconFromFile(GLFWwindow *window, const std::vector<std::string>& filepaths) {
        std::vector<GLFWimage> icons;
        std::vector<unsigned char*> allocatedImages; // Keep track to free later

        for (const auto& filepath : filepaths) {
            int width, height, channels;
            unsigned char* pixels = stbi_load(filepath.c_str(), &width, &height, &channels, 4);

            if (pixels) {
                GLFWimage icon;
                icon.width = width;
                icon.height = height;
                icon.pixels = pixels;
                icons.push_back(icon);
                allocatedImages.push_back(pixels);
            } else {
                const char* reason = stbi_failure_reason();
                PROTEA_CORE_ERROR("Failed to load icon '{0}': {1}", filepath, reason ? reason : "Unknown error");
            }
        }

        if (!icons.empty()) {
            glfwSetWindowIcon(window, static_cast<int>(icons.size()), icons.data());
        } else {
            PROTEA_CORE_WARN("No valid icons were loaded. Window will use the default icon.");
        }

        // Free memory
        for (auto pixels : allocatedImages) {
            stbi_image_free(pixels);
        }
    }


    void WindowsWindow::OnUpdate() {
        glfwPollEvents();


        glfwSwapBuffers(m_Window);
    }


    void WindowsWindow::SetVSync(bool enabled) {
        if (enabled)


            glfwSwapInterval(1);


        else


            glfwSwapInterval(0);


        m_Data.VSync = enabled;
    }


    bool WindowsWindow::IsVSync() const {
        return m_Data.VSync;
    }
}
