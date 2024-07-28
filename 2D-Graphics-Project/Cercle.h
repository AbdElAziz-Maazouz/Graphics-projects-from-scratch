#include "Line.h"

void bresenham_circle(int h, int k, int r, int color) {
    int x = 0, y = r;
    int s = 3 - 2 * r;

    while (x <= y) {
        
        // Mid-point is inside or on the perimeter of the circle
        if (s > 0) {
            s = s + 4 * (x - y) + 10;
            y--;
        } else {
            s = s + 4 * x + 6;
        }
		x++;
        // Draw the generated point and its reflection in the other octants
        pixel(h + x, k + y, color);
        pixel(h - x, k + y, color);
        pixel(h + x, k - y, color);
        pixel(h - x, k - y, color);
        pixel(h + y, k + x, color);
        pixel(h - y, k + x, color);
        pixel(h + y, k - x, color);
        pixel(h - y, k - x, color);
    }
}


void polynomial_circle(int h, int k, int r, int color) {	
    float x, y;

    // Initialize x and y
    x = 0;
    
    // Iterate over the circle and plot points
    for (x = 0; x <= r / sqrt(2); x += 0.25) {
        y = sqrt(r * r - (x * x)) ; // https://www.javatpoint.com/defining-a-circle-using-polynomial-method
        
        // Draw the generated points and their reflections in the other octants
        pixel(h + x, k + y, color);
        pixel(h - x, k + y, color);
        pixel(h + x, k - y, color);
        pixel(h - x, k - y, color);
        pixel(h + y, k + x, color);
        pixel(h - y, k + x, color);
        pixel(h + y, k - x, color);
        pixel(h - y, k - x, color);
    }
}

void trigonometric_circle(int h, int k, int r, int color) {	
    double theta;
    double theta_increment = M_PI / 360; // Increment by pi/25 'Zid 25 Labaghi Tzid Point'

    for (theta = 0; theta <= M_PI / 4; theta += theta_increment) {
        int x = r * cos(theta);
        int y = r * sin(theta);

        // Draw the points in the current octant and mirror them to other octants
        pixel(h + x, k + y, color);
        pixel(h - x, k + y, color);
        pixel(h + x, k - y, color);
        pixel(h - x, k - y, color);
        pixel(h + y, k + x, color);
        pixel(h - y, k + x, color);
        pixel(h + y, k - x, color);
        pixel(h - y, k - x, color);
    }
}


void Cercle(int choix) {
	
	int h, k, r;
	
    printf("Entrer les coordonnees pour le centre (h k): ");
    while (scanf("%d %d", &h, &k) != 2) {
        printf("Veuillez entrer des coordonnees valides pour le centre (h k) : ");
        while (getchar() != '\n');  // Efface le tampon d'entr?e
    }

    printf("Entrer la rayon de cercle (r): ");
    while (scanf("%d", &r) != 1) {
        printf("Veuillez entrer un rayon valide : ");
        while (getchar() != '\n');  // Efface le tampon d'entr?e
    }

	
    initwindow(1360,700);
    repere();
    
    switch(choix){
    case 3 :
		bresenham_circle(h, k, abs(r), 14);
		break;
	case 4 :
		polynomial_circle(h, k, abs(r), 14);
		break;
	case 5 :
		trigonometric_circle(h, k, abs(r), 14);
		break;
	}
	
}

