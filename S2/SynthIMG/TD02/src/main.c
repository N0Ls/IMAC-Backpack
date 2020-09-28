#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "../include/raytracer.h"
#include "../include/sdl_tools.h"

static const unsigned int WINDOW_WIDTH = 800;
static const unsigned int WINDOW_HEIGHT = 800;
static const unsigned int BIT_PER_PIXEL = 32;

int main(int argc, char** argv)
{
    // Initialisation de la SDL
    if(-1 == SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Impossible d'initialiser la SDL. Fin du programme.\n");
        return EXIT_FAILURE;
    }

    // Creation de la fenetre SDL
    SDL_Surface* surface = NULL;
    if(NULL == (surface = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, SDL_DOUBLEBUF))) {
        fprintf(stderr, "Impossible d'ouvrir la fenetre. Fin du programme.\n");
        return EXIT_FAILURE;
    }
    SDL_WM_SetCaption("TD02 Ex04", NULL);

    // Creation d'une surface SDL dans laquelle le raytracer dessinera
    SDL_Surface* framebuffer = NULL;
    if(NULL == (framebuffer = SDL_CreateRGBSurface(SDL_SWSURFACE, WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, 0, 0, 0, 0))) {
        fprintf(stderr, "Erreur d'allocation pour le framebuffer. Fin du programme.\n");
        return EXIT_FAILURE;
    }
    // Nettoyage du framebuffer par une couleur de fond (noir)
    SDL_FillRect(framebuffer, NULL, SDL_MapRGB(framebuffer->format, 0, 0, 0));


    // Creation de la scene
    //Scene scene = createScene();

    // Ajout d'objets dans la scene
    Sphere sphere_test = createSphere(1,1,1,255,0,0,0.5);
    Ray ray_test = createRay(0,0,0,1,1,1);
    Intersection intersect_test;
    float t;

    // Appel de la fonction de raytracing
    printf("x : %f, y : %f, z:%f \n",ray_test.origine.x, ray_test.origine.y,ray_test.origine.z);
    printf("%d\n",intersectsSphere(ray_test,sphere_test,&intersect_test, &t));


    int loop = 1;
    while(loop) {

        SDL_BlitSurface(framebuffer, NULL, surface, NULL);
        SDL_Flip(surface);

        SDL_Event e;
        while(SDL_PollEvent(&e)) {
            if(e.type == SDL_QUIT) {
                loop = 0;
                break;
            }
        }
    }

    SDL_Quit();

    return EXIT_SUCCESS;
}
