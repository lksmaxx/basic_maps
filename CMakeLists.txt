cmake_minimum_required(VERSION 3.12)

project(mapsGL)
set(EXEC_NAME maps)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

add_subdirectory(vendor)

file(GLOB_RECURSE SOURCE_FILES "src/*.cpp")

add_executable(${EXEC_NAME} ${SOURCE_FILES})

target_link_libraries(${EXEC_NAME} glfw)
