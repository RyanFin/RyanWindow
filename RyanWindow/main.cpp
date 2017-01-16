#include "SDL.h"
#include "SDL_ttf.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = NULL; //set pointers to null when they contain no values
	//cout << window << endl;

	window = SDL_CreateWindow( "Subscribe!",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640, //window width
		480, //window height
		SDL_WINDOW_RESIZABLE);

	if(window == NULL){
		cout << "There was an error initialising the window!" << endl
			<<SDL_GetError() << endl;
	}

	

	//create a reference to the screen
	SDL_Surface* screen = SDL_GetWindowSurface(window);

	
	//create a rectangle
	SDL_Rect rect1 ;
	rect1.w = 64;
	rect1.h = 64;
	rect1.x = 10;
	rect1.y = 10;

	SDL_Rect* rect1Pointer = &rect1;

	//create a color
	Uint32 red = SDL_MapRGB(screen->format, 244, 66, 66);
	Uint32 purple = SDL_MapRGB(screen->format, 66, 75, 244);

	//fill the surface with the color
	//SDL_FillRect(screen,rect1,purple);
	SDL_FillRect(screen, NULL, red); //NULL will fill the entire area of the screen
	SDL_FillRect(screen, &rect1, purple); //&rect1 is the memory address of the rectangle (which pointers can store), this area will be filled with purple

	cout << &rect1 << endl;
	cout << "Should be identical: " << rect1Pointer << endl; 
	

	//update the changes
	SDL_UpdateWindowSurface(window);

	SDL_Event event;
	bool running = true;
	
	while(running){
		//pollEvent handles the event 
		while (SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				running = false;
				break;
			}

		}

		/*SDL_GetWindowPosition(window, &x, &y);
		
		cout << x <<"," << y << endl;*/
	}

	SDL_Delay(5000); //5 second delay
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}