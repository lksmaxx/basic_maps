#include <renderer/renderer.hpp>

namespace Engine {
Renderer::Renderer(const Window &window) : m_window(window) {
  gladLoadGL((GLADloadfunc)this->m_window.getProcAddress());
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

void Renderer::bufferArrayStaticData(size_t data_size, const void *data) const {
  glBufferData(GL_ARRAY_BUFFER, data_size, data, GL_STATIC_DRAW);
}

} // namespace Engine
