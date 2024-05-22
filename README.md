# Differential Equations

This project is a function plotter written in C to test approximation of differential equations.

## Function plotter

The project will run on the console, onto which the function will be plotted using ASCII symbols.

If there's potential, we could move the project to wxWidgets for improved resolution and
convinient features.

## Approximation

Various techniques for approximating ODEs will be implemented, we'll start with Discrete-Euler to get
a better understanding of how the process works, later on we'll move to more advanced techniques
like Midpoint, or Runge-Kutta-4

## wxWidgets features

Since we're now moving to wxWidgets, let's define concrete features and a layout for development.

### Features

- A visual graph plot
- Number markings for reading values
- Ability to scale the graph on axes / zoom
- Multiple plots with configurable colours
- Calculate error / deviance between graphs
- Dropdown with different approximation methods

### Layout

It will be a two-split layout. The split is horizontal, meaning there are two areas on top of each other.
The top one will be the graph plot, the bottom one for settings.

## Memory Tests

Test following:

- Constructor - PASSED
- Calculation w/o regeneration - PASSED
- Calculation w/  regeneration - PASSED
- OdePointer - PASSED
- ListUpdate - PASSED
- ListUpdate & Calculation - PASSED
