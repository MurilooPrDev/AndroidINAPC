#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <thread>
#include <chrono>
#include <algorithm>
#include "recovery.h"

namespace fs = std::filesystem;

// Lista de extensões para recuperação total
const std::vector<std::string> EXTENSIONS = {
    ".apk", ".obb", ".zip", ".7z", ".rar", ".iso", 
    ".jpg", ".jpeg", ".png", ".mp4", ".mkv", ".mp3", 
    ".pdf", ".docx", ".txt", ".sql", ".db"
};

bool isRecoverable(const std::string& ext) {
    for (const auto& e : EXTENSIONS) {
        if (ext == e) return true;
    }
    return false;
}

int main() {
    std::cout << COLOR_BLUE << "--- ANDROID IN APC v2.0 (UNIVERSAL) ---" << COLOR_RESET << "\n\n";
    std::string device, scanMode, targetPath = "/storage/emulated/0/";
    
    std::cout << "Target: Console, PC, or Phone?\nChoice: ";
    std::cin >> device;

    if (device == "PC" || device == "pc" || device == "Console" || device == "console") {
        waitForUSB(device);
        std::cout << COLOR_GREEN << "[*] Bridge Active. Receiving Data..." << COLOR_RESET << std::endl;
        for(int i = 0; i <= 100; i += 5) {
            drawProgressBar((float)i/100, "RAW_BLOCK_STREAM");
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
        return 0; 
    }

    std::cout << "\nScan Mode (full/selected): ";
    std::cin >> scanMode;
    if (scanMode == "selected") {
        std::cout << "Path: "; std::cin >> targetPath;
    }

    fs::create_directories("output");
    std::vector<fs::path> items;

    std::cout << COLOR_BLUE << "[*] Initializing Universal Deep Scan..." << COLOR_RESET << std::endl;

    try {
        auto iter = fs::recursive_directory_iterator(targetPath, fs::directory_options::skip_permission_denied);
        for (const auto& entry : iter) {
            try {
                if (entry.is_regular_file()) {
                    std::string ext = entry.path().extension().string();
                    std::transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
                    
                    if (isRecoverable(ext)) {
                        items.push_back(entry.path());
                    }
                }
            } catch (...) { continue; }
        }

        if (items.empty()) {
            std::cout << "\033[33m[!] No files found for recovery.\033[0m" << std::endl;
        } else {
            for (size_t i = 0; i < items.size(); ++i) {
                drawProgressBar((float)(i + 1) / items.size(), items[i].filename().string());
                
                // Se for arquivo comprimido, extrai. Se não, copia o arquivo inteiro (APK, JPG, etc)
                std::string ext = items[i].extension().string();
                if (ext == ".zip" || ext == ".7z") {
                    extract_archive(items[i].string(), "output");
                } else {
                    fs::copy(items[i], "output/" + items[i].filename().string(), fs::copy_options::overwrite_existing);
                }
            }
            std::cout << "\n\n" << COLOR_GREEN << "[SUCCESS] Universal Recovery Finished! Files in /output" << COLOR_RESET << std::endl;
        }
    } catch (...) {
        std::cout << "\033[31m\n[!] Error: Access denied.\033[0m" << std::endl;
    }

    return 0;
}
