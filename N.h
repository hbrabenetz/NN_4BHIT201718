#pragma once

#include "Header.h"

class N {
public:

	N(std::initializer_list<int>& t, double LearnRate = 0.9, activationMethodchoosen act_method_received = activationMethodchoosen::eins_durch_ehoch, std::tuple<double, double, double, double> nP = { 1.0, 0.0, 1.0, 0.0 });

	std::vector<int> top;
	double LearnRate;
	activationMethodchoosen act_method;
	std::tuple<double, double, double, double> normalizationParam;

	void(*p_activationfunction)(double * val);

	double ** nod;
	double ** err;
	double *** wij;
	double * tru; // true Values

	int Nlay;
	int Nnod;
	int Nwij;

	double calc();

	~N();

};

