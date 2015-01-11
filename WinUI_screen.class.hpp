#ifndef     _WINUI_SCREEN_HPP_
# define    _WINUI_SCREEN_HPP_

# include   <iostream>
# include	"WinUI.class.hpp"
# include	"AUnit.class.hpp"
# include	"List.struct.hpp"
# include    "Vector2D.class.hpp"

class       WinUI_screen : public WinUI
{

    protected:

    public:
		void	draw ( AUnit* u );
		void	draw_all ( List* l );
		void	update ( List* l );

        WinUI_screen(void);
        WinUI_screen(unsigned int, unsigned int, unsigned int, unsigned int);
        WinUI_screen(WinUI_screen const &src);
        ~WinUI_screen(void);

        WinUI_screen          &operator=(WinUI_screen const &);
        
        std::string  keyEvent(AUnit *player);
};

#endif      /* _WINUI_SCREEN_HPP_ */
