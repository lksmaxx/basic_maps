#include "shader/shader.hpp"
#include <cstdlib>
#include <iostream>
#include "window/window.hpp"
#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <renderer/renderer.hpp>

const int WINDOW_W = 1280;
const int WINDOW_H = 720;

int main() {
  try {
    std::cout << "Init\n";

    Engine::Window window(1280, 720, "My Maps");
    Engine::Renderer renderer(window);

    std::cout << "renderer created\n";
    Engine::Shader shader = Engine::Shader();
    std::cout << "created shader\n";

    shader.loadVertexShader("res/shaders/basic.vs");
    shader.loadFragmentShader("res/shaders/basic.fs");
    shader.linkProgram();

    std::cout << "Hello\n";
    while (window.eventLoop()) {
      renderer.clearScreen();
      shader.useProgram();
    }
  } catch (std::runtime_error err) {
    std::cerr << err.what();
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}
