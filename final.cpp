/*
Natalie Alvarez and Kelly Dodson
Christmas Time!
Computing Final Project
December 12, 2016

The purpose of this program is to provide a user inferface for a user to
draw a festive Christmas scene. Depending on what the user types, the user
can draw anything from ornaments to a custom snowman.
*/
#include<iostream>
#include<cmath>
#include<string>
#include "stdlib.h"
#include "finalclass.h"
#include <unistd.h>
using namespace std;

int main() {
	int reds,greens,blues = 255;		//initialize rgb values
	char c;								//user choice character
	int x1,y1,r;
	int wd,ht,ht2;
	int win_wd = gfx_screenwidth(); 	//width of gfx window
	int win_ht = gfx_screenheight();	//height of gfx window
	int xcolor = win_wd - 40;
	int ycolor[] = {(win_ht/2 - 80), (win_ht/2 - 40), (win_ht/2), (win_ht/2 + 40)};

	gfx_open(win_wd,win_ht,"Christmas Time!");

	finalClass a; //create object of class finalClass
	a.drawStatic(xcolor, ycolor);
	//c represents what the user pressed on the keyboard
	while (c != 'q') {
		c = gfx_wait();
		switch (c) {
			case 't': //tinsel
				while (gfx_wait()=='t') {
					a.drawTinsel(reds,greens,blues);
				}
				break;
			case 'p': //present
				x1 = gfx_xpos();
				y1 = gfx_ypos();
				a.drawPresent(x1,y1);
				break;
			case 's': //star
				a.drawStar();
				break;
			case 'b': //bulb ornament
				a.drawOrnament();
			case 'q': //quit
				break;
			case 'o': //snowman
				r = 0;
				while (gfx_wait() =='o') {
					r++;
					reds = a.getReds();
					greens = a.getGreens();
					blues= a.getBlues();
					a.gfx_snowman(r,reds,greens,blues);
				}
				break;
			case 'h': //hat
				wd=0;
				ht=8;
				ht2=0;
				while(gfx_wait()=='h') {
					wd++;
					ht++;
					ht2++;
					a.gfx_hat(wd,ht,ht2);
				}
				break;
			case 'e': //eraser
				while (gfx_wait()=='e') {
					a.gfx_eraser();
				}
				break;
			case 'c': //color
                x1 = gfx_xpos();
                y1 = gfx_ypos();
                if(x1 >= (win_wd - 40) && x1 <= win_wd) {
                	if(y1 >= (win_ht/2 - 80) && y1 <= win_ht/2 + 80) {
                		a.gfx_randomcolorsyay(xcolor, ycolor, y1);
					}
				}
                break;
            case 'r': //restart scene and redraw tree and side colors (in case they are erased)
				gfx_clear();
				a.drawStatic(xcolor, ycolor);
				break;
		}
		gfx_flush();
	}

return 0;
}

