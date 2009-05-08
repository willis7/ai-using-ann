#pragma once

#include <iostream>
#include "MathUtil.h"

using namespace std;

/*/////////////////////////////////////////////////////////
Vector2: Handles all vectors with x, y co-ordinates
/////////////////////////////////////////////////////////*/
class Vector2
{
public:

	float x,y;

//Constructors

	//Default constructors leaves vector in
	//an intermediate state
	Vector2(){}

	//Copy constructor
	Vector2(const Vector2 &a) : x(a.x), y(a.y){}

	// Construct given three values
	Vector2(float nx, float ny) : x(nx), y(ny){}

//Object maintainance

	//Assignment
	Vector2 &operator = (const Vector2 &a){
		x = a.x; y = a.y;
		return *this;
	}

	// Check for equality
	bool operator ==(const Vector2 &a) const{
		return x==a.x && y==a.y;
	}

	bool operator !=(const Vector2 &a) const{
		return x!=a.x || y!=a.y;
	}

// Vector operations

	// Vector operations
	// Set the vector to zero
	void zero() { x = y = 0.0f; }

	// Unary minus returns the negative of the vector
	Vector2 operator -() const { return Vector2(-x,-y); }

	// Binary + and – add and subtract vectors
	Vector2 operator +(const Vector2 &a) const {
		return Vector2(x + a.x, y + a.y);
	}

	Vector2 operator -(const Vector2 &a) const {
		return Vector2(x - a.x, y - a.y);
	}

	// Multiplication and division by scalar
	Vector2 operator *(float a) const {
		return Vector2(x*a, y*a);
	}

	Vector2 operator /(float a) const {
		float oneOverA = 1.0f / a;
		return Vector2(x*oneOverA, y*oneOverA);
	}

	Vector2 &operator +=(const Vector2 &a) {
		x += a.x; y += a.y;
		return *this;
	}

	Vector2 &operator -=(const Vector2 &a) {
		x -= a.x; y -= a.y;
		return *this;
	}

	Vector2 &operator*=(float a) {
		x *= a; y *= a;
		return *this;
	}

	Vector2 &operator /=(float a) {
		float oneOverA = 1.0f / a;
		x *= oneOverA; y *= oneOverA;
		return *this;
	}

	// Normalize the vector
	void normalize() {
		float magSq = x*x + y*y;
		if (magSq > 0.0f) { // check for divide-by-zero
		float oneOverMag = 1.0f / sqrt(magSq);
		x *= oneOverMag;
		y *= oneOverMag;
		}
	}

	// Vector dot product. Overloaded 
	// multiplication symbol
	float operator *(const Vector2 &a) const {
		return x*a.x + y*a.y;
	}

};

// Compute the length of a vector
inline float vecLength(const Vector2 &a) {
	return sqrt(a.x*a.x + a.y*a.y);
}

// Scalar on the left multiplication, for symmetry
inline Vector2 operator *(float k, const Vector2 &v) {
	return Vector2(k*v.x, k*v.y);
}

// Compute the distance between two points
inline float distance(const Vector2 &a, const Vector2 &b) {
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	return sqrt(dx*dx + dy*dy);
}

/*/////////////////////////////////////////////////////////
Vector3: Handles all vectors with x, y, x co-ordinates
/////////////////////////////////////////////////////////*/
class Vector3
{
public:

	float x,y,z;

//Constructors

	//Default constructors leaves vector in
	//an intermediate state
	Vector3(){}

	//Copy constructor
	Vector3(const Vector3 &a) : x(a.x), y(a.y), z(a.z){}

	// Construct given three values
	Vector3(float nx, float ny, float nz) : x(nx), y(ny), z(nz) {}

//Object maintainance

	//Assignment
	Vector3 &operator = (const Vector3 &a)
	{
		x = a.x; y = a.y; z = a.z;
		return *this;
	}

	// Check for equality
	bool operator ==(const Vector3 &a) const {
		return x==a.x && y==a.y && z==a.z;
	}

	bool operator !=(const Vector3 &a) const 
	{
		return x!=a.x || y!=a.y || z!=a.z;
	}

// Vector operations

	// Vector operations
	// Set the vector to zero
	void zero() { x = y = z = 0.0f; }

	// Unary minus returns the negative of the vector
	Vector3 operator -() const { return Vector3(-x,-y,-z); }

	// Binary + and – add and subtract vectors
	Vector3 operator +(const Vector3 &a) const {
		return Vector3(x + a.x, y + a.y, z + a.z);
	}

	Vector3 operator -(const Vector3 &a) const {
		return Vector3(x - a.x, y - a.y, z - a.z);
	}

	// Multiplication and division by scalar
	Vector3 operator *(float a) const {
		return Vector3(x*a, y*a, z*a);
	}

	Vector3 operator /(float a) const {
		float oneOverA = 1.0f / a;
		return Vector3(x*oneOverA, y*oneOverA, z*oneOverA);
	}

	Vector3 &operator +=(const Vector3 &a) {
		x += a.x; y += a.y; z += a.z;
		return *this;
	}

	Vector3 &operator -=(const Vector3 &a) {
		x -= a.x; y -= a.y; z -= a.z;
		return *this;
	}

	Vector3 &operator*=(float a) {
		x *= a; y *= a; z *= a;
		return *this;
	}

	Vector3 &operator /=(float a) {
		float oneOverA = 1.0f / a;
		x *= oneOverA; y *= oneOverA; z *= oneOverA;
		return *this;
	}

	// Normalize the vector
	void normalize() {
		float magSq = x*x + y*y + z*z;
		if (magSq > 0.0f) { // check for divide-by-zero
		float oneOverMag = 1.0f / sqrt(magSq);
		x *= oneOverMag;
		y *= oneOverMag;
		z *= oneOverMag;
		}
	}

	// Vector dot product. Overloaded 
	// multiplication symbol
	float operator *(const Vector3 &a) const {
		return x*a.x + y*a.y + z*a.z;
	}

};

// Compute the length of a vector
inline float vecLength(const Vector3 &a) {
	return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

// Compute the cross product of two vectors
inline Vector3 crossProd(const Vector3 &a, const Vector3 &b) {
	return Vector3(
		a.y*b.z - a.z*b.y,
		a.z*b.x - a.x*b.z,
		a.x*b.y - a.y*b.x
	);
}

// Scalar on the left multiplication, for symmetry
inline Vector3 operator *(float k, const Vector3 &v) {
	return Vector3(k*v.x, k*v.y, k*v.z);
}

// Compute the distance between two points
inline float distance(const Vector3 &a, const Vector3 &b) {
	float dx = a.x - b.x;
	float dy = a.y - b.y;
	float dz = a.z - b.z;
	return sqrt(dx*dx + dy*dy + dz*dz);
}

// Global zero vector constant
extern const Vector3 kZeroVector;

/*/////////////////////////////////////////////////////////
Matrix4: Handles all 4x4 matrix operations
/////////////////////////////////////////////////////////*/

class Matrix4
{
protected:

	float mat4[16];	

public:

//Constructors

	//Default constructors sets to identity
	Matrix4(void);

	//Copy constructor
	Matrix4(const Matrix4 &matrix);

	//Destructor
	~Matrix4(void){}

//Matrix operations

	//Set to identity & check is identity
	void identity();
	bool isIdentity();

	// Assignment operator
	Matrix4& operator=(const Matrix4 &m);

	// Access index element
	float& operator[](const int index);

	//Matrix multiplication
	Matrix4 operator*(const Matrix4 &m)const;


	//Matrix transformation of 3D vector
	Vector3 operator*(const Vector3 &v) const;

	//Set the translation matrix
	void setTranslation(const Vector3 &t);

	//Set rotation matrix
	void rotateX(int angle);
	void rotateY(int angle);
	void rotateZ(int angle);

	//Set scale matrix
	void setScale(float scale);

//Object maintainance

	//Equality operators
	bool operator == (const Matrix4 &m) const;
	bool operator != (const Matrix4 &m) const;

//Look Ups for Matrix

	//flag to test for instantiation
	static bool tableCreated;

	//storage for look-up tables
	static float SIN_LUT[360];
	static float COS_LUT[360];
	static float IDENTITY[16];

	//Fills the LUT arrays for later use
	void setupLUT();
};
