#include <iostream>
#include <thread>
#include <chrono>
#include "../../include/recovery.h"

void waitForUSB(const std::string& device) {
    std::cout << "\033[33m\n[!] ACTION: Connect USB cable to " << device << " now." << COLOR_RESET << std::endl;
    for(int i = 0; i < 3; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(700));
        std::cout << COLOR_BLUE << "." << COLOR_RESET << std::flush;
    }
    std::cout << COLOR_GREEN << " Linked!\n" << COLOR_RESET << std::endl;
}
