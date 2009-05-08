#pragma once
#include "Agent.h"
#include "Track.h"
#include "Keyboard.h"
#include "TextDisplay.h"

//Window Properties
static int h=480,w=640;

// Create instance of agent & track
Agent Car;
Track Track;

Vector3 light;

//Used for calculating FPS
int frame=0,time,timebase=0;
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
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);		//Enable lighting
	glEnable(GL_LIGHT0);		//Enable light #0
	glEnable(GL_LIGHT1);		//Enable light #1
	glEnable(GL_NORMALIZE);		//Automatically normalize normals
	glShadeModel(GL_SMOOTH);	//Enable smooth shading
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

	//Add ambient light
	GLfloat ambientColor[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.2, 0.2, 0.2)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientColor);
	
	//Add positioned light
	GLfloat lightColor0[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
	GLfloat lightPos0[] = {4.0f, 0.0f, 8.0f, 1.0f}; //Positioned at (4, 0, 8)
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
	
	//Add directed light
	GLfloat lightColor1[] = {0.2f, 0.2f, 0.2f, 1.0f}; //Color (0.5, 0.2, 0.2)
	//Coming from the direction (-1, 0.5, 0.5)
	GLfloat lightPos1[] = {-1.0f, 0.5f, 0.5f, 0.0f};
	glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
	glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);

	Car.update();

	glColor3f(1.0f, 1.0f, 1.0f);
	Track.update();

	//Calculate FPS
	frame++;
	time=glutGet(GLUT_ELAPSED_TIME);
	if (time - timebase > 1000) 
	{
		sprintf(s,"FPS:%4.2f",frame*1000.0/(time-timebase));
		timebase = time;		
		frame = 0;
	}

	//Display FPS
	glDisable(GL_LIGHTING);
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