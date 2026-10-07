cmake_minimum_required(VERSION 3.12)

project(SimuladorFerroviario VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Mapeamento dos arquivos do Aluno 1 (Semana 1)
set(SOURCES
    src/main.cpp
    src/models/Trem.cpp
    src/models/Estacao.cpp
)

add_executable(SimuladorFerroviario ${SOURCES})

# Inclui a pasta de cabecalhos
target_include_directories(SimuladorFerroviario PRIVATE include)

if(MSVC)
    target_compile_options(SimuladorFerroviario PRIVATE /W4)
else()
    target_compile_options(SimuladorFerroviario PRIVATE -Wall -Wextra -Wpedantic)
endif()