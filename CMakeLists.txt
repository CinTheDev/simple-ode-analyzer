cmake_minimum_required(VERSION 3.10)

find_package(wxWidgets REQUIRED COMPONENTS net core base)

if (wxWidgets_USE_FILE)
    include(${wxWidgets_USE_FILE})
endif()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

project(diffeq)

add_subdirectory(src)

target_compile_options(diffeq PRIVATE -Wall -Wextra -Wpedantic)
