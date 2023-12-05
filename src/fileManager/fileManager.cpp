#include <fileManager/fileManager.hpp>
#include <fstream>
#include <iosfwd>
#include <iostream>

namespace Utils {

bool FileManager::readFile(const std::string &file_path, std::string &content) {
  if (file_path.length() == 0) {
    std::cerr << "ERROR::IO::FILE::EMPTY_PATH\n";
    return false;
  }

  std::ifstream input_file(file_path, std::fstream::binary);

  if (input_file.is_open()) {
    input_file.seekg(0, std::ios::end);
    std::streampos file_size = input_file.tellg();
    input_file.seekg(0, std::ios::beg);

    content.clear();
    content.reserve(file_size);

    content.assign(std::istreambuf_iterator<char>(input_file),
                   std::istreambuf_iterator<char>());

    input_file.close();
  } else {
    std::cerr << "ERROR::IO::FILE::COULD_NOT_OPEN\n";
    return false;
  }

  return true;
}

bool FileManager::writeFile(const std::string &file_path,
                            const std::string &content) {
  if (file_path.length() == 0) {
    std::cerr << "ERROR::IO::FILE::EMPTY_PATH\n";
    return false;
  }

  std::ofstream output_file(file_path);

  if (output_file.is_open()) {
    output_file << content;
    output_file.close();
  } else {
    std::cerr << "ERROR::IO::FILE::COULD_NOT_OPEN\n";
    return false;
  }

  return true;
}
} // namespace Utils
