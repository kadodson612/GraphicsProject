//Natalie Alvarez and Kelly Dodson
//Christmas Final Project
//December 12,2016

#include "finalclass.h"
#include <iostream>
#include <cmath>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include "gfxnew.h"
#include <X11/Xlib.h>
using namespace std;

finalClass::finalClass(){
	this->reds = 255;
	this->greens = 255;
	this->blues = 255;
	this->x = 0;
	this->y = 0;
}

finalClass::finalClass(int win_wd, int win_ht) {
	gfx_open(win_wd, win_ht, "Christmas Time!");
	this->reds = 255;
	this->greens = 255;
	this->blues = 255;
	this->x = 0;
	this->y = 0;
}

finalClass::~finalClass(){
}

void finalClass::drawPresent(int x1,int y1) {
	int wd, ht;
	//box and color:
	srand(time(NULL));
	gfx_randomColor(reds,greens,blues);
	wd = rand() % 150 + 1;
	while (wd <= 20) {
		wd =  rand() % 150 +1;
	}
	ht = rand() % 150 + 1;
	while (ht<=20) {
		ht = rand() % 150 + 1;
	}
	gfx_fill_rectangle(x1,y1,wd,ht);
	//decorations:
	gfx_randomColor(reds,greens,blues);
	gfx_fill_rectangle(x1+wd*2/5, y1, wd*1/5,ht);
	gfx_fill_rectangle(x1,y1+ht*2/5,wd,ht*1/5);
}

void finalClass::drawTinsel(int reds, int greens, int blues){
	gfx_changecursor(124); //changes cursor to spray can to spray garland
	int x1 = gfx_xpos();
	int y1 = gfx_ypos();
	gfx_color(reds,greens,blues);
	//gfx_fill_arc(x1,y1,20,20,0,M_PI);
	gfx_circle(x1,y1,20);

}

void finalClass::gfx_randomColor(int &reds, int &greens, int &blues) {
	this->reds = rand() % 255 + 1;
	this->blues = rand() % 255 +1;
	this->greens=rand() % 255+1;
	gfx_color(reds,greens,blues);
}

void finalClass::drawStatic(int xcolor, int ycolor[]) {
	//static text
	gfx_text(20,30,"Merry Christmas! You can decorate the Christmas scene.");
	gfx_text(20,45, "Commands:");
	gfx_text(20,60,  "Bulb ornament: Press 'b'");
	gfx_text(20, 75, "Presents     : Press 'p'");
	gfx_text(20, 90,"Star         : Press 's'");
	gfx_text(20, 105, "Tinsel       : Hold 't'");
	gfx_text(20, 120,"Snowman body : Hold 'o' to increase size");
	gfx_text(20, 135,"Snowman hat  : Hold 'h' to increase size");
	gfx_text(20, 150,"Change color : Hover over color selector and press 'c'");
	gfx_text(20, 165,"Erase, quit, or restart: 'e', 'q', and 'r'");

	//static tree
	int middle = gfx_screenwidth() / 2;
	int bottom = gfx_screenheight() - 200;
	gfx_color(139,69,19);//brown trunk
	gfx_fill_rectangle(middle-25,bottom,50,200);
	gfx_color(34, 139, 34); //green leaves
	XPoint pointsarr[6]={middle-200, bottom, middle + 200,bottom, middle, 30};
	gfx_fill_polygon(pointsarr, 3);

	//static colors on side
	for(int i = 1; i <= 4; i++) {
		switch(i) {
			case 1:
				gfx_color(255,255,255);
				break;
			case 2:
				gfx_color(255, 0, 0);
				break;
			case 3:
				gfx_color(0, 255, 0);
				break;
			case 4:
				gfx_color(0, 0, 255);
				break;
		}
		gfx_fill_rectangle(xcolor, ycolor[i-1], 40, 40);
	}
}
void finalClass::gfx_randomcolorsyay(int xcolor, int ycolor[], int y1) {
	if(y1 >= ycolor[0] && y1 <= ycolor[0] + 40) {
		setColor(255, 255, 255);
	} else if(y1 >= ycolor[1] && y1 <= ycolor[1] + 40) {
		setColor(255, 0, 0);
	} else if(y1 >= ycolor[2] && y1 <= ycolor[2] + 40) {
		setColor(0, 255, 0);
	} else if(y1 >= ycolor[3] && y1 <= ycolor[3] + 40) {
		setColor(0, 0, 255);
	}
}
void finalClass::drawStar() {
	gfx_changecursor(126);
	int x1 = gfx_xpos();
	int y1 = gfx_ypos();
	gfx_color(255,215,0); //gold
	XPoint pointsarr[6]={x1-20,y1,x1+20,y1,x1,y1-20};
	gfx_fill_polygon(pointsarr,3);
	XPoint pointsarr2[6]={x1-20,y1-10,x1+20,y1-10,x1,y1+10};
	gfx_fill_polygon(pointsarr2,3);

}
void finalClass::drawOrnament() {
	gfx_randomColor(reds,greens,blues);
	setPosition();
	gfx_fill_arc(x,y,20,20,0,360);
}
int finalClass::getx() {
	return x;
}
int finalClass::gety() {
	return y;
}
int finalClass::getReds() {
	return reds;
}
int finalClass::getGreens() {
	return greens;
}
int finalClass::getBlues() {
	return blues;
}
void finalClass::setPosition() {
	this->x = gfx_xpos();
	this->y = gfx_ypos();
}
void finalClass::setColor(int r,int g,int b) {
	this->reds = r;
	this->greens = g;
	this->blues = b;
}
void finalClass::gfx_snowman(int r, int reds, int greens, int blues) {
  	gfx_changecursor(62);
    gfx_color(reds, greens, blues);
   	int x1 = gfx_xpos();
    int y1 = gfx_ypos();
    gfx_circle(x1, y1, r);
}
void finalClass::gfx_hat(int wd, int ht, int ht2) {
  	gfx_changecursor(62);
	gfx_color(91, 0, 0);
    int x1 = gfx_xpos();
    int y1 = gfx_ypos();
    gfx_fill_rectangle(x1-wd, y1-ht, 2*wd, 2*ht);
    gfx_fill_rectangle(x1-2*wd, y1+ht, 4*wd, ht2);
}
void finalClass::gfx_eraser() {
    gfx_changecursor(38);
    gfx_color(0,0,0);
    int x1 = gfx_xpos();
    int y1 = gfx_ypos();
    gfx_fill_rectangle(x1-10, y1-10, 20, 20);
}
