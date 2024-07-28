#include "Ellipse.h"
#include <time.h>


void DrawClockNumber(int centerX, int centerY, int clockRadius){
	
    // Draw numbers around the clock
    for (int i = 1; i <= 12; i++) {
        double angle = i * 30 * M_PI / 180; // 30 degrees for each hour
        int numX = centerX - (4) + clockRadius * 0.8 * sin(angle);
        int numY = centerY + (6) + clockRadius * 0.8 * cos(angle);

        // Convert the integer to a string using sprintf
        char numStr[3];  // Assuming a two-digit number
        sprintf(numStr, "%d", i);

        // Use outtextxy to draw the number
        textxy(numX, numY, numStr);
    }	
	
}


void DrawClockXarta(int centerX, int centerY, int clockRadius){
	
    // Draw numbers around the clock
    for (int i = 1; i <= 12; i++) {
        double angle = i * 30 * M_PI / 180; // 30 degrees for each hour
        int Xd = centerX + clockRadius * 0.99 * sin(angle);
        int Yd = centerY + clockRadius * 0.99 * cos(angle);
        int Xf = centerX + clockRadius * 0.88 * sin(angle);
        int Yf = centerY + clockRadius * 0.88 * cos(angle);


        //to draw the -
        bresenham_line(Xd, Yd, Xf, Yf, 2);
    }	
	
}


// Function to draw a clock using Bresenham's line and circle drawing algorithms
void clock(int centerX, int centerY, int clockRadius, int color) {
	
	initwindow(1360,700);
	
    // Draw clock face (circle)
    bresenham_circle(centerX, centerY, clockRadius, color);

    DrawClockNumber(centerX, centerY, clockRadius);
    DrawClockXarta(centerX, centerY, clockRadius);

    while (1) {
        // Get current time
		time_t currentTime;
		struct tm *timeInfo;
		
		time(&currentTime);
		timeInfo = localtime(&currentTime);
		
		int secondAngle = 6 * timeInfo->tm_sec;  // 360 degrees / 60 seconds = 6 degrees per second
		int minuteAngle = 6 * timeInfo->tm_min + 0.1 * timeInfo->tm_sec; // 360 degrees / 60 minutes = 6 degrees per minute
		int hourAngle = 30 * timeInfo->tm_hour + 0.5 * timeInfo->tm_min; // 360 degrees / 12 hours = 30 degrees per hour

        // Draw hour hand
        int hourHandLength = clockRadius / 2;
        int hourHandX = centerX + hourHandLength * sin((hourAngle) * M_PI / 180);
        int hourHandY = centerY + hourHandLength * cos((hourAngle) * M_PI / 180);
        bresenham_line(centerX, centerY, hourHandX, hourHandY, 14);

        // Draw minute hand
        int minuteHandLength = clockRadius * 3 / 4;
        int minuteHandX = centerX + minuteHandLength * sin((minuteAngle) * M_PI / 180);
        int minuteHandY = centerY + minuteHandLength * cos((minuteAngle) * M_PI / 180);
        bresenham_line(centerX, centerY, minuteHandX, minuteHandY, 2);

        // Draw second hand
        int secondHandLength = clockRadius * 7 / 8;
        int secondHandX = centerX + secondHandLength * sin((secondAngle) * M_PI / 180);
        int secondHandY = centerY + secondHandLength * cos((secondAngle) * M_PI / 180);
        bresenham_line(centerX, centerY, secondHandX, secondHandY, 4);

        // Delay for one second
		delay(1000);
		bresenham_line(centerX, centerY, hourHandX, hourHandY, 0);
		bresenham_line(centerX, centerY, minuteHandX, minuteHandY, 0);
		bresenham_line(centerX, centerY, secondHandX, secondHandY, 0);
    }
}
