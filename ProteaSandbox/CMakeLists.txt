cmake_minimum_required(VERSION 3.31)
project(ProteaSandbox LANGUAGES CXX)

set(PROTEA_SANDBOX_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/source)

add_executable(ProteaSandbox
        ${PROTEA_SANDBOX_SOURCE_DIR}/SandboxApp.cpp
)

target_include_directories(ProteaSandbox PRIVATE
        ${PROTEA_SANDBOX_SOURCE_DIR}
        $<TARGET_PROPERTY:ProteaCore,INTERFACE_INCLUDE_DIRECTORIES>)

target_link_libraries(ProteaSandbox PRIVATE ProteaCore)

target_compile_definitions(ProteaSandbox PRIVATE PROTEA_PLATFORM_WINDOWS)

# Apply configuration-specific flags
configure_compiler_flags(ProteaSandbox)
