#include "Keyboard.h"

keyFunc upfunc=0;
keyFunc downfunc=0;

void SetKeyboardFunc(keyFunc func)
{
	downfunc = func;
}
void SetKeyboardUpFunc(keyFunc func) 
{
	upfunc = func;
}
bool keystates[512]={false};

bool IsKeyPressed(int key) 
{
	if (key>=0&&key<512) 
	{
		return keystates[key];
	}
	return false;
}
void KeyUpFunc(unsigned char key,int x,int y)
{
	keystates[key]=false;

	if (upfunc)
	{
		upfunc(key,x,y);
	}
}
void KeyDownFunc(unsigned char key,int x,int y) 
{
	keystates[key]=true;

	if (upfunc) 
	{
		upfunc(key,x,y);
	}
}
void SpecialKeyUpFunc(int key,int x,int y)
{
	keystates[key+256]=false;

	if (upfunc) 
	{
		upfunc(key+256,x,y);
	}
}
void SpecialKeyDownFunc(int key,int x,int y) 
{
	keystates[key+256]=true;

	if (upfunc) 
	{
		upfunc(key+256,x,y);
	}
}
void InitKeyboard() 
{
	glutKeyboardFunc(KeyDownFunc);
	glutKeyboardUpFunc(KeyUpFunc);
	glutSpecialFunc(SpecialKeyDownFunc);
	glutSpecialUpFunc(SpecialKeyUpFunc);
}
