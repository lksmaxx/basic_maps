#pragma once

#include <glad/gl.h>

#include <string>
namespace Engine {
class Shader {
public:
  Shader();
  ~Shader();

  void loadFragmentShader(const std::string &file_path);
  void loadVertexShader(const std::string &file_path);
  void linkProgram();
  void useProgram();

private:
  unsigned int m_shader_program;
};
} // namespace Engine
