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
void MouseEventHandler(int x,int y, int button, int event);

void Main()
{
	InitGraphics();
	SetPenColor("RED"); 
    SetPenSize(2);
    
	registerMouseEvent( MouseEventHandler );
}

void MouseEventHandler(int x, int y,int button, int event)
{
	static bool isDraw = FALSE;
	double px = ScaleXInches(x);
	double py = ScaleYInches(y);
	static double omx = 0.0;
	static double omy = 0.0;
	double mx,my;
	
	switch (event) {
		case BUTTON_DOWN:
			MovePen(px,py);
			if (button == LEFT_BUTTON) {
			    isDraw = TRUE;
			}
			break;
		case BUTTON_UP:
			if (button == LEFT_BUTTON) isDraw = FALSE;
			break;
		case BUTTON_DOUBLECLICK:  
            break; 
		case MOUSEMOVE:
			if (isDraw) {
                DrawLine(px-omx,py-omy);  
                MovePen(px,py);  
			}
			break;
	}
	omx=px;  
    omy=py;
}
