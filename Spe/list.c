#include<stdio.h>
#include<stdlib.h>

// LISTES CHAINEES
typedef struct Element Element;
struct Element
{
  int value;
  Element *next;
};

typedef struct List List;
struct List
{
  Element *first;
};

List *initialisation()
{
    List *liste = malloc(sizeof(*liste));
    Element *element = malloc(sizeof(*element));

    if (liste == NULL || element == NULL)
    {
        exit(EXIT_FAILURE);
    }

    element-> value = -1;
    element->next = NULL;
    liste->first = element;

    return liste;
}

void insertion(List *liste, int nvNombre)
{
    /* Création du nouvel élément */
    Element *nouveau = malloc(sizeof(*nouveau));
    if (liste == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->value = nvNombre;

    /* Insertion de l'élément au début de la liste */
    nouveau->next = liste->first;
    liste->first = nouveau;
}

void afficherListe(List *liste)
{
    if (liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    Element *actuel = liste->first;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->value);
        actuel = actuel->next;
    }
    printf("NULL\n");
}

int fromlist(List *liste, int n)
{
  int i = 0;
  if(liste == NULL)
    {
      exit(EXIT_FAILURE);
    }
  Element *actuel = liste -> first;

  while(actuel != NULL && i<n)
    {
      i++;
      actuel = actuel-> next;
    }
  if(actuel == NULL)
    {
      return -1;
    }
  return actuel-> value;
}

//not safe//
void insertion_n(List *list, int new, int place)
{
  int i = 0;
  Element *node = malloc(sizeof(*node));

  //verification good creation
  if(list == NULL || node== NULL)
    {
      exit(EXIT_FAILURE);
    }
  node -> value = new;

  Element *actuel = list -> first;

  //going to site
  while(actuel != NULL && i<place)
    {
      actuel = actuel -> next;
      i++;
    }

  //recreation of the links
  node-> next = actuel;
  if(actuel-> next != NULL)
    {
      actuel = actuel-> next;
      node-> next = actuel;
    }
}


void suppression(List *list)
{
    if (list == NULL)
    {
        exit(EXIT_FAILURE);
    }

    if (list->first != NULL)
    {
        Element *aSupprimer = list->first;
        list->first = list->first->next;
        free(aSupprimer);
    }
}
