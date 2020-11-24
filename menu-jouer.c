#include <stdio.h>
#include <stdlib.h>
#include "menu-jouer.h"


void afficher_menu_jouer(){
          int c;
    printf("*****************************JOUER******************************\n");
    printf("                         1-SOLO                                \n");
    printf("                         2-MULTIJOUEUR                         \n");
    printf("                         3-RETOUR                              \n");
    printf("***************************************************************\n");

/****evenement a note attende d'un choix********/
            printf("selectionnez l'action a faire \n");
            scanf("%d",&c);
    ///******lancement
        switch(c){
                case 1:
                    printf("\n \n \n");
                    system("cls");
                    jouer_solo();
                break;

                case 2:
                     printf("nouveau menu\n");
                     system("cls");
                break;

                case 3:
                     main();
                break;


                 }
}
