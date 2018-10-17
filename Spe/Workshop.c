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

List *borders(Matrix array, double base, Vector2 start, List *actual)
{
  //printf("x= %i, y=%i \n",start.x, start.y);
  
  if(*(array.pt + start.x*array.columns + start.y) == -1)
    {
      return actual;
    }
  *(array.pt + start.x*array.columns + start.y) = -1;
  
  
  int up = 0;
  int down = 0;
  int right = 0;
  int left = 0;

  double cell;
  Vector2 newStart = start;
  
  //test if limit of array

  if(start.x < array.rows-1)
    {
      down = 1;
    }
  if(start.x > 0)
    {
      up = 1;
    }
  if(start.y < array.columns-1)
    {
      right = 1;
    }
  if(start.y > 0)
    {
      left = 1;
    }
    
  //actualise
  if(up)
    {
     
      cell = *(array.pt + (start.x -1)*array.columns + start.y);
      newStart.x --;
      
      printf("up sur: %i.%i \n",start.x,start.y);
      
      if(cell == base)
	{
	  actual = borders(array, base,newStart, actual);
	}
      else
	{
	  // insertion(actual,newStart.x+newStart.y/1000);
	}
    }

    if(down)
    {
     
      cell = *(array.pt + (start.x +1)*array.columns + start.y);
      newStart.x ++;
      if(cell == base)
	{
	  
	  actual = borders(array, base,newStart, actual);
	}
      else
	{
	  // insertion(actual,newStart.x+newStart.y/1000);
	}
    }
  cell = -1;
  
  if(left)
    {
      cell = *(array.pt + start.x*array.columns + start.y -1);
      newStart.y --;
      if(cell == base)
	{
	  actual = borders(array, base,newStart, actual);
	}
      else
	{
	  // insertion(actual,newStart.x+newStart.y/1000);
	}
    }
  
  if(right)
    {
      cell = *(array.pt + start.x*array.columns + start.y +1);
      newStart.y ++;
      if(cell == base)
	{
	  actual = borders(array, base,newStart, actual);
	}
      else
	{
	  // insertion(actual,newStart.x+newStart.y/1000);
	}
    }
  

  

  cell = -1;




  
  return actual;
}

int main()
{
  Matrix array = init_matrix_zero(10,10);
  //print_matrix(array);
  Vector2 start;
  start.x = 0;
  start.y =0;
  
  List *list = initialisation();
  //list =  borders(array, 0,start,list );
  //afficherListe(list);

  
  //*(array.pt + (start.x)*array.columns + start.y) = 2;
  //*(array.pt + (start.x +1)*array.columns + start.y) = 1;
  //*(array.pt + (start.x -1)*array.columns + start.y) = 1;
  //*(array.pt + (start.x)*array.columns + start.y+1) = 1;
  //*(array.pt + (start.x)*array.columns + start.y-1) = 1;
  print_matrix(array);
  
  return (0);
}
