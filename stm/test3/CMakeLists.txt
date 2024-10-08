cmake_minimum_required(VERSION 3.22)
project(stm32_project C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Define o caminho do toolchain
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/toolchain.cmake")

# Adiciona o diretório de fontes
add_executable(${PROJECT_NAME} main.c)

# Linka as bibliotecas
target_link_libraries(${PROJECT_NAME} PRIVATE)

# Define os diretórios de include
target_include_directories(${PROJECT_NAME} PRIVATE)

# Adiciona o arquivo de linkagem
target_link_options(${PROJECT_NAME} PRIVATE -T${CMAKE_SOURCE_DIR}/STM32F103C8Tx_FLASH.ld)
