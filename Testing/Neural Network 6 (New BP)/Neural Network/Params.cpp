#include "Params.h"

//because we will always be loading in the settings from an ini file
//just initialize everything to zero
int Params::iNumInputs             = 0;
int Params::iNumHidden             = 0;
int Params::iNeuronsPerHiddenLayer = 0;
int Params::iNumOutputs            = 0;
double Params::dActivationResponse = 0;
double Params::dLearningRate	   = 0;
double Params::dBias               = 0;

//this function loads in the parameters from a given file name. Returns
//false if there is a problem opening the file.
bool Params::loadInParameters(char* fileName)
{
	ifstream grab(fileName);

	//check file exists
	if (!grab)
	{
		return false;
	}

	//load in from the file
	char ParamDescription[40];

	grab >> ParamDescription;
	grab >> iNumInputs;
	grab >> ParamDescription;
	grab >> iNumHidden;
	grab >> ParamDescription;
	grab >> iNeuronsPerHiddenLayer;
	grab >> ParamDescription;
	grab >> iNumOutputs;
	grab >> ParamDescription;
	grab >> dActivationResponse;
	grab >> ParamDescription;
	grab >> dLearningRate;
	grab >> ParamDescription;
	grab >> dBias;

	return true;
}

