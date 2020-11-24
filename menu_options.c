#include <stdio.h>
#include <stdlib.h>
#include "menu_options.h"

void afficher_menu_options(){
    int c;
 printf("*****************************OPTIONS******************************\n");
    printf("                         1-CONFIGURATION                       \n");
    printf("                         2-SON                                 \n");
    printf("                         3-AIDE                                \n");
    printf("                         4-RETOUR                              \n");
    printf("***************************************************************\n");
        printf("selectionnez l'action a faire \n");
            scanf("%d",&c);
    ///******lancement
        switch(c){
                case 1:
                   printf("nouveau menu\n");
                break;

                case 2:
                     printf("nouveau menu\n");
                break;

                case 3:
                     printf("nouveau menu\n");
                break;

                case 4:
                    main();

                break;


                 }

}

