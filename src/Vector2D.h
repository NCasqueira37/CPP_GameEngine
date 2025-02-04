#pragma once

#include <iostream>
#include <cmath>


class Vector2D
{
public:
	double x = 0;
	double y = 0;

	// Constructors
	Vector2D() = default;
	Vector2D(double x, double y) : x(x), y(y) {};

	// Function to get distance between 2 vectors
	static double distance(const Vector2D& a, const Vector2D& b);

	// Function to get the length of the vector
	const double getMagnitude() const { return sqrt(pow(x, 2) + pow(y, 2)); };

	// Function to normalize the vector
	Vector2D getNormalized() const { return Vector2D(x / getMagnitude(), y / getMagnitude()); };

	// function to print x and y values of vector
	void toString() const;

	// Operator overloads
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

