#ifndef _Vec2D_h_
#define _Vec2D_h_ 

#include "ext_include.h"

class Vec2D
{
public:
	double x;
	double y;

	Vec2D(double x, double y);
	Vec2D();
	Vec2D(const Vec2D &o);

	Vec2D operator +(const Vec2D &rhs) const;
	Vec2D operator +=(const Vec2D &rhs);
	Vec2D operator -(const Vec2D &rhs) const;
	Vec2D operator -=(const Vec2D &rhs);
	Vec2D operator *(double rhs) const;
	Vec2D operator *=(double rhs);
	Vec2D operator /(double rhs) const;
	Vec2D operator /=(double rhs);

	bool operator ==(const Vec2D &rhs) const;
	bool operator <(const Vec2D &rhs) const;
	bool operator >(const Vec2D &rhs) const;
	bool operator !=(const Vec2D &rhs) const;
	bool operator <=(const Vec2D &rhs) const;
	bool operator >=(const Vec2D &rhs) const;

	double dot(const Vec2D &rhs) const;
	Vec2D cross(const Vec2D &rhs) const;
	double length() const;
	Vec2D normalize() const;
};

#endif
