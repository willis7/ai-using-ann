#include "Triangle.h"

Triangle::Triangle(void)
{
	Vector3 vt1(-10.0, -1.0, -30.0);
	Vector3 vt2(10.0, -1.0, -30.0);
	Vector3 vt3(0.0, 10.0, -30.0);

	v1 = vt1;
	v2 = vt2;
	v3 = vt3;

	norm = triangleNormal(v1, v2, v3);

	p1.normal = norm;
	p1.point = v1;
}

Triangle::~Triangle(void)
{
}

void Triangle::draw()
{
	glBegin(GL_TRIANGLES);
		glVertex3f(v1.x, v1.y, v1.z);
		glVertex3f(v2.x, v2.y, v2.z);
		glVertex3f(v3.x, v3.y, v3.z);
	glEnd();

}

//Establish the surface normal of a triangle
//used later on in the calculation of intersections
Vector3 Triangle::triangleNormal(Vector3 &v1, Vector3 &v2, Vector3 &v3)
{
	Vector3 normal;
	Vector3 vec1;
	Vector3 vec2;

	vec1 = v2 - v1;
	vec2 = v3 - v1;

	normal = crossProd(vec1, vec2);

	//normal.normalize();

	return normal;
}