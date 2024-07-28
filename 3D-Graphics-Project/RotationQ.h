#include "RotationP.h"

void RotationQ() {
	initwindow(1360,700);
    repere();
    
//    float AxeP[2][4]; // F7alat mabghity Trsam ta Axe Q
//	Axe3D(0, 0, 0, 0, 300, 0, AxeP);
//	float AxeP0[2][4];
//	float AxeP1[2][4];
//	RotationX(AxeP, 45, AxeP0);
//	TranslationX(AxeP0, 150, AxeP1);
    
    float cube[8][4]; // Les huit sommets du cube
	Cube(50, 50, cube);

	float angle=360;
	float cube0[8][4];
	float cube1[8][4];
	
	for (int i = 0; i <= angle; i++) {
	TranslationX(cube, -150, cube0);
	TranslationY(cube0, -150, cube1);
	TranslationZ(cube1, -150, cube0);
	RotationX(cube0, -45, cube1);
	RotationY(cube1, 45, cube0);
	RotationZ(cube0, -45, cube1);
	RotationY(cube1, i, cube0);
	TranslationX(cube0, 150, cube1);
	TranslationY(cube1, 150, cube0);
	TranslationZ(cube0, 150, cube1);
	RotationX(cube1, 45, cube0);
	RotationY(cube0, -45, cube1);
	RotationZ(cube1, 45, cube0);
	
	// Appliquer la projection en cabinet
//	draw_Axe3D(AxeP1, 15);
	drawCubeCabinetBoucle(cube0);
	}
	
	TranslationX(cube, -150, cube0);
	TranslationY(cube0, -150, cube1);
	TranslationZ(cube1, -150, cube0);
	RotationX(cube0, -45, cube1);
	RotationY(cube1, 45, cube0);
	RotationZ(cube0, -45, cube1);
	RotationY(cube1, angle, cube0);
	TranslationX(cube0, 150, cube1);
	TranslationY(cube1, 150, cube0);
	TranslationZ(cube0, 150, cube1);
	RotationX(cube1, 45, cube0);
	RotationY(cube0, -45, cube1);
	RotationZ(cube1, 45, cube0);
	
	// Appliquer la projection en cabinet
//	draw_Axe3D(AxeP1, 15);
	drawCubeCabinetLast(cube0);
	
}


void RotationQSimple() {
	initwindow(1360,700);
    repere();
    
//    float AxeP[2][4]; // F7alat mabghity Trsam ta Axe Q
//	Axe3D(0, 0, 0, 0, 300, 0, AxeP);
//	float AxeP0[2][4];
//	float AxeP1[2][4];
//	RotationX(AxeP, 45, AxeP0);
//	TranslationX(AxeP0, 150, AxeP1);
    
    float cube[8][4]; // Les huit sommets du cube
	Cube(50, 50, cube);

	float angle=360;
	float cube0[8][4];
	float cube1[8][4];
	
	for (int i = 0; i <= angle; i++) {
	TranslationX(cube, -150, cube0);
	RotationX(cube0, 45, cube1);
	RotationY(cube1, i, cube0);
	TranslationX(cube0, 150, cube1);
	RotationX(cube1, -45, cube0);
	
	// Appliquer la projection en cabinet
//	draw_Axe3D(AxeP1, 15);
	drawCubeCabinetBoucle(cube0);
	}
	
	TranslationX(cube, -150, cube0);
	RotationX(cube0, 45, cube1);
	RotationY(cube1, angle, cube0);
	TranslationX(cube0, 150, cube1);
	RotationX(cube1, -45, cube0);
	
	// Appliquer la projection en cabinet
//	draw_Axe3D(AxeP1, 15);
	drawCubeCabinetLast(cube0);
	
}

void RotationQCour() {
	initwindow(1360,700);
    repere();
    
//    float AxeP[2][4]; // F7alat mabghity Trsam ta Axe Q
//	Axe3D(0, 0, 0, 0, 300, 0, AxeP);
//	float AxeP0[2][4];
//	float AxeP1[2][4];
//	RotationX(AxeP, 45, AxeP0);
//	TranslationX(AxeP0, 150, AxeP1);
    
    float cube[8][4]; // Les huit sommets du cube
	Cube(50, 50, cube);

	float angle=360;
	float cube0[8][4];
	float cube1[8][4];
	
	for (int i = 0; i <= angle; i++) {
	RotationQ(cube, i, 30, 80, 140, cube0);
	
	// Appliquer la projection en cabinet
//	draw_Axe3D(AxeP1, 15);
	drawCubeCabinetBoucle(cube0);
	}
	
	RotationQ(cube, angle, 30, 80, 140, cube0);
	
	// Appliquer la projection en cabinet
//	draw_Axe3D(AxeP1, 15);
	drawCubeCabinetLast(cube0);
	
}
