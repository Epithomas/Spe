#include <stdio.h>
#include <stdlib.h>

struct Vector3
{
  int R;
  int G;
  int B;
}

  Vector3 Blacked(Vector3 tableau, int hauteur, int largeur)
  {
    int noir = 0;
    for(int i = 0; i< hauteur; i++)
    {
      for(int j = 0; j< largeur; i++)
      {
	noir = noir + tableau[i][j].R;
	noir = noir + tableau[i][j].G;
	noir = noir + tableau[i][j].B;
	tableau[i][j] = noir/3;
	noir = 0;
      }
    }
    return tableau;
  }

int main(int argc, char *argv[])
{
  int hauteur = 0, largeur = 0;
  Vector3 tableau[hauteur][largeur];
  int noir = 0;

  FILE = *fichier;

  fichier = fopen("lien", "r");
  if(fichier != NULL)
    {
      /*beaucoup de chose à faire ici*/
    }
  
  
}
