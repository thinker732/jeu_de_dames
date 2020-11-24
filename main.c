#include <stdio.h>
#include <stdlib.h>
#include "menu-jouer.h"
#include <time.h>


void main()
{

    srand(time(NULL));
    int c;
    printf("*****************************MENU******************************\n");
    printf("                         1-JOUER                               \n");
    printf("                         2-OPTIONS                             \n");
    printf("                         3-CREDITS                             \n");
    printf("                         4-QUITTER                             \n");
    printf("***************************************************************\n");

/****evenement a note attende d'un choix********/
            printf("selectionnez l'action a faire \n");
            scanf("%d",&c);
    ///******lancement
        switch(c){
                case 1:
                   printf("\n \n \n");
                   system("cls");
                    afficher_menu_jouer();
                break;

                case 2:
                    printf("\n \n \n");
                    system("cls");
                     afficher_menu_options();
                break;

                case 3:
                     printf("\n \n \n");
                     system("cls");
                    afficher_menu_credits();
                break;

                case 4:
                     printf("AUREVOIR");

                break;


                 }

}
