#include "Layer.h"

//Create a layer of neurons of the required size by calling the Neuron constructor
//the required number of times
Layer::Layer(int numNeuron, int numInputsPerNeuron)
{
	numNeurons = numNeuron;

	for (int i = 0; i < numNeurons; i++)
	{
		vecNeurons.push_back(Neuron(numInputsPerNeuron));
	}
}


