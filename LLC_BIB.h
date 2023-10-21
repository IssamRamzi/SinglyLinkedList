/*
TODO:
    * Ajouter les fonctions de recherches
    * Ajouter les fonctions de tris
    * Ajouter les fonctions de changements de valeurs
    ! Fixer les problèmes de types de données
*/
#ifndef LLC_BIB_H
#define LLC_BIB_H
#include <stdio.h>

// Cellule de liste linéaire chainée d'entiers
typedef struct LLCint
{
    int val;
    struct LLCint *next;
}LLCint;
// Cellule de liste linéaire chainée de chaine de caractères
typedef struct LLCstring
{
    char *val;
    struct LLCstring *next;
}LLCstring;
// Cellule de liste linéaire chainée de float
typedef struct LLCfloat
{
    float val;
    struct LLCfloat *next;
}LLCfloat;
// Cellule de liste linéaire chainée de double
typedef struct LLCdouble
{
    double val;
    struct LLCdouble *next; 
}LLCdouble;
// Cellule de liste linéaire chainée de caractères
typedef struct LLCchar
{
    char val;
    struct LLCchar *next;   
}LLCchar;
// Taille d'une liste linéaire chainée
int LLCsize(LLCint *head){
    int size = 0;
    LLCint *tmp = head;
    while(tmp != NULL){
        size++;
        tmp = tmp->next;
    }
    return size;
}
// Affichage d'une liste linéaire chainée
void LLCprint(void *head){
    switch (sizeof(head))
    {
    case sizeof(LLCint):
        LLCint *current = (LLCint *)head;
        while (current != NULL)
        {
            printf("%d\n",current->val);
            current = current->next;
        }
    case sizeof(LLCfloat): {
            LLCfloat *current = (LLCfloat *)head;
            while (current != NULL) {
                printf("%f ", current->val);
                current = current->next;
            }
            break;
        }
        case sizeof(LLCdouble): {
            LLCdouble *current = (LLCdouble *)head;
            while (current != NULL) {
                printf("%lf ", current->val);
                current = current->next;
            }
            break;
        }
        case sizeof(LLCchar): {
            LLCchar *current = (LLCchar *)head;
            while (current != NULL) {
                printf("%c ", current->val);
                current = current->next;
            }
            break;
        }
        case sizeof(LLCstring): {
            LLCstring *current = (LLCstring *)head;
            while (current != NULL) {
                printf("%s ", current->val);
                current = current->next;
            }
            break;
        }
        default:
            printf("Unsupported data type.\n");
            break;
        }
}
// Ajout d'un élément au début d'une liste linéaire chainée
void LLCpushFront(void *head, void *toPush){
    switch (sizeof(head))
    {
    case sizeof(LLCint):
        LLCint *newNode = (LLCint *)toPush;
        newNode->next = (LLCint *)head;
        head = newNode;
        break;
    case sizeof(LLCfloat):
        LLCfloat *newNode = (LLCfloat *)toPush;
        newNode->next = (LLCfloat *)head;
        head = newNode;
        break;
    case sizeof(LLCdouble):
        LLCdouble *newNode = (LLCdouble *)toPush;
        newNode->next = (LLCdouble *)head;
        head = newNode;
        break;
    case sizeof(LLCchar):
        LLCchar *newNode = (LLCchar *)toPush;
        newNode->next = (LLCchar *)head;
        head = newNode;
        break;
    case sizeof(LCCstring):
        LLCstring *newNode = (LLCstring *)toPush;
        newNode->next = (LLCstring *)head;
        head = newNode;
        break;
    default:
        printf("Unsupported data type.\n");
        break;
    }
}
// Ajout d'un élément à la fin d'une liste linéaire chainée
void LLCpushBack(void *head, void *toPush){
    switch (sizeof(head))
    {
    case sizeof(LLCint):
        LLCint *newNode = (LLCint *)toPush;
        LLCint *current = (LLCint *)head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = NULL;
        break;
    case sizeof(LLCfloat):
        LLCfloat *newNode = (LLCfloat *)toPush;
        LLCfloat *current = (LLCfloat *)head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = NULL;
        break;
    case sizeof(LLCdouble):
        LLCdouble *newNode = (LLCdouble *)toPush;
        LLCdouble *current = (LLCdouble *)head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = NULL;
        break;
    case sizeof(LLCchar):
        LLCchar *newNode = (LLCchar *)toPush;
        LLCchar *current = (LLCchar *)head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = NULL;
        break;
    default:
        printf("Unsupported data type.\n");
        break;
    }
}
// Ajout d'un élément à un index donné
void LLCpushIndex(void *head, void *toPush, int index){
    int cmpt = 0;
    switch (sizeof(head))
    {
    case sizeof(LLCint):
        LLCint *newNode = (LLCint *)toPush;
        LLCint *current = (LLCint *)head;
        LLCint *prev = NULL;
        while (current != NULL)
        {
            if (cmpt == index)
            {
                prev->next = newNode;
                newNode->next = current;
                break;
            }
            cmpt++;
            prev = current;
            current = current->next;
        }
        printf("Index out of range.\n");
        break;
    case sizeof(LLCfloat):
        LLCfloat *newNode = (LLCfloat *)toPush;
        LLCfloat *current = (LLCfloat *)head;
        LLCfloat *prev = NULL;
        while (current != NULL)
        {
            if (cmpt == index)
            {
                prev->next = newNode;
                newNode->next = current;
                break;
            }
            cmpt++;
            prev = current;
            current = current->next;
        }
        printf("Index out of range.\n");
        break;
    case sizeof(LLCdouble):
        LLCdouble *newNode = (LLCdouble *)toPush;
        LLCdouble *current = (LLCdouble *)head;
        LLCdouble *prev = NULL;
        while (current != NULL)
        {
            if (cmpt == index)
            {
                prev->next = newNode;
                newNode->next = current;
                break;
            }
            cmpt++;
            prev = current;
            current = current->next;
        }
        printf("Index out of range.\n");
        break;
    case sizeof(LLCchar):
        LLCchar *newNode = (LLCchar *)toPush;
        LLCchar *current = (LLCchar *)head;
        LLCchar *prev = NULL;
        while (current != NULL)
        {
            if (cmpt == index)
            {
                prev->next = newNode;
                newNode->next = current;
                break;
            }
            cmpt++;
            prev = current;
            current = current->next;
        }
        printf("Index out of range.\n");
        break;
    default:
        printf("Unsupported data type.\n");
        break;
    }
}
// Retourne l'adresse d'une cellule à un index donné
void *LLCget(void *head, int index) {
    int cmpt = 0;
    
    switch (sizeof(head)) {
        case sizeof(LLCint):
            LLCint *currentInt = (LLCint *)head;
            while (currentInt != NULL) {
                if (cmpt == index) {
                    return currentInt;
                }
                cmpt++;
                currentInt = currentInt->next;
            }
            printf("Index out of range.\n");
            break;
            
        case sizeof(LLCfloat):
            LLCfloat *currentFloat = (LLCfloat *)head;
            while (currentFloat != NULL) {
                if (cmpt == index) {
                    return currentFloat;
                }
                cmpt++;
                currentFloat = currentFloat->next;
            }
            printf("Index out of range.\n");
            break;

        case sizeof(LLCdouble):
            LLCdouble *currentDouble = (LLCdouble *)head;
            while (currentDouble != NULL) {
                if (cmpt == index) {
                    return currentDouble;
                }
                cmpt++;
                currentDouble = currentDouble->next;
            }
            printf("Index out of range.\n");
            break;

        case sizeof(LLCchar):
            LLCchar *currentChar = (LLCchar *)head;
            while (currentChar != NULL) {
                if (cmpt == index) {
                    return currentChar;
                }
                cmpt++;
                currentChar = currentChar->next;
            }
            printf("Index out of range.\n");
            break;

        case sizeof(LLCstring):
            LLCstring *currentString = (LLCstring *)head;
            while (currentString != NULL) {
                if (cmpt == index) {
                    return currentString->val;
                }
                cmpt++;
                currentString = currentString->next;
            }
            printf("Index out of range.\n");
            break;

        default:
            printf("Unsupported data type.\n");
            break;
    }
}
// Supprime la 1ere cellule
void LLCpopFront(void *head){
    switch (sizeof(head))
    {
    case sizeof(LLCint):
        LLCint *current = (LLCint *)head;
        head = current->next;
        free(current);
        break;
    case sizeof(LLCint):
        LLCfloat *current = (LLCfloat *)head;
        head = current->next;
        free(current);
        break;
    case sizeof(LLCint):
        LLCdouble *current = (LLCdouble *)head;
        head = current->next;
        free(current);
        break;
    case sizeof(LLCint):
        LLCchar *current = (LLCchar *)head;
        head = current->next;
        free(current);
        break;
    default:
        printf("Unsupported data type.\n");
        break;
    }
}
// Supprime la dernière cellule
void LLCpopBack(void *head){
    switch (sizeof(head))
    {
    case sizeof(LLCint):
        LLCint *current = (LLCint *)head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        free(current);
        break;
    case sizeof(LLCfloat):
        LLCfloat *current = (LLCfloat *)head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        free(current);
        break;
    case sizeof(LLCdouble):
        LLCdouble *current = (LLCdouble *)head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        free(current);
        break;
    case sizeof(LLCchar):
        LLCchar *current = (LLCchar *)head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        free(current);
        break;
    case sizeof(LLCstring):
        LLCstring *current = (LLCstring *)head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        free(current);
        break;
    default:
        break;
    }
}
// Supprime une cellule a un index donné
void LLCpopIndex(void *head, int index){
    int cmpt = 0;
    switch (sizeof(head))
    {
    case sizeof(LLCint):
        LLCint *current = (LLCint *)head;
        LLCint *prev = NULL;
        while (current != NULL)
        {
            if (cmpt == index)
            {
                prev->next = current->next;
                free(current);
                break;
            }
            cmpt++;
            prev = current;
            current = current->next;
        }
        printf("Index out of range.\n")
        break;
    case sizeof(LLCfloat):
        LLCfloat *current = (LLCfloat *)head;
        LLCfloat *prev = NULL;
        while (current != NULL)
        {
            if (cmpt == index)
            {
                prev->next = current->next;
                free(current);
                break;
            }
            cmpt++;
            prev = current;
            current = current->next;
        }
        printf("Index out of range.\n")
        break;
    case sizeof(LLCdouble):
        LLCdouble *current = (LLCdouble *)head;
        LLCdouble *prev = NULL;
        while (current != NULL)
        {
            if (cmpt == index)
            {
                prev->next = current->next;
                free(current);
                break;
            }
            cmpt++;
            prev = current;
            current = current->next;
        }
        printf("Index out of range.\n")
        break;
    case sizeof(LLCchar):
        LLCchar *current = (LLCchar *)head;
        LLCchar *prev = NULL;
        while (current != NULL)
        {
            if (cmpt == index)
            {
                prev->next = current->next;
                free(current);
                break;
            }
            cmpt++;
            prev = current;
            current = current->next;
        }
        printf("Index out of range.\n")
        break;
    case sizeof(LLCstring):
        LLCstring *current = (LLCstring *)head;
        LLCstring *prev = NULL;
        while (current != NULL)
        {
            if (cmpt == index)
            {
                prev->next = current->next;
                free(current);
                break;
            }
            cmpt++;
            prev = current;
            current = current->next;
        }
        printf("Index out of range.\n")
        break;
    default:
        printf("Unsupported data type.\n");
        break;
    }
}
// Modifie la valeur d'un élément à un index donné

#endif // 