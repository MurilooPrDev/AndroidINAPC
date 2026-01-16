#!/bin/bash

echo -e "\033[34m[*] Installing AINAPC v2.0 Dependencies...\033[0m"

# Instala tudo o que é necessário sem perguntar nada (-y)
pkg install clang libarchive make -y

echo -e "\033[34m[*] Compiling High-Performance Engine...\033[0m"

# Cria a pasta de build e compila
mkdir -p build
make

echo -e "\033[32m[SUCCESS] AINAPC is ready! Starting now...\033[0m"
sleep 1

# Já executa o programa pro cara não ter trabalho
./build/AINAPC
