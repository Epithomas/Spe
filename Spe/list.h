#ifndef LIST_H
#define LIST_H

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *next;
};

typedef struct List List;
struct List
{
  Element *first;
};

List *initialisation();
void insertion(List *list, int nvNombre);
void suppression(List *list);
void afficherListe(List *list);
void insertion_n(List *list, int new, int place);
int fromlist(List *list, int n);
void suppression(List *list);
void clean(List * list);

#endif
