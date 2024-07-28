#include "Clock.h"

void drawPendulum(int x, int y, double angle,int length, int color) {
    int bob_radius = 50;  // Radius of the pendulum bob

    // Calculate the position of the bob
    int bob_x = x + length * sin(angle);
    int bob_y = y + length * cos(angle);

    // Clear the screen
    cleardevice();
	bresenham_line(-200, 200, 200, 200, 15);

    // Draw the pendulum rod
    bresenham_line(x, y, bob_x, bob_y, color);

    // Draw the pendulum bob
    bresenham_circle(bob_x, bob_y, bob_radius, color);
}

void Pendulum(){
	
	initwindow(1360,700);
	
	int length = 300;  // Length of the pendulum
	double angle = M_PI / 2;  // Initial angle of the pendulum (90 degrees)
    double angularVelocity = 0.0;  // Initial angular velocity

    double gravity = 1.81;  // Acceleration due to gravity
    
    while (1) {
        // Update the angular velocity and angle using the simple pendulum equations
        angularVelocity += (gravity / length) * sin(angle);
        angle += angularVelocity;


        drawPendulum(0, 200, angle,length, 14);

        delay(20);  // Introduce a delay for smooth animation
    }
	
}

