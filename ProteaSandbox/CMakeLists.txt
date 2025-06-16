cmake_minimum_required(VERSION 3.31)
project(ProteaSandbox)

# Default fallback
set(DEFAULT_CXX_STANDARD 23)

if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # Limit GCC to C++17 to avoid known issues with DLLs
    set(DEFAULT_CXX_STANDARD 17)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(DEFAULT_CXX_STANDARD 23)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(DEFAULT_CXX_STANDARD 20) # Or 23 if you’ve tested it works
endif()

# Project Directories:
set(PROTEA_SANDBOX_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)

# Add Executable:
add_executable(ProteaSandbox ${PROTEA_SANDBOX_SOURCE_DIR}/SandboxApp.cpp)

# Link to the library:
target_link_libraries(ProteaSandbox PRIVATE ProteaCore)

# Compile Definitions:
target_compile_definitions(ProteaSandbox PRIVATE PROTEA_PLATFORM_WINDOWS)
