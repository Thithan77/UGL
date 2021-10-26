#include "SDL2/sdl.h"
class ugl_handler{
public:
	virtual int events() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};
class UGL{
public:
	UGL(const char* windowname);
	~UGL();
	int mainLoop(ugl_handler* m_handler);
	void drawRect(int x,int y,int w, int h); // draw a non-filled rectangle
	void fillRect(int x,int y,int w, int h); // draw a filled rectangle
	void clearWindow(int r,int g,int b); // clear the window (paint this color on the whole screen)
	void setDrawColor(int r,int g,int b); // change renderer draw color
	void render();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool running;
	ugl_handler* handler;
};