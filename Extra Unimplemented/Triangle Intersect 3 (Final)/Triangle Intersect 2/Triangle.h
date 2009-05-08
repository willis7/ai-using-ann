#pragma once
#include "MathLib.h"
#include <GL/glut.h>

class Triangle
{
public:
	Triangle(void);
	~Triangle(void);

	Vector3 v1;
	Vector3 v2;
	Vector3 v3;

	Vector3 norm;

	Plane p1;


//Funtions

	Vector3 triangleNormal(Vector3 &v1, Vector3 &v2, Vector3 &v3);

	void draw();
};
