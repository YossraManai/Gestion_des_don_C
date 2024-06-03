
#include<stdio.h>
#include<string.h>
#include "don1.h"


enum
{

     ID_DON,
     ID_DONNEUR,
     ID_ETS,
     TYPE_SANGUIN,
     QUANTITE,
     DATE_DON,    


     COLUMNS
};

//ajouter don

int ajouter_don(don d)
{

FILE *f;
f=fopen("don.txt","a+");
if(f!=NULL)
{
fprintf(f,"%s %s %s %s %s %s \n",d.id_don,d.id_donneur,d.id_ets,d.type_sanguin,d.quantite,d.date_don);
fclose(f);
return 0;
}
}

//afficher don

void afficher_don(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;

	GtkListStore *store;


char id_don[100];
char id_donneur[100];
char id_ets[100];
char type_sanguin[100];
char quantite[100];
char date_don[100];

store=NULL;

FILE *f;

store=gtk_tree_view_get_model(liste);
if(store==NULL)
{
renderer =gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id_don",renderer,"text",ID_DON,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("id_donneur",renderer,"text",ID_DONNEUR,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" id_ets",renderer,"text",ID_ETS,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes(" type_sanguin",renderer, "text",TYPE_SANGUIN,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
	
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("quantite",renderer,"text",QUANTITE,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
renderer = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("date_don",renderer,"text",DATE_DON ,NULL);
	gtk_tree_view_append_column (GTK_TREE_VIEW (liste),column);
    
     
   
      

}
	store=gtk_list_store_new(6,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f = fopen("don.txt","r");
if(f==NULL)
{
return;
}
else
{
 f=fopen("don.txt","a+");
	while(fscanf(f, "%s %s %s %s %s %s \n", id_don, id_donneur, id_ets, type_sanguin, quantite, date_don) != EOF) {
    printf("Lecture depuis le fichier: %s %s %s %s %s %s \n", id_don, id_donneur, id_ets, type_sanguin, quantite, date_don);
    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, ID_DON, id_don, ID_DONNEUR, id_donneur, ID_ETS, id_ets, TYPE_SANGUIN, type_sanguin, QUANTITE, quantite, DATE_DON, date_don, -1);
}

	
	fclose(f);}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

	
}

// supprimer don
void supprimer_don(char id_don[100])
{
FILE *f,*f1;
f=fopen("don.txt","r");
f1=fopen("don_tmp.txt","w");
 if ((f!=NULL) && (f1!=NULL))
{
while(fscanf(f,"%s %s %s %s %s %s \n",d.id_don,d.id_donneur,d.id_ets,d.type_sanguin,d.quantite,d.date_don)!=EOF)
{
if(strcmp(id_don,d.id_don)!=0)
{
fprintf(f1,"%s %s %s %s %s %s \n",d.id_don,d.id_donneur,d.id_ets,d.type_sanguin,d.quantite,d.date_don);
}
}
fclose(f) ;
fclose(f1);
remove("don.txt");
rename("don_tmp.txt","don.txt");
}
}
////////////////////////////////
void modifier_don(don d)
{
    don x;
    FILE *f;
    FILE *f2;

    f = fopen("don.txt", "r");
    f2 = fopen("don_tmp.txt", "w");

    if (f != NULL && f2 != NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %s \n", x.id_don, x.id_donneur, x.id_ets, x.type_sanguin, x.quantite, x.date_don) != EOF)
        {
            if (strcmp(d.id_don, x.id_don) == 0)
            {
                fprintf(f2, "%s %s %s %s %s %s \n", d.id_don, d.id_donneur, d.id_ets, d.type_sanguin, d.quantite, d.date_don);
            }
            else
            {
                fprintf(f2, "%s %s %s %s %s %s \n", x.id_don, x.id_donneur, x.id_ets, x.type_sanguin, x.quantite, x.date_don);
            }
        }
        fclose(f);
        fclose(f2);

        remove("don.txt");
        rename("don_tmp.txt", "don.txt");
    }
}


//////////////

int recherche_don(char id_don[])
{
    int test = 1;  // Initialisé à 1
    don x;
    FILE *f;
    f = fopen("don.txt", "r");

    if (f != NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %s \n", x.id_don, x.id_donneur, x.id_ets, x.type_sanguin, x.quantite, x.date_don) != EOF)
        {
            if (strcmp(id_don, x.id_don) == 0)
            {
                test = 0;  // Membre trouvé, mettez à jour à 0
                break;     // Pas besoin de continuer la recherche
            }
        }
        fclose(f);
    }

    return test;
}



/////
//verification de id 
int verifier_don(char id_don[])
{don d;
FILE *f;
int test = 0 ; 
f=fopen("don.txt","r");
if(f!=NULL) { 
while(fscanf(f,"%s %s %s %s %s %s \n",d.id_don,d.id_donneur,d.id_ets,d.type_sanguin,d.quantite,d.date_don)!=EOF)
{ 
if((strcmp(d.id_don,id_don)==0))
test=1 ;
 } }
fclose(f);
 
return test;
} 

// Fonction pour obtenir la quantité de chaque type de sang
void trouver_quantite_par_type(char resultats[8][100], int quantites[8])
{
    // Initialisez les tableaux pour stocker les résultats
    char types_sanguins[8][100] = {"AB+", "AB-", "A+", "A-", "B+", "B-", "O+", "O-"};
    int i;

    for (i = 0; i < 8; i++)
    {
        // Initialisez les quantités à zéro pour chaque type de sang
        quantites[i] = 0;
        strcpy(resultats[i], types_sanguins[i]);
    }

    don d;
    FILE *f;

    f = fopen("don.txt", "r");
    if (f != NULL)
    {
        while (fscanf(f, "%s %s %s %s %s %s \n", d.id_don, d.id_donneur, d.id_ets, d.type_sanguin, d.quantite, d.date_don) != EOF)
        {
            // Parcourez les types de sang et mettez à jour les quantités
            for (i = 0; i < 8; i++)
            {
                if (strcmp(d.type_sanguin, types_sanguins[i]) == 0)
                {
                    quantites[i] += atoi(d.quantite);
                }
            }
        }
        fclose(f);
    }
}



