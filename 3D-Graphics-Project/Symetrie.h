void SymetrieYz(float a[8][4], float b[8][4]) {

    float MatrixSymetrieYz[4][4] = {
        {-1.0, 0.0, 0.0, 0.0},
        {0.0, 1.0, 0.0, 0.0},
        {0.0, 0.0, 1.0, 0.0},
        {0.0, 0.0, 0.0, 1.0}
    };

    // Apply the SymetrieYz using the product_mat2 function
    produit_mat2(a, MatrixSymetrieYz, b);
}

void SymetrieXz(float a[8][4], float b[8][4]) {

    float MatrixSymetrieXz[4][4] = {
        {1.0, 0.0, 0.0, 0.0},
        {0.0, -1.0, 0.0, 0.0},
        {0.0, 0.0, 1.0, 0.0},
        {0.0, 0.0, 0.0, 1.0}
    };

    // Apply the SymetrieXz using the product_mat2 function
    produit_mat2(a, MatrixSymetrieXz, b);
}

void SymetrieXy(float a[8][4], float b[8][4]) {

    float MatrixSymetrieXy[4][4] = {
        {1.0, 0.0, 0.0, 0.0},
        {0.0, 1.0, 0.0, 0.0},
        {0.0, 0.0, -1.0, 0.0},
        {0.0, 0.0, 0.0, 1.0}
    };

    // Apply the SymetrieXy using the product_mat2 function
    produit_mat2(a, MatrixSymetrieXy, b);
}


void SymetrieParRapportXy() {
    initwindow(1360,700);
    repere();

    float cube[8][4]; // Les huit sommets du cube
	Cube(100, 50, cube);

    // Appliquer la projection en cabinet
    float cube2[8][4];
    projection_de_cabinet(cube, cube2);
	Position_noms_point(cube2, 14);
	// Dessiner les lignes du cube
	Dessiner_cube_lignes(cube2, 14);
	
	
	// Appliquer la SymetrieXy en cabinet
	float cube3[8][4];
	SymetrieXy(cube, cube2);
    projection_de_cabinet(cube2, cube3);
	Position_noms_point(cube3, 13);
	// Dessiner les lignes du cube
	Dessiner_cube_lignes(cube3, 13);
	
	
}

void SymetrieParRapportYz() {
    initwindow(1360,700);
    repere();

    float cube[8][4]; // Les huit sommets du cube
	Cube(100, 50, cube);

    // Appliquer la projection en cabinet
    float cube2[8][4];
    projection_de_cabinet(cube, cube2);
	Position_noms_point(cube2, 14);
	// Dessiner les lignes du cube
	Dessiner_cube_lignes(cube2, 14);
	
	
	// Appliquer la SymetrieYz en cabinet
	float cube3[8][4];
	SymetrieYz(cube, cube2);
    projection_de_cabinet(cube2, cube3);
	Position_noms_point(cube3, 13);
	// Dessiner les lignes du cube
	Dessiner_cube_lignes(cube3, 13);
	
	
}

void SymetrieParRapportXz() {
    initwindow(1360,700);
    repere();

    float cube[8][4]; // Les huit sommets du cube
	Cube(100, 50, cube);

    // Appliquer la projection en cabinet
    float cube2[8][4];
    projection_de_cabinet(cube, cube2);
	Position_noms_point(cube2, 14);
	// Dessiner les lignes du cube
	Dessiner_cube_lignes(cube2, 14);
	
	
	// Appliquer la SymetrieXz en cabinet
	float cube3[8][4];
	SymetrieXz(cube, cube2);
    projection_de_cabinet(cube2, cube3);
	Position_noms_point(cube3, 13);
	// Dessiner les lignes du cube
	Dessiner_cube_lignes(cube3, 13);
	
}
