/**
 * Programme réalisé pour le challenge efficacité de la SAÉ2.02 du département Info de Blagnac.
 * 
 * Ce programme est efficace car il n'implémente pas un algorithme de tri classique.
 * Il ne fait aucune comparaison entre deux chaînes.
 * 
 * Ce programme réalise une sorte de tri-fusion où chaque mot est envoyé dans une liste
 * correspondant à sa première lettre, et où toutes ces listes sont finalement concaténées.
 */

#include <stdlib.h>

/* Section 1 *****************************************************************
    Traitement des chaînes de caractères.
*/

/** Sous-chaîne d'un texte. debut inclu, fin exclue. */
static inline char *sous_chaine(char *texte, int debut, int fin_z) {
    char *mot = malloc(fin_z - debut + 1);
    int i = 0;
    for (int p = debut; p < fin_z; p++, i++) {
        mot[i] = texte[p];
    }
    mot[i] = '\0';
    return mot;
}

/* Section 2 *****************************************************************
   Table de correspondance : lettre -> rang dans l'alphabet étrange
   C'est une correspondance totale (pour tout char).
*/

/** Type d'une table. */
typedef unsigned char table_t[256];

/** Initialise la table avec un alphabet donné. */
static inline void init_table(table_t table_ordre, char* ordre, int tailleOrdre) {
    for (int i = 0; i < 256; i++) {
        table_ordre[i] = tailleOrdre;  // les lettres inconnues sont placées sans distinction
                                       // au tout dernier rang
    }
    for (int i = 0; i < tailleOrdre; i++) {
        table_ordre[ordre[i]] = i;
    }
}

/** Donne le rang d'un caractère. */
static inline int rang(table_t table_ordre, char c) {
    return table_ordre[c];
}

/* Section 3 *****************************************************************
    Liste chainée.
*/

/** Type d'un maillon. */
typedef struct cell {
    char* mot;
    struct cell* suivant;
} cell_t;

/** Type d'une liste. */
typedef struct {
    cell_t* tete;
    cell_t* queue;
} liste_t;

/** Valeur d'une liste vide. */
static liste_t liste_vide = {NULL, NULL};

/** Ajout d'une cellule à la fin d'une liste. */
static inline void ajouter_cellule(liste_t *li, cell_t* c) {
    c->suivant = NULL;
    if (li->tete == NULL) {
        li->tete = c;
        li->queue = c;
    } else {
        li->queue->suivant = c;
    }
}

/* Section 4 *****************************************************************
    Fonctions directement liées au problème à résoudre.
*/

/** Ajout d'un mot dans la bonne liste. */
static inline void ajouter_mot(table_t table_ordre, liste_t listes[], cell_t *free_cell, char *mot) {
    cell_t *cell = free_cell;
    cell->mot = mot;
    int li_idx = rang(table_ordre, mot[0]);
    liste_t *li = &listes[li_idx];
    ajouter_cellule(li, cell);
}

/** Fonction de résolution du problème. */
void solution(char** result, int tailleResult, char* texte, char* ordre, int tailleOrdre) {
    // table de correspondance
    table_t table_ordre;
    init_table(table_ordre, ordre, tailleOrdre);

    // listes pour chaque lettre
    liste_t listes[tailleOrdre + 1];
    for (int i = 0; i < tailleOrdre + 1; i++) {
        listes[i] = liste_vide;
    }

    // une cellule pour chaque mot (on se gère notre propre allocateur dans la pile)
    cell_t tas[tailleResult];
    int libreIdx = 0;

    // on parcourt la chaine pour la couper en mot et placer ces mots dans la bonne liste
    int debut_mot = -1;
    int i = 0;
    while (texte[i] != '\0') {
        char c = texte[i];
        if (('0' <= c && c <= '9')
                || ('A' <= c && c <= 'Z')
                || ('a' <= c && c <= 'z')) {
            if (debut_mot == -1) {  // nouveau mot
                debut_mot = i;
            }
        } else {
            if (debut_mot != -1) {  // fin d'un mot
                char *mot = sous_chaine(texte, debut_mot, i);
                ajouter_mot(table_ordre, listes, &tas[libreIdx++], mot);
                debut_mot = -1;
            }
        }
        i++;
    }
    if (debut_mot !=  -1) {  // dernier mot
        char *mot = sous_chaine(texte, debut_mot, i);
        ajouter_mot(table_ordre, listes, &tas[libreIdx++], mot);
    }

    // recopie des résultats dans le paramètre result
    int j = 0;
    for (int i = 0; i < tailleOrdre + 1; i++) {
        cell_t *c = listes[i].tete;
        while (c != NULL)  {
            result[j++] = c->mot;
            c = c->suivant;
        }
    }
}
