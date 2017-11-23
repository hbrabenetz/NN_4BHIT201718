#pragma once

#include "Header.h"

class N {
public:

	N(std::initializer_list<int>& t, double LearnRate = 0.9, activationMethodchoosen act_method_received = activationMethodchoosen::eins_durch_ehoch, std::tuple<double, double, double, double> nP = { 1.0, 0.0, 1.0, 0.0 });

	std::vector<int> top;
	double LearnRate;
	activationMethodchoosen act_method;
	std::tuple<double, double, double, double> normalizationParam;
	double A_max, A_min, new_A_max, new_A_min;
	void   norm  (double& p_v_orig); // Normalization function
	double denorm(double& p_v_norm); // Denormalization function

	void(*p_activationfunction)(double * val);

	double ** nod;
	double ** err;
	double *** wij;
	double * tru; // true Values
	double * den; // denormalized result of calc, only returned on demand

	int Nlay;
	int Nnod;
	int Nwij;

	void calc();
	double* getCalcRes();

	~N();

};

