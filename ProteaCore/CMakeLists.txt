cmake_minimum_required(VERSION 3.31)
project(ProteaCore)

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
set(PROTEA_CORE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)
set(PROTEA_CORE_VENDOR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor)

# Fetch Dependencies:
include(${PROTEA_CORE_VENDOR_DIR}/Dependencies.cmake)

# Add Library source files
add_library(ProteaCore SHARED
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Application.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Application.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/EntryPoint.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Core.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Log.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Log.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea.h
)

# Linking:
target_link_libraries(ProteaCore PUBLIC spdlog::spdlog)

# Include Directories:
target_include_directories(ProteaCore PUBLIC ${PROTEA_CORE_SOURCE_DIR})

# Compile Definitions:
target_compile_definitions(ProteaCore PRIVATE PROTEA_PLATFORM_WINDOWS PROTEA_BUILD_DLL)

# Copy the DLL to the sandbox bin folder after building
#[[
add_custom_command(TARGET ProteaCore POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory
        ${CMAKE_BINARY_DIR}/ProteaSandbox/bin/
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_FILE:ProteaCore>
        ${CMAKE_BINARY_DIR}/ProteaSandbox/bin/)]]
