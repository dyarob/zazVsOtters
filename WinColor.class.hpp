#ifndef WINCOLOR_CLASS_HPP
# define WINCOLOR_CLASS_HPP

# include <vector>
# include <ncurses.h>
# include "CONST.h"


class		WinColor
{
	private:
		WinColor( void );
		WinColor( WinColor const &in );
		WinColor	&operator=( WinColor const &in );

		int				id;


		static unsigned int	curs_x;
		static unsigned int	curs_y;
		static int			curr_id;


	public:
		~WinColor( void );
		WinColor( int id_ );

		WINDOW			*win;

		void		draw( void );


		static std::vector<WinColor*>	wc;

		static void		init_wincolors();
		static void		refresh();
		static void		prev();
		static void		next();
		static short	getCursColor();
};

#endif /* !WINCOLOR_CLASS_HPP */
