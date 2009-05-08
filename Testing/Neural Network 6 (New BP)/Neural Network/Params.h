#pragma once
#include <fstream>
#include <windows.h>
using namespace std;

class Params
{
public:
    static int iNumInputs;
    static int iNumHidden;
    static int iNeuronsPerHiddenLayer;
    static int iNumOutputs;
    static double dActivationResponse;
	static double dLearningRate;
    static double dBias;
   

	Params()
	{
		if(!loadInParameters("params.ini"))
		{
		  printf("Error loading params.ini");
		}
	}
	
	bool loadInParameters(char* fileName);
};

