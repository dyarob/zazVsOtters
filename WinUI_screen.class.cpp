#include    "WinUI_screen.class.hpp"

std::string		WinUI_screen::keyEvent(Player *player){
	timeout(0);
	int  ch  = getch();
	switch (ch){
		case 'w':
			if (player->getCoord().getX() > 1)
				player->getCoord() += *(new Vector2D(-1,0));
			return "haut";
		case 'a':
			if (player->getCoord().getY() > 1)
				player->getCoord() += *(new Vector2D(0,-1));
			return "gauche";
		case ' ':
			player->shoot();
			return "espace";
		case 'd':
			if (player->getCoord().getY() < (int)_width - 2)
				player->getCoord() += *(new Vector2D(0,1));
			return "droite";
		case 's':
			if (player->getCoord().getX() < (int)_height - 2)
				player->getCoord() += *(new Vector2D(1,0));
			return "bas";
		case 27:	// escape
			if (getch() == -1)
				return "escape";
			return "segfault";
		default:
			return "je met ce que je veux!";
	}
}

void	WinUI_screen::update ( List* l )
{
	werase ( win );
	box( win, 0, 0 );
	draw_all ( l );
	wrefresh ( win );
}

void	WinUI_screen::draw_all ( List* l )
{
	while (l)
	{
		draw( l->u );
		l = l->next;
	}
}

void	WinUI_screen::draw ( AGameObject* u )
{
	Vector2D v = u->getCoord();
	if (has_colors()) {
		if (u->getSkin()) {
			u->getSkin()->init_cp();
			wattron(win, COLOR_PAIR(u->getSkin()->_id));
			int	w = u->getWidth();
			if ( w == 1 )
			{
				char c = u->getSkin()->_c;
				mvwaddch( win, v.getX(), v.getY(), c);
			}
			else		// Zaz
			{
				int h = u->getHeight();
				//int j;
				char *c;
				for (int i = 0; i < h; ++i)
				{
					c = ((E_Zaz*)u)->img[i];
					mvwaddch( win, v.getX() + i, v.getY(), *c );
				}
			}
			wattroff(win, COLOR_PAIR(u->getSkin()->_id));
		}
	}
}

//--------------------

WinUI_screen::WinUI_screen(void) 
: WinUI()
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
}

WinUI_screen &	WinUI_screen::operator=(WinUI_screen const & src) {
	this->_height = src.getHeight();
	this->_width = src.getHeight();
	this->_heightMap = src.getHeight() * 3;
	this->_startX = src.getStartX();
	this->_startY = src.getStartY();
    return *this;
}
