#pragma once

#include <iostream>
#include <cmath>

class Vector2D
{

public:
	double x = 0;
	double y = 0;

	Vector2D() = default;
	Vector2D(double x, double y) : x(x), y(y) {};

	static double distance(const Vector2D& a, const Vector2D& b);
	void toString() const;

	Vector2D operator+(const Vector2D& other) { return Vector2D(x + other.x, y + other.y); };
	Vector2D operator-(const Vector2D& other) { return Vector2D(x - other.x, y - other.y); };
	Vector2D operator*(const Vector2D& other) { return Vector2D(x * other.x, y * other.y); };
	Vector2D operator/(const Vector2D& other) { return Vector2D(x / other.x, y / other.y); };

	Vector2D operator+(const double& amount) { return Vector2D(x + amount, y + amount); };
	Vector2D operator-(const double& amount) { return Vector2D(x - amount, y - amount); };
	Vector2D operator*(const double& amount) { return Vector2D(x * amount, y * amount); };
	Vector2D operator/(const double& amount) { return Vector2D(x / amount, y / amount); };

	bool operator=(const Vector2D& other) { return (x == other.x && y == other.y ? true : false); };
	bool operator!=(const Vector2D& other) { return (x != other.x && y != other.y ? true : false); };
};