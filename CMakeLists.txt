cmake_minimum_required(VERSION 3.25)
project(ExerciseEveryday)

set(CMAKE_CXX_STANDARD 17)
include_directories(String smart_pointer)

add_executable(ExerciseEveryday main.cpp String/MyString.h String/MyString.cpp String/TestString.cpp smart_pointer/smart_pointer.h)
