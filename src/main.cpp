#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <iostream>

const int WINDOW_W = 1280;
const int WINDOW_H = 720;

int main() {
  int glfw_init = glfwInit();
  if (!glfw_init) {
    std::cerr << "ERROR::GLFW::INIT::FAILED_TO_INITIALIZE_WITH_CODE::"
              << glfw_init << "\n";
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow *window;
  window = glfwCreateWindow(WINDOW_W, WINDOW_H, "Maps", NULL, NULL);
  if (window == NULL) {
    std::cerr << "ERROR::GLFW::WINDOW::FAILED_TO_CREATE_WINDOW\n";
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  while (!glfwWindowShouldClose(window)) {
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
