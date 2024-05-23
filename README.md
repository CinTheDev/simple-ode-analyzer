# Differential Equations

This project is a simple function plotter written in C++ to test and compare approximation
of ordinary differential equations.

Here, "differential equation" will almost alway be abbreviated to "ODE" (Ordinary Differential Equation)
for convinience.

## Feature description

### Function plotter

The plotter is relatively simple, it can display multiple functions in different colours.

The interface has shortcuts implemented, it's possible to zoom along x and y, and also offset on x.

### Approximation (Numerical) methods

Various techniques for approximating ODEs will be implemented, we'll start with Discrete-Euler to get
a better understanding of how the process works, later on we'll move to more advanced techniques
like Midpoint, or Runge-Kutta-4

### Representation of ODEs in code

A specific ODE is being represented by a class that derives from `ODE`. Unfortunatly, the program cannot
convert an equation into code on it's own. Analysing a custom differential equation requires custom
implementation and recompilation of the program.

When multiple different numerical approximation methods are used, every possible method must be
implemented in code.

So in short, the actual equation part of the ODE is represented in the different kinds of
`calculate` methods implemented for every descendant of `ODE`.

## Development

### CMake

The program is built using CMake. You can do this yourself or by using the scripts found in the root:
`build.sh` and `run.sh`.

A dependency of this project is wxWidgets, which will get explained in further detail below.

### wxWidgets

As stated above already, CMake requires a wxWidgets installation in order to compile.
Please make sure to have wxWidgets installed, so that inside CMakeLists.txt `find_package()`
can find wxWidgets.

Right now, wxWidgets version 3.2.2 is being used.

## TODOs

Steps in implementing synchronized ODEs:

- Change ODE array to vector
- Update Vector based on input
- Apply all ODE settings immediatly
