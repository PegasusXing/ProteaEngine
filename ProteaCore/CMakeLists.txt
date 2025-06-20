cmake_minimum_required(VERSION 3.31)
project(ProteaCore LANGUAGES CXX)

set(PROTEA_CORE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)
set(PROTEA_CORE_VENDOR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor)

include(${PROTEA_CORE_VENDOR_DIR}/Dependencies.cmake)

set(PROTEA_CORE_SOURCES
        ### Core #######################################################################################################
        ${PROTEA_CORE_SOURCE_DIR}/ProteaPCH.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Application.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Log.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Layer.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Protea/LayerStack.cpp
        ### Platform ###################################################################################################
        ${PROTEA_CORE_SOURCE_DIR}/Platform/Windows/WindowsWindow.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Platform/Windows/WindowsInput.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Platform/OpenGL/OpenGLContext.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Platform/OpenGL/OpenGLVertexArray.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Platform/OpenGL/OpenGLBuffer.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Platform/OpenGL/OpenGLRendererAPI.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Platform/OpenGL/OpenGLShader.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Platform/OpenGL/OpenGLTexture.cpp
        ### ImGUI ######################################################################################################
        ${PROTEA_CORE_SOURCE_DIR}/Protea/ImGui/ImGuiLayer.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Protea/ImGui/ImGuiBuild.cpp
        ### Renderer ###################################################################################################
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Renderer/Shader.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Renderer/VertexArray.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Renderer/Buffer.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Renderer/Renderer.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Renderer/RenderCommand.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Renderer/RendererAPI.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Renderer/OrthographicCamera.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Renderer/Texture.cpp
)

set(PROTEA_CORE_HEADERS
        ### Core #######################################################################################################
        ${PROTEA_CORE_SOURCE_DIR}/Protea.h
        ${PROTEA_CORE_SOURCE_DIR}/ProteaPCH.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Core.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Log.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Application.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/EntryPoint.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Window.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Layer.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/LayerStack.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Core/Timestep.h
        ### Platform ###################################################################################################
        ${PROTEA_CORE_SOURCE_DIR}/Platform/Windows/WindowsWindow.h
        ${PROTEA_CORE_SOURCE_DIR}/Platform/Windows/WindowsInput.h
        ${PROTEA_CORE_SOURCE_DIR}/Platform/OpenGL/OpenGLContext.h
        ${PROTEA_CORE_SOURCE_DIR}/Platform/OpenGL/OpenGLBuffer.h
        ${PROTEA_CORE_SOURCE_DIR}/Platform/OpenGL/OpenGLVertexArray.h
        ${PROTEA_CORE_SOURCE_DIR}/Platform/OpenGL/OpenGLRendererAPI.h
        ${PROTEA_CORE_SOURCE_DIR}/Platform/OpenGL/OpenGLShader.h
        ${PROTEA_CORE_SOURCE_DIR}/Platform/OpenGL/OpenGLTexture.h
        ### Input ######################################################################################################
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Input.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/KeyCodes.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/MouseButtonCodes.h
        ### Events #####################################################################################################
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Events/Event.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Events/KeyEvent.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Events/MouseEvent.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Events/ApplicationEvent.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Events/EventFormatter.h
        ### ImGUI ######################################################################################################
        ${PROTEA_CORE_SOURCE_DIR}/Protea/ImGui/ImGuiLayer.h
        ### Renderer ###################################################################################################
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Renderer/GraphicsContext.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Renderer/Shader.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Renderer/Buffer.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Renderer/Renderer.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Renderer/VertexArray.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Renderer/RendererAPI.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Renderer/RenderCommand.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Renderer/OrthographicCamera.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Renderer/Texture.h
)

# Changed from SHARED to STATIC
add_library(ProteaCore STATIC ${PROTEA_CORE_SOURCES} ${PROTEA_CORE_HEADERS})

target_include_directories(ProteaCore PUBLIC ${PROTEA_CORE_SOURCE_DIR})

# Libraries are now linked PUBLIC so they're available to consumers of ProteaCore
target_link_libraries(ProteaCore PUBLIC opengl32 glad glfw imgui glm stb_img spdlog::spdlog
)

# Static library - no DLL definitions needed
# PROTEA_DYNAMIC_LINK is NOT defined, so PROTEA_API will be empty
target_compile_definitions(ProteaCore PRIVATE
        PROTEA_PLATFORM_WINDOWS
        GLFW_INCLUDE_NONE
)

target_precompile_headers(ProteaCore PRIVATE ${PROTEA_CORE_SOURCE_DIR}/ProteaPCH.h)

# Apply configuration-specific flags
configure_compiler_flags(ProteaCore)