#include "RotationQ.h"

void ExerciceXVII() {
    initwindow(1360,700);
    
    float cube[8][4]; // Les huit sommets du cube
	Cube(100, 50, cube);

	float cube0[8][4];
	float cube1[8][4];
	float cube2[8][4];
	float cube3[8][4];
	
	// Appliquer la Translation Par Rapport a X
	drawCubeCabinetStep(cube);
	TranslationX(cube, -100, cube0);
	TranslationY(cube0, -100, cube);
	TranslationZ(cube, -100, cube0);
	drawCubeCabinetStep(cube0);
	RotationY(cube0, -45, cube1);
	drawCubeCabinetStep(cube1);
	RotationX(cube1, 30, cube0);
	drawCubeCabinetStep(cube0);
	
	float MatrixProjectionPer[4][4] = {
        {1, 0, 0.0, 0.002},
        {0, 1, 0.0, 0.0066},
        {0.0, 0.0, 0, 0.0},
        {0.0, 0.0, 0.0, 1.0}
    };

    // Apply the RotationZ using the produit_mat2 function
    printM(cube0);
    produit_mat2(cube0, MatrixProjectionPer, cube1);
    printM(cube1);
	
    DiviseH(cube1);
    printM(cube1);
    
	drawCubeCabinetStep(cube1);
    
	TranslationX(cube1, 150, cube2);
	TranslationY(cube2, -150, cube1);
//	TranslationZ(cube1, 100, cube2);
	
	drawCubeCabinetLast(cube1);
//	printM(cube2);

    float A[2] = { cube1[0][0], cube1[0][1] };
    float B[2] = { cube1[1][0], cube1[1][1] };
    float C[2] = { cube1[2][0], cube1[2][1] };
    float D[2] = { cube1[3][0], cube1[3][1] };
    float E[2] = { cube1[4][0], cube1[4][1] };
    float F[2] = { cube1[5][0], cube1[5][1] };
    float G[2] = { cube1[6][0], cube1[6][1] };
    float H[2] = { cube1[7][0], cube1[7][1] };
    
    float X[2];
    
    float FB[2];
    float GC[2];
    
    
    findVector(F[0], F[1], B[0], B[1], FB);
    findVector(G[0], G[1], C[0], C[1], GC);
    
    findIntersection(FB, GC , X);
    bresenham_line(B[0], B[1], X[0], X[1], 12);
    bresenham_line(C[0], C[1], X[0], X[1], 12);

    float BC[2];
    float EH[2];
	
	findVector(B[0], B[1], C[0], C[1], BC);
    findVector(E[0], E[1], H[0], H[1], EH);   
	
	findIntersection(BC, EH , X);
    bresenham_line(C[0], C[1], X[0], X[1], 12);
    bresenham_line(H[0], H[1], X[0], X[1], 12);
    
    float GH[2];
    float FE[2];
	
	findVector(G[0], G[1], H[0], H[1], GH);
    findVector(F[0], F[1], E[0], E[1], FE);   
	
	findIntersection(GH, FE , X);
    bresenham_line(H[0], H[1], X[0], X[1], 12);
    bresenham_line(E[0], E[1], X[0], X[1], 12);

	
}
