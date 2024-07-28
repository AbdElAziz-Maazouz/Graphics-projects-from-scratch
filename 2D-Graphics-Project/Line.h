#include "Basic.h"

// Function to draw a line using Bresenham's algorithm
void bresenham_line(int x1, int y1, int x2, int y2, int color) {
    
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int x_increment = (x1 < x2) ? 1 : -1;
    int y_increment = (y1 < y2) ? 1 : -1;
    int x = x1;
    int y = y1;

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

void polynomial_line(int x1, int y1, int x2, int y2, int color) {

    int x, y, dx, dy, px, py;
    float m, b;

    dx = x2 - x1;
    dy = y2 - y1;
    px = (x1 > x2) ? -1 : 1;
    py = (y1 > y2) ? -1 : 1;

    // Draw the initial and final points
    pixel(x1, y1, color);
    pixel(x2, y2, color);

    if (abs(dx) >= abs(dy)) {
        m = (float)dy / dx;
        b = y1 - x1 * m;

        for (x = x1 + px; x != x2; x += px) {
            y = m * x + b;
            pixel(x, y, color);
        }
    } else {
        m = (float)dx / dy;
        b = x1 - y1 * m;

        for (y = y1 + py; y != y2; y += py) {
            x = m * y + b;
            pixel(x, y, color);
        }
    }
}


void Ligne(int choix) {
	
	int xd, yd, xf, yf;
	
	printf("Entrer le point de depart (x1 y1): ");
    while (scanf("%d %d", &xd, &yd) != 2) {
        printf("Veuillez entrer des coordonnees valides pour le point de depart (x1 y1) : ");
        while (getchar() != '\n');  // Efface le tampon d'entr?e
    }

    printf("Entrer le point de fin (x2 y2): ");
    while (scanf("%d %d", &xf, &yf) != 2) {
        printf("Veuillez entrer des coordonnees valides pour le point de fin (x2 y2) : ");
        while (getchar() != '\n');  // Efface le tampon d'entr?e
    }
	
    initwindow(1360,700);
    repere();
    
    switch(choix){
    case 1 :
		bresenham_line(xd, yd, xf, yf, 14);
		break;
	case 2 :
		polynomial_line(xd, yd, xf, yf, 14);
		break;
	}
	
}

