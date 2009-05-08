#include "Agent.h"

Agent::Agent(void)
{
	position.zero();
	rotation.zero();

	radius = 60.0f;

	model.loadModel("Asset/Hyundai Coupe3.obj");
	model.loadTexture("Asset\UV1024.bmp");
}

Agent::~Agent(void)
{
}

void Agent::moveUp()
{
	//Convert from deg to rad for math.h
	float yRad;
	yRad = degToRad(rotation.y);

	//Calculate the new positions based on current rotations
	position.x += float(sin(yRad));
	position.z -= float(cos(yRad));
}

void Agent::moveDown()
{
	//Convert from deg to rad for math.h
	float yRad;
	yRad = degToRad(rotation.y);

	//Calculate the new positions based on current rotations
	position.x -= float(sin(yRad));
	position.z += float(cos(yRad));
}

void Agent::moveLeft()
{
	//Rotate about y axis
	rotation.y -= 1.5;
}

void Agent::moveRight()
{
	//Rotate about y axis
	rotation.y += 1.5;
}

void Agent::update()
{
	glTranslatef(0.0,0.0, -radius);			//Translate away from vehicle
	glRotatef(65,1.0,0.0,0.0);				//Rotate camera to a bird eye view
	glColor3f(1.0f, 0.0f, 0.0f);
	model.draw();

	glRotatef(rotation.y,0.0,1.0,0.0);				//rotate our camera on the y-axis (up and down)
	glTranslatef(-(position.x),0.0f,-(position.z));		//translate the screen to the position of our camera
}

