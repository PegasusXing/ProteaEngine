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
