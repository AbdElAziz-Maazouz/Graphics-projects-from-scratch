#include "ExerciceXVII.h"
#include "Symetrie.h"


int Menu_choix() {
    int choix;
    printf(" <---------------------[ 3D ]------------------->\n\n");
    printf(" -----------------------------------------------\n");
    printf(" | 1- Simple cube                               |\n");
    printf(" | 2- Translation Par Rapport a X               |\n");
    printf(" | 3- Translation Par Rapport a Y               |\n");
    printf(" | 4- Translation Par Rapport a Z               |\n");
    printf(" | 5- Rotation par Rapport X                    |\n");
    printf(" | 6- Rotation par Rapport Y                    |\n");
    printf(" | 7- Rotation par Rapport Z                    |\n");
    printf(" | 8- Rotation Parallele Z                      |\n");
    printf(" | 9- Rotation Parallele Y                      |\n");
    printf(" |10- Rotation Quelconque                       |\n");
    printf(" |11- Symetrie / XY                             |\n");
    printf(" |12- Symetrie / YZ                             |\n");
    printf(" |13- Symetrie / XZ                             |\n");
    printf(" |14- Aligne 2 Vecteur Quelconque               |\n");
    printf(" |15- ExerciceXVII                              |\n");
//    printf(" | 13- Projection cavalière                     |\n");
//    printf(" | 14- Projection cabinet                       |\n");
//    printf(" | 15- Projection Perspective                   |\n");
//    printf(" | 17- Symétrie par rapport à un planquelconque |\n");
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
		drawCube();
		break;
	case 2 :
		TranslationParRapportX();
		break;
	case 3 :
		TranslationParRapportY();
		break;
	case 4 :
		TranslationParRapportZ();
		break;
	case 5 :
		RotationParRapportX();
		break;
	case 6 :
		RotationParRapportY();
		break;
	case 7 :
		RotationParRapportZ();
		break;
	case 8 :
		RotationPZ();
		break;
	case 9 :
		RotationPY();
		break;
	case 10 :
		RotationQCour();
		break;
	case 11 :
		SymetrieParRapportXy();
		break;
	case 12 :
		SymetrieParRapportYz();
		break;
	case 13 :
		SymetrieParRapportXz();
		break;
	case 14 :
		Aligne2Vecteur();
		break;
	case 15 :
		ExerciceXVII();
		break;
	}
}

