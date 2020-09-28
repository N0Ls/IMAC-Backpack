#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/* Dimensions initiales et titre de la fenetre */
static const unsigned int WINDOW_WIDTH = 400;
static const unsigned int WINDOW_HEIGHT = 400;
static const char WINDOW_TITLE[] = "TD04 Ex01";

static float aspectRatio;

/* Espace fenetre virtuelle */
static const float GL_VIEW_SIZE = 200.;

/* Nombre de bits par pixel de la fenetre */
static const unsigned int BIT_PER_PIXEL = 32;

/* Nombre minimal de millisecondes separant le rendu de deux images */
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;


void reshape(SDL_Surface** surface, unsigned int width, unsigned int height)
{ 
    SDL_Surface* surface_temp = SDL_SetVideoMode(   
        width, height, BIT_PER_PIXEL,
        SDL_OPENGL | SDL_GL_DOUBLEBUFFER | SDL_RESIZABLE);
    if(NULL == surface_temp) 
    {
        fprintf(
            stderr, 
            "Erreur lors du redimensionnement de la fenetre.\n");
        exit(EXIT_FAILURE);
    }
    *surface = surface_temp;

    aspectRatio = width / (float) height;

    glViewport(0, 0, (*surface)->w, (*surface)->h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if( aspectRatio > 1) 
    {
        gluOrtho2D(
        -GL_VIEW_SIZE / 2. * aspectRatio, GL_VIEW_SIZE / 2. * aspectRatio, 
        -GL_VIEW_SIZE / 2., GL_VIEW_SIZE / 2.);
    }
    else
    {
        gluOrtho2D(
        -GL_VIEW_SIZE / 2., GL_VIEW_SIZE / 2.,
        -GL_VIEW_SIZE / 2. / aspectRatio, GL_VIEW_SIZE / 2. / aspectRatio);
    }
}


int main(int argc, char** argv) 
{
    /* Initialisation de la SDL */
    if(-1 == SDL_Init(SDL_INIT_VIDEO)) 
    {
        fprintf(
            stderr, 
            "Impossible d'initialiser la SDL. Fin du programme.\n");
        exit(EXIT_FAILURE);
    }
  
    /* Ouverture d'une fenetre et creation d'un contexte OpenGL */
    SDL_Surface* surface;
    reshape(&surface, WINDOW_WIDTH, WINDOW_HEIGHT);

    /* Initialisation du titre de la fenetre */
	SDL_WM_SetCaption(WINDOW_TITLE, NULL);
  

    /* Chargement de l'image */
    char image_path[] = "doc/logo_imac.jpg";
    SDL_Surface* image = IMG_Load(image_path);
    if(NULL == image) {
        fprintf(stderr, "Echec du chargement de l'image %s\n", image_path);
        exit(EXIT_FAILURE);
    }


    /* Boucle principale */
    int loop = 1;
    while(loop) 
    {
        /* Recuperation du temps au debut de la boucle */
        Uint32 startTime = SDL_GetTicks();
        
        /* Placer ici le code de dessin */
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        
        /* Echange du front et du back buffer : mise a jour de la fenetre */
        SDL_GL_SwapBuffers();
        
        /* Boucle traitant les evenements */
        SDL_Event e;
        while(SDL_PollEvent(&e)) 
        {
            /* L'utilisateur ferme la fenetre : */
            if(e.type == SDL_QUIT) 
            {
                loop = 0;
                break;
            }

            /* L'utilisateur ferme la fenetre : */
			if(e.type == SDL_QUIT) 
			{
				loop = 0;
				break;
			}
		
			if(	e.type == SDL_KEYDOWN 
				&& (e.key.keysym.sym == SDLK_q || e.key.keysym.sym == SDLK_ESCAPE))
			{
				loop = 0; 
				break;
			}
            
            /* Quelques exemples de traitement d'evenements : */
            switch(e.type) 
            {
                /* Redimensionnement fenetre */
				case SDL_VIDEORESIZE:
                    reshape(&surface, e.resize.w, e.resize.h);
                    break;

                /* Clic souris */
                case SDL_MOUSEBUTTONUP:
                    printf("clic en (%d, %d)\n", e.button.x, e.button.y);
                    break;
                
                /* Touche clavier */
                case SDL_KEYDOWN:
                    printf("touche pressee (code = %d)\n", e.key.keysym.sym);
                    break;
                    
                default:
                    break;
            }
        }

        /* Calcul du temps ecoule */
        Uint32 elapsedTime = SDL_GetTicks() - startTime;
        /* Si trop peu de temps s'est ecoule, on met en pause le programme */
        if(elapsedTime < FRAMERATE_MILLISECONDS) 
        {
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
        }
    }

    /* Liberation de la mémoire occupee par img */ 
    SDL_FreeSurface(image);

    /* Liberation des ressources associees a la SDL */ 
    SDL_Quit();
    
    return EXIT_SUCCESS;
}
