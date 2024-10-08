cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(project)

# Define a versão do C a ser utilizada
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_BUILD_TYPE Debug)

# Adiciona o diretório include ao caminho de pesquisa
include_directories(include)

# Adiciona o executável
#add_executable(project  src/t1_2.cpp)
add_executable(project  src/func.cpp src/main.cpp)

# Linka a biblioteca math e pthread
target_link_libraries(project pthread )
