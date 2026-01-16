AINAPC v2.0 (Android In APC) - Universal Recovery Engine
AINAPC é uma ferramenta de recuperação de dados de alta performance escrita em C++, projetada para rodar nativamente em ambientes Android (via Termux). Ao contrário de scripts simples, o AINAPC utiliza a biblioteca de baixo nível libarchive e o sistema de arquivos nativo para realizar varreduras profundas, extração de containers e restauração de arquivos deletados ou perdidos em dispositivos móveis, PCs e Consoles.

🚀 Funcionalidades Principais
Motor de Busca Universal: Localiza e recupera automaticamente APKs, OBBs, Imagens (JPG, PNG), Vídeos (MP4, MKV), Documentos (PDF, DOCX) e Bancos de Dados (SQL, DB).

Deep Archive Extraction: Suporte nativo para extração em tempo real de arquivos comprimidos .zip, .7z, .rar e imagens .iso.

Modo Bridge (Console/PC): Protocolo de handshake USB dedicado para intermédio de dados entre dispositivos externos e o Android.

Live Recovery: Diferente de outras ferramentas, o AINAPC realiza a cópia e restauração dos dados no exato momento em que são encontrados, garantindo a integridade parcial mesmo em interrupções.

Escaneamento Inteligente: Ignora automaticamente pastas restritas do sistema para evitar travamentos, focando nos setores de armazenamento real.

🛠️ Estrutura do Projeto
O software é modularizado para facilitar a manutenção e futuras expansões:

src/main.cpp: Núcleo lógico e gerenciador de estados.

src/recovery/: Motor de extração binária e manipulação de arquivos.

src/ui/: Gerenciamento de interface via terminal e barras de progresso.

src/usb/: Protocolos de comunicação e detecção de hardware.

include/: Cabeçalhos técnicos e definições globais.

📦 Instalação e Uso
Para instalar o AINAPC no Termux, você precisará de um compilador C++ e das dependências de desenvolvimento.

1. Clonar e Instalar
Bash

git clone https://github.com/MurilooPrDev/AndroidINAPC.git
cd AndroidINAPC
chmod +x install.sh
./install.sh
2. Compilação Manual (Se necessário)
Caso prefira compilar manualmente, o Makefile incluído automatiza o download das bibliotecas:

Bash

make
./build/AINAPC
⚠️ Requisitos Importantes
Permissões de Armazenamento: Para que a ferramenta funcione no Phone, execute termux-setup-storage antes de iniciar.

Acesso Root (Opcional): Para recuperações em pastas profundas do sistema ou partições de hardware, recomenda-se o uso do tsu (Root no Termux).

Dependência: O software requer libarchive para manipulação de arquivos comprimidos.

👨‍💻 Desenvolvedor
Projeto mantido por MurilooPrDev. Desenvolvido com foco em perícia digital e recuperação de desastres em dispositivos Android
