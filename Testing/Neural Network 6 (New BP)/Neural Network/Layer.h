#pragma once
#include "Neuron.h"

class Layer
{
public:
	Layer(int numNeuron, int numInputsPerNeuron);

	//the number of neurons in this layer
	int numNeurons;

	//the layer of neurons
	vector<Neuron> vecNeurons;

};
