cmake_minimum_required(VERSION 3.16)
project(C_Cpp_Sample)

set(CMAKE_CXX_STANDARD 11)

add_executable(C_Cpp_Sample main.cpp CModule/1-basic-data-type/Sample.cpp CModule/2-variable-address-and-pointer/Sample.cpp CModule/3-pointer-change-value/Sample.cpp CModule/4-muti-pointer/Sample.cpp)