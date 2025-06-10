cmake_minimum_required(VERSION 3.31)
project(ProteaSandbox)

set(CMAKE_CXX_STANDARD 23)

# Set output directories for all configurations:
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/ProteaSandbox/bin)

# Project Directories:
set(PROTEA_SANDBOX_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)

# Add Executable:
add_executable(ProteaSandbox ${PROTEA_SANDBOX_SOURCE_DIR}/SandboxApp.cpp)

# Link to the library:
target_link_libraries(ProteaSandbox PRIVATE ProteaCore)

# Compile Definitions:
target_compile_definitions(ProteaSandbox PRIVATE PROTEA_PLATFORM_WINDOWS)
