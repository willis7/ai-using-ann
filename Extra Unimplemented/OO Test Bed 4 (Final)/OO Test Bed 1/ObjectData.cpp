#include "ObjectData.h"

ObjectData::ObjectData(void)
{
}

ObjectData::~ObjectData(void)
{
}

Vector3 ObjectData::getPosition()
{
	return position;
}

void ObjectData::setPosition(Vector3 &pos)
{
	position.x = pos.x;
	position.y = pos.x;
	position.z = pos.z;
}

Vector2 ObjectData::getRotation()
{
	return rotation;
}

void ObjectData::setRotation(Vector3 &rot)
{
	rotation.x = rot.x;
	rotation.y = rot.y;
}

float ObjectData::getAngle()
{
	return angle;
}

void ObjectData::setAngle(float a)
{
	angle = a;
}

float ObjectData::getScale()
{
	return scale;
}

void ObjectData::setScale(float s)
{
	scale = s;
}