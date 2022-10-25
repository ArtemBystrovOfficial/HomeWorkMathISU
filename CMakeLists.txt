cmake_minimum_required (VERSION 3.0)

project(MathISU)

set(PROJECT_CPP_SOURCE "source/cpp")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(googletest)

add_executable(vectors_tests 
                ${PROJECT_CPP_SOURCE}/Vectors.cpp 
                ${PROJECT_CPP_SOURCE}/VectorsTests.cpp)
add_executable(matrix_tests 
                ${PROJECT_CPP_SOURCE}/MatrixTests.cpp 
                ${PROJECT_CPP_SOURCE}/Matrix.cpp)
add_executable(gauss_tests 
                ${PROJECT_CPP_SOURCE}/Matrix.cpp                
                ${PROJECT_CPP_SOURCE}/GaussTests.cpp 
                ${PROJECT_CPP_SOURCE}/Gauss.cpp)

target_link_libraries( vectors_tests PRIVATE
                    gtest gtest_main
                    gmock gmock_main )

target_link_libraries( matrix_tests PRIVATE
                    gtest gtest_main
                    gmock gmock_main )
                
target_link_libraries( gauss_tests PRIVATE
                    gtest gtest_main
                    gmock gmock_main )