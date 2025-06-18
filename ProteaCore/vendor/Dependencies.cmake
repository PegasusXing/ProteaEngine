# //////////////////////////////////////////////////////////////
# /// Dependencies: ////////////////////////////////////////////
# //////////////////////////////////////////////////////////////

find_package(OpenGL REQUIRED)

include(FetchContent)

# SPDLOG
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY              https://github.com/gabime/spdlog.git
        GIT_TAG                     v1.15.3
        GIT_SHALLOW                 TRUE
)

set(spdlog_POPULATE 1 CACHE INTERNAL "Mark spdlog as already populated")

FetchContent_GetProperties(spdlog)

if(NOT spdlog_POPULATED)
    FetchContent_MakeAvailable(spdlog)
    file(REMOVE_RECURSE "${spdlog_SOURCE_DIR}/.git")
endif()

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_Declare(
        glfw
        GIT_REPOSITORY              https://github.com/glfw/glfw.git
        GIT_TAG                     3.4
        GIT_SHALLOW                 TRUE
)

set(glfw_POPULATE 1 CACHE INTERNAL "Mark glfw as already populated")

FetchContent_GetProperties(glfw)

if(NOT glfw_POPULATED)
    FetchContent_MakeAvailable(glfw)
    file(REMOVE_RECURSE "${glfw_SOURCE_DIR}/.git")
endif()

# GLAD
FetchContent_Declare(
        glad
        GIT_REPOSITORY              https://github.com/PegasusXing/glad.git
        GIT_TAG                     0.1.36 # main branch
        GIT_SHALLOW                 TRUE
)

set(glad_POPULATE 1 CACHE INTERNAL "Mark glad as already populated")

FetchContent_GetProperties(glad)

if(NOT glad_POPULATED)
    FetchContent_MakeAvailable(glad)
    file(REMOVE_RECURSE "${glad_SOURCE_DIR}/.git")
endif()