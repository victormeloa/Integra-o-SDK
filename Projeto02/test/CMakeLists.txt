add_executable(
    ${PROJECT_NAME}test
    main.cpp
    test_ares.cpp
    test_apolo.cpp
    test_cronos.cpp
    test_zeus.cpp
    test_eletraenergysolution.cpp

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