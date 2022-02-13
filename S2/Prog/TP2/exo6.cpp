#include <iostream>

using namespace std;

//Implémenter une structure DynaTableau et une structure Liste avec les comportements suivants :
//-ajoute(int valeur) : Ajoute une nouvelle valeur à la fin de la structure (alloue de la mémoire
//en plus si nécessaire)
//-recupere (int n) : Retourne le n ième entier de la structure
//-cherche (int valeur) : Retourne l’index de valeur dans la structure ou -1 s’il n’existe pas
//-stocke(intn,int valeur) : Redéfini lanième valeur de la structure avecvaleur


typedef struct Cellule{
    int valeur;
    struct Cellule * suivant;
}Cellule;

typedef struct Liste{
    Cellule * headListe;
} Liste;



typedef struct DynaTableau{
    int * tab;
    int taille;
    int tailleMax;
} DynaTableau;

void initialise(Liste* liste);
void initialise(DynaTableau* tableau);

void ajoute(Liste* liste, int valeur);
void recupere(Liste* liste, int n);
int cherche(Liste* liste, int valeur);
void stocke(Liste* liste, int n, int valeur);
void printListe(Liste* liste);

void ajoute(DynaTableau* tableau, int valeur);
void recupere(DynaTableau* tableau, int n);
int cherche(DynaTableau* tableau, int valeur);
void stocke(DynaTableau* tableau, int n, int valeur);
void printTab(DynaTableau* tab);

//void pousse_file();
//void retire_file();
//void pousse_pile();
//void retire_pile();


int main()
{
    cout << "Hello World!" << endl;

    Liste *newListeTest = (Liste *) malloc(sizeof(Liste));
    initialise(newListeTest);

    ajoute(newListeTest,1);
    ajoute(newListeTest,2);
    ajoute(newListeTest,3);


    //recupere(newListeTest,1);
    //cherche(newListeTest,2);
    //stocke(newListeTest,0,4);

    printListe(newListeTest);

//    DynaTableau tabTest;
//    initialise(&tabTest);
//    ajoute(&tabTest,3);
//    ajoute(&tabTest,12);
//    ajoute(&tabTest,3);
//    ajoute(&tabTest,5);


//    ajoute(&tabTest,1);
//    ajoute(&tabTest,2);

//    stocke(&tabTest,3,666);
//    printTab(&tabTest);
//    //recupere(&tabTest,2);
//    cherche(&tabTest, 12);


    return 0;
}

void initialise(Liste* liste)
{
    liste->headListe=NULL;
}

void printCellule(Cellule* cell){
    if(cell!=NULL){
        cout << cell->valeur <<endl;
        printCellule (cell->suivant);
    }
}

void printListe(Liste* liste){
    if(liste->headListe!=NULL){
        cout << liste->headListe->valeur <<endl;
        printCellule(liste->headListe->suivant);
    }
}


void ajoute(Liste* liste, int valeur)
{
    Cellule* newCell = (Cellule*) malloc(sizeof(Cellule));
    if(newCell == NULL){
        cout << "Bug Init cell" << endl;
        exit(1);
    }
    newCell ->valeur = valeur;
    newCell ->suivant = liste->headListe;
    liste->headListe=newCell;
}


void recupere(Liste* liste, int n){
    Liste *tmp = liste;
    int compteur = 0;
    if(tmp->headListe==NULL){
        cout << "liste vide" ;
    }
    else{
      while (tmp->headListe->suivant!=NULL && n < compteur)
      {
         compteur ++;
         tmp->headListe = tmp->headListe->suivant;
      }
      cout << "La valeur au rang " << n << " est " << tmp->headListe->valeur << endl;
      return;
    }
}

int cherche(Liste* liste, int valeur){
    Cellule *tmp2 = liste->headListe;
    int compteur = 0;
    if(tmp2==NULL){
        cout << "liste vide" ;
        return -1;
    }
    else{
      while (tmp2!=NULL)
      {
         if(tmp2->valeur == valeur){
            cout << "Nous avons trouvé " << valeur << " au rang " << compteur << endl;
            return compteur;
         }

         compteur ++;
         tmp2= tmp2->suivant;
         cout << tmp2->valeur << endl;
      }
      cout << "rien trouvé" << endl;
      return -1;
    }
}

void stocke(Liste* liste, int n, int valeur){
    Liste *tmp = liste;
    int compteur = 0;
    if(tmp->headListe==NULL){
        cout << "liste vide" ;
    }
    else{
      while (tmp->headListe->suivant!=NULL && n < compteur)
      {
         compteur ++;
         tmp->headListe = tmp->headListe->suivant;
      }
      tmp->headListe->valeur=valeur;
      return;
    }
}

void initialise(DynaTableau* tableau)
{
    tableau->tailleMax=4;
    tableau->tab=(int*) malloc(tableau->tailleMax * sizeof(int));
    if(tableau->tab==NULL){
        exit(1);
    }
    tableau->taille=0;
}
void ajoute(DynaTableau* tableau, int valeur){
    if(tableau->taille==tableau->tailleMax){
        tableau->tailleMax=tableau->tailleMax*2;
        tableau->tab=(int*) realloc(tableau->tab,tableau->tailleMax * sizeof(int));
    }
    tableau->tab[tableau->taille]=valeur;
    tableau->taille++;
}

void printTab(DynaTableau* tableau){
    for(int i=0; i<tableau->taille;i++){
        cout << tableau->tab[i] << endl;
    }
}

void recupere(DynaTableau* tableau, int n){
    if (n<tableau->taille){
        cout << "La valeur au rang " << n << " est " << tableau->tab[n]<< endl;
    }else {
        cout << "pas possible"<< endl;
    }
    return;
}

int cherche(DynaTableau* tableau, int valeur){
    for(int i=0; i <= tableau->taille;i++){
        if(valeur == tableau->tab[i]){

            cout << "trouvé " << valeur << " au rang " << i <<endl;
            return i;
        }
    }
        cout << "pas trouvé" << endl;
        return -1;
}

void stocke(DynaTableau* tableau, int n, int valeur){
    if (n<tableau->taille){
       tableau->tab[n]= valeur;
    }else {
        cout << "pas possible"<< endl;
    }
    return;
}
