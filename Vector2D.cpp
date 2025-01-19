#include "Vector2D.h"


void Vector2D::toString() const {
	std::cout << "x: " << x << ", y:" << y << std::endl;
}


double Vector2D::distance(const Vector2D& a, const Vector2D& b) {
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}