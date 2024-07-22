# Differential Equations

This project is a simple function plotter written in C++ to test and compare approximation
of ordinary differential equations.

Here, "differential equation" will almost always be abbreviated to "ODE" (Ordinary Differential Equation)
for convinience.

## Feature description

### Function plotter

The plotter is relatively simple, it can display multiple functions in different colours.

The interface has shortcuts implemented, it's possible to zoom along x and y, and also offset on x.

### Approximation (Numerical) methods

Currently implemented:

- Euler
- Midpoint

Note: As of right now, only ODEs of second order in the form of `f''(x) = A(x)` are supported. A(x)
is only allowed to contain f(x) and some other values.

Perhaps in the future I will generalize it so other orders (especially first order) can be computed.

### Representation of ODEs in code

A specific ODE is being represented by a class that derives from `OdeFunction`. Unfortunatly, the program
cannot convert an equation into code on it's own. Analysing a custom differential equation requires custom
implementation and recompilation of the program.

The good news is that only the function itself and the customizable options have to be implemented by hand.
There's no need to implement the approximation itself, as the program can handle that by itself.

The new class only needs to implement `evaluate_function(double fx)`, where this function just computes
the second derivative using the ODE in the form of `f''(x) = ...`. The given parameter `double fx` represents
`f(x)` which is required if the equation is an ODE.

As the ODE classes are now integrated in wxWidgets (unlike in past versions), it's really easy to create
custom options for specifying some values relevant for the ODE.

There's a few examples for simple ODE implementations under `src/controls/ode/ode_variants`.

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

Implement dampening for the ODEs

- ode_oscillation_pendulum
- ode_oscillation_gravitational
