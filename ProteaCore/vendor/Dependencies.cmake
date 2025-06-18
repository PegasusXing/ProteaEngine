# //////////////////////////////////////////////////////////////
# /// Dependencies: ////////////////////////////////////////////
# //////////////////////////////////////////////////////////////

include(FetchContent)

# OpenGL
find_package(OpenGL REQUIRED)

# SPDLOG
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.15.3
        GIT_SHALLOW TRUE
)

set(spdlog_POPULATE 1 CACHE INTERNAL "Mark spdlog as already populated")

FetchContent_GetProperties(spdlog)

if (NOT spdlog_POPULATED)
    FetchContent_MakeAvailable(spdlog)
    file(REMOVE_RECURSE "${spdlog_SOURCE_DIR}/.git")
endif ()

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
        GIT_SHALLOW TRUE
)

set(glfw_POPULATE 1 CACHE INTERNAL "Mark glfw as already populated")

FetchContent_GetProperties(glfw)

if (NOT glfw_POPULATED)
    FetchContent_MakeAvailable(glfw)
    file(REMOVE_RECURSE "${glfw_SOURCE_DIR}/.git")
endif ()

# GLAD
FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/PegasusXing/glad.git
        GIT_TAG 0.1.36 # main branch
        GIT_SHALLOW TRUE
)

set(glad_POPULATE 1 CACHE INTERNAL "Mark glad as already populated")

FetchContent_GetProperties(glad)

if (NOT glad_POPULATED)
    FetchContent_MakeAvailable(glad)
    file(REMOVE_RECURSE "${glad_SOURCE_DIR}/.git")
endif ()

# ImGUI
FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG docking # docking branch v1.91.9b @ latest
        GIT_SHALLOW TRUE
)

set(imgui_POPULATE 1 CACHE INTERNAL "Mark imgui as already populated")

FetchContent_GetProperties(imgui)

if (NOT imgui_POPULATED)
    FetchContent_MakeAvailable(imgui)
    file(REMOVE_RECURSE "${imgui_SOURCE_DIR}/.git")

    # Add imgui manually as a library
    add_library(imgui
            ${imgui_SOURCE_DIR}/imgui.cpp
            ${imgui_SOURCE_DIR}/imgui_demo.cpp
            ${imgui_SOURCE_DIR}/imgui_draw.cpp
            ${imgui_SOURCE_DIR}/imgui_tables.cpp
            ${imgui_SOURCE_DIR}/imgui_widgets.cpp
    )

    target_include_directories(imgui PUBLIC ${imgui_SOURCE_DIR})

    target_sources(imgui PRIVATE
            ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp
            ${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
    )
    target_include_directories(imgui PUBLIC
            ${imgui_SOURCE_DIR}/backends
    )
    target_link_libraries(imgui PUBLIC glfw glad)

endif ()