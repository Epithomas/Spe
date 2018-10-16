#include<stdio.h>
#include<stdlib.h>
#include "list.h"

//-----------------------------MAIN-----------------------------------//

int main()
{
  int array[10][10] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,4,4,4,0,1,0,0,0},
    {0,0,4,1,4,0,1,0,0,0},
    {0,0,4,1,4,0,0,0,0,0},
    {0,0,4,4,4,0,0,0,0,0},
  };
  int hight = 10, lenght = 10;
  
  
  /*--------------affiche tableau--------------------*/
  for(int i = hight -1 ; i > -1; i--)
    {
      printf("|");
      for(int j = 0 ; j < lenght ; j++)
	{
	  printf(" %i |",array[i][j]);
	}
      printf("\n");
    }
  /*---------------------------------------------------*/
  
  List *maListe = initialisation();
  
  /*insertion(maListe, 4);
  insertion(maListe, 8);
  insertion(maListe, 15);
  
  afficherListe(maListe);*/

  int x = 0;
  int y = 0;
  int base = 0 ;
  
  //chercher les couleurs differentes de celle de la base
  //mettre en fonction 
  while(y < 9)
    {
      x++;

      if(x == 10)
	{
	  x = 0;
	  y++;
	}

      if(array[x][y] > base)
	{
	  insertion(maListe,y*100+x);
	}
    }

  printf("parcours arret a [%i][%i]\n", x,y);
  afficherListe(maListe);

  //printf("valeur: %i\n", fromlist(maListe, 0) );
  return 0;
}
