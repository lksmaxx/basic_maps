#pragma once

#include <string>
namespace Utils {
class FileManager {
public:
  static bool readFile(const std::string &file_path, std::string &content);
  static bool writeFile(const std::string &file_path,
                        const std::string &content);
};
} // namespace Utils
