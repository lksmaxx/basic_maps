#pragma once

#include "window/window.hpp"
#include <glad/gl.h>
namespace Engine {
class Renderer {
public:
  Renderer(const Window &window);
  ~Renderer();

  void clearScreen();

private:
  const Window &m_window;
};
} // namespace Engine
