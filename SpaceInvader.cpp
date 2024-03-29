//********* Projet de Moubarak et Charles : C'est un jeux vidéo appelé Space Invaders.

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <iostream>

//** Les Fonctions : **//
void accueil(void);
void piste_de_lancement(void);
void jouer_quitter(void);
void demarrage(void);
void quadrillage(void);
void personnage(void);
void ennemi(void);
void ennemi2(void);
void ennemi3(void);
void vitamine(void);
void menupause(void);
void gotoxy(int x, int y);
void color(int t,int f);

//** Les Différentes Variables **//
unsigned char touche;
int yi = 4;
int comptage = 0;
int choixmenu = 1;
int posx = 69;
int posy = 40;
int eposx = 0;
int eposy = 0;
int e2posx = 0;
int e2posy = 0;
int e3posx = 0;
int e3posy = 0;
int vposx = 0;
int vposy = 0;
int vie = 5;
int lasoluceV = 0;
int lasoluceE2 = 0;
int lasoluceE3 = 0;
int victoire = 0;

//** Corps du Programme **//
int main()
{
//** Position aléatoire sur l'axe Y **//
srand(time(NULL));
eposx = (rand() % 55) + 43;
e2posx = (rand() % 55) + 43;
e3posx = (rand() % 55) + 43;
vposx = (rand() % 55) + 43;
//** Curseur Invisible **//
  CONSOLE_CURSOR_INFO cci;
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  GetConsoleCursorInfo(hConsole, &cci);
  cci.bVisible = FALSE;
  SetConsoleCursorInfo(hConsole, &cci);

//** Taille de la fenêtre **//
	system("MODE CON COLS=160 LINES=50");
	system("color 0");

//** Accueil **//
	accueil();
	system("cls");

//** Piste de lancement **//
	piste_de_lancement();
	system("cls");
	demarrage();
	system("cls");

//** Jeu 1.0 **//
	quadrillage();
	gotoxy(posx,posy),
	printf("*******");
while (vie != 0)
 {
	if (touche == 32)
	{
		menupause();
	}
	//** Les Ifs de l'ennemi **//
	if ((posx > eposx - 7) && (posx < eposx + 5) && (eposy >= posy))
	{
		Sleep(1000);
		vie = vie - 1;
	}

	if (touche == 32)
	{
		menupause();
	}

	if (eposy >= posy)
	{
		gotoxy(eposx, eposy - 3);
		printf("     ");
		eposx = (rand() % 55) + 43;
		eposy = 0;
	}

	if (touche == 32)
	{
		menupause();
	}

	//** Les Ifs de l'ennemi 2 **//
	if ((posx > e2posx - 7) && (posx < e2posx + 5) && (e2posy == posy))
	{
		Sleep(1000);
		vie = vie - 1;
	}
	if (e2posy == posy)
	{
		gotoxy(e2posx, e2posy - 1);
		printf("     ");
		e2posx = (rand() % 55) + 43;
		e2posy = 0;
	}

	if (touche == 32)
	{
		menupause();
	}

	//** Les Ifs de l'ennemi 3 **//
	if ((posx > e3posx - 7) && (posx < e3posx + 5) && (e3posy >= posy))
	{
		Sleep(1000);
		vie = vie - 1;
	}
	if (e3posy >= posy)
	{
		gotoxy(e3posx, e3posy - 2);
		printf("     ");
		e3posx = (rand() % 55) + 43;
		e3posy = 0;
	}

	if (touche == 32)
	{
		menupause();
	}

	//** Les Ifs des vitamines **//
	if ((vposx >= posx) && (vposx < posx + 7) && (vposy == posy))
	{
		vie = vie + 1;
	}
	if (vposy == posy)
	{
		gotoxy(vposx, vposy - 1);
		printf(" ");
		vposx = (rand() % 55) + 43;
		vposy = 0;
	}

	if (touche == 32)
	{
		menupause();
	}

	//** Personnage **//
	personnage();

	if (touche == 32)
	{
		menupause();
	}

	//** Ennemi **//
	ennemi();

	if (touche == 32)
	{
		menupause();
	}

	//** Vitamine **//
	if (eposy > 10)
	{
		lasoluceV = 1;
	}
	if (lasoluceV == 1)
	{
		vitamine();
	}

	if (touche == 32)
	{
		menupause();
	}

	//** Ennemi 2**//
	if (vposy > 10)
	{
		lasoluceE2 = 1;
	}
	if (lasoluceE2 == 1)
	{
		ennemi2();
	}

	if (touche == 32)
	{
		menupause();
	}

	//** Ennemi 3**//
	if (e2posy > 10)
	{
		lasoluceE3 = 1;
	}
	if (lasoluceE3 == 1)
	{
		ennemi3();
	}
	gotoxy(110, 20);
	color(12, 0);
	printf("Vie : %d", vie);
	color(15, 0);
	if (touche == 32)
	{
		menupause();
	}
	Sleep(100);
	//***** Victoire *******//
	if (vie == 10)
	{
		victoire = victoire + 1;
		vie = 5;
		gotoxy(55, 2);
		color(12, 0);
		printf("%d Victoire !!!!!!! Rejouer ?", victoire);
		menupause();
		gotoxy(55, 2);
		printf("                             ");
		color(15, 0);
	}
 }
	gotoxy(50,2);
	printf("Perdu !!!!!!!");
	Sleep(7000);
	return(0);
}

void accueil(void)
{
	system("cls");
while (yi != 34)
  {
	comptage = comptage + 1;
	color(15,0);
	gotoxy(0,8);
    printf("\n                                                                                                                          *                 ");
    printf("\n                                                                                                                        * * *               ");
    printf("\n                                                                                                                       *  *  *              ");
    printf("\n                                                                                                                      *  * *  *             ");
    printf("\n                                                                                                                     ****   ****            ");
    printf("\n                                                                                                                    *-----------*           ");
    printf("\n                                                                                                                   *-------------*          ");
    printf("\n                                                                                                                   ***************          ");
    printf("\n                                                                                                                   *             *          ");
    printf("\n                                                                                                                   *             *          ");
    printf("\n                                                                                                                   *             *          ");
    printf("\n                                                                                                                  **             **         ");
    printf("\n                                                                                                                 ****           ****        ");
    printf("\n                                                                                                                 *****         *****        ");
    printf("\n                                                                                                                 ******       ******        ");
    printf("\n                                                                                                                 *******************        ");
    printf("\n                                                                                                                  *-----*   *-----*         ");
    printf("\n                                                                                                                 **-----*   *-----**        ");
    printf("\n                                                                                                                ***-----*   *-----***       ");
    printf("\n                                                                                                               ****-----*   *-----****      ");
    printf("\n                                                                                                                    ---       ---           ");
    printf("\n                                                                                                                     -         -            ");

	gotoxy(0,yi);
	printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
    printf("\n                                                                                                      ");
	yi = yi + 1;
	gotoxy(0,yi);
	color(11,0);
	printf("\n                                     ******* ********   *******   ********  ********   ");
	printf("\n                                    ******** ********* ********* ********* *********   ");
	printf("\n                                    **       **     ** **     ** **        **          ");
	printf("\n                                    **       **     ** **     ** **        **          ");
	printf("\n                                    **       ********* **     ** **        **          ");
	printf("\n                                    *******  ********  ********* **        *********   ");
	printf("\n                                    ******** **        ********* **        *********   ");
	printf("\n                                          ** **        **     ** **        **          ");
	printf("\n                                          ** **        **     ** **        **          ");
	printf("\n                                          ** **        **     ** **        **          ");
	printf("\n                                    ******** **        **     ** ********* *********   ");
	printf("\n                                    *******  **        **     **  ********  ********   ");
	printf("\n");printf("\n");
	printf("\n                    ********* **     ** **     **  *******  *****     ********  ********   ******** ");
	printf("\n                    ********* ***    ** **     ** ********* ******    ********* ********* ********* ");
	printf("\n                        **    ***    ** **     ** **     ** **  ***   **        **     ** **        ");
	printf("\n                        **    ****   ** **     ** **     ** **   ***  **        **     ** **        ");
	printf("\n                        **    ** **  ** **     ** **     ** **    *** **        ********* **        ");
	printf("\n                        **    ** **  ** **     ** ********* **     ** ********* ********  ********  ");
	printf("\n                        **    ** **  ** **     ** ********* **     ** ********* ****      ********* ");
	printf("\n                        **    **  ** ** **     ** **     ** **    *** **        ** **            ** ");
	printf("\n                        **    **  ** **  **   **  **     ** **   ***  **        **  **           ** ");
	printf("\n                        **    **   ****   ** **   **     ** **   **   **        **   **          ** ");
	printf("\n                    ********* **    ***    ***    **     ** ******    ********* **    **  ********* ");
	printf("\n                    ********* **     **     *     **     ** *****     ********  **     ** ********  ");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");

		if (comptage==1)
		{
		gotoxy(74,36);
		color(15,0);
		printf("Chargement");
		Sleep(1000);
		printf(".");
		Sleep(1000);
		printf(".");
		Sleep(1000);
		printf(".");
		Sleep(1000);
		gotoxy(74,36);
		printf("             ");
		Sleep(1000);
		gotoxy(70,36);
		printf("Decollage Immediat");
		Sleep(1000);
		gotoxy(70,36);
		printf("                  ");
		}

	Sleep(95);
  }
  gotoxy(0,11);
  	printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
	printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
    printf("\n                                                                                                      ");Sleep(40);
}

void piste_de_lancement(void)
{
	color(9,0);
	gotoxy(0,10);
	printf("\n                                                                **  *****  **   **  ******  ******            ");
	printf("\n                                                                ** **   ** **   ** **       **   **           ");
	printf("\n                                                                ** **   ** **   ** ******   ******            ");
	printf("\n                                                           **   ** **   ** **   ** **       **  **            ");
	printf("\n                                                            *****   *****   *****   ******  **   **           ");
	color(1,0);
	gotoxy(0,16);
	printf("\n                                                      ******* **   **  **  ****** ******  ****** ******       ");
	printf("\n                                                      **   ** **   **  **  ****** ****** **      **   **      ");
	printf("\n                                                      ** * ** **   **  **    **     **   ******  ******       ");
	printf("\n                                                      ******* **   **  **    **     **   **      **  **       ");
	printf("\n                                                           *   *****   **    **     **    ****** **   **      ");

 while (touche != 13) // Debut de la boucle, qui attend de détecter la touche [entrer]
 {
	touche = _getch();
		
	if (touche==72) // fleche haut
	 {
	   		choixmenu = 1;
	 }
	else if (touche==80) // fleche bas
	 {
			choixmenu = 2;
	 }
			if (choixmenu==2)
			{
					color(1,0);
			}
			else if (choixmenu==1) 
			{
				color(9,0);
			}
			
	gotoxy(0,10);
	printf("\n                                                                **  *****  **   **  ******  ******            ");
	printf("\n                                                                ** **   ** **   ** **       **   **           ");
	printf("\n                                                                ** **   ** **   ** ******   ******            ");
	printf("\n                                                           **   ** **   ** **   ** **       **  **            ");
	printf("\n                                                            *****   *****   *****   ******  **   **           ");
	gotoxy(0,16);
			if (choixmenu==2)
			{
					color(9,0);
			}
			else if (choixmenu==1)
			{
				color(1,0);
			}
	printf("\n                                                      ******* **   **  **  ****** ******  ****** ******       ");
	printf("\n                                                      **   ** **   **  **  ****** ****** **      **   **      ");
	printf("\n                                                      ** * ** **   **  **    **     **   ******  ******       ");
	printf("\n                                                      ******* **   **  **    **     **   **      **  **       ");
	printf("\n                                                           *   *****   **    **     **    ****** **   **      ");
 } // Fin de la boucle, vous avez appuyer sur [Entrer]
 if (choixmenu==2)
{
	exit(EXIT_SUCCESS);
}
}

void demarrage(void)
{
	color(15,0);
	gotoxy(74,24);
	printf("Lancement !!!");
	Sleep(750);
	gotoxy(74,24);
	printf("             ");
	Sleep(750);
	gotoxy(74,24);
	printf("Lancement !!!");
	Sleep(1000);
}

void quadrillage(void)
{
	gotoxy(0,0);
	printf("\n                                          |                                                            |");
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");	
	printf("\n                                          |                                                            |");
}

void personnage(void)
{
	if (_kbhit()) 
	{
		touche = _getch();
	}
		if (touche==77) // Fleche droite
	 {
	  gotoxy(posx,posy);
	  printf("       ");
	  posx = posx + 1;
	  gotoxy(posx,posy),
	  printf("*******");
	 }
	    if (touche==75) // Fleche gauche
	 {
      gotoxy(posx,posy);
	  printf("       ");
	   		posx = posx - 1;
	  gotoxy(posx,posy);
	  printf("*******");
	 }
	    if (posx==42) // Saturation Gauche
	 {
      gotoxy(posx,posy);
	  printf("       ");
	   		posx = posx + 1;
	  gotoxy(posx,posy);
	  printf("*******");
	 }
		else if (posx==97) // Saturation Droite
	 {
      gotoxy(posx,posy);
	  printf("       ");
	   		posx = posx - 1;
	  gotoxy(posx,posy);
	  printf("*******");
	 }
	gotoxy(0,40);
	printf("                                          |                                                            |");
	gotoxy(posx,posy);
	printf("*******");
}

void ennemi(void)
{
	gotoxy(eposx, eposy - 3);
	printf("     ");
	gotoxy(eposx,eposy);
	printf(".....");
	personnage();

	eposy = eposy + 3;
}

void vitamine(void)
{
	gotoxy(vposx, vposy - 1);
	printf(" ");
	gotoxy(vposx, vposy);
	printf("X");
	personnage();

	vposy = vposy + 1;
}

void ennemi2(void)
{
	gotoxy(e2posx, e2posy - 1);
	printf("     ");
	gotoxy(e2posx, e2posy);
	printf(".....");
	personnage();
	
	e2posy = e2posy + 1;
}

void ennemi3(void)
{
	gotoxy(e3posx, e3posy - 2);
	printf("     ");
	gotoxy(e3posx, e3posy);
	printf(".....");
	personnage();

	e3posy = e3posy + 2;
}

void menupause(void)
{
		while (touche != 13) // Debut de la boucle, qui attend de détecter la touche [entrer]
		{
			touche = _getch();

			if (touche == 72) // fleche haut
			{
				choixmenu = 1;
			}
			else if (touche == 80) // fleche bas
			{
				choixmenu = 2;
			}
			if (choixmenu == 2)
			{
				color(8, 0);
			}
			else if (choixmenu == 1)
			{
				color(15, 0);
			}

			gotoxy(55, 10);
			printf("     **  *****  **   **  ******  ****** ");
			gotoxy(55, 11);
			printf("     ** **   ** **   ** **       **   **");
			gotoxy(55, 12);
			printf("     ** **   ** **   ** ******   ****** ");
			gotoxy(55, 13);
			printf("**   ** **   ** **   ** **       **  ** ");
			gotoxy(55, 14);
			printf(" *****   *****   *****   ******  **   **");
			gotoxy(49, 16);
			if (choixmenu == 2)
			{
				color(15, 0);
			}
			else if (choixmenu == 1)
			{
				color(8, 0);
			}
			printf("******* **   **  **  ****** ******  ****** ****** ");
			gotoxy(49, 17);
			printf("**   ** **   **  **  ****** ****** **      **   **");
			gotoxy(49, 18);
			printf("** * ** **   **  **    **     **   ******  ****** ");
			gotoxy(49, 19);
			printf("******* **   **  **    **     **   **      **  ** ");
			gotoxy(49, 20);
			printf("     *   *****   **    **     **    ****** **   **");
		} // Fin de la boucle, vous avez appuyer sur [Entrer]
		 if (choixmenu==2)
{
	exit(EXIT_SUCCESS);
}
		 gotoxy(55, 10);
		 printf("                                        ");
		 gotoxy(55, 11);
		 printf("                                        ");
		 gotoxy(55, 12);
		 printf("                                        ");
		 gotoxy(55, 13);
		 printf("                                        ");
		 gotoxy(55, 14);
		 printf("                                        ");
		 gotoxy(49, 16);
		 printf("                                                  ");
		 gotoxy(49, 17);
		 printf("                                                  ");
		 gotoxy(49, 18);
		 printf("                                                  ");
		 gotoxy(49, 19);
		 printf("                                                  ");
		 gotoxy(49, 20);
		 printf("                                                  ");
		 color(15, 0);
}

void gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hConsole, pos);
}

void color(int t,int f)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,f*16+t);
}




//*****            Quelques Liens :     - https://openclassrooms.com/forum/sujet/tuto-couleur-console-windows
//*****                                 - https://www.commentcamarche.net/forum/affich-2604401-c-couleurs-de-la-console
//*****                                 - https://www.developpez.net/forums/d1090428/c-cpp/bibliotheques/qt/debuter/centrer-fenetre/
//*****                                 - https://openclassrooms.com/forum/sujet/cacher-le-curseur-clignotant-en-c-42160
//*****        Fleche 224 : Bas = 80 ; Haut = 72 ; Droite = 75 ; Gauche = 77 ; Entrer = 13 ; Espace = 27
