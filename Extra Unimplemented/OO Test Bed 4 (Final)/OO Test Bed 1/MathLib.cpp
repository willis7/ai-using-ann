#include "MathLib.h"


//Singleton
bool Matrix4::tableCreated = false;
float Matrix4::SIN_LUT[360];
float Matrix4::COS_LUT[360];
float Matrix4::IDENTITY[16] ={1.0, 0.0, 0.0, 0.0,
							0.0, 1.0, 0.0, 0.0,
							0.0, 0.0, 1.0, 0.0,
							0.0, 0.0, 0.0, 1.0};

///////////////////////////////////////////////////
Matrix4::Matrix4(void)
{
	identity();
	setupLUT();	
}

Matrix4::Matrix4(const Matrix4 &matrix)
{
	(*this) = matrix;
}

//////////////////////////////////////////////////
void Matrix4::identity()
{

	mat4[0] = 1.0;	mat4[4] = 0.0;	mat4[8] = 0.0;  mat4[12] = 0.0;
	mat4[1] = 0.0;	mat4[5] = 1.0;	mat4[9] = 0.0;	mat4[13] = 0.0;
	mat4[2] = 0.0;	mat4[6] = 0.0;	mat4[10] = 1.0;	mat4[14] = 0.0;
	mat4[3] = 0.0;	mat4[7] = 0.0;	mat4[11] = 0.0;	mat4[15] = 1.0;

}

bool Matrix4::isIdentity()
{
	return !memcmp(mat4,IDENTITY,16*sizeof(float));
}

Matrix4& Matrix4::operator =(const Matrix4 &m)
{
	memcpy(mat4,m.mat4,sizeof(mat4));
	return *this;
}

float& Matrix4::operator [](const int index)
{
	return mat4[index];
}

Matrix4 Matrix4::operator *(const Matrix4 &m) const
{
	Matrix4 temp;

	temp[0] = (mat4[0]*m.mat4[0])+(mat4[4]*m.mat4[1])+(mat4[8]*m.mat4[2])+(mat4[12]*m.mat4[3]);
	temp[1] = (mat4[1]*m.mat4[0])+(mat4[5]*m.mat4[1])+(mat4[9]*m.mat4[2])+(mat4[13]*m.mat4[3]);
	temp[2] = (mat4[2]*m.mat4[0])+(mat4[6]*m.mat4[1])+(mat4[10]*m.mat4[2])+(mat4[14]*m.mat4[3]);
	temp[3] = (mat4[3]*m.mat4[0])+(mat4[7]*m.mat4[1])+(mat4[11]*m.mat4[2])+(mat4[15]*m.mat4[3]);

	temp[4] = (mat4[0]*m.mat4[4])+(mat4[4]*m.mat4[5])+(mat4[8]*m.mat4[6])+(mat4[12]*m.mat4[7]);
	temp[5] = (mat4[1]*m.mat4[4])+(mat4[5]*m.mat4[5])+(mat4[9]*m.mat4[6])+(mat4[13]*m.mat4[7]);
	temp[6] = (mat4[2]*m.mat4[4])+(mat4[6]*m.mat4[5])+(mat4[10]*m.mat4[6])+(mat4[14]*m.mat4[7]);
	temp[7] = (mat4[3]*m.mat4[4])+(mat4[7]*m.mat4[5])+(mat4[11]*m.mat4[6])+(mat4[15]*m.mat4[7]);

	temp[8] = (mat4[0]*m.mat4[8])+(mat4[4]*m.mat4[9])+(mat4[8]*m.mat4[10])+(mat4[12]*m.mat4[11]);
	temp[9] = (mat4[1]*m.mat4[8])+(mat4[5]*m.mat4[9])+(mat4[9]*m.mat4[10])+(mat4[13]*m.mat4[11]);
	temp[10] = (mat4[2]*m.mat4[8])+(mat4[6]*m.mat4[9])+(mat4[10]*m.mat4[10])+(mat4[14]*m.mat4[11]);
	temp[11] = (mat4[3]*m.mat4[8])+(mat4[7]*m.mat4[9])+(mat4[11]*m.mat4[10])+(mat4[15]*m.mat4[11]);

	temp[12] = (mat4[0]*m.mat4[12])+(mat4[4]*m.mat4[13])+(mat4[8]*m.mat4[14])+(mat4[12]*m.mat4[15]);
	temp[13] = (mat4[1]*m.mat4[12])+(mat4[5]*m.mat4[13])+(mat4[9]*m.mat4[14])+(mat4[13]*m.mat4[15]);
	temp[14] = (mat4[2]*m.mat4[12])+(mat4[6]*m.mat4[13])+(mat4[10]*m.mat4[14])+(mat4[14]*m.mat4[15]);
	temp[15] = (mat4[3]*m.mat4[12])+(mat4[7]*m.mat4[13])+(mat4[11]*m.mat4[14])+(mat4[15]*m.mat4[15]);

	return temp;

}

Vector3 Matrix4::operator *(const Vector3 &v) const
{
	Vector3 temp;

	temp.x = (mat4[0]*v.x)+(mat4[4]*v.y)+(mat4[8]*v.z)+(mat4[12]*1);
	temp.y = (mat4[1]*v.x)+(mat4[5]*v.y)+(mat4[9]*v.z)+(mat4[13]*1);
	temp.z = (mat4[2]*v.x)+(mat4[6]*v.y)+(mat4[10]*v.z)+(mat4[14]*1);

	return temp;

}

void Matrix4::setTranslation(const Vector3 &t)
{
	mat4[12] = t.x;
	mat4[13] = t.y;
	mat4[14] = t.z;
}

void Matrix4::rotateX(int a)
{
	mat4[5] = COS_LUT[a];
	mat4[6] = SIN_LUT[a];
	mat4[9] = -SIN_LUT[a];
	mat4[10] = COS_LUT[a];	
}

void Matrix4::rotateY(int a)
{
	mat4[0] = COS_LUT[a];
	mat4[2] = -SIN_LUT[a];
	mat4[8] = SIN_LUT[a];
	mat4[10] = COS_LUT[a];	
}

void Matrix4::rotateZ(int a)
{
	mat4[0] = COS_LUT[a];
	mat4[1] = SIN_LUT[a];
	mat4[4] = -SIN_LUT[a];
	mat4[5] = COS_LUT[a];	
}

void Matrix4::setScale(float s)
{
	mat4[0] = s;
	mat4[5] = s;
	mat4[10] = s;
}

/////////////////////////////////////////////////
bool Matrix4::operator ==(const Matrix4 &m) const
{
	return !memcmp(mat4, m.mat4, 16*sizeof(mat4));
}

bool Matrix4::operator !=(const Matrix4 &m) const
{
	return memcmp(mat4, m.mat4, 16*sizeof(mat4))!= 0;
}

////////////////////////////////////////////////
void Matrix4::setupLUT()
{
	if(!tableCreated){
		// create look-up table
		for (int angle=0; angle < 360; angle++)
		{
			// convert angle to radians since math library uses
			// rads instead of degrees
			// there are 2*pi rads in 360 degrees
			float radAngle = degToRad(angle);

			SIN_LUT[angle] = sin((float) radAngle); //working in degrees
			COS_LUT[angle] = cos((float) radAngle);
		
		} // end for angle   

		tableCreated=1;
	  }
}
