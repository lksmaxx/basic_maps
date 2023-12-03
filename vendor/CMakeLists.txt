set(GLFW_BUILD_TESTS 0)
set(GLFW_BUILD_EXAMPLES 0)
set(GLFW_BUILD_DOCS 0)

add_subdirectory(glfw-3.3.8)

add_library(glad STATIC glad/src/gl.c)
target_include_directories(glad PUBLIC glad/include)
