#include "Flower.h"


int Menu_choix() {
    int choix;
    printf(" <---------------------[ Courbes ]------------------->\n\n");
    printf(" -----------------------------------------------\n");
    printf(" | 1- Ligne Bresenham :                         |\n");
    printf(" | 2- Ligne Polynomiale :                       |\n");
    printf(" | 3- Cercle Bresenham :                        |\n");
    printf(" | 4- Cercle Polynomiale :                      |\n");
    printf(" | 5- Cercle Trigonometric :                    |\n");
    printf(" | 6- Ellipse Bresenham :                       |\n");
    printf(" | 7- Ellipse Polynomiale :                     |\n");
    printf(" | 8- Ellipse Trigonometric :                   |\n");
    printf(" | 9- Ellipse Avec Rotation :                   |\n");
    printf(" |10- Dessine l'horloge :                       |\n");
    printf(" |11- Dessine Un Pendule :                      |\n");
    printf(" |12- Dessine Flower :                          |\n");
//    printf(" |12- Symetrie / YZ                             |\n");
//    printf(" |13- Symetrie / XZ                             |\n");
//    printf(" |14- Aligne 2 Vecteur Quelconque               |\n");
//    printf(" |15- ExerciceXVII                              |\n");
//    printf(" | 13- Projection cavali?re                     |\n");
//    printf(" | 14- Projection cabinet                       |\n");
//    printf(" | 15- Projection Perspective                   |\n");
//    printf(" | 17- Sym?trie par rapport ? un planquelconque |\n");
    printf(" -----------------------------------------------\n\n");

    do {
        printf(" ------------------------------\n");
        printf(" | Svp Donner la votre choix  |\n");
        printf(" ------------------------------\n");
        scanf("%d", &choix);
    } while (choix > 20 || choix < 1);

    return choix;
}

void Opertion(int choix){
  double Result[8][4];
  double teta,re;
  switch(choix){
//    case 1 :
//        initwindow(1360,700);
//        repere();
//        Produit_deux_Matrice(Result);
//        Position_noms_point(Result);
//        Cube(Result);
//        cout<<"Donner la valeur de X : ";
//        cin>>re;
//        Translation_X(Result,re);
//        break;
    case 1 :
		Ligne(choix);
		break;
	case 2 :
		Ligne(choix);
		break;
	case 3 :
		Cercle(choix);
		break;
	case 4 :
		Cercle(choix);
		break;
	case 5 :
		Cercle(choix);
		break;
	case 6 :
		Ellipse(choix);
		break;
	case 7 :
		Ellipse(choix);
		break;
	case 8 :
		Ellipse(choix);
		break;
	case 9 :
		EllipseRotation();
		break;
	case 10 :
		clock(0, 0, 200, 14);
		break;
	case 11 :
		Pendulum();
		break;
	case 12 :
		Flower();
		break;
//	case 13 :
//		SymetrieParRapportXz();
//		break;
//	case 14 :
//		Aligne2Vecteur();
//		break;
//	case 15 :
//		ExerciceXVII();
//		break;
	}
}


