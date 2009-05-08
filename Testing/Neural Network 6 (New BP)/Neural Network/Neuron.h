#pragma once
#include <vector>
#include "Params.h"
using namespace std;



class Neuron
{
public:

	//Constructor - take number of inputs
	Neuron(int numIn);

	//Record of number of inputs into each neuron
	int numInputs;

	//weights for each input
	vector<double> vecWeights;

	
};

//Return random value between 0 and 1
inline double randFloat()	{return ((float)rand()/((float)RAND_MAX) -0.5);}

//returns a random float in the range -1 < n < 1
inline double randomClamped()	{return randFloat() - randFloat();}