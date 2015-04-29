/*
** pong.c for 101pong in /home/ducate_c/rendu/101pong
** 
** Made by Corentin Ducatez
** Login   <ducate_c@epitech.net>
** 
** Started on  Thu Nov 13 14:31:56 2014 Corentin Ducatez
** Last update Wed Apr 29 18:58:14 2015 Corentin Ducatez
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<math.h>

static void	check_my_args(char **av)
{
  int	a;
  int	b;

  a = 1;
  while (av[a] != NULL)
    {
      b = 0;
      while (av[a][b] != '\0')
	{
	  if (av[a][b] != '-' && av[a][b] != '+' && (av[a][b] > '9' || av[a][b] < '0'))
	    {
	      printf("L'argument %d n'est pas un nombre\n", a);
	      exit(0);
	    }
	  b++;
	}
      a++;
    }
}

static int	my_coordinates(int x, int y, int z, int xb, int yb, int zb, int n)
{
  printf("A L'instant t+%d, les coordonnée de la balle seront ", n);
  while (n != 0)
    {
      xb += x;
      yb += y;
      zb += z;
      n--;
    }
  printf("(%d;%d;%d).\n", xb, yb, zb);
  return (0);
}

static int	my_incidence(int x, int y, int z, int xraq, int yraq)
{
  int		scalar_product;
  double	norm_u;
  double	norm_raq;
  double	angle;

  if (x == 0 && y == 0 && z == 0)
    {
      printf("(Comme le vecteur vitesse est un vecteur nul, la balle ne bouge pas)\n");
      return (0);
    }
  norm_u = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
  norm_raq = sqrt(pow(xraq, 2) + pow(yraq, 2));
  scalar_product = (x * x + y * y);
  angle = acos(scalar_product / (norm_u * norm_raq)) * (180 / M_PI);
  printf("L'angle d'incidence est de %.2f degrés.\n", angle);
  return (0);
}

static int	my_speed_vector(int xa, int ya, int za, int xb, int yb, int zb, int n)
{
  int	x;
  int	y;
  int	z;

  x = xb - xa;
  y = yb - ya;
  z = zb - za;
  printf("Les coordonnées du vecteur vitesse sont");
  printf(" (%d;%d;%d).\n", xb - xa, yb - ya, zb - za);
  my_coordinates(x, y, z, xb, yb, zb, n);
  my_incidence(x, y, z, x, y);
  return (0);
}

int	main(int ac, char **av)
{
  int	xa;
  int	ya;
  int	za;
  int	xb;
  int	yb;
  int	zb;
  int	n;

  if (ac < 8)
    { 
      printf("Usage: ./101pong xt-1 yt-1 zt-1 xt yt zt n\nAvec :\t_ xt-1, yt-1, zt-1 les coordonnées de la balle à l'instant t - 1\n");
      printf("\t_ xt, yt et zt les coordonnées de la balle à l'instant t\n\t_ n un entier strictement positif n\n");
    }
  else if (ac > 8)
    printf("(Ce programme n'utilise que les 8 premiers arguments fournis.)\n\n");
  if (ac >= 8)
    {
      check_my_args(av);
      xa = atoi(av[1]);
      ya = atoi(av[2]);
      za = atoi(av[3]);
      xb = atoi(av[4]);
      yb = atoi(av[5]);
      zb = atoi(av[6]);
      n = atoi(av[7]);
      if (n <= 0)
	printf("Le paramètre n doit être strictement positif.\n");
      else if (n > 0)
	my_speed_vector(xa, ya, za, xb, yb, zb, n);
    }
  return (0);
}
