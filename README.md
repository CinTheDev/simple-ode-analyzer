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

Various techniques for approximating ODEs will be implemented, we'll start with Discrete-Euler to get
a better understanding of how the process works, later on we'll move to more advanced techniques
like Midpoint, or Runge-Kutta-4

### Representation of ODEs in code

A specific ODE is being represented by a class that derives from `ODE`. Unfortunatly, the program cannot
convert an equation into code on it's own. Analysing a custom differential equation requires custom
implementation and recompilation of the program.

An ODE can choose between many different methods for being calculated / approximated. In code, there are
various functions that calculate the ODE in a specific way. An ODE can implement as many methods as it
wants, and the User can choose the used method via GUI.

So in short, the actual equation part of the ODE is represented in the different kinds of
`calculate` methods implemented for every descendant of `ODE`.

It's also possible for ODE classes to inherit not from the base ODE class, but from another specific
ODE. This way it's possible to create general ODEs and specific applications of that ODE without
repeating too much. In theory, other c++ features like multiple inheritance can also be taken advantage
of, but I don't know in what way that could be useful here.

Mutable mathematical constants used in the equation are stored in a special array, which the GUI part of
the program is able to access. This way, these constants can be changed at runtime. (But they will never
change while the function is calculated, hence why I call them 'constants').

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

## Potential new / changed features

### Approximation settings in ODE settings

Put approximation settings in ODE options, effectively making every ODE have its own independent settings.

In combination with this, it's also possible to restructure the settings data flow, which is handled via
Events right now.

### Use two arrays for result

Instead of representing the result in a single `double` array, where x values have to be calculated
externally using some `step_x` variable, have the x values be stored alongside the y values using
a second array. This way, we can have custom step_x values for every ODE, step_x no longer has to be
handled individually for the plotter, and gain the ability to plot parameterized functions as an
added bonus.

### Put all controls on the left edge instead of bottom

It is quite annoying to have little vertical space for the ODE options, which require a lot of vertical
space. By putting controls on the left (or right if it's better), the area expands much further vertically
which makes the required scrolling way less annoying.

Implement this only after integrating approximation settings into ODE settings though, otherwise it's not
going to be an efficient process.

## TODOs

- Add way to choose ODE type at creation
