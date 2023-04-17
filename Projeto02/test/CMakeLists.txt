add_executable(
    ${PROJECT_NAME}test
    main.cpp
    medidor_de_energia/test_ares.cpp
    medidor_de_energia/test_apolo.cpp
    medidor_de_energia/test_cronos.cpp
    medidor_de_energia/test_zeus.cpp
    test_medidor_de_energia.cpp
    test_EletraEnergySolutions.cpp
    test_Utility.cpp
    services/test_utility_services
   
)

target_include_directories(
    ${PROJECT_NAME}test
    PRIVATE
        ./
)

target_compile_features(
    ${PROJECT_NAME}test
    PRIVATE
        cxx_std_20

)

target_link_libraries(
    ${PROJECT_NAME}test

        PRIVATE
        ${PROJECT_NAME}lib
    

)