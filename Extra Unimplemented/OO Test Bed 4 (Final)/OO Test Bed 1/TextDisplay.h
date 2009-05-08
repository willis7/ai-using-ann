#pragma once
/*/////////////////////////////////////////////////////////
Text Display: small lib for displaying text in OpenGL
/////////////////////////////////////////////////////////*/

// Display Text string
void renderBitmapString(float x, float y,char *text)
{  
	int i=0;	
	glRasterPos2i(x,y);

	while(text[i]) 
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10,text[i]);
		++i;
	}
}

// Set/Reset Ortho
void setOrthographicProjection(int w, int h) 
{
	glMatrixMode(GL_PROJECTION);
	// save previous matrix which contains the 
	//settings for the perspective projection
	glPushMatrix();
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	// invert the y axis, down is positive
	glScalef(1, -1, 1);
	glTranslatef(0, -h, 0);
	glMatrixMode(GL_MODELVIEW);
}

void resetPerspectiveProjection() 
{
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
}