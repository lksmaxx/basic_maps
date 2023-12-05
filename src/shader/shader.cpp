#include "fileManager/fileManager.hpp"
#include <shader/shader.hpp>
#include <stdexcept>
#include <string>

namespace Engine {
Shader::Shader() : m_shader_program(glCreateProgram()) {}
Shader::~Shader() { glDeleteProgram(m_shader_program); }

void Shader::loadVertexShader(const std::string &file_path) {
  std::string shader_source;
  Utils::FileManager::readFile(file_path, shader_source);
  const char *shader_source_ptr = shader_source.c_str();

  int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertex_shader, 1, &shader_source_ptr, NULL);
  glCompileShader(vertex_shader);

  int success;
  char info_log[512];

  glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
  if (success == 0) {
    glGetShaderInfoLog(vertex_shader, 512, NULL, info_log);
    throw new std::runtime_error("ERROR::SHADER::VERTEX::COMPILATION\n" +
                                 std::string(info_log));
  }
  glAttachShader(m_shader_program, vertex_shader);

  glDeleteShader(vertex_shader);
}

void Shader::loadFragmentShader(const std::string &file_path) {
  std::string shader_source;
  Utils::FileManager::readFile(file_path, shader_source);
  const char *shader_source_ptr = shader_source.c_str();

  int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment_shader, 1, &shader_source_ptr, NULL);
  glCompileShader(fragment_shader);

  int success;
  char info_log[512];

  glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
  if (success == 0) {
    glGetShaderInfoLog(fragment_shader, 512, NULL, info_log);
    throw new std::runtime_error("ERROR::SHADER::FRAGMENT::COMPILATION\n" +
                                 std::string(info_log));
  }

  glAttachShader(m_shader_program, fragment_shader);

  glDeleteShader(fragment_shader);
}

void Shader::linkProgram() {
  glLinkProgram(m_shader_program);
  int success;
  char info_log[512];
  glGetProgramiv(m_shader_program, GL_LINK_STATUS, &success);
  if (success == 0) {
    glGetProgramInfoLog(m_shader_program, 512, NULL, info_log);
    throw std::runtime_error("ERROR::SHADER::PROGRAM::LINKING\n" +
                             std::string(info_log));
  }
}
void Shader::useProgram() { glUseProgram(m_shader_program); }
} // namespace Engine
