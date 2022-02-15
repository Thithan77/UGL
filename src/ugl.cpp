#include "SDL2/sdl.h"
#include <SDL2/SDL_image.h>
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
ugl_texture UGL::loadTexture(const char* path,int w,int h){
	return ugl_texture(renderer,path,w,h);
}
void UGL::renderTexture(ugl_texture &texture,int x,int y){
	int w;
	int h;
	SDL_QueryTexture(texture.getTexture(), NULL, NULL, &w, &h);
	SDL_Rect to{x,y,w,h};
	SDL_RenderCopy(renderer,texture.getTexture(),NULL,&to);
}
ugl_texture::ugl_texture(SDL_Renderer* renderer, const char* path,int mw,int mh){
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, mw, mh);
	SDL_Surface* surface{};
	SDL_SetTextureBlendMode(texture,SDL_BLENDMODE_BLEND);
	surface = IMG_Load(path);
	uint32_t keyColor;
    // gets the proper color for white (255,255,255)
    keyColor = SDL_MapRGB(surface->format, 255, 255, 255);
    // enables transparency for all white pixels
    SDL_SetColorKey(surface, SDL_TRUE, keyColor);
	texture = SDL_CreateTextureFromSurface(renderer,surface);
	SDL_FreeSurface(surface);
	w = mw;
	he = mh;
}
ugl_texture::~ugl_texture(){
	
}
ugl_texture::ugl_texture(SDL_Texture* Mtexture){
	texture = Mtexture;
}
ugl_map::ugl_map(){

}
ugl_map::~ugl_map(){
	
}