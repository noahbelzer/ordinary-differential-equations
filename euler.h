#ifndef EULER
#define EULER

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

// Function declarations (prototypes)
double f(double t, double y);
double exact_solution_y(double t);
int euler(double h, int num_of_t_values);

#endif 