#pragma once
#include "Layer.h"
#include <math.h>


class NN
{
private:

	double activationResponse;
	double learningRate;

	//Network architecture
	int numInputs;
	int numOutputs;
	int numHiddenLayers;
	int neuronsPerHidden;

	// stores all of the layers in the NN including the output layer
	vector<Layer> vecLayers;

	//Activations	
	vector<double> inputs; //Values given as inputs
	vector<double> hiddenOutput; //Output of hidden neuron
	vector<double> actualOutput; //Values provided by the NN

	//Store the errors
	vector<double> errorOutput;
	vector<double> errorHidden;


public:
	NN();

	void createNet();

	//gets the weights from the NN
	vector<double> getWeights() const;

	//returns total number of weights in net
	int getNumOfWeights();

	//calculates the outputs from a set of inputs
	void putWeights(vector<double> &weights);

	//calculates the outputs from a set of inputs
	vector<double> update(vector<double> &inputs);

	//sigmoid response curve
	double sigmoid(double sigInput);

	//implements the derivative of the sigmoid function and is used during error backpropagation
	double sigmoidDerivative(double sigInput);

	//this function outlines the method described in the methodology
	float backprop(vector<double> &target);

	//Import and export weights
	void writeWeights();
};
