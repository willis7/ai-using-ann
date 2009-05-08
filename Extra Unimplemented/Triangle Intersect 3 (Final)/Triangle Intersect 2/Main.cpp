#include "OGL.h"


int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_RGBA|GLUT_DOUBLE);
	glutInitWindowSize(w,h);
	glutCreateWindow("Triangle intersection test");

	glutDisplayFunc(OnDraw);
	glutReshapeFunc(OnReshape);
	OnInit();

	InitKeyboard();
	glutIdleFunc(OnIdle);

	glutMainLoop();
	return 0;
}