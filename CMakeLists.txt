cmake_minimum_required(VERSION 3.10)

find_package(wxWidgets REQUIRED COMPONENTS net core base)

if (wxWidgets_USE_FILE)
    include(${wxWidgets_USE_FILE})
endif()

project(diffeq)

add_subdirectory(src)
add_subdirectory(app)
