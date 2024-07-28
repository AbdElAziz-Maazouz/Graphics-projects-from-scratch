#include <graphics.h>
#include <math.h>

void repere(){
  setcolor(15);
  line(680,350,1360,350);//X
  line(680,0,680,350); //Y
  line(680,350,330,700);//Z
}

void pixel(int x, int y, int color) {
    x += getmaxx() / 2;
    y = getmaxy() / 2 - y;
    putpixel(x, y, color);
}

void drawHorizontalLine(float x1, float x2, float y, float color) {
    for (int x = x1; x <= x2; x++) {
        pixel(x, y, color);
    }
}

// Function to draw a line using Bresenham's algorithm
void bresenham_line(int x1, int y1, int x2, int y2, int color) {
    
    float dx = abs(x2 - x1);
    float dy = abs(y2 - y1);
    float x_increment = (x1 < x2) ? 1 : -1;
    float y_increment = (y1 < y2) ? 1 : -1;
    float x = x1;
    float y = y1;

    // Draw the line using Bresenham's algorithm
    if (dx > dy) { // 1st octant
        int s = 2 * dy - dx;
        while (x != x2) {
            pixel(x, y, color);
            if (s < 0) {
                s += 2 * dy;
            } else {
                s += 2 * dy - 2 * dx;
                y += y_increment;
            }
            x += x_increment;
        }
    } else { // 2nd octant
        int s = 2 * dx - dy;
        while (y != y2) {
            pixel(x, y, color);
            if (s < 0) {
                s += 2 * dx;
            } else {
                s += 2 * dx - 2 * dy;
                x += x_increment;
            }
            y += y_increment;
        }
    }
}

void textxy(float x, float y, char* c) {
    x += getmaxx() / 2;
    y = getmaxy() / 2 - y;
    outtextxy(x,y,c);
}



void Position_noms_point(float Result[8][4],int color){
    setcolor(color);
    textxy(Result[0][0],Result[0][1],(char*)"A");
    textxy(Result[1][0],Result[1][1],(char*)"B");
    textxy(Result[2][0],Result[2][1],(char*)"C");
    textxy(Result[3][0],Result[3][1],(char*)"D");
    textxy(Result[4][0],Result[4][1],(char*)"E");
    textxy(Result[5][0],Result[5][1],(char*)"F");
    textxy(Result[6][0],Result[6][1],(char*)"G");
    textxy(Result[7][0],Result[7][1],(char*)"H");
    
//    float A[2] = { cube1[0][0], cube1[0][1] };
//    float B[2] = { cube1[1][0], cube1[1][1] };
//    float C[2] = { cube1[2][0], cube1[2][1] };
//    float D[2] = { cube1[3][0], cube1[3][1] };
//    float E[2] = { cube1[4][0], cube1[4][1] };
//    float F[2] = { cube1[5][0], cube1[5][1] };
//    float G[2] = { cube1[6][0], cube1[6][1] };
//    float H[2] = { cube1[7][0], cube1[7][1] };
}

void findIntersection(float  vecteur1[2], float vecteur2[2] ,  float resultat[2]) {
   resultat[0] = (vecteur2[1] - vecteur1[1]) / (vecteur1[0] - vecteur2[0]);
   resultat[1] = vecteur1[0] * resultat[0] + vecteur1[1];
      

}


void findVector(float x1, float y1, float x2, float y2, float vecteur[2]) {
    vecteur[0] = (y2 - y1) / (x2 - x1);
    vecteur[1] = y1 - vecteur[0] * x1;
}



