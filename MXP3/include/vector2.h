#ifndef VECTOR2_H
#define VECTOR2_H

#include <math.h>

class Vector2 {

public:
	int x;
	int y;

	Vector2();

	Vector2(int x_, int y_);

	virtual ~Vector2();

	Vector2 operator+(const Vector2 &oth);

	void operator+=(const Vector2 &oth);

	Vector2 operator-(const Vector2 &oth);

	void operator-=(const Vector2 &oth);

	Vector2 operator*(const Vector2 &oth);

	void operator*=(const Vector2 &oth);

	Vector2 operator/(const Vector2 &oth);

	void operator/=(const Vector2 &oth);

	void normalize();

	int mag();


private:

};

#endif // !VECTOR2_H