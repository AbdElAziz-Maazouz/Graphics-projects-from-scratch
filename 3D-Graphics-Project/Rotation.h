// Function for rotation along the X-axis
void RotationX(float a[8][4], float angle, float b[8][4]) {
    float radianAngle = angle * (M_PI / 180.0); // Convert angle to radians
    float cosTheta = cos(radianAngle);
    float sinTheta = sin(radianAngle);

    float MatrixRotationX[4][4] = {
        {1.0, 0.0, 0.0, 0.0},
        {0.0, cosTheta, sinTheta, 0.0},
        {0.0, -sinTheta, cosTheta, 0.0},
        {0.0, 0.0, 0.0, 1.0}
    };

    // Apply the RotationX using the produit_mat2 function
    produit_mat2(a, MatrixRotationX, b);
}


void RotationY(float a[8][4], float angle, float b[8][4]) {
    float radianAngle = angle * (M_PI / 180.0); // Convert angle to radians
    float cosTheta = cos(radianAngle);
    float sinTheta = sin(radianAngle);

    float MatrixRotationY[4][4] = {
        {cosTheta, 0.0, -sinTheta, 0.0},
        {0.0, 1.0, 0.0, 0.0},
        {sinTheta, 0.0, cosTheta, 0.0},
        {0.0, 0.0, 0.0, 1.0}
    };

    // Apply the RotationY using the produit_mat2 function
    produit_mat2(a, MatrixRotationY, b);
}


void RotationZ(float a[8][4], float angle, float b[8][4]) {
    float radianAngle = angle * (M_PI / 180.0); // Convert angle to radians
    float cosTheta = cos(radianAngle);
    float sinTheta = sin(radianAngle);

    float MatrixRotationZ[4][4] = {
        {cosTheta, sinTheta, 0.0, 0.0},
        {-sinTheta, cosTheta, 0.0, 0.0},
        {0.0, 0.0, 1.0, 0.0},
        {0.0, 0.0, 0.0, 1.0}
    };

    // Apply the RotationZ using the produit_mat2 function
    produit_mat2(a, MatrixRotationZ, b);
}



//------------- (alna Lprof Jarboha Sa3a Makhdmatx ) -------------
void RotationQ(float a[8][4], float Thete, float Alpha, float Beta, float Delta, float b[8][4]) {
    // Convert angles to radians
    float alphaRad = Alpha * M_PI / 180.0;
    float betaRad = Beta * M_PI / 180.0;
    float deltaRad = Delta * M_PI / 180.0;
    float TheteRad = Thete * M_PI / 180.0;

    // Define the rotation matrix for the given angles
    float n1 = cos(alphaRad);
    float n2 = cos(betaRad);
    float n3 = cos(deltaRad);

    float MatrixRotationQ[4][4] = {
        {n1 * n1 + (1 - n1 * n1) * cos(TheteRad), 
        n1 * n2 * (1 - cos(TheteRad)) + n3 * sin(TheteRad), 
        n1 * n3 * (1 - cos(TheteRad)) - n2 * sin(TheteRad), 0},

        {n1 * n2 * (1 - cos(TheteRad)) - n3 * sin(TheteRad), 
        n2 * n2 + (1 - n2 * n2) * cos(TheteRad), 
        n2 * n3 * (1 - cos(TheteRad)) + n1 * sin(TheteRad), 0},

        {n1 * n2 * (1 - cos(TheteRad)) - n2 * sin(TheteRad), 
        n2 * n3 * (1 - cos(TheteRad)) + n1 * sin(TheteRad), 
        n3 * n3 + (1 - n3 * n3) * cos(TheteRad), 0},
        {0, 0, 0, 1}
    };

    // Apply the rotation using matrix multiplication
    produit_mat2(a, MatrixRotationQ, b);
}



void RotationParRapportX() {
    initwindow(1360,700);
    repere();

    float cube[8][4]; // Les huit sommets du cube
	Cube(50, 50, cube);

	float angle=90;
	float cube2[8][4];
	float cube3[8][4];
	
	for (int i = 0; i <= angle; i++) {
	// Appliquer la Translation Par Rapport a X
	RotationX(cube, i, cube2);
	
	// Appliquer la projection en cabinet
	drawCubeCabinetBoucle(cube2);
	}
	
	// Appliquer la Translation Par Rapport a X
	RotationX(cube, angle, cube2);
	
	// Appliquer la projection en cabinet
	drawCubeCabinetLast(cube2);
	
}


void RotationParRapportY() {
    initwindow(1360,700);
    repere();

    float cube[8][4]; // Les huit sommets du cube
	Cube(50, 50, cube);

	float angle=90;
	float cube2[8][4];
	float cube3[8][4];
	
	for (int i = 0; i <= angle; i++) {
	// Appliquer la Translation Par Rapport a Y
	RotationY(cube, i, cube2);
	
	// Appliquer la projection en cabinet
	drawCubeCabinetBoucle(cube2);
	}
	
	// Appliquer la Translation Par Rapport a Y
	RotationY(cube, angle, cube2);
	
	// Appliquer la projection en cabinet
	drawCubeCabinetLast(cube2);
	
}

void RotationParRapportZ() {
    initwindow(1360,700);
    repere();

    float cube[8][4]; // Les huit sommets du cube
	Cube(50, 50, cube);

	float angle=90;
	float cube2[8][4];
	float cube3[8][4];
	
	for (int i = 0; i <= angle; i++) {
	// Appliquer la Translation Par Rapport a Z
	RotationZ(cube, i, cube2);
	
	// Appliquer la projection en cabinet
	drawCubeCabinetBoucle(cube2);
	}
	
	// Appliquer la Translation Par Rapport a Z
	RotationZ(cube, angle, cube2);
	
	// Appliquer la projection en cabinet
	drawCubeCabinetLast(cube2);
	
}
