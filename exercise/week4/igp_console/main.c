#include <stdio.h>
#include"graphics.h"
#include<math.h>

double Angle = 0;

#define Pi 3.141592653589793

void forward(double distance); 
/*沿当前方向画线，长度为distance，当distance为负数时后退*/

void turn (double angle);
 /*顺时针旋转角度angle，角度单位为DEG，当angle为负数时逆时针旋转*/

void move(double distance); 
/*沿当前方向移动笔（不画线），长度为distance，当distance为负数时后退*/

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
	SetPenColor("MYGREEN");
	SetPenSize(4);
	int loop,i;
	for (loop = 0 ; loop <= 18; loop ++){
		Angle = -30.0;
		turn(loop*20.0);
		
		for (i = 0 ; i < 6 ; i++){
			forward(1.0);
			turn(60.0);
		}
		turn(60.0);
		forward(1.0);
		turn(60.0);
		forward(1.0);
		turn(180.0);
		forward(1.0);
		turn(60.0);
		forward(1.0);
		turn(-120.0);
		forward(1.0);
		turn(-60.0);
		forward(1.0);		
	}
}

void forward(double distance)
{
	DrawLine(distance*cos(Angle/180*Pi),distance*sin(Angle/180*Pi));
}

void turn (double angle)
{
	Angle += angle;
}

void move(double distance)
{
	MovePen(distance*cos(Angle/180*Pi),distance*sin(Angle/180*Pi));
}
