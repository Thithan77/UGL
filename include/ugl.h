#include "SDL2/sdl.h"
class ugl_handler{
public:
	/**
	 * Gets called each frame and in charge of handling events
	 * @return -1 to stop the program
	 */
	virtual int events() = 0;
	/**
	 * Gets called each frame and in charge of handling events
	 */
	virtual void update() = 0;
	/**
	 * Gets called each frame and in charge of handling events
	 */
	virtual void draw() = 0;
};
class UGL{
public:
	/**
	 * @param windowname Well it sounds clear to me
	*/
	UGL(const char* windowname);
	~UGL();
	/**
	 * @param m_handler Your {@link ugl_handler} class
	*/
	int mainLoop(ugl_handler* m_handler);
	/**
	Draw a non-filled rect on the screen
	Set the color with {@link UGL.setDrawColor}
	@param x position x
	@param y position y
	@param w width
	@param h height
	@return void
	*/
	void drawRect(int x,int y,int w, int h);
	/**
	Draw a filled rect on the screen
	Set the color with {@link UGL.setDrawColor}
	@param x position x
	@param y position y
	@param w width
	@param h height
	@return void
	*/
	void fillRect(int x,int y,int w, int h); // draw a filled rectangle
	/**
	 * Fill the entire window with color (r,g,b)
	 * @param r color red (0,255)
	 * @param g color green (0,255)
	 * @param g color blue (0,255)
	 * @return void
	*/
	void clearWindow(int r,int g,int b); // clear the window (paint this color on the whole screen)
	/**
	 * Set the drawing color to (r,g,b)
	 * @param r color red (0,255)
	 * @param g color green (0,255)
	 * @param g color blue (0,255)
	 * @return void
	 */
	void setDrawColor(int r,int g,int b); // change renderer draw color
	/**
	 * Render everything
	 * Call at the end of your draw function
	 */
	void render();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool running;
	ugl_handler* handler;
};