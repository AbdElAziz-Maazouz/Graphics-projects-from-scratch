#include <graphics.h>
#include <math.h>

void repere(){
  setcolor(15);
  line(0,350,1360,350);//X
  line(680,0,680,700); //Y
}

void pixel(int x, int y, int color) {
    x += getmaxx() / 2;
    y = getmaxy() / 2 - y;
    putpixel(x, y, color);
}


void textxy(float x, float y, char* c) {
	setcolor(15);
    x += getmaxx() / 2;
    y = getmaxy() / 2 - y;
    outtextxy(x,y,c);
}



