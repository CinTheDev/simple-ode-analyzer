add_executable(diffeq
    src/main.c
)

target_link_libraries(diffeq
    PUBLIC
    ${wxWidgets_LIBRARIES}
    ode
    plotter
    m
)
