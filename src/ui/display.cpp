#include <iostream>
#include <string>
#include "../../include/recovery.h"

void drawProgressBar(float progress, const std::string& currentFile) {
    int barWidth = 30;
    std::cout << "\r" << COLOR_BLUE << "[AINAPC] " << COLOR_RESET << "[";
    int pos = barWidth * progress;
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) std::cout << "█"; else std::cout << "░";
    }
    std::string display = currentFile.length() > 20 ? currentFile.substr(0, 17) + "..." : currentFile;
    std::cout << "] " << int(progress * 100.0) << "% | " << COLOR_GREEN << display << COLOR_RESET << "          " << std::flush;
}
