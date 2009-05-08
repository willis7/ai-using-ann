#include "NN.h"
#include "csvparser.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

#define sqr(x)	((x)*(x))

#define TEST	1000

Params parameters;
NN theBrain;


void main(void)
{
	//Inputs
	vector<double> input;

	//Outputs
	vector<double> actual;
	vector<double> expected;

/////////////////////////////////Load Training Data/////////////////

	ifstream infile("training.csv");
	string sLine;
	double dCol1, dCol2, dCol3;

	CSVParser parser;

	while (!infile.eof()) 
	{
		getline(infile, sLine); // Get a line
		if (sLine == "")
		  continue;

		parser << sLine; // Feed the line to the parser

		parser >> dCol1 >> dCol2 >> dCol3;

		input.push_back(dCol1);			//Left feeler
		input.push_back(dCol2);			//Right feeler
		expected.push_back(dCol3);		//Expected output
	}
	infile.close();

/////////////////////////////////Load Test weights/////////////////

	//Store for test weights
	vector<double> tWeights;

	//"TestingWeights3" for 3 hidden nodes, "TestingWeights6" for 6 hidden
	ifstream ifile("TestingWeights6.csv");

	while (!ifile.eof()) 
	{
		getline(ifile, sLine); // Get a line
		if (sLine == "")
		  continue;

		parser << sLine; // Feed the line to the parser

		parser >> dCol1;

		tWeights.push_back(dCol1);			//Left feeler

	}
	ifile.close();

	theBrain.putWeights(tWeights);
	tWeights.clear();
	tWeights = theBrain.getWeights();

//////////////////Run the training data throught the NN ////////////

	//How many training pairs
	int sExpect = expected.size();

	//Test output file
	FILE* fError;
	fError = fopen("Error.csv", "w");

	float totError;	//Stores accumilative error
	float output;	//Stores MSE
	int count = 0;		//Counter for test output

	for(int epoch = 0; epoch < TEST; epoch++)
	{

		totError = 0.0f;
		for( int i = 0; i < sExpect; i++)
		{
			//Feed forward
			actual = theBrain.update(input);	
			totError += sqr(theBrain.backprop(expected));
		
			//Move to next training set
			input.push_back(input[0]);
			input.erase(input.begin());	//Remove left input

			input.push_back(input[0]);
			input.erase(input.begin());	//Remove right input

			expected.push_back(expected[0]);
			expected.erase(expected.begin());	//Remove output

			
		}
		count++;

		//Print every 10th output to file
		if(count == 10)
		{
			output = 0.5 * totError;
			fprintf(fError,"%f", output);
			fprintf(fError,"%s\n", "");

			count = 0;
		}
			
	}

//////////////////Test the NN with test inputs ////////////

	FILE* fTests;
	fTests = fopen("Tests.csv", "w");

//Test 1
	input.clear();
	input.push_back(0);
	input.push_back(0.3);

	actual = theBrain.update(input);
	cout << actual[0] << endl;
	fprintf(fTests,"%f", actual[0]);
	fprintf(fTests,"%s\n", "");

	input.erase(input.begin());	
	input.erase(input.begin());

//Test 2
	input.push_back(0);
	input.push_back(0.5);

	actual = theBrain.update(input);
	cout << actual[0] << endl;
	fprintf(fTests,"%f", actual[0]);
	fprintf(fTests,"%s\n", "");

	input.erase(input.begin());	
	input.erase(input.begin());	

//Test 3
	input.push_back(0);
	input.push_back(0.7);

	actual = theBrain.update(input);
	cout << actual[0] << endl;
	fprintf(fTests,"%f", actual[0]);
	fprintf(fTests,"%s\n", "");

	input.erase(input.begin());
	input.erase(input.begin());	

//Test 4
	input.push_back(0);
	input.push_back(0.9);

	actual = theBrain.update(input);
	cout << actual[0] << endl;
	fprintf(fTests,"%f", actual[0]);
	fprintf(fTests,"%s\n", "");

	input.erase(input.begin());
	input.erase(input.begin());	

//Test 5
	input.push_back(0.3);
	input.push_back(0);

	actual = theBrain.update(input);
	cout << actual[0] << endl;
	fprintf(fTests,"%f", actual[0]);
	fprintf(fTests,"%s\n", "");

	input.erase(input.begin());	
	input.erase(input.begin());	

//Test 6
	input.push_back(0.5);
	input.push_back(0);

	actual = theBrain.update(input);
	cout << actual[0] << endl;
	fprintf(fTests,"%f", actual[0]);
	fprintf(fTests,"%s\n", "");
	
	input.erase(input.begin());	
	input.erase(input.begin());	

//Test 7
	input.push_back(0.7);
	input.push_back(0);

	actual = theBrain.update(input);
	cout << actual[0] << endl;
	fprintf(fTests,"%f", actual[0]);
	fprintf(fTests,"%s\n", "");

	input.erase(input.begin());	//Remove left input
	input.erase(input.begin());	//Remove right input

//Test 8
	input.push_back(0.9);
	input.push_back(0);

	actual = theBrain.update(input);
	cout << actual[0] << endl;
	fprintf(fTests,"%f", actual[0]);
	fprintf(fTests,"%s\n", "");
}