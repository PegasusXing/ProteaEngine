cmake_minimum_required(VERSION 3.31)
project(ProteaSandbox)

# Default fallback
set(DEFAULT_CXX_STANDARD ${DEFAULT_CXX_STANDARD})

# Project Directories:
set(PROTEA_SANDBOX_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)

# Add Executable:
add_executable(ProteaSandbox ${PROTEA_SANDBOX_SOURCE_DIR}/SandboxApp.cpp)

# Link to the library:
target_link_libraries(ProteaSandbox PRIVATE ProteaCore)

# Compile Definitions:
target_compile_definitions(ProteaSandbox PRIVATE PROTEA_PLATFORM_WINDOWS)
