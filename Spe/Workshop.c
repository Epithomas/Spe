#include <stdio.h>
#include "Matrix.h"
#include "list.h"

typedef struct Vector2 Vector2;
struct Vector2
{
  int x;
  int y;
};

typedef struct Vector3 Vector3;
struct Vector3
{
  double x;
  double y;
  double z;
};

typedef struct Vector4 Vector4;
struct Vector4
{
  int x;
  int y;
  int z;
  int t;
};

//--------------------------------------------------------------------//
//--------------------------NEIGHBOURS--------------------------------//
//--------------------------------------------------------------------//

//rempli une liste des voisins du top de la liste actual
//_dans next si pas de contraste par rapport a la base
//_dans contrast si contrast
//note la cellule visitee, marqueur: -1

void neighbours(Matrix array, List *actual, List *next, List *contrast, double base)
{
  double cell = 0;
  
  //get coor
  //take number of columns
  int L = array.columns;
  
  Vector2 pos;
  pos.x = fromlist(actual,0)/L;
  pos.y = fromlist(actual,0)%L;
  suppression(actual);

  

  // printf("x: %d, y: %d\n",pos.x, pos.y);

 
  //up
  if(pos.x > 0)
    {
      cell = *(array.pt + (pos.x-1)*array.columns + pos.y);
      if(cell == base)
	{
	  insertion(next, (pos.x-1)*L+pos.y);
	}
      else if(cell != -1)
	{
	  insertion(contrast, (pos.x-1)*L + pos.y);
	}
    }
  //down
  if(pos.x < array.rows-1)
    {
      cell = *(array.pt + (pos.x+1)*array.columns + pos.y);
      if(cell == base)
	{
	  insertion(next, (pos.x+1)*L + pos.y);
	}
      else if(cell != -1)
	{
	  insertion(contrast, (pos.x+1)*L+ pos.y);
	}
    }
  //left
  if(pos.y > 0)
    {
      cell = *(array.pt + (pos.x)*array.columns + pos.y-1);
      if(cell == base)
	{
	  insertion(next, pos.x*L +pos.y-1);
	}
      else if(cell != -1)
	{
	  insertion(contrast, pos.x*L + pos.y-1);
	}
    }
  //right
  if(pos.y < array.columns-1)
    {
      cell = *(array.pt + (pos.x)*array.columns + pos.y+1);
      if(cell == base)
	{
	  insertion(next, pos.x*L + pos.y+1);
	}
      else if(cell != -1)
	{
	  insertion(contrast, pos.x*L + pos.y+1);
	}
    }

  //put a mark on the cell;
   *(array.pt + (pos.x)*array.columns + pos.y) = -1;
}

//-----------------------------------------------------------//
//--------------------Propa----------------------------------//
//-----------------------------------------------------------//

//renvoi le contraste depuis la 1ere cellule de la liste actual
//rempli la liste contrast
//pour valeur de comparaison: la valeur de la premiere entre de curr[ent];


void propa(Matrix array, List *curr, List *next, List *contrast)
{
  //List *link = initialisation();

  int boucle = 1;
  insertion(curr,0);
  insertion(curr,0);

  double base = *(array.pt);
  
  while(boucle)
    {
      while(fromlist(curr,0) != -1)
	{
	  //printf("boucle \n");
	  neighbours(array, curr, next, contrast,0);
	}
      if(fromlist(next,0) == -1)
	{
	  boucle = 0;
	}
      else
	{
	  curr = next;
	  next = initialisation();
	}
    }
}



int main()
{
  Matrix array = init_matrix_zero(10,10);
  //print_matrix(array);
  
  List *curr = initialisation();
  List *next = initialisation();
  List *contrast = initialisation();

  //*(array.pt + 0*array.columns + 0) = 1;
  //*(array.pt + (start.x)*array.columns + start.y) = 2;
  *(array.pt + 1*array.columns + 1) = 5;
  *(array.pt + 1*array.columns + 2) = 5;
  *(array.pt + 1*array.columns + 3) = 5;
  *(array.pt + 2*array.columns + 3) = 5;
  *(array.pt + 3*array.columns + 3) = 5;
  *(array.pt + 3*array.columns + 2) = 5;
  *(array.pt + 3*array.columns + 1) = 5;
  *(array.pt + 2*array.columns + 1) = 5;
    
  propa(array,curr,next,contrast);
  clean(contrast);
  afficherListe(contrast);
  afficherListe(next);
  
  //*(array.pt + (start.x)*array.columns + start.y+1) = 1;
  //*(array.pt + (start.x)*array.columns + start.y-1) = 1;
  
  print_matrix(array);

  return (0);
}
