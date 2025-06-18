# ///////////////////////////////////////////////////////////
# /// Dependencies: /////////////////////////////////////////
# ///////////////////////////////////////////////////////////
# TODO: Move to manual vendor linking for standalone build
# ///////////////////////////////////////////////////////////

find_package(OpenGL REQUIRED)

include(FetchContent)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY              https://github.com/gabime/spdlog.git
        GIT_TAG                     v1.15.3
        GIT_SHALLOW                 TRUE
)

# Prevent multiple fetches in multi-config generators (e.g., Visual Studio)
set(spdlog_POPULATE 1 CACHE INTERNAL "Mark spdlog as already populated")

FetchContent_GetProperties(spdlog)

if(NOT spdlog_POPULATED)
    FetchContent_MakeAvailable(spdlog)
    # After fetching, delete the .git folder from the source directory to avoid nested repos
    file(REMOVE_RECURSE "${spdlog_SOURCE_DIR}/.git")
endif()


FetchContent_Declare(
        glfw
        GIT_REPOSITORY              https://github.com/glfw/glfw.git
        GIT_TAG                     3.4
        GIT_SHALLOW                 TRUE
)

# Prevent multiple fetches in multi-config generators (e.g., Visual Studio)
set(glfw_POPULATE 1 CACHE INTERNAL "Mark glfw as already populated")

FetchContent_GetProperties(glfw)

if(NOT glfw_POPULATED)
    FetchContent_MakeAvailable(glfw)
    # After fetching, delete the .git folder from the source directory to avoid nested repos
    file(REMOVE_RECURSE "${glfw_SOURCE_DIR}/.git")
endif()