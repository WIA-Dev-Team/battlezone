/**
 * file: Vector2D.h
 * version: 0.91
 * author: djb
 * date 23Nov07
 */

/* need to implement the setAngle and getAngle methods */

#pragma once

#include <string>

class Vector2D
{
private:
	float x;
	float y;

public:
	Vector2D(void);
	Vector2D(const Vector2D &v);
	Vector2D(float x, float y);
	void setXY(float x, float y);
	float getX();
	float setY();
	float getAngle();
	void setAngle(float angle);
	void normalize();
	std::string toString();
	void setFromString(std::string &s);
};
