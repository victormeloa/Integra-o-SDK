cmake_minimum_required(VERSION 3.17)

add_executable(
    foo
    
    main.cpp
    src/teste_meter_energy.cpp

)

target_include_directories(
    foo

    PRIVATE
        ./
)

target_link_libraries(
    foo

    PUBLIC
        ${PROJECT_NAME}SRCS
)

target_compile_features(
    foo

    PUBLIC
        cxx_std_17   
)

add_custom_target(
    test

    COMMAND
        foo

    USES_TERMINAL
)

add_dependencies(test foo)
