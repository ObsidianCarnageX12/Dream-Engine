// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
#include <stdio.h>

#include <SDL.h>

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 768;

bool init();
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;

bool init()
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    }
    else
    {
        gWindow = SDL_CreateWindow("Dream Engine SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL)
        {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        }
    }
    return success;

}

bool loadMedia()
{
    bool success = true;

    gHelloWorld = SDL_LoadBMP("Hello.bmp");
    if (gHelloWorld == NULL)
    {
        printf("Unable to load image %s! SDL Error: %s\n", "Hello.bmp", SDL_GetError() );
        success = false;

    }
    return success;
}

void close()
{
    //Deallocate Surface

    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = NULL;

    //Destroy Window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    //Quit SDL
    SDL_Quit();

}




int main(int argc, char** argv)
{
    if (!init())
    {
        printf("Failed to Initialize\n");
    }
    else
    {
        if (!loadMedia())
        {
            printf("Failed to load media!\n");

        }
        else
        {
            //Apply the image
            SDL_BlitSurface(gHelloWorld, NULL, gScreenSurface, NULL);

            //Update the surface
            SDL_UpdateWindowSurface(gWindow);

            //wait two seconds
            SDL_Delay(2000);

        }
       
    }
    close();
    return 0;
}
