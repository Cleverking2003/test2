cmake_minimum_required(VERSION 3.10)
project(editor)

add_compile_options(-fprofile-arcs -ftest-coverage)

add_subdirectory(editor)
add_subdirectory(external/googletest)
add_subdirectory(tests)
add_subdirectory(text)
