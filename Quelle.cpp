

#include "N.h" 


int main() {

	N n{ topologie{ 2,3,1 }, 0.9, activationMethodchoosen::eins_durch_ehoch, {1.0, 0.0, 1.0, 0.0} };
	
	auto [Max, Min, max, min] = n.normalizationParam;










	auto nor = std::bind(normalizationfunction1, std::placeholders::_1, 1.0, 0.0, 1.0, 0.0);
	auto den = std::bind(denormalizationfunction1, std::placeholders::_1, 1.0, 0.0, 1.0, 0.0);

	// or on the heap
	// N* pn = new N{ topologie{ 2,3,1 }, 0.9, activationMethodchoosen::eins_durch_ehoch };
	// which requires pn->nod[0][0]

	std::chrono::high_resolution_clock::time_point timex;
	std::chrono::nanoseconds elapsed;
	// � 1 sec == 1 000 000 000 Nanosekunden

	timex = std::chrono::high_resolution_clock::now();
	if (1) // proper sequence for teaching
		for (int it = 0; it < 1000; ++it) {
			n.nod[0][0] = nor(0.0);
			n.nod[0][1] = nor(0.0);
			n.tru[0] = nor(0.0);
			n.calc();
			n.nod[0][0] = nor(0.0);
			n.nod[0][1] = nor(1.0);
			n.tru[0] = nor(1.0);
			n.calc();
			n.nod[0][0] = nor(1.0);
			n.nod[0][1] = nor(0.0);
			n.tru[0] = nor(1.0);
			n.calc();
			n.nod[0][0] = nor(1.0);
			n.nod[0][1] = nor(1.0);
			n.tru[0] = nor(0.0);
			n.calc();
		}
	elapsed = std::chrono::high_resolution_clock::now() - timex;


	if (1) {
		cout << "Ergebnis:" << endl;
		n.nod[0][0] = nor(0.0);
		n.nod[0][1] = nor(0.0);
		n.tru[0] = nor(0.0);
		cout << den(n.nod[0][0]) << den(n.nod[0][1]) << " -> " << den(n.tru[0]) << " return = " << den(n.calc()) << endl;
		n.nod[0][0] = 0.0;
		n.nod[0][1] = 1.0;
		n.tru[0] = 1.0;
		cout << den(n.nod[0][0]) << den(n.nod[0][1]) << " -> " << den(n.tru[0]) << " return = " << den(n.calc()) << endl;
		n.nod[0][0] = 1.0;
		n.nod[0][1] = 0.0;
		n.tru[0] = 1.0;
		cout << den(n.nod[0][0]) << den(n.nod[0][1]) << " -> " << den(n.tru[0]) << " return = " << den(n.calc()) << endl;
		n.nod[0][0] = 1.0;
		n.nod[0][1] = 1.0;
		n.tru[0] = 0.0;
		cout << den(n.nod[0][0]) << den(n.nod[0][1]) << " -> " << den(n.tru[0]) << " return = " << den(n.calc()) << endl;
	}

	std::cout << "Elapsed time in seconds = " << elapsed.count() / 1000000000.0 << std::endl;


	getchar();
	return 0;
}