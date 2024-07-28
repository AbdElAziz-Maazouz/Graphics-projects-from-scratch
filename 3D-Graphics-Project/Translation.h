void TranslationX(float a[8][4], float l,float b[8][4]) {

    float MatrixTranslationX[4][4] = {
        {1.0, 0.0, 0.0, 0.0},
        {0.0, 1.0, 0.0, 0.0},
        {0.0, 0.0, 1.0, 0.0},
        {l, 0.0, 0.0, 1.0}
    };

    // Apply the TranslationX using the product_mat2 function
    produit_mat2(a, MatrixTranslationX, b);
}


void TranslationY(float a[8][4], float m,float b[8][4]) {

    float MatrixTranslationY[4][4] = {
        {1.0, 0.0, 0.0, 0.0},
        {0.0, 1.0, 0.0, 0.0},
        {0.0, 0.0, 1.0, 0.0},
        {0.0, m, 0.0, 1.0}
    };

    // Apply the TranslationX using the product_mat2 function
    produit_mat2(a, MatrixTranslationY, b);
}

void TranslationZ(float a[8][4], float n,float b[8][4]) {

    float MatrixTranslationZ[4][4] = {
        {1.0, 0.0, 0.0, 0.0},
        {0.0, 1.0, 0.0, 0.0},
        {0.0, 0.0, 1.0, 0.0},
        {0.0, 0.0, n, 1.0}
    };

    // Apply the TranslationX using the product_mat2 function
    produit_mat2(a, MatrixTranslationZ, b);
}

void TranslationParRapportX() {
    initwindow(1360,700);
    repere();

    float cube[8][4]; // Les huit sommets du cube
	Cube(100, 50, cube);

	float l=200;
	float cube2[8][4];
	
	for (int i = 0; i <= l; i+=4) {
	// Appliquer la Translation Par Rapport a X
	TranslationX(cube, i, cube2);
	
	// Appliquer la projection en cabinet
	drawCubeCabinetBoucle(cube2);
	}
	
	// Appliquer la Translation Par Rapport a X
	TranslationX(cube, l, cube2);
	
	// Appliquer la projection en cabinet
	drawCubeCabinetLast(cube2);
	
}

void TranslationParRapportY() {
    initwindow(1360,700);
    repere();

    float cube[8][4]; // Les huit sommets du cube
	Cube(100, 50, cube);

	float m=150;
	float cube2[8][4];
	
	for (int i = 0; i <= m; i+=4) {
	// Appliquer la Translation Par Rapport a Y
	TranslationY(cube, i, cube2);
	
	// Appliquer la projection en cabinet
	drawCubeCabinetBoucle(cube2);
	}
	
	// Appliquer la Translation Par Rapport a Y
	TranslationY(cube, m, cube2);
	
	// Appliquer la projection en cabinet
	drawCubeCabinetLast(cube2);
}


void TranslationParRapportZ() {
    initwindow(1360,700);
    repere();

    float cube[8][4]; // Les huit sommets du cube
	Cube(100, 50, cube);

	float n=300;
	float cube2[8][4];
	float cube3[8][4];
	
	for (int i = 0; i <= n; i+=4) {
	// Appliquer la Translation Par Rapport a Z
	TranslationZ(cube, i, cube2);
	
	// Appliquer la projection en cabinet
	drawCubeCabinetBoucle(cube2);
	}
	
	// Appliquer la Translation Par Rapport a Z
	TranslationZ(cube, n, cube2);
	
	// Appliquer la projection en cabinet
	drawCubeCabinetLast(cube2);
}
