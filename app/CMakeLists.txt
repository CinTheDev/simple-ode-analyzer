add_executable(diffeq
    main.c
)

target_link_libraries(diffeq
    PUBLIC
    ${wxWidgets_LIBRARIES}
    ode
    plotter
    m
)
