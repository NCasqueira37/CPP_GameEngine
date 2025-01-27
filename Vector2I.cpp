#include "Vector2I.h"


void Vector2I::toString() const {
	std::cout << "x: " << x << ", y:" << y << std::endl;
}


double Vector2I::distance(const Vector2I& a, const Vector2I& b) {
	return (sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2)));
}