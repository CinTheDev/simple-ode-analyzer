add_library(ode ode.cpp)

target_include_directories(ode PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/plotter/ode
)

target_link_libraries(ode PRIVATE
    m
)

add_subdirectory(ode_variants)
