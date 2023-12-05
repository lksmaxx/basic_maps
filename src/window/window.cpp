#include <iostream>
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <window/window.hpp>
#include <stdexcept>
#include <string>

namespace MySpace {
Window::Window(unsigned int window_w, unsigned int window_h,
               const std::string &name) {

  const int init_value = glfwInit();
  if (init_value == 0) {
    throw new std::runtime_error("ERROR::GLFW::FAILED_TO_INITIALIZE\n");
  }
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  this->m_window =
      glfwCreateWindow(window_w, window_h, name.c_str(), NULL, NULL);
  if (m_window == NULL) {
    throw new std::runtime_error("ERROR::GLFW::FAILED_TO_CRAETE_WINDOW");
  }

  glfwMakeContextCurrent(m_window);
  std::cout << "created window\n";
}
Window::~Window() {
  glfwDestroyWindow(m_window);
  glfwTerminate();
}

bool Window::eventLoop() {
  glfwPollEvents();
  glfwSwapBuffers(m_window);

  return !glfwWindowShouldClose(m_window);
}
} // namespace MySpace
