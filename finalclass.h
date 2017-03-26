//finalclass.h
//Natalie Alvarez and Kelly Dodson

#include<string>
#include "gfxnew.h"
using namespace std;

class finalClass {
	public:

	finalClass();
	finalClass(int,int);
	~finalClass();

	void drawPresent(int,int);
	void drawTinsel(int, int, int); //RGB input
	void gfx_randomColor(int &, int &, int &);
	void drawStatic(int, int []);
	void drawStar();
	void drawOrnament();
	void gfx_snowman(int,int,int,int);
	void gfx_hat(int,int,int);
	void gfx_eraser();
	void gfx_randomcolorsyay(int, int [], int); //creates a color choice selector


	//Public Getters
	int getx();
	int gety();
	int getReds();
	int getGreens();
	int getBlues();
	//Public Setters
	void setPosition();
	void setColor(int,int,int);
	void setSideColors(int, int, int,int);

	private:
	int x;
	int y;
	int reds;
	int greens;
	int blues;
};
