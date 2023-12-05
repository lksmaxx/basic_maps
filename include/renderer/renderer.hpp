#pragma once

#include "window/window.hpp"
#include <glad/gl.h>
namespace Engine {
enum DATA_TYPES { FLOAT = GL_FLOAT };
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
  void vertexAttribPointer(size_t index, size_t offset, DATA_TYPES type,
                           size_t size, void *start);

  // draw
  void drawStaticTriangles(size_t offset, size_t count);

private:
  const Window &m_window;
};
} // namespace Engine
