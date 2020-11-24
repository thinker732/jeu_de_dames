#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jeu_solo.h"

int couleur_pion_User;
int couleur_pion_adv;
DAMIER dames;

int tour,player=1,cpu=0;

void jouer_solo(){

printf("**********************************************solo**************************************");

couleur_pion_User=choix_pion();
couleur_pion_adv=pion_adv(couleur_pion_User);

printf("ton choix c'est le %c",t_couleurs[couleur_pion_User]);
printf("\n ton choix c'est le %c",t_couleurs[couleur_pion_adv]);

construction_plateau(dames,couleur_pion_User,couleur_pion_adv);
afficher_damier(dames);


int px,py,newx,newy,cx,cy,newcx,newcy;
char charx ,charNx;

  tour=1;
do{

        /**********************jouer un pion*********************************/

        if(tour==1){

                if((possiblite_de_prise(dames,couleur_pion_User,couleur_pion_adv))!=0){

getch();
printf("tu peux faire une prise choisi un pion \n");


  do{
        printf("choisissez un pion qui va faire une prise  \n");
    printf("x: \t");
    getchar();
    scanf("%c",&charx);
    px=convert_position(charx);
    printf("y: \t");
    scanf("%d",&py);

 }while ( (dames[py][px].pion.couleur!=couleur_pion_User)  || !((prise_pion_gauche(dames,py,px,couleur_pion_adv)) || (prise_pion_droite(dames,py,px,couleur_pion_adv))) );

 if(possiblite_de_prise_G(dames,py,px,couleur_pion_User,couleur_pion_adv)){
  do{

    printf("\n ou souhaitez vous faire une prise \n");
    printf("x: \t");
   getchar();
    scanf("%c",&charNx);
    newx=convert_position(charNx);
    printf("y: \t");
    scanf("%d",&newy);

    }while(((py==newy) && (px==newx)) || (!(dames[newy][newx].statut==0)) || ((newy!=py+2) && (newx!=px-2)));

Prise_pion( &dames[py][px],&dames[py+1][px-1],&dames[newy][newx]);
}
 if(possiblite_de_prise_D(dames,py,px,couleur_pion_User,couleur_pion_adv)){
  do{

    printf("\n ou souhaitez vous faire une prise \n");
    printf("x: \t");
   getchar();
    scanf("%c",&charNx);
    newx=convert_position(charNx);
    printf("y: \t");
    scanf("%d",&newy);

    }while(((py==newy) && (px==newx)) || (!(dames[newy][newx].statut==0)) || ((newy!=py+2) && (newx!=px+2)));

Prise_pion( &dames[py][px],&dames[py+1][px+1],&dames[newy][newx]);
}
afficher_damier(dames);
tour=0;
                }

                else{


        do{
        printf("quel pion voulez vous deplacer \n");
    printf("x: \t");
    getchar();
    scanf("%c",&charx);
    px=convert_position(charx);
    printf("y: \t");
    scanf("%d",&py);

    if( (dames[py][px].pion.couleur!=couleur_pion_User) || ( !pion_jouable(dames,py,px)) )//|| ((prise_pion_droite(dames,py,px,couleur_pion_adv)) || (prise_pion_droite(dames,py,px,couleur_pion_adv)) ))*/)
      printf("ERREUR CHOISISSEZ UN PION JOUABLE!!!!!!!!!!!!!!!!! \n");

    }while ( (dames[py][px].pion.couleur!=couleur_pion_User)  || (!pion_jouable(dames,py,px))); // || ((prise_pion_gauche(dames,py,px,couleur_pion_adv)) || (prise_pion_droite(dames,py,px,couleur_pion_adv)) )) */ );

    do{

    printf("\n ou souhaitez vous le placer \n");
    printf("x: \t");
   getchar();
    scanf("%c",&charNx);
    newx=convert_position(charNx);
    printf("y: \t");
    scanf("%d",&newy);

    }while(((py==newy) && (px==newx)) || (!(dames[newy][newx].statut==0)));


    deplacer_pion(&(dames[py][px]),&(dames[newy][newx]));
      afficher_damier(dames);

tour=0;
//getch();
    }

        }



    /// JEU DE L'ORDINATEUR
    else{
    printf("CPU");

     if((possiblite_de_prise_cpu(dames,couleur_pion_User,couleur_pion_adv))!=0){

          do{
        cx=1+rand()%10;
        cy=1+rand()%10;

             printf("ETAPE 1 OK");

 }while ( (dames[cx][cy].pion.couleur!=couleur_pion_adv)  || !((prise_pion_cpu_gauche(dames,cx,cy,couleur_pion_User)) || (prise_pion_cpu_droite(dames,cx,cy,couleur_pion_User))) );


     if(possiblite_de_prise_cpu_G(dames,cx,cy,couleur_pion_User,couleur_pion_adv)){

        newcx=cx-2;
            newcy=cy+2;
            Prise_pion(&dames[cx][cy],&dames[cx-1][cy+1],&dames[newcx][newcy]);
            //printf("ETAPE 2 OK");

     }

     if(possiblite_de_prise_cpu_D(dames,cx,cy,couleur_pion_User,couleur_pion_adv)){
        newcx=cx-2;
            newcy=cy-2;
            Prise_pion(&dames[cx][cy],&dames[cx-1][cy-1],&dames[newcx][newcy]);
            //printf("ETAPE 2 OK");


    }



     afficher_damier(dames);
     tour=1-cpu;
    }


    else{
          do{

                        cx=1+rand()%10;
                       cy=1+rand()%10;

            // printf("ETAPE 1 OK");

    }while((dames[cx][cy].pion.couleur!=couleur_pion_adv)  || (!(pion_jouable_cpu(dames,cx,cy))) /*autre condition*/);

    do{
        newcx=cx-1;

        newcy=(rand()%2);

        if(newcy)
            newcy=cy+1;
        else
            newcy=cy-1;





            printf("ETAPE 2 OK");
    }while((!(dames[newcx][newcy].statut==0)) );


      deplacer_pion(&(dames[cx][cy]),&(dames[newcx][newcy]));
      afficher_damier(dames);
        tour=1-cpu;
    }
    }

}while(possiblite_de_jeu(dames,couleur_pion_User)!=0);

system("cls");
printf("\N \N \N \N \T \T \T \TVOUS AVEZ PERDU");

}
