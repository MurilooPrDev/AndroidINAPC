#ifndef RECOVERY_H
#define RECOVERY_H
#include <string>

#define COLOR_BLUE  "\033[34m"
#define COLOR_GREEN "\033[32m"
#define COLOR_RESET "\033[0m"

int extract_archive(const std::string& filename, const std::string& out_path);
void drawProgressBar(float progress, const std::string& currentFile);
void waitForUSB(const std::string& device);
#endif
