#pragma once
#include "MathLib.h"

class ObjectData
{
protected:

	//Object position
	Vector3 position;

	//Object rotation (x,y components)
	Vector2 rotation;

	float angle;

	//Store values if any scaling is required
	float scale;
	
public:
	ObjectData(void);
	~ObjectData(void);

//Accessor functions
	Vector3 getPosition();
	void setPosition(Vector3 &pos);

	Vector2 getRotation();
	void setRotation(Vector3 &rot);

	float getAngle();
	void setAngle(float a);

	float getScale();
	void setScale(float s);
};
