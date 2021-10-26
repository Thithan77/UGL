#include "SDL2/sdl.h"
#include "ugl.h"
#include <iostream>
UGL::UGL(const char* windowname){
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow(windowname,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,1080,720,SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	running = true;
}
UGL::~UGL(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
int UGL::mainLoop(ugl_handler* m_handler){
	handler = m_handler;
	while(running){
		int r = handler->events();
		if(r == -1){
			std::cout << "-1" << std::endl;
			running = false;
		}
		handler->update();
		handler->draw();

	}
	return 0;
}
void UGL::drawRect(int x,int y,int w, int h){
	SDL_Rect rect{x,y,w,h};
	SDL_RenderFillRect(renderer,&rect);
}
void UGL::fillRect(int x,int y,int w, int h){
	SDL_Rect rect{x,y,w,h};
	SDL_RenderFillRect(renderer,&rect);
}
void UGL::clearWindow(int r,int g,int b){
	SDL_SetRenderDrawColor(renderer,r,g,b,255);
	SDL_RenderClear(renderer);
}
void UGL::setDrawColor(int r,int g,int b){
	SDL_SetRenderDrawColor(renderer,r,g,b,255);
}
void UGL::render(){
	SDL_RenderPresent(renderer);
}