#pragma once
#include "Objectdata.h"
#include <gl/glut.h>

#define SMALL_NUM	0.00000001	//Avoid division overflow

typedef struct
{
	Vector3 p0;
	Vector3 p1;
}Segment;

class Agent :	public ObjectData
{
private:

	//Camera distance from object
	float radius;

	Segment line;

	Vector3 temp;

	Vector3 intersect;

	Matrix4 transform;

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

//Establish feeler intersection
	//Returns 0 for no intersection [0.001...1] for intersection
	float intersect3DSegmentPlane(Plane p);

};
