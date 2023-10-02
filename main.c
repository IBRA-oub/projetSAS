#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

struct date {
    int jour;
    int mois;
    int annee;
};

struct variables {
    int id;
    char titre[100];
    char description[100];
    char statut[100];
    struct date time[100];
};


 // Compteur du nombre de tâches actuelles
 int taille=0;


//----------------------------------ajouter une seule tâche----------------------------------------//

void seulTache(struct variables listeTaches[]) {




    //***ID***
    listeTaches[taille].id = taille + 1;
    printf("===> L'identification de cette tache est:  %d\n", listeTaches[taille].id);

    //***titre***
    printf("===> Entrer le titre de tache:  ");
    scanf(" %[^\n]", listeTaches[taille].titre);

    //***description***
    printf("===> Entrer la description de tache:  ");
    scanf(" %[^\n]", listeTaches[taille].description);

    //***deadline***


    printf("===> Entrer la date de limite de cette tache JJ/MM/AAAA:  ");
    scanf("%d/%d/%d",&listeTaches[taille].time->jour,&listeTaches[taille].time->mois,&listeTaches[taille].time->annee);




    //**statut**
    int choixStatut;



            printf("===> entrer le statut de cette tache(1-a realise/ 2-en cours de realisation / 3-finalisee): ");
            scanf("%d",&choixStatut);
            printf("\n");

            switch (choixStatut){

              case 1 :  strcpy(listeTaches[taille].statut,"a realise");
                        break;
              case 2 :  strcpy(listeTaches[taille].statut,"en cours de realisation");
                        break;
              case 3 :  strcpy(listeTaches[taille].statut,"finalisee");
                        break;

              default: printf("choix invalide!!\n");


            }


    // Ajoute la nouvelle tâche à la liste

        taille++;


                        printf("*********la tache ajouter avec succes********\n");
                        printf("\n");

}

//----------------------------------ajout pleusieur taches----------------------------------------//

void plusieureTaches(struct variables listeTaches[]){

    //**ID*
    int nbTaches;

  printf("===> Entrer nembre des taches vous touvez faire: ");
  scanf("%d",&nbTaches);


  for(int i=0 ; i < nbTaches ;i++){
    seulTache( listeTaches);
}
  }

//-----------------------------------tri des taches-----------------------------------------------//

                //-------------tri par ordre alphabitique----------------//

void triOrdreAlpha(struct variables listeTaches[]) {



               //--------tri par selection----------------//

    for (int i = 0; i < taille; i++) {

        for (int j = i+1; j < taille; j++) {

            if (strcmp(listeTaches[i].titre, listeTaches[j].titre) > 0) {

                struct variables temp = listeTaches[i];
                listeTaches[i] = listeTaches[j];
                listeTaches[j] = temp;

            }
        }

    }


    for (int i = 0; i < taille; i++) {

        printf("\t|ID          =>        \t%d             \n", listeTaches[i].id);
        printf("\t|Titre       =>        \t %s            \n", listeTaches[i].titre);
        printf("\t|Description =>        \t %s            \n", listeTaches[i].description);
        printf("\t|Date Limite =>        \t %02d/%02d/%04d\n", listeTaches[i].time->jour, listeTaches[i].time->mois, listeTaches[i].time->annee);
        printf("\t|Statut      =>        \t %s            \n", listeTaches[i].statut);

        printf("\n");
    }
}

                //------------tri par deadline---------------------------//

void triParOrderDeadline(struct variables listeTaches[]){



               //-------------tri par selection---------------------//

       for (int i = 0; i < taille; i++){

        for (int j =i+1; j < taille; j++){

            if ((listeTaches[i].time->annee > listeTaches[j].time->annee) ||
                ((listeTaches[i].time->annee == listeTaches[j].time->annee) && (listeTaches[i].time->mois > listeTaches[j].time->mois)) ||
                ((listeTaches[i].time->annee == listeTaches[j].time->annee) &&(listeTaches[i].time->mois == listeTaches[j].time->mois) && (listeTaches[i].time->jour > listeTaches[j].time->jour)))
            {
                struct variables temp = listeTaches[i];
                listeTaches[i] = listeTaches[j];
                listeTaches[j] = temp;

            }


        }
    }

     for (int i = 0; i < taille; i++) {
        printf("\t|ID          =>        \t%d             \n", listeTaches[i].id);
        printf("\t|Titre       =>        \t %s            \n", listeTaches[i].titre);
        printf("\t|Description =>        \t %s            \n", listeTaches[i].description);
        printf("\t|Date Limite =>        \t %02d/%02d/%04d\n", listeTaches[i].time->jour, listeTaches[i].time->mois, listeTaches[i].time->annee);
        printf("\t|Statut      =>        \t %s            \n", listeTaches[i].statut);
        printf("\n");
    }

}


            //--- les tâches dont le deadline est dans 3 jours ou moins--//

void tacheMoins3jours(struct variables listeTaches[]){



int dateLimit,jours;
    time_t seconds=time(NULL);
    struct tm *dt=localtime(&seconds);
    int cetteAnnee = (dt->tm_year + 1900);
    int ceMois =(dt->tm_mon + 1);
    int cetteJournee =dt->tm_mday;

    for (int i = 0; i < taille; i++){
        jours = listeTaches[i].time->annee*365+listeTaches[i].time->mois*30+listeTaches[i].time->jour;
        dateLimit = jours-(cetteAnnee*365+ceMois*30+cetteJournee);

        if(dateLimit >0 && dateLimit <= 3){

            printf("\t|ID          =>        \t%d             \n", listeTaches[i].id);
            printf("\t|Titre       =>        \t %s            \n", listeTaches[i].titre);
            printf("\t|Description =>        \t %s            \n", listeTaches[i].description);
            printf("\t|Date Limite =>        \t %02d/%02d/%04d\n", listeTaches[i].time->jour, listeTaches[i].time->mois, listeTaches[i].time->annee);
            printf("\t|Statut      =>        \t %s            \n", listeTaches[i].statut);
            printf("\n");
        }
    }



}

//-------------------------------------recherche une tache---------------------------------------//

               //-----------recherche par l'identification--------------//

void rechercheId(struct variables listeTaches[]){
    //**ID cherche**
        int entrerID,i;

    printf("===>Entrer l'identification de la tache: ");
    scanf("%d",&entrerID);

        int verifie1=0;
        for(i=0 ; i<taille ; i++){


            if(entrerID==listeTaches[i].id ){

                printf("*****La tache est trouve****\n");
                verifie1=1;
                break;

                    }
        }

            if( verifie1==0){

                printf("*******La tache n'exist pas*******\n");

            }


}

               //-----------recherche par titre-------------------------//

void rechercheTitre(struct variables listeTaches[]){



      char enterTitre[100];
      int i;
      int verifie2=0;

        printf("===>Entrer le titre de la tache: ");
        scanf(" %[^\n]", enterTitre);

            for(i=0 ; i<taille ; i++){

                if(strcmp(listeTaches[i].titre,enterTitre)==0){

                    printf("******la tache est trouve*****\n");
                    verifie2=1;
                break;
                        }
            }


                if(verifie2==0){
                    printf("******la tache n'exist pas********\n");
                }


}

//-------------------------------------modofication d'une tache----------------------------------//

               //----------modificatin de description--------------------//

void modifieDiscrTaches(struct variables listeTaches[]){

        printf("========================DESCRIPTION MODIFICATION=====================\n");

    int modifieDescrip;
    char nouvelleDescrip[300];
    printf("===>Entrer l'identification de tache: ");
    scanf("%d",&modifieDescrip);

    for(int i=0 ; i<taille ; i++){

        if(modifieDescrip==listeTaches[i].id){
        printf("===>Entrer la nouvelle description pour la tache: ");
        scanf(" %[^\n]",nouvelleDescrip);

        strcpy(listeTaches[i].description, nouvelleDescrip);

        printf("---------le description mise en jour avec succes---------\n");
        break;

        }


    }



}

             //-----------modification de statuts------------------------//

void modifieStatutTach(struct variables listeTaches[]){

  printf("========================STATUT MODIFICATION=====================\n");

    int modifieStatut;

    printf("===>Entrer l'identification de tache: ");
    scanf("%d",&modifieStatut);

    for(int i=0 ; i<taille ; i++){

        if(modifieStatut==listeTaches[i].id){
        int choixStatut;



            printf("===>Entrer le nouvelle statut de cette tache(1-a realise/ 2-en cours de realisation / 3-finalisee): ");
            scanf("%d",&choixStatut);
            printf("\n");

            switch (choixStatut){

              case 1 :  strcpy(listeTaches[i].statut,"a realise");
                        break;
              case 2 :  strcpy(listeTaches[i].statut,"en cours de realisation");
                        break;
              case 3 :  strcpy(listeTaches[i].statut,"finalisee");
                        break;

              default: printf("choix invalide!!\n");

            }

               printf("----------le statut mise en jour avec succes---------\n");

              break;

        }

    }


}

            //----------modification de deadline ------------------------//
void modifieDeadline(struct variables listeTaches[]){


 printf("========================DEADLINE MODIFICATION=====================\n");

    int modifieDlTache;
   struct date nouvelleDeadline;
    printf("===>Entrer l'identification de tache: ");
    scanf("%d",&modifieDlTache);

    for(int i=0 ; i<taille ; i++){

        if(modifieDlTache==listeTaches[i].id){



        printf("===>ntrer la nouvelle date de limite de cette tache JJ/MM/AAAA: ");
        scanf("%d/%d/%d",&nouvelleDeadline.jour,&nouvelleDeadline.mois,&nouvelleDeadline.annee);
        printf("\n");


        listeTaches[i].time->jour=nouvelleDeadline.jour;
        listeTaches[i].time->mois=nouvelleDeadline.mois;
        listeTaches[i].time->annee=nouvelleDeadline.annee;

        printf("----------le deadline mise en jour avec succes---------\n");
        printf("\n");
        break;

        }

    }


}

//-------------------------------------supprimer une taches--------------------------------------//

void supprimeTache( struct variables listeTaches[]){




        printf("========================SUPPRIMER UNE TACHE=====================\n");
        int supprimerTache;
        //struct variables tempsupp;

        printf("===>Entrer l'identification de tache qui tu supprimer: ");
        scanf("%d",&supprimerTache);
        printf("\n");

       for (int i=0; i < taille; i++){


        if( listeTaches[i].id==supprimerTache){

            for (int j=i; j < taille-1; j++){

               listeTaches[j] = listeTaches[j + 1];

            }
             taille--;

        }

    }
    printf("----------la tache est supprimer avec secces---------\n");
    printf("\n");

}

//-----------------------------------------statistique-------------------------------------------//

            //--------------------nembres des taches----------------------//

void nbrTotalTach(){

int nombreTaches=taille;
printf("===>Nembre total des taches est: %d\n",nombreTaches);
}

            //--------------nembres des taches complet et incomplet-------//

void nbrTachCopmIncomp(struct variables listeTaches[]){
 int tachComplet=0;
 int tachIncomplet=0;


 for(int i=0 ; i<taille ; i++){

  if(strcmp(listeTaches[i].statut,"finalisee")==0){
            tachComplet++;
            }
    else{
           tachIncomplet++;
     }
  }

   printf("===>Nembre des taches completes est: %d\n",tachComplet);
   printf("===>Nembre des taches incompletes est: %d\n",tachIncomplet);

}

           //--------------- nombre de jours restants --------------------//
void nmbJourRstant(struct variables listeTaches[]){
}

int main(){

   struct variables listeTaches[100];


      printf("==============================================GESTION DES TACHES TODO==========================================\n");
      int choixUtiliser;
      int choixAffiche;
      int choixModifir;
      int choixRecherch;
      int choixStatistique;

    do{

    printf("\t================MENU PRINCIPAL==============\n");
    printf("\t| 1-Ajouter une seul nouvelle tache.        |\n");
    printf("\t| 2-Ajouter plusieur nouvelle tache.        |\n");
    printf("\t| 3-Afficher la liste de toutes les taches. |\n");
    printf("\t| 4-Modifier une tache.                     |\n");
    printf("\t| 5-Supprimer une tache.                    |\n");
    printf("\t| 6-Rechercher une tache.                   |\n");
    printf("\t| 7-Statistiques.                           |\n");
    printf("\t| 8-Exist                                   |\n");
    printf("\t============================================\n");
    printf("\n");


    printf("==>quelle fonction qui tu vus effectuer: ");
    scanf("%d",&choixUtiliser);
    printf("\n");

    switch(choixUtiliser){

    case 1:seulTache(listeTaches);
            break;

    case 2: plusieureTaches(listeTaches);
            break;

    case 3:

                do{

                            printf("\t=============================SOUS MENU ==============================\n");
                            printf("\t| 1-Trier les taches par ordre alphabetique.                         |\n");
                            printf("\t| 2-Trier les taches par deadline                                    |\n");
                            printf("\t| 3-Afficher les taches dont le deadline est dans 3 jours ou moins.  |\n");
                            printf("\t| 4-Returner au menu principal                                       |\n");
                            printf("\t=====================================================================\n");
                            printf("\n");

                              printf("==>quelle fonction qui tu vus effectuer: ");
                              scanf("%d",&choixAffiche);
                              printf("\n");
                              switch(choixAffiche){

                                    case 1:triOrdreAlpha(listeTaches);
                                        break;
                                    case 2:triParOrderDeadline(listeTaches);
                                        break;
                                    case 3:tacheMoins3jours(listeTaches);
                                        break;
                                    case 4:
                                        break;
                                    default:
                                        printf("--choix in valid!! merci d'entrer un choix valide--\n");

                              }
                }while(choixAffiche!=4);
            break;

    case 4:
                 do{

                            printf("\t=================SOUS MENU ==============\n");
                            printf("\t| 1-Modifier la description d'une tache. |\n");
                            printf("\t| 2-Modifier le statut d'une tache.      |\n");
                            printf("\t| 3-Modifier le deadline d'une tache.    |\n");
                            printf("\t| 4-Returner au menu principal.          |\n");
                            printf("\t=========================================\n");
                            printf("\n");

                              printf("==>quelle fonction qui tu vus effectuer: ");
                              scanf("%d",&choixModifir);
                              printf("\n");
                              switch(choixModifir){

                                    case 1:modifieDiscrTaches(listeTaches);
                                        break;
                                    case 2:modifieStatutTach(listeTaches);
                                        break;
                                    case 3:modifieDeadline(listeTaches);
                                        break;
                                     case 4:
                                        break;
                                    default:
                                        printf("--choix in valid!! merci d'entrer un choix valide--\n");

                              }
                }while(choixModifir!=4);
            break;

    case 5:

        supprimeTache(listeTaches);

        break;

    case 6:
                do{

                            printf("\t==================SOUS MENU =================\n");
                            printf("\t| 1-Rechercher une tache par son Identifiant.|\n");
                            printf("\t| 2-Rechercher une tache par son Titre.      |\n");
                            printf("\t| 3-Returner au menu principal.              |\n");
                            printf("\t=============================================\n");
                            printf("\n");

                              printf("==>quelle fonction qui tu vus effectuer: ");
                              scanf("%d",&choixRecherch);
                              printf("\n");
                              switch(choixRecherch){

                                    case 1:rechercheId(listeTaches);
                                        break;
                                    case 2:rechercheTitre(listeTaches);
                                        break;
                                     case 3:
                                        break;
                                    default:
                                        printf("--choix in valid!! merci d'entrer un choix valide--\n");

                              }
                }while(choixRecherch!=3);


            break;

    case 7:

                  do{

                            printf("\t================================SOUS MENU ==============================\n");
                            printf("\t| 1-Afficher le nombre total des taches.                                |\n");
                            printf("\t| 2-Afficher le nombre de taches completes et incompletes.              |\n");
                            printf("\t| 3-Afficher le nombre de jours restants jusqu'au delai de chaque tache.|\n");
                            printf("\t| 4-Returner au menu principal.                                         |\n");
                            printf("\t========================================================================\n");
                            printf("\n");

                              printf("==>quelle fonction qui tu vus effectuer: ");
                              scanf("%d",&choixStatistique);
                              printf("\n");
                              switch(choixStatistique){

                                    case 1:nbrTotalTach();
                                        break;
                                    case 2:nbrTachCopmIncomp(listeTaches);
                                        break;
                                    case 3:nmbJourRstant(listeTaches);
                                        break;
                                     case 4:
                                        break;
                                    default:
                                        printf("--choix in valid!! merci d'entrer un choix valide--\n");

                              }
                }while(choixStatistique!=4);
            break;


    default:
        printf("EXIST");

    }
    }while(choixUtiliser!=8);

    return 0;
}


