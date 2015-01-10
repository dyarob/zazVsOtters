#include    "WinUI_screen.class.hpp"

WinUI_screen::WinUI_screen(void) : WinUI()
{
}

WinUI_screen::WinUI_screen(unsigned int width, unsigned int height, unsigned int x, unsigned y)
: WinUI(width, height, x, y)
{
}

WinUI_screen::WinUI_screen(WinUI_screen const & src)
: WinUI(src)
{
}

WinUI_screen::~WinUI_screen(void)
{
	this->destroyWin();
}

WinUI_screen &	WinUI_screen::operator=(WinUI_screen const & src) {
	this->_height = src.getHeight();
	this->_width = src.getHeight();
	this->_heightMap = src.getHeight() * 3;
	this->_startX = src.getStartX();
	this->_startY = src.getStartY();
    return *this;
}
