#include "Cercle.h"

void bresenham_ellipse(int h, int k, int a, int b, int color) {
    int x = 0, y = b;
    int s1 = b * b - a * a * b + a * a / 4;
    int s2 = 0;

    while (2 * b * b * x <= 2 * a * a * y) {
        pixel(x + h, y + k, color);
        pixel(-x + h, y + k, color);
        pixel(x + h, -y + k, color);
        pixel(-x + h, -y + k, color);

        x++;
        if (s1 < 0) {
            s1 += 2 * b * b * x + b * b;
        } else {
            y--;
            s1 += 2 * b * b * x - 2 * a * a * y + b * b;
        }
    }

    s2 = b * b * (x + 0.5) * (x + 0.5) + a * a * (y - 1) * (y - 1) - a * a * b * b;

    while (y >= 0) {
        pixel(x + h, y + k, color);
        pixel(-x + h, y + k, color);
        pixel(x + h, -y + k, color);
        pixel(-x + h, -y + k, color);

        y--;
        if (s2 > 0) {
            s2 += a * a - 2 * a * a * y;
        } else {
            x++;
            s2 += 2 * b * b * x - 2 * a * a * y + a * a;
        }
    }
}



void polynomial_ellipse(int h, int k, int a, int b, int color) {
    float x, y;

    for (x = 0 ; x <= a; x += 0.01) {
        y = b * sqrt(1 - (x * x) / (a * a)); // https://www.javatpoint.com/computer-graphics-polynomial-method

        // Draw the generated points and their reflections in the other quadrants
        pixel(x + h, y + k, color);
        pixel(-x + h, y + k, color);
        pixel(x + h, -y + k, color);
        pixel(-x + h, -y + k, color);
    }
}


void trigonometric_ellipse(int h, int k, int a, int b, int color) {
    float theta, x, y;

    for (theta = 0; theta <= M_PI / 2; theta += M_PI / 360) {
        x = a * cos(theta);
        y = b * sin(theta);
        // https://www.javatpoint.com/computer-graphics-trignometric-method

        // Draw the generated points and their reflections in the other quadrants
        pixel(x + h, y + k, color);
        pixel(-x + h, y + k, color);
        pixel(x + h, -y + k, color);
        pixel(-x + h, -y + k, color);
    }
}


void EllipseR(int xc, int yc, int a, int b, float alpha, int color) {
    float theta, radian_alpha;
    int x, y;

    alpha = 360 - alpha; 
	radian_alpha = alpha * (M_PI / 180.0); // Convert degrees to radians

    // Draw the ellipse with rotation
    for (theta = 0; theta <= 360; theta += 0.9) {
        // Parametric equations for an ellipse with rotation
        x = xc + a * cos(theta) * cos(radian_alpha) - b * sin(theta) * sin(radian_alpha);
        y = yc + a * cos(theta) * sin(radian_alpha) + b * sin(theta) * cos(radian_alpha);

        // Plot the pixel
        pixel(x, y, color);
    }
}


void Ellipse(int choix) {
	
	int h, k, a, b;
	
    printf("Entrer les coordonnees pour le centre (h k):  ");
    while (scanf("%d %d", &h, &k) != 2) {
        printf("Veuillez entrer des coordonn?es valides pour le centre (h k) : ");
        while (getchar() != '\n');  // Efface le tampon d'entr?e
    }

    printf("Entrer une valeur pour l'axe semi-majeur (a): ");
    while (scanf("%d", &a) != 1) {
        printf("Veuillez entrer une valeur valide pour l'axe semi-majeur (a) : ");
        while (getchar() != '\n');  // Efface le tampon d'entr?e
    }

    printf("Entrer une valeur pour l'axe semi-mineur (b): ");
    while (scanf("%d", &b) != 1) {
        printf("Veuillez entrer une valeur valide pour l'axe semi-mineur (b) : ");
        while (getchar() != '\n');  // Efface le tampon d'entr?e
    }

	
    initwindow(1360,700);
    repere();
    
    switch(choix){
    case 6 :
		bresenham_ellipse(h, k, abs(a), abs(b), 14);
		break;
	case 7 :
		polynomial_ellipse(h, k, abs(a), abs(b), 14);
		break;
	case 8 :
		trigonometric_ellipse(h, k, abs(a), abs(b), 14);
		break;
	}
	
}


void EllipseRotation() {
	
	int h, k, a, b;
	float alpha;
	
    printf("Entrer les coordonnees pour le centre (h k):  ");
    while (scanf("%d %d", &h, &k) != 2) {
        printf("Veuillez entrer des coordonn?es valides pour le centre (h k) : ");
        while (getchar() != '\n');  // Efface le tampon d'entr?e
    }

    printf("Entrer une valeur pour l'axe semi-majeur (a): ");
    while (scanf("%d", &a) != 1) {
        printf("Veuillez entrer une valeur valide pour l'axe semi-majeur (a) : ");
        while (getchar() != '\n');  // Efface le tampon d'entr?e
    }

    printf("Entrer une valeur pour l'axe semi-mineur (b): ");
    while (scanf("%d", &b) != 1) {
        printf("Veuillez entrer une valeur valide pour l'axe semi-mineur (b) : ");
        while (getchar() != '\n');  // Efface le tampon d'entr?e
    }
    
    printf("Entrer une valeur alpha pour la rotation : ");
    while (scanf("%f", &alpha) != 1) {
        printf("Veuillez entrer une valeur valide pour alpha : ");
        while (getchar() != '\n');  // Efface le tampon d'entr?e
    }

	
    initwindow(1360,700);
    repere();
    
	EllipseR(h, k, abs(a), abs(b), alpha, 14);
	
}

