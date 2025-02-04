#include "Ran.h"


int Ran::ranInt(int min, int max) {
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_int_distribution dist(min, max);

	return dist(eng);
}


double Ran::ranDouble(double min, double max) {
	std::random_device rd;
	std::default_random_engine eng(rd());
	std::uniform_real_distribution<double> dist(min, max);

	return dist(eng);
}