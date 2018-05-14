#include "graphics.h"
#include "extgraph.h"
#include "genlib.h"
#include "simpio.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include <windows.h>
#include <olectl.h>
#include <stdio.h>
#include <mmsystem.h>
#include <wingdi.h>
#include <ole2.h>
#include <ocidl.h>
#include <winuser.h>

#define deltax 0.03
#define deltay 0.03

#define TIMER_BLINK500  1     /*500ms��ʱ���¼���־��*/
#define TIMER_BLINK1000 2     /*1000ms��ʱ��ʱ���־��*/

const int mseconds500 = 500;   
const int mseconds1000 = 1000; 

static double ccx = 1.0, ccy = 1.0;/*Բ������*/
static double radius = 1.0; /*Բ�뾶*/

static char text[100]="AAAAAAA"; /*������ַ���������*/
static int textlen = 0;/*������ַ�������*/
static double textx, texty; /*�ַ�������ʼλ��*/

static bool isBlink = TRUE;   /*�Ƿ���˸��־*/
static bool isDisplayText = TRUE; /*�ַ�����ʾ��־*/
static bool isDisplayCircle = TRUE; /*Բ��ʾ��־*/

void DrawCenteredCircle(double x, double y, double r);/*������Բ*/
/*�жϵ�(x0,y0)�Ƿ��ھ��ΰ�Χ��(x1, y1) --> (x2, y2)��Χ��*/
bool inBox(double x0, double y0, double x1, double x2, double y1, double y2);

void KeyboardEventProcess(int key,int event);/*������Ϣ�ص�����*/
void CharEventProcess(char c);/*�ַ���Ϣ�ص�����*/
void MouseEventProcess(int x, int y, int button, int event);/*�����Ϣ�ص�����*/
void TimerEventProcess(int timerID);/*��ʱ����Ϣ�ص�����*/

void Main() /*����ʼ��ִ��һ��*/
{   
   
	InitGraphics();        	
	
	registerKeyboardEvent(KeyboardEventProcess);/*ע�������Ϣ�ص�����*/
	registerCharEvent(CharEventProcess);/*ע���ַ���Ϣ�ص�����*/
	registerMouseEvent(MouseEventProcess);/*ע�������Ϣ�ص�����*/
	registerTimerEvent(TimerEventProcess);/*ע�ᶨʱ����Ϣ�ص�����*/

	SetPenColor("BLUE"); 
    SetPenSize(4);
    
    ccx = GetWindowWidth()/2;
    ccy = GetWindowHeight()/2;
    
    MovePen(ccx, ccy);
    DrawLine(0.0, 2.0);
    DrawLine(2.0,0.0);
    DrawLine(0.0,-2.0);
    DrawLine(-2.0,0.0);
    DrawTextString("Hello");

    SetPenColor("RED"); 
    SetPenSize(8);
    DrawCenteredCircle(ccx+1, ccy+2, radius);
    
    startTimer(TIMER_BLINK500, mseconds500);/*500ms��ʱ������*/
    startTimer(TIMER_BLINK1000, mseconds1000);/*1000ms��ʱ������*/
  
}


void DrawCenteredCircle(double x, double y, double r)
{
/*
    StartFilledRegion(1);
*/
    MovePen(x + r, y);
    DrawArc(r, 0.0, 360.0);
/*
    EndFilledRegion();
*/
}

void KeyboardEventProcess(int key,int event)/*ÿ������������Ϣ����Ҫִ��*/
{
 	 double oldradius;
 	 
     switch (event) {
	 	case KEY_DOWN:
			 switch (key) {
			     case VK_UP:/*UP*/
			         SetEraseMode(TRUE);/*����ǰһ��*/
                     DrawCenteredCircle(ccx, ccy, radius);
					 ccy += deltay;
					 SetEraseMode(FALSE);/*���µ�*/
                     DrawCenteredCircle(ccx, ccy, radius);
                     break;
			     case VK_DOWN:
			         SetEraseMode(TRUE);
                     DrawCenteredCircle(ccx, ccy, radius);
					 ccy -= deltay;
					 SetEraseMode(FALSE);
                     DrawCenteredCircle(ccx, ccy, radius);
                     break;
			     case VK_LEFT:
			         SetEraseMode(TRUE);
                     DrawCenteredCircle(ccx, ccy, radius);
					 ccx -= deltax;
					 SetEraseMode(FALSE);
                     DrawCenteredCircle(ccx, ccy, radius);
                     break;
			     case VK_RIGHT:
			         SetEraseMode(TRUE);
                     DrawCenteredCircle(ccx, ccy, radius);
					 ccx += deltax;
					 SetEraseMode(FALSE);
                     DrawCenteredCircle(ccx, ccy, radius);
                     break;
			     case VK_F1:
  					 SetEraseMode(TRUE);
                     DrawCenteredCircle(ccx, ccy, radius);
		 	         SetPenSize(GetPenSize()+1);
					 SetEraseMode(FALSE);
                     DrawCenteredCircle(ccx, ccy, radius);
					 break;
			     case VK_F2:
  					 SetEraseMode(TRUE);
                     DrawCenteredCircle(ccx, ccy, radius);
		 	         SetPenSize(GetPenSize()-1);
					 SetEraseMode(FALSE);
                     DrawCenteredCircle(ccx, ccy, radius);
                     break;
			     case VK_F3:
			     case VK_PRIOR:
	 	     		 SetEraseMode(TRUE);
                     DrawCenteredCircle(ccx, ccy, radius);
                     radius += 0.1;
					 SetEraseMode(FALSE);
                     DrawCenteredCircle(ccx, ccy, radius);
                     break;
			     case VK_F4:
			     case VK_NEXT:
		 	         SetEraseMode(TRUE);
                     DrawCenteredCircle(ccx, ccy, radius);
                     radius -= 0.1;
					 SetEraseMode(FALSE);
                     DrawCenteredCircle(ccx, ccy, radius);
                     break;
			     case VK_F5:
                     break;
			     case VK_F6:
                     break;
			     case VK_F9:
			         InitConsole();
			         oldradius = radius;
			         printf("Input radius: ");
			         radius = GetReal();
			         FreeConsole();
  					 SetEraseMode(TRUE);
                     DrawCenteredCircle(ccx, ccy, oldradius);
					 SetEraseMode(FALSE);
                     DrawCenteredCircle(ccx, ccy, radius);
                     break;
			     case VK_ESCAPE:/*���ù����˸��־*/
                     isBlink = !isBlink;
                     if (isBlink ) {
						startTimer(TIMER_BLINK500, mseconds500);
						startTimer(TIMER_BLINK1000, mseconds1000);
                     } else {
						cancelTimer(TIMER_BLINK500);
    					cancelTimer(TIMER_BLINK1000);
					 }
                     break;
			 }
			 break;
		case KEY_UP:
			 break;
	 }	 
}

void CharEventProcess(char c)
{
 	 static char str[2] = {0, 0};

     switch (c) {
       case '\r':  /* ע�⣺�س������ﷵ�ص��ַ���'\r'������'\n'*/
		   isDisplayText = TRUE;/*�����ַ�����ʾ��־*/
           textx = GetCurrentX()-TextStringWidth(text);/*�����ַ�������ʼ����*/
		   texty = GetCurrentY();
   	 	   break;
 	   case 27: /*ESC*/
 	       break;
      default:
	  	   str[0] = c;/*�γɵ�ǰ�ַ����ַ���*/
	 	   text[textlen++] = c;/*����ǰ�ַ����뵽�����ַ���������*/
	 	   text[textlen] = '\0';
	 	   DrawTextString(str);/*�����ǰ�ַ��������λ����Ӧ����*/
	 	   break;
    }
}

bool inBox(double x0, double y0, double x1, double x2, double y1, double y2)
{
	return (x0 >= x1 && x0 <= x2 && y0 >= y1 && y0 <= y2);
}

void MouseEventProcess(int x, int y, int button, int event)
{
 	 static bool isDraw = FALSE;
	 static bool isChangeRadius = FALSE;
     static double r = 0.2;
 	 static double omx = 0.0, omy = 0.0;
     double mx, my;

 	 mx = ScaleXInches(x);/*pixels --> inches*/
 	 my = ScaleYInches(y);/*pixels --> inches*/
 
     switch (event) {
         case BUTTON_DOWN:
   		 	  if (button == LEFT_BUTTON) {
				  if (inBox(mx, my, ccx-radius, ccx+radius, ccy-radius, ccy+radius)){
					  isDraw = TRUE;
				  }
			  } else if (button == RIGHT_BUTTON) {
					  isChangeRadius = TRUE;
			  }
		      omx = mx; omy = my;
              break;
    	 case BUTTON_DOUBLECLICK:
			  break;
         case BUTTON_UP:
  		 	  if (button == LEFT_BUTTON) isDraw = FALSE;
			  else if (button == RIGHT_BUTTON) isChangeRadius = FALSE;
              break;
         case MOUSEMOVE:
			  if (isDraw) {
                  SetEraseMode(TRUE);/*����ǰһ��*/
                  DrawCenteredCircle(ccx, ccy, radius);
				  ccx += mx - omx;
				  ccy += my - omy;
				  omx = mx;
				  omy = my;
				  SetEraseMode(FALSE);/*���µ�*/
                  DrawCenteredCircle(ccx, ccy, radius);
			  } else if (isChangeRadius) {
                  SetEraseMode(TRUE);/*����ǰһ��*/
                  DrawCenteredCircle(ccx, ccy, radius);
				  radius += mx - omx;
				  omx = mx;
				  omy = my;
				  SetEraseMode(FALSE);/*���µ�*/
                  DrawCenteredCircle(ccx, ccy, radius);
			  }
              break;
     }	
}

void TimerEventProcess(int timerID)
{
      bool erasemode;

	  switch (timerID) {
	    case TIMER_BLINK500: /*500ms�����˸��ʱ��*/
		  if (!isBlink) return;
	      erasemode = GetEraseMode();
          MovePen(textx, texty);/*��ʼλ��*/
		  SetEraseMode(isDisplayText);/*���ݵ�ǰ��ʾ��־����������ʾ���������ַ���*/
		  DrawTextString(text);/*��ǰλ�û����ַ�������*/
	      SetEraseMode(erasemode);
		  isDisplayText = !isDisplayText;/*������ʾ/�����ַ�������*/
		  break;
	    case TIMER_BLINK1000: /*1000ms�����˸��ʱ��*/
		  if (!isBlink) return;
	      erasemode = GetEraseMode();
		  SetEraseMode(isDisplayCircle);
          DrawCenteredCircle(ccx, ccy, radius);
	      SetEraseMode(erasemode);
		  isDisplayCircle = !isDisplayCircle;
		  break;
	    default:
		  break;
	  }
}
