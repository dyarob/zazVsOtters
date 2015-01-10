#include    "Vector2D.class.hpp"

Vector2D::Vector2D(void) _x(0), _y(0) {

}

Vector2D::Vector2D(int x, int y)
    : _x(x), _y(y) {

}

Vector2D::Vector2D(Vector2D const &src) {
    *this = src;
}

Vector2D              &Vector2D::operator=(Vector2D const &src) {
    this->_x        = src._x;
    this->_y        = src._y;
    return *this;
}

Vector2D              &Vector2D::operator-=(Vector2D const &rhs) {
    this->_x        -= rhs.getX();
    this->_y        -= rhs.getY();
    return *this;
}

Vector2D              &Vector2D::operator+=(Vector2D const &rhs) {
    this->_x        += rhs.getX();
    this->_y        += rhs.getY();
    return *this;
}

int                     Vector2D::getX(void)               const{
    return this->_x;
}

int                     Vector2D::getY(void)               const{
    return this->_y;
}

Vector2D::~Vector2D(void) {

}
