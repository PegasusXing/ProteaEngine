cmake_minimum_required(VERSION 3.31)
project(ProteaCore LANGUAGES CXX)

set(PROTEA_CORE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)
set(PROTEA_CORE_VENDOR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor)

include(${PROTEA_CORE_VENDOR_DIR}/Dependencies.cmake)

set(PROTEA_CORE_SOURCES
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Application.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Log.cpp
        ${PROTEA_CORE_SOURCE_DIR}/ProteaPCH.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Layer.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Protea/LayerStack.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Platform/Windows/WindowsWindow.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Protea/ImGui/ImGuiLayer.cpp
)

set(PROTEA_CORE_HEADERS
        ${PROTEA_CORE_SOURCE_DIR}/ProteaPCH.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Application.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/EntryPoint.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Core.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Log.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Window.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Layer.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/LayerStack.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Events/Event.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Events/KeyEvent.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Events/MouseEvent.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Events/ApplicationEvent.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Events/EventFormatter.h
        ${PROTEA_CORE_SOURCE_DIR}/Platform/Windows/WindowsWindow.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/ImGui/ImGuiLayer.h
)

add_library(ProteaCore SHARED ${PROTEA_CORE_SOURCES} ${PROTEA_CORE_HEADERS})

target_include_directories(ProteaCore PUBLIC ${PROTEA_CORE_SOURCE_DIR})

target_link_libraries(ProteaCore PUBLIC opengl32 glad glfw imgui spdlog::spdlog)

target_compile_definitions(ProteaCore PRIVATE
        PROTEA_PLATFORM_WINDOWS
        PROTEA_BUILD_DLL
        GLFW_INCLUDE_NONE
)

target_precompile_headers(ProteaCore PRIVATE ${PROTEA_CORE_SOURCE_DIR}/ProteaPCH.h)

# Apply configuration-specific flags
configure_compiler_flags(ProteaCore)
