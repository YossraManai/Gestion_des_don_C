#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#include "don1.h"

void
on_deco_clicked                        (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{

}/*
void
on_button_don_clicked                  (GtkWidget *objet_graphique, gpointer user_data)
{
GtkWidget *dach ;
    GtkWidget *acc;
    dach = lookup_widget(objet_graphique, "login");
    gtk_widget_hide(dach);
    acc = create_acceuil_don();
    gtk_widget_show(acc);
}*/
void
on_afficher_don_clicked                (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *treeview;
        GtkWidget *window1;
        window1=lookup_widget(objet_graphique,"acceuil_don");
        treeview=lookup_widget(objet_graphique,"treeview1");
        
        afficher_don(treeview);
}

void
on_go_to_ajout_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1 ;
 GtkWidget *window2;

window1=lookup_widget(objet_graphique,"acceuil_don");
gtk_widget_hide(window1);
window2 =create_ajoute_don();
gtk_widget_show (window2);

}


void
on_go_to_modif_clicked(GtkWidget *objet_graphique,gpointer user_data)
{
GtkWidget *window1 ;
 GtkWidget *window2;

window1=lookup_widget(objet_graphique,"acceuil_don");
gtk_widget_hide(window1);
window2 =create_modifer_don();
gtk_widget_show (window2);
}
void
on_recherche_modif_gr_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
   char id_don[100];
   char id_donneur[100];
   char id_ets[100];
   char type_sanguin[100];
   char quantite[100];
   char date_don[100];
   int x;
   GtkWidget *input;
   GtkWidget *output;
   input=lookup_widget(objet_graphique,"entry6_md_gr");
   strcpy(id_don,gtk_entry_get_text(GTK_ENTRY(input)));
   x=verifier_don(id_don);
   output=lookup_widget(objet_graphique,"label24_md_gr");
 if ((strlen(id_don)==0))
{
       gtk_label_set_text(GTK_LABEL(output),"veuilez remplir la case");
}
else 
{
if (x == 1) // Membre trouvé
{
    gtk_label_set_text(GTK_LABEL(output), "membre existant");
}
else // Membre non trouvé
{
    gtk_label_set_text(GTK_LABEL(output), "membre non existant");
}

}
}



void
on_modifier_don_gr_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
   don d; 
       
        
   GtkWidget *input1, *input2,*input3,*input4,*input5,*combobox;
        GtkWidget *output1;
   input1=lookup_widget(objet_graphique,"entry6_md_gr");
   input2=lookup_widget(objet_graphique,"entry7_md_gr");
   input3=lookup_widget(objet_graphique,"entry8_md_gr");
   input4=lookup_widget(objet_graphique,"entry9_md_gr");
        input5=lookup_widget(objet_graphique,"entry10_md_gr");
   combobox=lookup_widget(objet_graphique,"combobox2_md_gr");
   output1=lookup_widget(objet_graphique,"label23_md_gr");
   



   strcpy(d.id_don,gtk_entry_get_text(GTK_ENTRY(input1)));
   strcpy(d.id_donneur,gtk_entry_get_text(GTK_ENTRY(input2)));
   strcpy(d.id_ets,gtk_entry_get_text(GTK_ENTRY(input3)));
   strcpy(d.quantite,gtk_entry_get_text(GTK_ENTRY(input4)));
        strcpy(d.date_don,gtk_entry_get_text(GTK_ENTRY(input5)));
   strcpy(d.type_sanguin,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));
   
   modifier_don (d);
    


       if ((strlen(d.id_don)==0)||(strlen(d.id_donneur)==0)||(strlen(d.id_ets)==0)||(strlen(d.date_don)==0) )
        
{
   
       gtk_label_set_text(GTK_LABEL(output1),"veuilez remplir toutes les cases");
}
else
{
     
     
     gtk_label_set_text(GTK_LABEL(output1),"modifié avec succés");
}
}


void
on_go_to_aff_md_gr_clicked             (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1 ;
 GtkWidget *window2;

window1=lookup_widget(objet_graphique,"modifer_don");
gtk_widget_hide(window1);
window2 =create_acceuil_don();
gtk_widget_show (window2);
}



void
on_recherche_supp_don_clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
   char id_don[100];
   char id_donneur[100];
   char id_ets[100];
   char type_sanguin[100];
   char quantite[100];
   char date_don[100];
   int x;
   GtkWidget *input;
   GtkWidget *output;
   input=lookup_widget(objet_graphique,"recherche_sup_don");
   strcpy(id_don,gtk_entry_get_text(GTK_ENTRY(input)));
   x=verifier_don(id_don);
   output=lookup_widget(objet_graphique,"label28_vr_gr_sup");
 if ((strlen(id_don)==0))
{
       gtk_label_set_text(GTK_LABEL(output),"veuilez remplir la case");
}
else 
{
if (x == 1) // Membre trouvé
{
    gtk_label_set_text(GTK_LABEL(output), "membre existant");
}
else // Membre non trouvé
{
    gtk_label_set_text(GTK_LABEL(output), "membre non existant");
}

}
}

void
on_sup_don_gr_clicked                  (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *input;
GtkWidget *output;
don d;
char ref[20];
input=lookup_widget(objet_graphique,"recherche_sup_don");
output=lookup_widget(objet_graphique,"label31gr");
strcpy(ref,gtk_entry_get_text(GTK_ENTRY(input)));
if(strcmp(ref,d.id_don)==0)
gtk_label_set_text(GTK_LABEL(output),"don n'existe pas");
else
{
supprimer_don(ref);
gtk_label_set_text(GTK_LABEL(output),"suppression avec succée");
}
}

void
on_go_to_aff_sup_gr_clicked            (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1 ;
 GtkWidget *window2;

window1=lookup_widget(objet_graphique,"supprim_don");
gtk_widget_hide(window1);
window2 =create_acceuil_don();
gtk_widget_show (window2);
}


void
on_go_to_supprim_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{GtkWidget *window1 ;
 GtkWidget *window2;

window1=lookup_widget(objet_graphique,"acceuil_don");
gtk_widget_hide(window1);
window2 =create_supprim_don();
gtk_widget_show (window2);

}


void
on_go_to_acceuil_ajout_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1 ;
 GtkWidget *window2;

window1=lookup_widget(objet_graphique,"ajoute_don");
gtk_widget_hide(window1);
window2 =create_acceuil_don();
gtk_widget_show (window2);

}


void
on_ajoute_don_gr_clicked               (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
   int a;
   don d;
   GtkWidget *input1, *input2,*input3,*input4,*input5,*combobox;
        GtkWidget *output1;
   input1=lookup_widget(objet_graphique,"entry1_aj_gr");
   input2=lookup_widget(objet_graphique,"entry2_aj_rg");
   input3=lookup_widget(objet_graphique,"entry3_aj_gr");
   input4=lookup_widget(objet_graphique,"entry4_aj_gr");
        input5=lookup_widget(objet_graphique,"entry5_date_ajout_gr");
   combobox=lookup_widget(objet_graphique,"combobox1_aj_gr");
   output1=lookup_widget(objet_graphique,"label16_verif_aj_gr");
   



   strcpy(d.id_don,gtk_entry_get_text(GTK_ENTRY(input1)));
   strcpy(d.id_donneur,gtk_entry_get_text(GTK_ENTRY(input2)));
   strcpy(d.id_ets,gtk_entry_get_text(GTK_ENTRY(input3)));
   strcpy(d.quantite,gtk_entry_get_text(GTK_ENTRY(input4)));
        strcpy(d.date_don,gtk_entry_get_text(GTK_ENTRY(input5)));
   strcpy(d.type_sanguin,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combobox)));

       if ((strlen(d.id_don)==0)||(strlen(d.id_donneur)==0)||(strlen(d.id_ets)==0)||(strlen(d.date_don)==0) )
{

       gtk_label_set_text(GTK_LABEL(output1),"veuilez remplir toutes les cases");
}
else
{
if (verifier_don(d.id_don)==1)
gtk_label_set_text(GTK_LABEL(output1),"don est existe ");
else
{
        ajouter_don(d);
        
        
        gtk_label_set_text(GTK_LABEL(output1),"ajout avec succés");
       
   
}
}
}


void
on_go_to_quantit___sang_clicked         (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1 ;
 GtkWidget *window2;

window1=lookup_widget(objet_graphique,"acceuil_don");
gtk_widget_hide(window1);
window2 =create_quantite_sang();
gtk_widget_show (window2);
}


void on_sang_plus_rare_clicked(GtkWidget *objet_graphique, gpointer user_data)
{
    char types_sanguin[8][100] = {"AB+", "AB-", "A+", "A-", "B+", "B-", "O+", "O-"};
    char resultats[8][100];
    int quantites[8];

    // Appelez la fonction pour trouver les quantités par type de sang
    trouver_quantite_par_type(resultats, quantites);

    // Trouvez le type de sang le moins fréquent
    int index_sang_plus_rare = 0;
    for (int i = 1; i < 8; i++)
    {
        if (quantites[i] < quantites[index_sang_plus_rare])
        {
            index_sang_plus_rare = i;
        }
    }

    // Obtenez le label correspondant
    GtkWidget *label_sang_plus_rare = lookup_widget(objet_graphique, "label33_sang_rare");

    // Ajoutez une vérification pour le label
    if (label_sang_plus_rare == NULL)
    {
        g_print("Erreur : Le label pour le sang le plus rare est NULL.\n");
        return;
    }

    // Mettez à jour le label avec le type de sang le moins fréquent et sa quantité
    char texte[100];
    sprintf(texte, "%s : %d", types_sanguin[index_sang_plus_rare], quantites[index_sang_plus_rare]);
    gtk_label_set_text(GTK_LABEL(label_sang_plus_rare), texte);
}



void
on_afficche_quantit___clicked          (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
    char types_sanguin[8][100] = {"AB+", "AB-", "A+", "A-", "B+", "B-", "O+", "O-"};
    char resultats[8][100];
    int quantites[8];

    // Appelez la fonction pour trouver les quantités par type de sang
    trouver_quantite_par_type(resultats, quantites);

    // Obtenez les labels correspondantes
    GtkWidget *labels[8];
    labels[0] = lookup_widget(objet_graphique, "label43");
    labels[1] = lookup_widget(objet_graphique, "label44");
    labels[2] = lookup_widget(objet_graphique, "label45");
    labels[3] = lookup_widget(objet_graphique, "label46");
    labels[4] = lookup_widget(objet_graphique, "label47");
    labels[5] = lookup_widget(objet_graphique, "label48");
    labels[6] = lookup_widget(objet_graphique, "label49");
    labels[7] = lookup_widget(objet_graphique, "label50");

    // Ajoutez des vérifications pour chaque label
    for (int i = 0; i < 8; i++)
    {
        if (labels[i] == NULL)
        {
            g_print("Erreur : Le label %s est NULL.\n", types_sanguin[i]);
            return;
        }
    }

    // Mettez à jour les labels avec les quantités correspondantes
    for (int i = 0; i < 8; i++)
    {
        char texte[100];
        sprintf(texte, " %d",  quantites[i]);
        gtk_label_set_text(GTK_LABEL(labels[i]), texte);
    }
}
void
on_go_to_aff_gr_clicked                 (GtkWidget       *objet_graphique,
                                        gpointer         user_data)
{
GtkWidget *window1 ;
 GtkWidget *window2;

window1=lookup_widget(objet_graphique,"quantite_sang");
gtk_widget_hide(window1);
window2 =create_acceuil_don();
gtk_widget_show (window2);
}










