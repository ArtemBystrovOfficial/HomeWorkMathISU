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

add_executable(reverse_matrix_tests
                ${PROJECT_CPP_SOURCE}/Gauss.cpp 
                ${PROJECT_CPP_SOURCE}/Matrix.cpp                
                ${PROJECT_CPP_SOURCE}/ReverseMatrixTests.cpp 
                ${PROJECT_CPP_SOURCE}/ReverseMatrix.cpp)

add_executable(interpolation_tests 
                ${PROJECT_CPP_SOURCE}/Interpolation.cpp
                ${PROJECT_CPP_SOURCE}/InterpolationTests.cpp
                ${PROJECT_CPP_SOURCE}/Gauss.cpp
                ${PROJECT_CPP_SOURCE}/Matrix.cpp)

add_executable(macloren_tests
                ${PROJECT_CPP_SOURCE}/Macloren.cpp
                ${PROJECT_CPP_SOURCE}/MaclorenTests.cpp
)

target_link_libraries( interpolation_tests PRIVATE 
                    gtest gtest_main
                    gmock gmock_main )

target_link_libraries( vectors_tests PRIVATE
                    gtest gtest_main
                    gmock gmock_main )

target_link_libraries( reverse_matrix_tests PRIVATE
                    gtest gtest_main
                    gmock gmock_main )

target_link_libraries( matrix_tests PRIVATE
                    gtest gtest_main
                    gmock gmock_main )
                
target_link_libraries( gauss_tests PRIVATE
                    gtest gtest_main
                    gmock gmock_main )

target_link_libraries( macloren_tests PRIVATE
                    gtest gtest_main
                    gmock gmock_main )                    