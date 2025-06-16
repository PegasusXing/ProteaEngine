cmake_minimum_required(VERSION 3.31)
project(ProteaSandbox LANGUAGES CXX)

# Source directory
set(PROTEA_SANDBOX_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)

# Executable
add_executable(ProteaSandbox
        ${PROTEA_SANDBOX_SOURCE_DIR}/SandboxApp.cpp
)

# Include paths (optional if ProteaCore already exports includes)
target_include_directories(ProteaSandbox PRIVATE ${PROTEA_SANDBOX_SOURCE_DIR})

# Link to ProteaCore
target_link_libraries(ProteaSandbox PRIVATE ProteaCore)

# Platform definitions
target_compile_definitions(ProteaSandbox PRIVATE PROTEA_PLATFORM_WINDOWS)
