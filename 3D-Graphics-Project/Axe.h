void Axe3D(float x1, float y1,float z1,float x2, float y2,float z2, float Axe3D[2][4]) {

    // Coordonnées 
    Axe3D[0][0] = x1;
    Axe3D[0][1] = y1;
    Axe3D[0][2] = z1;
    Axe3D[0][3] = 1.0;

    Axe3D[1][0] = x2;
    Axe3D[1][1] = y2;
    Axe3D[1][2] = z2;
    Axe3D[1][3] = 1.0;
	    
}

void produit_Axe2(float a[2][4], float b[4][4], float c[2][4]) {
    int i, j, k;

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 4; j++) {
            c[i][j] = 0;
            for (k = 0; k < 4; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
}


void projection_de_cavaliereAxe(float a[2][4], float b[2][4]) {
    // Projection matrix for cavaliere projection
    float projectionMatrix[4][4] = {
        {1.0, 0.0, 0.0, 0.0},
        {0.0, 1.0, 0.0, 0.0},
        {sqrt(2)/2, sqrt(2)/2, 0.0, 0.0},
        {0.0, 0.0, 0.0, 1.0}
    };

    // Apply the projection using the product_mat2 function
    produit_Axe2(a, projectionMatrix, b);
}

void TranslationXAxe(float a[2][4], float l,float b[2][4]) {

    float MatrixTranslationX[4][4] = {
        {1.0, 0.0, 0.0, 0.0},
        {0.0, 1.0, 0.0, 0.0},
        {0.0, 0.0, 1.0, 0.0},
        {l, 0.0, 0.0, 1.0}
    };

    // Apply the TranslationX using the product_mat2 function
    produit_Axe2(a, MatrixTranslationX, b);
}

void RotationXAxe(float a[2][4], float angle, float b[2][4]) {
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
    produit_Axe2(a, MatrixRotationX, b);
}

void draw_Axe3D(float Axe[2][4], int color) {

	
	float Axe1[2][4];
	projection_de_cavaliereAxe(Axe, Axe1);
	 
	bresenham_line(Axe1[0][0], Axe1[0][1], Axe1[1][0], Axe1[1][1], color);
	    
}

