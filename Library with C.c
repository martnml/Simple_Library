//@Author : Zergaoui Mohamed El Amine
//@version : 6.20 
//@date :01/02/2018



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for key presses
#define ENTER 13
#define TAB 9
#define BKSP 8

// Global variable for category
char *categorie[30];

// Define the structure for a book
typedef struct livre {
    char cat[30];
    int lid;
    char lnom[30];
    char aut[30];
    int qt;
    float pr;
    struct livre *suiv;
} livre;

typedef struct livre *liste;

// Function to add a book to the list
liste ajouter(liste l) {
    int i;
    char qst = 'y';

    while (qst == 'y') {
        liste c = malloc(sizeof(liste));

        printf("------------------------  Enter the information --------------------------\n\n");
        strcpy(c->cat, *categorie);

        printf("Category: %s\n\n", c->cat);

        liste p = l;
        for (i = 0; p != NULL; (p) = (p)->suiv, i++)
            ;
        c->lid = i;

        printf("Book ID: %d\n\n", c->lid);

        printf("Book Name: ");
        scanf("%s", c->lnom);
        printf("\n");

        printf("Author: ");
        scanf("%s", c->aut);
        printf("\n");

        printf("Quantity: ");
        scanf("%d", &c->qt);
        printf("\n");

        printf("Price: ");
        scanf("%f", &c->pr);
        printf("\n\n");

        c->suiv = l;

        printf("\n\n**** Book has been successfully registered ****\n\nAdd another one? Y/N: ");
        scanf(" %c", &qst);
    }

    return l;
}

// Function to display the main menu
void mainmenu(liste l) {
    int c, d;

    printf("\n\n----------------------  Main Menu  --------------------------------- \n\n");
    printf("   1. Add a book\n\n   2. Delete a book\n\n   3. Search for a book\n\n");
    printf("   4. Issue a book\n\n   5. View the list of books\n\n   6. Modify a book\n\n");
    printf("   7. Close the application\n\n\n\n");
    printf("Enter your choice: ");
    scanf("%d", &c);

    if (c == 7) {
        printf("\n\n\n\n ------------ ! APPLICATION IS CLOSED !-------------\n\n\n");
        exit(0);
    } else {
        printf("\n\n--------------------- Choose a category ---------------------------- \n\n");

        printf("   1. Information Technology\n   2. Electronics\n   3. Electrical\n");
        printf("   4. Civil Engineering\n   5. Mechanical\n   6. Architecture\n");
        printf("   7. Return to the main menu\n\n");
        printf("Enter your choice: ");

        scanf("%d", &d);

        switch (d) {
            case 1:
                *categorie = "Information Technology";
                break;
            case 2:
                *categorie = "Electronics";
                break;
            case 3:
                *categorie = "Electrical";
                break;
            case 4:
                *categorie = "Civil Engineering";
                break;
            case 5:
                *categorie = "Mechanical";
                break;
            case 6:
                *categorie = "Architecture";
                break;
            case 7:
                mainmenu(l);
                break;
        }

        switch (c) {
            case 1:
                l = ajouter(l);
                break;
            // Add cases for other menu options
        }
    }
    printf("\n\n------------------EXIT-------------------\n\n");
}

// Other functions (supprimer, modifier, recherche, issue, voir, returnfunc, quiter, password) remain unchanged.

int main(int argc, char *argv[]) {
    liste l;
    l = NULL;

    password(l);

    return 0;
}
