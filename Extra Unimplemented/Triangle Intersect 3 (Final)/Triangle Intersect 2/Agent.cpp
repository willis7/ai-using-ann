#include "Agent.h"

Agent::Agent(void)
{
	position.zero();
	rotation.zero();
	intersect.zero();

	radius = 30.0f;
	Vector3 vec(0.0, 0.0, 10.0);

	//The lines 2 points are

	temp = vec;
	line.p1 = position;

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

	line.p1 = position;
}

void Agent::moveDown()
{
	//Convert from deg to rad for math.h
	float yRad;
	yRad = degToRad(rotation.y);

	//Calculate the new positions based on current rotations
	position.x -= float(sin(yRad));
	position.z += float(cos(yRad));

	line.p1 = position;
}

void Agent::moveLeft()
{
	//Rotate about y axis
	rotation.y -= 4;
}

void Agent::moveRight()
{
	//Rotate about y axis
	rotation.y += 4;
}

void Agent::update()
{
	glTranslatef(0.0,0.0, -radius);			//Translate away from vehicle
	glRotatef(45,1.0,0.0,0.0);				//Rotate camera to a bird eye view

	glColor3f(0.0f, 1.0f, 1.0f);

	glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 10.0);
	glEnd();

	//Here I am trying to apply the theory Trurl mentioned in his post.
	//Track the car's model matrix and use that
	transform.identity();											
	transform.setTranslation(Vector3((position.x),0.0f,(position.z)));
	transform.rotateY(rotation.y);
	

	//These are the new points based on the stored transforms
	line.p0 = transform * temp;			

	glRotatef(rotation.y,0.0,1.0,0.0);				//rotate our camera on the y-axis (up and down)
	glTranslatef(-(position.x),0.0f,-(position.z));		//translate the screen to the position of our agent
}

float Agent::intersect3DSegmentPlane(Plane p)
{
	Vector3 u = line.p1 - line.p0;
	Vector3 w = p.point - line.p0;

	float d = p.normal * u;
	float n = p.normal * w;


	//They are not parallel
	//Compute intersect param

	float sI = n/d;

	if(sI < 0 || sI > 1)
		return 0;
	else
		return 1.0 - sI; //To get a value of intersection

	
}
