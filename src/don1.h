
#include <gtk/gtk.h>


typedef struct
{
char id_don[100];
char id_donneur[100];
char id_ets[100];
char type_sanguin[100];
char quantite[100];
char date_don[100];

}don;

don d,m;


int ajouter_don(don d);
void supprimer_don(char id_don[100]);
void modifier_don(don d);
int verifier_don(char id_don[]);
void  afficher_don(GtkWidget *treeview);
int recherche_don (char id_don[]);
void trouver_quantite_par_type(char resultats[8][100], int quantites[8]);

