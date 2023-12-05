#pragma once

#include "window/window.hpp"
#include <glad/gl.h>
namespace Engine {
class Renderer {
public:
  Renderer(const Window &window);
  ~Renderer();

  // screen
  void clearScreen();

  // buffers

  // VAO
  int generateVertexArray();
  void bindVertexArray(const int vao) const;

  // VBO
  int generateVertexBuffer();
  void bindVertexBuffer(const int vbo) const;
  void bufferArrayStaticData(size_t data_size, const void *data) const;

private:
  const Window &m_window;
};
} // namespace Engine
