#ifndef JEU_SOLO_H_INCLUDED
#define JEU_SOLO_H_INCLUDED
#define  taille 12
#define nb_couleur 7


/*************definition des elements du projets**/

/*******pion*****************/

typedef struct{
int x;///coordonees axe des lettres
int y;///coordonees axes des chiffres
int couleur; ///depend du tableau t_couleurs[]  -1-->pratiquable mais vide  -3-->impratiquable
int rang; ///0-->pion simple 1-->Roi
}pion;
/***************************/


/**********case**********************/
typedef struct{
int type;  /// 0-->impratiquable(case clair)  1-->pratiquable(case sombre)  -1--hors du plateau
int  statut; ///0--> libre 1-->occupe -1-->impossible -10-->bordure
char apparence;/// X--> bordures   -->case injouable  - -->case vide pratiquable   couleur-->opratiquable occuop
pion pion;

} D_case;


/*******************creation du tableau de jeu****************/
typedef D_case tab[taille][taille];
typedef tab DAMIER;





void jouer_solo();
int choix_pion();
int pion_adv(int choix_pre);
void construction_plateau(DAMIER plateau_de_jeu,int c1,int c2);
void afficher_damier(DAMIER plateau_de_jeu);
void  choisir_pion(D_case* plateau_de_jeu);
void  deplacer_pion(D_case* A_case,D_case* N_case);
int  pion_jouable(DAMIER  dames,int i,int j);
int  pion_jouable_cpu(DAMIER  dames,int i,int j);
int  prise_pion_gauche(DAMIER  dames,int i,int j,int adv);
int  prise_pion_droite(DAMIER  dames,int i,int j,int adv);
int  prise_pion_cpu_gauche(DAMIER  dames,int i,int j,int user);
int prise_pion_cpu_droite(DAMIER  dames,int i,int j,int user);
int convert_position(char lettre);
int possiblite_de_jeu(DAMIER  dames,int couleur_pion_User);
int possiblite_de_prise(DAMIER  dames,int couleur_pion_User,int couleur_pion_adv);
int possiblite_de_prise_cpu(DAMIER  dames,int couleur_pion_User,int couleur_pion_adv);
int possiblite_de_prise_G(DAMIER  dames,int i,int j,int couleur_pion_User,int couleur_pion_adv);
int possiblite_de_prise_D(DAMIER  dames,int i,int j,int couleur_pion_User,int couleur_pion_adv);
int possiblite_de_prise_cpu_G(DAMIER  dames,int i,int j,int couleur_pion_User,int couleur_pion_adv);
int possiblite_de_prise_cpu_D(DAMIER  dames,int i,int j,int couleur_pion_User,int couleur_pion_adv);
void Prise_pion(D_case* A_case,D_case* I_case,D_case* N_case);
int C;
int cu,cad;





/********************tableau de couleur***********************/
char t_couleurs[nb_couleur]={'N','B','V','R','J','G','M'};



int choix_pion(){
    int couleur;
     printf("\n \n Choisir la couleur de vos pions") ;
     printf("\n Noir(0)\n Blanc(1)\n Vert(2)\n Rouge(3)\n Jaune(4)\n Gris(5)\n Marron(6) \n");
     scanf("%d",&couleur);

     return couleur;
}
int pion_adv(int choix_pre){
    int couleur;
do{
   couleur=rand()%7;
}while(couleur==choix_pre);
return couleur;
}

void construction_plateau(DAMIER plateau_de_jeu,int c1,int c2){
cu=c1;
cad=c1;
 int ca=0;

 ///partie pratiquable du damier
        for(int i=0;i<12;i++)
            {
                for(int j=0;j<12;j++)
                    {
                        if((j==11 || j==0) || (i==11 || i==0) ){plateau_de_jeu[i][j].type=-1;}

                        else{
                            plateau_de_jeu[i][j].type=1-ca;
                            ca=1-ca;
                        }





///representation des cases
                        switch(plateau_de_jeu[i][j].type){

                        case (1):
                            plateau_de_jeu[i][j].apparence='-';
                            plateau_de_jeu[i][j].statut=0;
                            plateau_de_jeu[i][j].pion.couleur=-1;
                        break;
                        case (-1):
                             plateau_de_jeu[i][j].apparence=' ';
                             plateau_de_jeu[i][j].statut=-10;
                              plateau_de_jeu[i][j].pion.couleur=-3;
                        break;

                        case(0):
                        plateau_de_jeu[i][j].apparence=' ';
                        plateau_de_jeu[i][j].statut=-1;
                        plateau_de_jeu[i][j].pion.couleur=-3;
                        break;

                    }
                    }
                    ca=1-ca;
            }


///ajout des pions


///pion adverse
for(int i=10;i>6;i--)
    {
        for(int j=1;j<11;j++){
            if(plateau_de_jeu[i][j].type==1){

                plateau_de_jeu[i][j].apparence=t_couleurs[c2];
                plateau_de_jeu[i][j].statut=1;
                plateau_de_jeu[i][j].pion.x= i;
                plateau_de_jeu[i][j].pion.y= j;
                plateau_de_jeu[i][j].pion.couleur=c2;
                plateau_de_jeu[i][j].pion.rang=0;
            }
            else
                plateau_de_jeu[i][j].statut=-1;

        }
    }

///pion choisi


for(int i=1;i<5;i++)
{
        for(int j=1;j<11;j++){
            if(plateau_de_jeu[i][j].type==1){

                plateau_de_jeu[i][j].apparence=t_couleurs[c1];
                plateau_de_jeu[i][j].statut=1;
                 plateau_de_jeu[i][j].pion.x= i;
                plateau_de_jeu[i][j].pion.y= j;
                plateau_de_jeu[i][j].pion.couleur=c1;
                plateau_de_jeu[i][j].pion.rang=0;
            }
                else
                plateau_de_jeu[i][j].statut=-1;
        }
    }



}

void afficher_damier(DAMIER plateau_de_jeu){

    system("cls");
    printf("\n \n \n ");

    ///mise en place des lettres pour indiquer les positions
    printf("\t\t\t \t         ");
     for(int i=65;i<75;i++){
       printf("%c    ",i);
    }
        printf("\n \n");


    for(int i=11;i>=0;i--)
    {    printf(" \t \t \t \t");

            if(i!=0 && i!=11 && i!=10)
            printf("%d ",i);
            else if(i==0)
              printf("  ");
            else if(i==10)
              printf("%d",i);
            else if(i==11)
              printf("  ");


        for(int j=0;j<12;j++)
            {
                printf("  %c  " ,plateau_de_jeu[i][j].apparence );
            }
                printf("\n \n");
    }

    ///mise en place des lettres pour indiquer les positions
    printf("\t\t\t \t         ");
     for(int i=65;i<75;i++){

       printf("%c    ",i);
    }
    printf("\n \n");
}

void choisir_pion(D_case *plateau_de_jeu){

plateau_de_jeu->apparence='O';


}

void deplacer_pion(D_case* A_case,D_case* N_case){

    N_case->apparence=A_case->apparence;
    N_case->pion.couleur=A_case->pion.couleur;
    N_case->statut=1;

    A_case->apparence='-';
    A_case->statut=0;
    A_case->pion.couleur=-1;

}

int  pion_jouable(DAMIER  dames,int i,int j){

return (((dames[i+1][j+1].statut==0) || (dames[i+1][j-1].statut==0))); //|| ((((dames[i+1][j+1].statut==1) || (dames[i+2][j-2].statut==1)))       &&      (((dames[i+2][j+2].statut==0) || (dames[i+2][j-2].statut==0))) )  );

}

int  pion_jouable_cpu(DAMIER  dames,int i,int j){

return (((dames[i-1][j+1].statut==0) || (dames[i-1][j-1].statut==0)) );//|| ((((dames[i-1][j+1].statut==1) || (dames[i-1][j-1].statut==1)))       &&      (((dames[i-2][j+2].statut==0) || (dames[i-2][j-2].statut==0))) ) );

}


int  prise_pion_gauche(DAMIER  dames,int i,int j,int adv){

return ( (dames[i+1][j-1].statut==1) && (dames[i+1][j-1].pion.couleur==adv) && (dames[i+2][j-2].statut==0));

}
int  prise_pion_droite(DAMIER  dames,int i,int j,int adv){
return ( (dames[i+1][j+1].statut==1) && (dames[i+1][j+1].pion.couleur==adv) && (dames[i+2][j+2].statut==0));
}

int  prise_pion_cpu_droite(DAMIER  dames,int i,int j,int user){

return ( (dames[i-1][j-1].statut==1) && (dames[i-1][j-1].pion.couleur==user) && (dames[i-2][j-2].statut==0));
}

int prise_pion_cpu_gauche(DAMIER  dames,int i,int j,int user){

return ( (dames[i-1][j+1].statut==1) && (dames[i-1][j+1].pion.couleur==user) && (dames[i-2][j+2].statut==0));

}

int possiblite_de_jeu(DAMIER  dames,int couleur_pion_User){
int poss=0,i,j;
            for(i=1;i<=10;i++){

                    for(j=1;j<=10;j++){

                            if((dames[i][j].pion.couleur==couleur_pion_User) && ((dames[i+1][j+1].statut==0) || (dames[i+1][j-1].statut==0)))
                                poss++;
                        }

            }

return poss;

}

int possiblite_de_prise_G(DAMIER  dames,int i,int j,int couleur_pion_User,int couleur_pion_adv){
return(((dames[i][j].pion.couleur==couleur_pion_User) && ( (dames[i+1][j-1].statut==1) && (dames[i+1][j-1].pion.couleur==couleur_pion_adv) && (dames[i+2][j-2].statut==0))));
}
int possiblite_de_prise_D(DAMIER  dames,int i,int j,int couleur_pion_User,int couleur_pion_adv){
return (((dames[i][j].pion.couleur==couleur_pion_User) && ( (dames[i+1][j+1].statut==1) && (dames[i+1][j+1].pion.couleur==couleur_pion_adv) && (dames[i+2][j+2].statut==0))));
}

int possiblite_de_prise(DAMIER  dames,int couleur_pion_User,int couleur_pion_adv){

int prise=0;
int CONDITION_A;
int  CONDITION_B;
         for(int i=1;i<=10;i++){

                    for(int j=1;j<=10;j++){
CONDITION_A=((dames[i][j].pion.couleur==couleur_pion_User) && ( (dames[i+1][j-1].statut==1) && (dames[i+1][j-1].pion.couleur==couleur_pion_adv) && (dames[i+2][j-2].statut==0)));
CONDITION_B=((dames[i][j].pion.couleur==couleur_pion_User) && ( (dames[i+1][j+1].statut==1) && (dames[i+1][j+1].pion.couleur==couleur_pion_adv) && (dames[i+2][j+2].statut==0)));



        if(CONDITION_A || CONDITION_B )
                                prise++;
                        }

            }
            return prise;
}


int possiblite_de_prise_cpu(DAMIER  dames,int couleur_pion_User,int couleur_pion_adv){


    int prise=0;
int CONDITION_A;
int  CONDITION_B;
         for(int i=1;i<=10;i++){

                    for(int j=1;j<=10;j++){
CONDITION_A=((dames[i][j].pion.couleur==couleur_pion_adv) && ( (dames[i-1][j+1].statut==1) && (dames[i-1][j+1].pion.couleur==couleur_pion_User) && (dames[i-2][j+2].statut==0)));
CONDITION_B=((dames[i][j].pion.couleur==couleur_pion_adv) && ( (dames[i-1][j-1].statut==1) && (dames[i-1][j-1].pion.couleur==couleur_pion_User) && (dames[i-2][j-2].statut==0)));



        if(CONDITION_A || CONDITION_B )
                                prise++;
                        }

            }
            return prise;
}

int possiblite_de_prise_cpu_G(DAMIER  dames,int i,int j,int couleur_pion_User,int couleur_pion_adv){
return(((dames[i][j].pion.couleur==couleur_pion_adv) && ( (dames[i-1][j+1].statut==1) && (dames[i-1][j+1].pion.couleur==couleur_pion_User) && (dames[i-2][j+2].statut==0))));
}

int possiblite_de_prise_cpu_D(DAMIER  dames,int i,int j,int couleur_pion_User,int couleur_pion_adv){
return(((dames[i][j].pion.couleur==couleur_pion_adv) && ( (dames[i-1][j-1].statut==1) && (dames[i-1][j-1].pion.couleur==couleur_pion_User) && (dames[i-2][j-2].statut==0))));
}


int convert_position(char lettre){
char tab[10]={'A','B','C','D','E','F','G','H','I','J'};
int c;

for(int i=0;i<10;i++){

    if(tab[i]==lettre)
      c=i+1;

}
return c;
}

void Prise_pion(D_case* A_case,D_case* I_case,D_case* N_case){

    N_case->apparence=A_case->apparence;
    N_case->pion.couleur=A_case->pion.couleur;
    N_case->statut=1;

     I_case->apparence='-';
    I_case->pion.couleur=-1;
    I_case->statut=0;

    A_case->apparence='-';
    A_case->statut=0;
    A_case->pion.couleur=-1;

}


#endif // JEU_SOLO_H_INCLUDED
