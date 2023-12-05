#include <cstdlib>
#include <iostream>
#include "window/window.hpp"
#include <glad/gl.h>
#include <GLFW/glfw3.h>

const int WINDOW_W = 1280;
const int WINDOW_H = 720;

int main() {
  try {
    std::cout << "Alou\n";

    MySpace::Window window(1280, 720, "My Maps");

    while (window.eventLoop()) {
      std::cout << "oi oi\n";
    }
  } catch (std::runtime_error err) {
    std::cerr << err.what();
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}
