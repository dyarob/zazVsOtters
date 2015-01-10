#ifndef     _VECTOR_2D_HPP_
# define    _VECTOR_2D_HPP_

# include   <iostream>

class       Vector2D {

    protected:
        unsigned int    _x;
        unsigned int    _y;

    public:
        Vector2D(void);
        Vector2D(int, int);
        Vector2D(Vector2D const &src);

        Vector2D          &operator=(Vector2D const &);
        Vector2D          &operator-=(Vector2D const &rhs);
        Vector2D          &operator+=(Vector2D const &rhs);
        
        int               getX(void)   const;
        int               getY(void)   const;

        virtual         ~Vector2D(void);
};

#endif      /* _VECTOR_2D_HPP_ */
