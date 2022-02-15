#include "include/ugl.h"
#include <iostream>
class mainHandler:public ugl_handler{
public:
	int events() override{
		while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				return -1;
			}
		}
		return 0;
	}
	void update() override{

	}
	void draw() override{
		ugl->clearWindow(51,51,51);
		ugl->setDrawColor(90,90,90);
		ugl->drawRect(200,200,200,200);
		ugl->render();
	}
	mainHandler(UGL* gameM){
		ugl = gameM;
	}
	~mainHandler(){

	}
private:
	UGL* ugl;
	SDL_Event event;
};
int main(int argc,char* argv[]){
	UGL game("Test de fou UGL");
	mainHandler handler(&game);
	game.mainLoop(&handler);
	return 0;
}