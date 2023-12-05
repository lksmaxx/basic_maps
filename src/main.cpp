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

    Engine::Window window(1280, 720, "My Maps");
    Engine::Renderer renderer(window);

    Engine::Shader shader = Engine::Shader();

    shader.loadVertexShader("res/shaders/basic.vs");
    shader.loadFragmentShader("res/shaders/basic.fs");
    shader.linkProgram();

    float vertices[] = {-0.5f, -0.5f, 0.0f, 0.5f, -0.5f,
                        0.0f,  0.0f,  0.5f, 0.0f};

    const unsigned int buffer = renderer.generateVertexBuffer();
    const unsigned int vertex_array = renderer.generateVertexArray();
    renderer.bindVertexArray(vertex_array);
    renderer.bindVertexBuffer(buffer);
    renderer.bufferArrayStaticData(sizeof(vertices), vertices);
    renderer.vertexAttribPointer(0, 3, Engine::DATA_TYPES::FLOAT,
                                 3 * sizeof(float), (void *)0);

    while (window.eventLoop()) {
      renderer.clearScreen();
      shader.useProgram();

      renderer.bindVertexArray(vertex_array);
      renderer.drawStaticTriangles(0, 3);
    }
  } catch (std::runtime_error err) {
    std::cerr << err.what();
    exit(EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}
