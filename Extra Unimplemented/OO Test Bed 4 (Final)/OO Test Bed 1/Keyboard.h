#pragma once

#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;

#define KEY_LEFT		(GLUT_KEY_LEFT+256)
#define KEY_UP			(GLUT_KEY_UP+256)
#define KEY_RIGHT		(GLUT_KEY_RIGHT+256)
#define KEY_DOWN		(GLUT_KEY_DOWN+256)

#define KEY_F1			(GLUT_KEY_F1+256)
#define KEY_F2			(GLUT_KEY_F2+256)

#define KEY_SPACE		' '
#define KEY_ESCAPE		27

void InitKeyboard();
bool IsKeyPressed(int key);
typedef void (*keyFunc)(int,int,int);
void SetKeyboardFunc(keyFunc);
void SetKeyboardUpFunc(keyFunc);


