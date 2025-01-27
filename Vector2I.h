#pragma once

#include <iostream>
#include <cmath>


class Vector2I
{

public:
	double x = 0;
	double y = 0;

	Vector2I() = default;
	Vector2I(double x, double y) : x(x), y(y) {};

	static double distance(const Vector2I& a, const Vector2I& b);
	void toString() const;

	Vector2I operator+(const Vector2I& other) { return Vector2I(x + other.x, y + other.y); };
	Vector2I operator-(const Vector2I& other) { return Vector2I(x - other.x, y - other.y); };
	Vector2I operator*(const Vector2I& other) { return Vector2I(x * other.x, y * other.y); };
	Vector2I operator/(const Vector2I& other) { return Vector2I(x / other.x, y / other.y); };

	Vector2I operator+(const double& amount) { return Vector2I(x + amount, y + amount); };
	Vector2I operator-(const double& amount) { return Vector2I(x - amount, y - amount); };
	Vector2I operator*(const double& amount) { return Vector2I(x * amount, y * amount); };
	Vector2I operator/(const double& amount) { return Vector2I(x / amount, y / amount); };

	bool operator=(const Vector2I& other) { return (x == other.x && y == other.y ? true : false); };
	bool operator!=(const Vector2I& other) { return (x != other.x && y != other.y ? true : false); };
};