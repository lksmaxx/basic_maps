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
} // namespace Engine
