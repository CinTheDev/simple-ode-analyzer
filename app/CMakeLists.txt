add_executable(diffeq
    main.cpp
    app.cpp
)

target_include_directories(diffeq PUBLIC
    ${CMAKE_SOURCE_DIR}/include/diffeq/app
)

target_link_libraries(diffeq
    PUBLIC
    ${wxWidgets_LIBRARIES}
    ode
    plotter
    m
)
