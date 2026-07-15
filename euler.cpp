/*
Compile:
g++ -O3 -march=native -funroll-loops -Wall -Wextra -o euler euler.cpp

Run:
./euler
*/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include "euler.h"

double f(double t, double y) {
	// y'
	return t * y + std::pow(t, 3);
};


double exact_solution_y(double t) {
	return 3 * std::exp(std::pow(t, 2) / 2) - std::pow(t, 2) - 2; 
};


int euler(double h, int num_of_t_values) {
	// Sauer - Numerical Analysis 2nd ed. pg. 283
	double val = 0;
	double y_0 = exact_solution_y(val);
	std::cout << "y_0: " << y_0 << std::endl;

	double t[num_of_t_values] = {0.0};
	double w[num_of_t_values] = {0.0};
	double y[num_of_t_values] = {0.0};

	// Generate array of t values
	t[0] = 0.0;
	for (int i = 1; i < num_of_t_values; i++) {
		t[i] = (t[i-1] + h); 	
	};

	// Generate y values
	for (int i = 0; i < num_of_t_values; i++) {
		y[i] = exact_solution_y(t[i]);
	};

	// Euler's Method eq. (6.7)
	w[0] = y_0;
	// The i+1th iteration must be less than num_of_t_values so it does not go out of bounds (undefined)
	for (int i = 0; i + 1 < num_of_t_values; i++) {
		w[i+1] = w[i] + h * f(t[i], w[i]);
	};

	// Calculate errors
	double e[num_of_t_values] = {0.0};
        for (int i = 0; i < num_of_t_values; i++) {
                e[i] = std::abs(y[i] - w[i]);
        };

	// Table
	std::cout << std::setw(10) << "step" << std::setw(10) << "t_i" << std::setw(10) << "w_i" << std::setw(10) << "y_i" << std::setw(10) << "e_i" << std::endl;
	std::cout << std::setfill('-') << std::setw(50) << "" << std::setfill(' ') << std::endl;
	
	for (int i = 0; i < num_of_t_values; i++) {
		std::cout << std::setw(10) << i << std::setw(10) << std::fixed << std::setprecision(1) << t[i] << std::setw(10) << std::fixed << std::setprecision(4) << w[i] << std::setw(10) << y[i] << std::setw(10) << e[i] << std::endl;
	};
	
	std::cout << std::endl;

	return 0;
};


int main() {
	double h = 0.2;
	int num_of_t_values = 6;

	euler(h, num_of_t_values);

	h = 0.1;
	num_of_t_values = 11;

	euler(h, num_of_t_values);

	return 0;
};