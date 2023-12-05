#pragma once
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <string>

namespace MySpace {
class Window {
public:
  Window(unsigned int window_w, unsigned int window_h, const std::string &name);
  ~Window();
  bool eventLoop();

private:
  GLFWwindow *m_window;
  unsigned int m_window_w;
  unsigned int m_window_h;
  std::string m_window_name;
};
} // namespace MySpace
