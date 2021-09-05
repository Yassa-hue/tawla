cmake_minimum_required(VERSION 3.16)
project(tawla)

set(CMAKE_CXX_STANDARD 14)

add_executable(tawla main.cpp cpp_files/tawla.cpp header_files/tawla.h header_files/main_header.h cpp_files/random_t.cpp header_files/random_t.h)