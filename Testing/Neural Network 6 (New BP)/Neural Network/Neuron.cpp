#include "Neuron.h"
#include <time.h>
#include <stdlib.h>

Neuron::Neuron(int numIn):numInputs(numIn +1)
{
	//srand((unsigned int)time(0));


	//for(int i=0; i<numIn + 1; i++)
	for(int i=0; i<numIn; i++)
	{
		//set up weights with initial random value
		vecWeights.push_back(randFloat());
	}

	vecWeights.push_back(Params::dBias);
}

