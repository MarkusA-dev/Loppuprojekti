#ifndef RANDGEN_H
#define RANDGEN_H

#include <random>

static int randGen(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> distrib(min, max);
	return distrib(gen);
}

#endif