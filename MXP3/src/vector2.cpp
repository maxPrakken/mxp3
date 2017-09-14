#include "../include/vector2.h"

Vector2::Vector2() {

}

Vector2::Vector2(int x_, int y_) {
	x = x_;
	y + y_;
}

Vector2::~Vector2() {

}

Vector2 Vector2::operator+(const Vector2 & oth)
{
	return Vector2(this->x + oth.x, this->y + oth.y);
}

void Vector2::operator+=(const Vector2 & oth)
{
	this->x += oth.x;
	this->y += oth.y;
}

Vector2 Vector2::operator-(const Vector2 & oth)
{
	return Vector2(this->x - oth.x, this->y - oth.y);
}

void Vector2::operator-=(const Vector2 & oth)
{
	this->x -= oth.x;
	this->y -= oth.y;
}

Vector2 Vector2::operator*(const Vector2 & oth)
{
	return Vector2(this->x * oth.x, this->y * oth.y);
}

void Vector2::operator*=(const Vector2 & oth)
{
	this->x *= oth.x;
	this->y *= oth.y;
}

Vector2 Vector2::operator/(const Vector2 & oth)
{
	return Vector2(this->x / oth.x, this->y / oth.y);
}

void Vector2::operator/=(const Vector2 & oth)
{
	this->x /= oth.x;
	this->y /= oth.y;
}

void Vector2::normalize() {
	int i = mag();
	if (i != 0) {
		y = y / i;
		x = x / i;
	}
}

int Vector2::mag() {
	return sqrt(x*x + y*y);
}