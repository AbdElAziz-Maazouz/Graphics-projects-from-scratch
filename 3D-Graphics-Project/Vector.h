void Vector3D(float a, float b,float c, float Vector3D[1][4]) {

    // Coordonnées 
    Vector3D[0][0] = a;
    Vector3D[0][1] = b;
    Vector3D[0][2] = c;
    Vector3D[0][3] = 1.0;
	    
}

void produit_Vec2(float a[1][4], float b[4][4], float c[1][4]) {
    int i, j, k;

    for (i = 0; i < 1; i++) {
        for (j = 0; j < 4; j++) {
            c[i][j] = 0;
            for (k = 0; k < 4; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
}


void projection_de_cavaliereV(float a[1][4], float b[1][4]) {
    // Projection matrix for cavaliere projection
    float projectionMatrix[4][4] = {
        {1.0, 0.0, 0.0, 0.0},
        {0.0, 1.0, 0.0, 0.0},
        {sqrt(2)/2, sqrt(2)/2, 0.0, 0.0},
        {0.0, 0.0, 0.0, 1.0}
    };

    // Apply the projection using the product_mat2 function
    produit_Vec2(a, projectionMatrix, b);
}

void draw_Vector3D(float Vector[1][4], int color) {

	
	float Vector1[1][4];
	projection_de_cavaliereV(Vector, Vector1);
	 
	bresenham_line(0, 0, Vector1[0][0], Vector1[0][1], color);
	    
}

void Aligne2Vecteur() {
	
    initwindow(1360,700);
    repere();


    // Exemple d'utilisation
    float Vector[1][4];
    int a = 100;
    int b = 100;
    int c = 100;
    float A = sqrt(a * a + b * b + c * c);
    float B = sqrt(b * b + c * c);
    
    Vector3D(a, b, c, Vector);
    draw_Vector3D(Vector, 11);
    
    // Appliquer la projection en cabinet
	printf("Vecteur V Simple : %.2f, %.2f, %.2f, %.2f\n",
       Vector[0][0], Vector[0][1], Vector[0][2], Vector[0][3]);
       
    float AVZ[4][4] = {
        {B/A,		    0.0, a/A, 0.0},
        {-(a*b)/(A*B),  c/B, b/A, 0.0},
        {-(c*a)/(A*B), -b/B, c/A, 0.0},
        {0.0,		    0.0, 0.0, 1.0}
    };

    
    // Exemple d'utilisation
    float Vector1[1][4];
    a = -200;
    b = -300;
    c = -300;
    A = sqrt(a * a + b * b + c * c);
    B = sqrt(b * b + c * c);
    
    Vector3D(a, b, c, Vector1);
    Sleep(3000);
    draw_Vector3D(Vector1, 12);
    
    // Appliquer la projection en cabinet
	printf("Vecteur V1 Simple : %.2f, %.2f, %.2f, %.2f\n",
       Vector1[0][0], Vector1[0][1], Vector1[0][2], Vector1[0][3]);
    
    float AZV[4][4] = {
        {B/A,-(a*b)/(A*B), -(c*a)/(A*B), 0.0},
        {0.0, c/B,		   -b/B, 		 0.0},
        {a/A, b/A, 	    	c/B, 	  	 0.0},
        {0.0, 0.0, 			0.0, 		 1.0}
    };
	    
    float Vector2[1][4];
	produit_Vec2(Vector, AVZ, Vector2);
	 
	float Vector3[1][4];
	produit_Vec2(Vector2, AZV, Vector3);
	
	printf("Vecteur VF Simple : %.2f, %.2f, %.2f, %.2f\n",
       Vector3[0][0], Vector3[0][1], Vector3[0][2], Vector3[0][3]);
       
	Sleep(3000);
	draw_Vector3D(Vector3, 13);
    	
}
