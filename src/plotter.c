#include "plotter.h"
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

void print_graph(char* graph, uint16_t width, uint16_t height) {
    for (int y = 0; y < height * 2 + 1; y++) {
        for (int x = 0; x < width; x++) {
            int graph_index = (y * width) + x;
            printf("%c", graph[graph_index]);
        }

        printf("\n");
    }
}

void draw_graph(char* graph, uint16_t width, uint16_t height) {
    uint16_t x_axis_index = height;
    uint16_t y_axis_index = 0;

    for (uint16_t y = 0; y < height * 2 + 1; y++) {
        for (uint16_t x = 0; x < width; x++) {
            int graph_index = (y * width) + x;

            if (x == y_axis_index && y == x_axis_index) {
                graph[graph_index] = '+';
            } 
            else if (x == y_axis_index) {
                graph[graph_index] = '|';
            }
            else if (y == x_axis_index) {
                graph[graph_index] = '-';
            }
            else {
                graph[graph_index] = ' ';
            }
        }
    }
}

void draw_function(char* graph, uint16_t width, uint16_t height, double step_x, double step_y, double* func_values) {
    for (uint16_t x = 0; x < width; x++) {
        int index_y = round(func_values[x] / -step_y + height);

        if (index_y >= 0 && index_y <= height * 2) {
            int graph_index = (index_y * width) + x;
            graph[graph_index] = '*';
        }
    }
}

void plot_function(uint16_t width, uint16_t height, double step_x, double step_y, double* func_values) {
    int graph_length = width * (height * 2 + 1);
    char graph[graph_length];

    draw_graph(graph, width, height);

    draw_function(graph, width, height, step_x, step_y, func_values);

    print_graph(graph, width, height);
}
