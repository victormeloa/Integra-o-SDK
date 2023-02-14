cmake_minimum_required(VERSION 3.17)


PROJECT(
    PROJETO01
    LANGUAGES CXX
)

add_executable(
    ${PROJECT_NAME}

    src/main.cpp
    src/menu_options.cpp
    src/meter_energy.cpp
    src/meter_water.cpp
    src/religadores.cpp
    src/controle.cpp
    src/textos.cpp
    
)

target_include_directories(
    ${PROJECT_NAME}

    PUBLIC  
    ./include
    ${CMAKE_CURRENT_BINARY_DIR}

)

target_compile_features(
    ${PROJECT_NAME}

    PUBLIC
      cxx_std_20

)