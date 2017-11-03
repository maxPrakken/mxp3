#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>
#include <iostream>
class __declspec(dllexport) Vector2 {

public:
	double x;
	double y;

	Vector2();

	Vector2(double x_, double y_);

	virtual ~Vector2();

	Vector2 operator+(const Vector2 &oth);

	void operator+=(const Vector2 &oth);

	Vector2 operator-(const Vector2 &oth);

	void operator-=(const Vector2 &oth);

	Vector2 operator*(const Vector2 &oth);
	Vector2 operator*(const float &oth);
	Vector2 operator*=(const float &oth);
	Vector2 operator*(const double &oth);

	void operator*=(const Vector2 &oth);

	Vector2 operator/(const Vector2 &oth);

	void operator/=(const Vector2 &oth);

	void operator/=(const float & oth);

	void operator/(const float & oth);

	void normalize();

	int mag();


private:

};

#endif // !VECTOR2_H
