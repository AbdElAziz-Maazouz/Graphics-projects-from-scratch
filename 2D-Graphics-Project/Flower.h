#include "Pendulum.h"


void Flower(){
	
		// Prompt the user for the number of petals
	int numPetals;
    do {
        printf("Entrez le nombre de petales (f): ");
        scanf("%d", &numPetals);

//        if (numPetals <= 5) {
//            printf("Veuillez entrer une valeur valide{ > 5} pour le nombre de petales (f): ");
//            scanf("%d", &numPetals);
//        }
    } while (numPetals <= 0);

	// Set the center of the flower
    int centerX = 0;
    int centerY = 0;
    
    // Calculate the angle between each petal
    double angleIncrement = 360.0 / numPetals;

    // Calculate the radius of each petal
    double flowerCenterRadius = 50.0; // Adjust the value as needed
    double xRadius = 2 * M_PI * flowerCenterRadius / numPetals;
	double yRadius = flowerCenterRadius;
	
	initwindow(1360,700);
	
    // Draw the flower center using a circle
    bresenham_circle(centerX, centerY, abs(flowerCenterRadius), 15);
	
    // Draw petals using ellipses
    for (int i = 0; i < numPetals; i++) {
        double angle = i * angleIncrement;

        // Calculate the position of the ellipse
        int x = 2 * flowerCenterRadius * cos(angle * M_PI / 180);
        int y = 2 * flowerCenterRadius * sin(angle * M_PI / 180);

        // Draw the ellipse
        EllipseR(x, y, xRadius, yRadius, angle, 14);
    }

	Sleep(10000);
	
}
