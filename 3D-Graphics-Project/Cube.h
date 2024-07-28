void Cube(float centre, float taille, float cube[8][4]) {

    // Coordonnées des sommets du cube
    cube[0][0] = centre - taille;
    cube[0][1] = centre - taille;
    cube[0][2] = centre - taille;
    cube[0][3] = 1.0;

    cube[1][0] = centre + taille;
    cube[1][1] = centre - taille;
    cube[1][2] = centre - taille;
    cube[1][3] = 1.0;

    cube[2][0] = centre + taille;
    cube[2][1] = centre + taille;
    cube[2][2] = centre - taille;
    cube[2][3] = 1.0;

    cube[3][0] = centre - taille;
    cube[3][1] = centre + taille;
    cube[3][2] = centre - taille;
    cube[3][3] = 1.0;

    cube[4][0] = centre - taille;
    cube[4][1] = centre - taille;
    cube[4][2] = centre + taille;
    cube[4][3] = 1.0;

    cube[5][0] = centre + taille;
    cube[5][1] = centre - taille;
    cube[5][2] = centre + taille;
    cube[5][3] = 1.0;

    cube[6][0] = centre + taille;
    cube[6][1] = centre + taille;
    cube[6][2] = centre + taille;
    cube[6][3] = 1.0;

    cube[7][0] = centre - taille;
    cube[7][1] = centre + taille;
    cube[7][2] = centre + taille;
    cube[7][3] = 1.0;
}



void DiviseH(float cube[8][4]){
	
	cube[0][0] /= cube[0][3];
    cube[0][1] /= cube[0][3];
    cube[0][2] /= cube[0][3];
    cube[0][3] /= cube[0][3];

    cube[1][0] /= cube[1][3];
    cube[1][1] /= cube[1][3];
    cube[1][2] /= cube[1][3];
    cube[1][3] /= cube[1][3];

    cube[2][0] /= cube[2][3];
    cube[2][1] /= cube[2][3];
    cube[2][2] /= cube[2][3];
    cube[2][3] /= cube[2][3];

    cube[3][0] /= cube[3][3];
    cube[3][1] /= cube[3][3];
    cube[3][2] /= cube[3][3];
    cube[3][3] /= cube[3][3];

    cube[4][0] /= cube[4][3];
    cube[4][1] /= cube[4][3];
    cube[4][2] /= cube[4][3];
    cube[4][3] /= cube[4][3];

    cube[5][0] /= cube[5][3];
    cube[5][1] /= cube[5][3];
    cube[5][2] /= cube[5][3];
    cube[5][3] /= cube[5][3];

    cube[6][0] /= cube[6][3];
    cube[6][1] /= cube[6][3];
    cube[6][2] /= cube[6][3];
    cube[6][3] /= cube[6][3];

    cube[7][0] /= cube[7][3];
    cube[7][1] /= cube[7][3];
    cube[7][2] /= cube[7][3];
    cube[7][3] /= cube[7][3];
}

void produit_mat2(float a[8][4], float b[4][4], float c[8][4]) {
    int i, j, k;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 4; j++) {
            c[i][j] = 0;
            for (k = 0; k < 4; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void projection_de_cabinet(float a[8][4], float b[8][4]) {
    // Projection matrix for cabinet projection
    float projectionMatrix[4][4] = {
        {1.0, 0.0, 0.0, 0.0},
        {0.0, 1.0, 0.0, 0.0},
        {sqrt(3)/4, 1/4.0, 0.0, 0.0},
        {0.0, 0.0, 0.0, 1.0}
    };

    // Apply the projection using the product_mat2 function
    produit_mat2(a, projectionMatrix, b);
}

void projection_de_cavaliere(float a[8][4], float b[8][4]) {
    // Projection matrix for cavaliere projection
    float projectionMatrix[4][4] = {
        {1.0, 0.0, 0.0, 0.0},
        {0.0, 1.0, 0.0, 0.0},
        {sqrt(2)/2, sqrt(2)/2, 0.0, 0.0},
        {0.0, 0.0, 0.0, 1.0}
    };

    // Apply the projection using the product_mat2 function
    produit_mat2(a, projectionMatrix, b);
}

void Dessiner_cube_lignes(float cube[8][4],int color) {
	// Dessiner les lignes du cube
    for (int i = 0; i < 4; i++) {
        bresenham_line(cube[i][0], cube[i][1], cube[(i + 1) % 4][0], cube[(i + 1) % 4][1], color);
        bresenham_line(cube[i + 4][0], cube[i + 4][1], cube[((i + 1) % 4) + 4][0], cube[((i + 1) % 4) + 4][1], color);
        bresenham_line(cube[i][0], cube[i][1], cube[i + 4][0], cube[i + 4][1], color);
    } 
}


void printM(float Matrix[8][4]){
	printf("==================\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%.2f\t", Matrix[i][j]);
    	}
    printf("\n");
    }
   
}


void drawCubeCabinetStep(float cube[8][4]) {

	repere();
	float cube0[8][4];
	projection_de_cabinet(cube, cube0);
	Position_noms_point(cube0, 14);
	Dessiner_cube_lignes(cube0, 14);
	Sleep(2000);
	cleardevice(); 
	
	
}

void drawCubeCabinetBoucle(float cube[8][4]) {

	repere();
	float cube1[8][4];
	projection_de_cabinet(cube, cube1);
	Position_noms_point(cube1, 14);
	Dessiner_cube_lignes(cube1, 14);
	Sleep(20);
	cleardevice(); 
	
	
}

void drawCubeCabinetLast(float cube[8][4]) {

	repere();
	float cube0[8][4];
	projection_de_cabinet(cube, cube0);
	Position_noms_point(cube0, 14);
	Dessiner_cube_lignes(cube0, 14);
	
}


void drawCube() {
    initwindow(1360,700);
    repere();

    float cube[8][4]; // Les huit sommets du cube
	Cube(50, 50, cube);

    // Appliquer la projection en cabinet
    float cube2[8][4];
    projection_de_cabinet(cube, cube2);
	Position_noms_point(cube2, 14);
	
    // Dessiner les lignes du cube
	Dessiner_cube_lignes(cube2, 14);

}
