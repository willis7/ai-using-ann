#include "NN.h"

//Create a NN based on the values set below
NN::NN()
{
	numInputs = Params::iNumInputs;
	numOutputs = Params::iNumOutputs;
	numHiddenLayers = Params::iNumHidden;
	neuronsPerHidden = Params::iNeuronsPerHiddenLayer;
	activationResponse = Params::dActivationResponse;
	learningRate = Params::dLearningRate;

	createNet();
}

//Creates a NN with weights initially set between -1 and 1
void NN::createNet()
{
	//create the layers of the network
	if(numHiddenLayers > 0)
	{
		//Push first hidden layer
		vecLayers.push_back(Layer(neuronsPerHidden, numInputs));

		//Push every additional layer
		//If only one hidden this will be missed
		for( int i = 0; i < numHiddenLayers - 1; i++)
		{
			//Layer(int numNeuron, int numInputsPerNeuron)
			vecLayers.push_back(Layer(neuronsPerHidden, neuronsPerHidden));
		}

		//Create ouput layer
		vecLayers.push_back(Layer(numOutputs, neuronsPerHidden));

	}
	else
	{
		//If no hidden layers, create output layer
		vecLayers.push_back(Layer(numOutputs, neuronsPerHidden));
	}
}

vector<double> NN::getWeights() const
{
	//temp store for weights
	vector<double> weights;
	
	//for each layer
	for (int i = 0; i < numHiddenLayers + 1; ++i)
	{

		//for each neuron
		for (int j = 0; j < vecLayers[i].numNeurons; ++j)
		{
			//for each weight
			for (int k = 0; k < vecLayers[i].vecNeurons[j].numInputs; ++k)
			{
				weights.push_back(vecLayers[i].vecNeurons[j].vecWeights[k]);
			}
		}
	}

	return weights;
}

//Given a vector of doubles this function replaces the weights in the NN
//with the new values
void NN::putWeights(vector<double> &weights)
{
	int weight = 0;

	//for each layer
	for (int i = 0; i < numHiddenLayers + 1; ++i)
	{
		//for each neuron
		for (int j = 0; j < vecLayers[i].numNeurons; ++j)
		{
			//for each weight
			for (int k = 0; k < vecLayers[i].vecNeurons[j].numInputs; ++k)
			{
				vecLayers[i].vecNeurons[j].vecWeights[k] = weights[weight++];
			}
		}
	}
	return;
}

//Returns the total number of weights needed for the net
int NN::getNumOfWeights()
{
	int weights = 0;

	//for each layer
	for (int i = 0; i < numHiddenLayers + 1; ++i)
	{

		//for each neuron
		for (int j = 0; j < vecLayers[i].numNeurons; ++j)
		{
			//for each weight
			for (int k = 0; k < vecLayers[i].vecNeurons[j].numInputs; ++k)
			{
				weights++;
			}
		}
	}
	return weights;
}

//Given an input vector this function calculates the output vector
vector<double> NN::update(vector<double> &i)
{
	actualOutput.clear();
	hiddenOutput.clear();
	inputs.clear();

	for( int z = 0; z < numInputs; z++)
	{
		inputs.push_back(i[z]);
	}	
		
	//Get the weights
	vector<double> weights;
	weights = getWeights();

	double sum;

	int indx = 0;
	//Calculate the input to hidden layer
	for(int hid = 0; hid < neuronsPerHidden; hid++)
	{
		sum = 0.0;

		for(int inp = 0; inp < numInputs; inp++)
		{
			sum += inputs[inp] * weights[indx];
			indx ++;
		}

		//Add in the Bias
		sum += weights[indx];
		indx ++;

		hiddenOutput.push_back(sigmoid(sum));
	}

	//Calculate the hidden to output layer
	for(int out = 0; out < numOutputs; out++)
	{
		sum = 0.0;

		for( int hid = 0; hid < neuronsPerHidden; hid++)
		{
			sum += hiddenOutput[hid] * weights[indx];
			indx++;
		}

		//Add in bias
		sum += weights[indx];
		indx++;

		actualOutput.push_back(sigmoid(sum));

	}

	return actualOutput;
}


double NN::sigmoid(double sigInput)
{
	//Returns a value between 0..1 this curve is always centred around 0.5. 
	//Negative activation values produce a result less than 0.5, positive activation values produce a result greater than 0.5.
	return( 1.0 / ( 1.0 + exp(-sigInput)));
}

double NN::sigmoidDerivative(double sigInput)
{
	return( sigInput * (1.0 - sigInput) );

}
float NN::backprop(vector<double> &target)
{
	errorOutput.clear();

///////////////////////////////////////////////////		
	//Calculate output layer error
///////////////////////////////////////////////////

	for(int out = 0; out <  numOutputs; out++)
	{
		errorOutput.push_back((target[out] - actualOutput[out]) * sigmoidDerivative(actualOutput[out]));
	}

///////////////////////////////////////////////////
	//Calculate the hidden layer error	
///////////////////////////////////////////////////

	vector<double> weights;

	weights = getWeights();	

	int indx = (numInputs +1) * neuronsPerHidden;
	
	for( int hid = 0; hid < neuronsPerHidden; hid++)
	{
		errorHidden.push_back(0.0);

		for( int out = 0; out < numOutputs; out++)
		{
			errorHidden[hid] += errorOutput[out] * weights[indx + hid];
		}
		errorHidden[hid] *= sigmoidDerivative(hiddenOutput[hid]);
	}
///////////////////////////////////////////////////
	//Update the hidden to output weights
///////////////////////////////////////////////////
	indx = (numInputs +1) * neuronsPerHidden;

	for(int out = 0; out < numOutputs; out++)
	{
		for( int hid = 0; hid < neuronsPerHidden; hid++)
		{
			weights[indx + hid] += (learningRate * errorOutput[out] * errorHidden[hid]);
		}

		//Update the bias
		int i = weights.size() - 1;
		weights[i] += (learningRate * errorOutput[out]);
		
	}

///////////////////////////////////////////////////
	//Update the input to hidden weights
///////////////////////////////////////////////////

	indx = 0;
	int b = 2;
	for( int hid = 0; hid < neuronsPerHidden; hid++)
	{
		for(int inp = 0; inp < numInputs; inp++)
		{
			indx = inp;

			weights[indx + hid] += (learningRate * errorHidden[hid] * inputs[inp]);
			
		}
		indx ++;

		//Update the input Bias
		
		weights[b] += (learningRate * errorHidden[hid]);

		b += 3;
	}

	//Update the network with the newly calculated weights
	putWeights(weights);	

	return target[0] - actualOutput[0];
}

void NN::writeWeights()
{
	FILE* fWeights;
	fWeights = fopen("Weights.csv", "w");

	//temp store for weights
	vector<double> weights;

	weights = getWeights();

	for(int i = 0; i < getNumOfWeights(); i++)
	{
		fprintf(fWeights,"%f", weights[i]);
		fprintf(fWeights,"%s\n", "");
	}
}