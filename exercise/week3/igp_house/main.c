#include <stdio.h>
#include"graphics.h"

/* 
 * Function: Main
 * ------------------
 * Write your codes in this function.
 * Note that this is not a real "main" function. 
 * It is called by WinMain at line: 1926 in graphics.c. 
 * The return type is "void", so do not return anything.
 */
void Main()
{
	// sample
	InitGraphics();	
	MovePen(GetWindowWidth()/2,GetWindowHeight()/2);
	DrawLine(0.0,2.0);
	DrawLine(4.0,0.0);
	DrawLine(0.0,-2.0);
	DrawLine(-4.0,0.0);
	DrawLine(0.0,1.0);
	DrawLine(4.0,0.0);
	DrawLine(-1.0,0.0);
	DrawLine(0.0,1.0);
	DrawLine(0.0,-2.0);
	DrawLine(-1.0,0.0);
	DrawLine(0.0,2.0);
	DrawLine(-1.0,0.0);
	DrawLine(0.0,-2.0);
	DrawLine(-1.0,0.0);
	DrawLine(0.0,2.0);
	DrawLine(0.5,0.83);
	DrawLine(0.5,-0.83);
	double s = 1.0/6; 
	int i = 0;
	for(;i<6;i++){
		DrawLine(0.0,s);
		DrawLine(s,0.0);
		DrawLine(0.0,-s);
		DrawLine(s,0.0);
	}
	DrawLine(0.5,0.83);
	DrawLine(0.5,-0.83);
	
}

