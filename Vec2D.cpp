#include "Vec2D.h"

Vec2D::Vec2D(double x, double y)
{
	this->x = x;
	this->y = y;
}

Vec2D::Vec2D()
{
	x = 0;
	y = 0;
}

Vec2D::Vec2D(const Vec2D &o)
{
	x = o.x;
	y = o.y;
}

Vec2D Vec2D::operator +(const Vec2D &rhs) const
{
	return Vec2D(x + rhs.x, y + rhs.y);
}

Vec2D Vec2D::operator +=(const Vec2D &rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

Vec2D Vec2D::operator -(const Vec2D &rhs) const
{
	return Vec2D(x - rhs.x, y - rhs.y);
}

Vec2D Vec2D::operator -=(const Vec2D &rhs)
{
	x -= rhs.x;
	y -= rhs.y;
	return *this;
}

Vec2D Vec2D::operator *(double rhs) const
{
	return Vec2D(x * rhs, y * rhs);
}

Vec2D Vec2D::operator *=(double rhs)
{
	x *= rhs;
	y *= rhs;
	return *this;
}

Vec2D Vec2D::operator /(double rhs) const
{
	return *this * (1 / rhs);
}

Vec2D Vec2D::operator /=(double rhs)
{
	rhs = 1 / rhs;
	x *= rhs;
	y *= rhs;
	return *this;
}

bool Vec2D::operator ==(const Vec2D &rhs) const
{
	if(abs(x - rhs.x) > 1e-9)
		return false;
	if(abs(y - rhs.y) > 1e-9)
		return false;
	return true;
}

bool Vec2D::operator <(const Vec2D &rhs) const
{
	if(abs(x - rhs.x) > 1e-9)
		return x < rhs.x;
	if(abs(y - rhs.y) > 1e-9)
		return y < rhs.y;
	return false;
}

bool Vec2D::operator >(const Vec2D &rhs) const
{
	return rhs < *this;
}

bool Vec2D::operator !=(const Vec2D &rhs) const
{
	return !(*this == rhs);
}

bool Vec2D::operator <=(const Vec2D &rhs) const
{
	return rhs > *this;
}

bool Vec2D::operator >=(const Vec2D &rhs) const
{
	return rhs < *this;
}

double Vec2D::dot(const Vec2D &rhs) const
{
	return x * rhs.x + y * rhs.y;
}

Vec2D Vec2D::cross(const Vec2D &rhs) const
{
	return Vec2D(x * rhs.y - y * rhs.x, y * rhs.x - x * rhs.y);
}

double Vec2D::length() const
{
	return sqrt(this->dot(*this));
}

Vec2D Vec2D::normalize() const
{
	return *this / length();
}