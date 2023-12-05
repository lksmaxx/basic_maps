#pragma once

#include <string>
class FileManager {
public:
  static bool readFile(const std::string &file_path, std::string &content);
  static bool writeFile(const std::string &file_path,
                        const std::string &content);
};
