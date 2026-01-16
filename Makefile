CXX = g++
CXXFLAGS = -std=c++17 -Iinclude
LIBS = -larchive
SRCS = src/main.cpp src/recovery/archive_engine.cpp src/ui/display.cpp src/usb/handler.cpp
TARGET = build/AINAPC

all: prepare_libs build_app

prepare_libs:
	@echo "[*] Installing dependencies..."
	@pkg install libarchive -y

build_app:
	@mkdir -p build
	@echo "[*] Compiling AINAPC v2.0..."
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LIBS)
	@echo "---------------------------------------"
	@echo "Done! Run with ./build/AINAPC"
	@echo "---------------------------------------"
