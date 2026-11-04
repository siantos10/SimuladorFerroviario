cmake_minimum_required(VERSION 3.12)

project(SimuladorFerroviario VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Listagem dos arquivos-fonte do projeto (Atualizada para Semana 2 - Aluno 1)
set(SOURCES
    src/main.cpp
    src/models/Trem.cpp
    src/models/Estacao.cpp
    src/models/Passageiro.cpp
    src/models/Viagem.cpp
    src/models/Incidente.cpp
    src/services/AcervoCentral.cpp
)

add_executable(SimuladorFerroviario ${SOURCES})

target_include_directories(SimuladorFerroviario PRIVATE include)

if(MSVC)
    target_compile_options(SimuladorFerroviario PRIVATE /W4)
else()
    target_compile_options(SimuladorFerroviario PRIVATE -Wall -Wextra -Wpedantic)
endif()