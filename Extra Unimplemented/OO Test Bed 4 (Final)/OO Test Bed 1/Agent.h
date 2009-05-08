#pragma once
#include "Objectdata.h"
#include "Model.h"

class Agent :	public ObjectData
{
private:

	//Camera distance from object
	float radius;

	// .obj model 
	Model model;

public:

	Agent(void);
	~Agent(void);

//Movement of the object

	void moveUp();

	void moveDown();

	void moveLeft();

	void moveRight();

//Update camera position

	void update();
};
