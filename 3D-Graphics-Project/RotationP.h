#include "DrawBasic.h"
#include "Cube.h"
#include "Vector.h"
#include "Translation.h"
#include "Rotation.h"
#include "Axe.h"


void RotationPY() {
	initwindow(1360,700);
    repere();
    
    float AxeP[2][4]; // Les huit sommets du cube
	Axe3D(200, 0, 0, 200, 300, 0, AxeP);

    float cube[8][4]; // Les huit sommets du cube
	Cube(50, 50, cube);

	float angle=360;
	float cube0[8][4];
	float cube1[8][4];
	float cube2[8][4];
	
	for (int i = 0; i <= angle; i++) {
	// Appliquer la Translation Par Rapport a X
	TranslationX(cube, -200, cube0);
	RotationY(cube0, i, cube1);
	TranslationX(cube1, 200, cube2);
	
	// Appliquer la projection en cabinet
	draw_Axe3D(AxeP, 15);
	drawCubeCabinetBoucle(cube2);
	}
	
	// Appliquer la Translation Par Rapport a X
	TranslationX(cube, -200, cube0);
	RotationY(cube0, angle, cube1);
	TranslationX(cube1, 200, cube2);
	
	// Appliquer la projection en cabinet
	draw_Axe3D(AxeP, 15);
	drawCubeCabinetLast(cube2);
	
}


void RotationPZ() {
	initwindow(1360,700);
    repere();
    
    float AxeP[2][4]; // Les huit sommets du cube
	Axe3D(200, 0, 0, 200, 0, -300, AxeP);
	
    float cube[8][4]; // Les huit sommets du cube
	Cube(50, 50, cube);

	float angle=360;
	float cube0[8][4];
	float cube1[8][4];
	float cube2[8][4];
	
	for (int i = 0; i <= angle; i++) {
	// Appliquer la Translation Par Rapport a X
	TranslationX(cube, -200, cube0);
	RotationZ(cube0, i, cube1);
	TranslationX(cube1, 200, cube2);
	
	// Appliquer la projection en cabinet
	draw_Axe3D(AxeP, 15);
	drawCubeCabinetBoucle(cube2);
	}
	
	// Appliquer la Translation Par Rapport a X
	TranslationX(cube, -200, cube0);
	RotationZ(cube0, angle, cube1);
	TranslationX(cube1, 200, cube2);
	
	// Appliquer la projection en cabinet
	draw_Axe3D(AxeP, 15);
	drawCubeCabinetLast(cube2);
	
}
