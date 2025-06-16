cmake_minimum_required(VERSION 3.31)
project(ProteaCore LANGUAGES CXX)

# Directories
set(PROTEA_CORE_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)
set(PROTEA_CORE_VENDOR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/vendor)

# Dependencies
include(${PROTEA_CORE_VENDOR_DIR}/Dependencies.cmake)

# Core source files
set(PROTEA_CORE_SOURCES
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Application.cpp
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Log.cpp
)

set(PROTEA_CORE_HEADERS
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Application.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/EntryPoint.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Core.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea/Log.h
        ${PROTEA_CORE_SOURCE_DIR}/Protea.h
)

# Shared library target
add_library(ProteaCore SHARED ${PROTEA_CORE_SOURCES} ${PROTEA_CORE_HEADERS})

# Includes
target_include_directories(ProteaCore PUBLIC ${PROTEA_CORE_SOURCE_DIR})

# Libraries
target_link_libraries(ProteaCore PUBLIC spdlog::spdlog)

# Preprocessor definitions
target_compile_definitions(ProteaCore
        PRIVATE
        PROTEA_PLATFORM_WINDOWS
        PROTEA_BUILD_DLL
)
