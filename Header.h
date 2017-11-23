#pragma once

#include <iostream>
#include <vector>
#include <initializer_list>
#include <cmath>
#include <random>
#include <functional>
#include <chrono>
#include <tuple>

using namespace std;

using topologie = std::initializer_list<int>;

enum class activationMethodchoosen { tanh_sigmoid, eins_durch_ehoch, no_formula }; // Attention, it always needs an activation method, 

inline void eins_durch_ehoch(double * p_val);

double normalizationfunction1(double p_v_orig,
	double A_max = 1.0,//  6000.0;
	double A_min = 0.0,// 500.0;
	double new_A_max = 1.0,
	double new_A_min = 0.0);



double denormalizationfunction1(double p_v_orig,
	double A_max = 1.0,//  6000.0;
	double A_min = 0.0,// 500.0;
	double new_A_max = 1.0,
	double new_A_min = 0.0);

