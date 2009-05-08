#include "Agent.h"
#include "Keyboard.h"
#include "Triangle.h"
#include "TextDisplay.h"

//Window Properties
static int h=480,w=640;

// Create instance of agent
Agent Car;
Triangle test;

float t;
Vector3 test1;
char s[30];

/*/////////////////////////////////////////////////////////
OGL: Handles all of the OpenGL windowing, resizing, keypresses etc.
/////////////////////////////////////////////////////////*/

void OnReshape(int w, int h)
{
	glViewport (0, 0, (GLsizei)w, (GLsizei)h);	//set the viewport to the current window specifications
	glMatrixMode (GL_PROJECTION);				//set the matrix to projection
	glLoadIdentity ();
	gluPerspective (60,							//field of view
					(GLfloat)w / (GLfloat)h,	//aspect ratio
					0.1, 100.0);				//near & far
	glMatrixMode (GL_MODELVIEW);				//set the matrix back to model
}

void OnInit() 
{

	glEnable (GL_DEPTH_TEST);	//enable the depth testing
	glEnable (GL_LIGHTING);		//enable the lighting
	glEnable (GL_LIGHT0);		//enable LIGHT0, our Diffuse Light
	glEnable (GL_COLOR_MATERIAL);
	glShadeModel (GL_SMOOTH);	 //set the shader to smooth shader
	glEnable(GL_TEXTURE_2D);

}

void OnIdle() 
{

	if(IsKeyPressed(KEY_LEFT)) 
	{
		Car.moveLeft();
	}
	if(IsKeyPressed(KEY_RIGHT))
	{
		Car.moveRight();
	}
	if(IsKeyPressed(KEY_UP)) 
	{
		Car.moveUp();
	}
	if(IsKeyPressed(KEY_DOWN)) 
	{
		Car.moveDown();
	}
	
	glutPostRedisplay();
}




/*/////////////////////////////////////////////////////////
Main draw sequence
/////////////////////////////////////////////////////////*/

void OnDraw()
{
	glClearColor (0.0,0.0,0.0,1.0); //clear the screen to black
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear the color buffer and the depth buffer
    
	glLoadIdentity(); 

	Car.update();

	glColor3f(1.0f, 1.0f, 1.0f);
	test.draw();


	sprintf(s,"Intersection:%4.2f",Car.intersect3DSegmentPlane(test.p1));

	glColor3f(0.0f,1.0f,1.0f);
	glPushMatrix();
		glLoadIdentity();
		setOrthographicProjection(w, h);
		renderBitmapString(30,35, s);
	glPopMatrix();
	resetPerspectiveProjection();
	glEnable(GL_LIGHTING);	
	
	glutSwapBuffers();
	
}