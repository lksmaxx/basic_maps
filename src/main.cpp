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

    Engine::Window window(1280, 720, "My Maps");
    Engine::Renderer renderer(window);

    while (window.eventLoop()) {
      renderer.clearScreen();
    }
  } catch (std::runtime_error err) {
    std::cerr << err.what();
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}
