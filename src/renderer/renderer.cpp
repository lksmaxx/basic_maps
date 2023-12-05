#include <renderer/renderer.hpp>

namespace Engine {

Renderer::Renderer(const Window &window) : m_window(window) {
  gladLoadGL((GLADloadfunc)this->m_window.getProcAddress());

  glViewport(0, 0, window.getWindowW(), window.getWindowH());
}
Renderer::~Renderer() {}

void Renderer::clearScreen() {
  glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
}

int Renderer::generateVertexArray() {
  unsigned int vao;
  glGenVertexArrays(1, &vao);
  return vao;
}

void Renderer::bindVertexArray(const int vao) const { glBindVertexArray(vao); }

int Renderer::generateVertexBuffer() {
  unsigned int vbo;
  glGenBuffers(1, &vbo);
  return vbo;
}
void Renderer::bindVertexBuffer(int vbo) const {
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
}

void Renderer::bufferArrayStaticData(size_t data_size, const void *data) const {
  glBufferData(GL_ARRAY_BUFFER, data_size, data, GL_STATIC_DRAW);
}

void Renderer::drawStaticTriangles(size_t offset, size_t count) {
  glDrawArrays(GL_TRIANGLES, offset, count);
}

void Renderer::vertexAttribPointer(size_t index, size_t offset, DATA_TYPES type,
                                   size_t stride, void *start) {
  glVertexAttribPointer(index, offset, type, GL_FALSE, stride, start);
  glEnableVertexAttribArray(index);
}

} // namespace Engine
