#pragma once
#include "Vector2.h"

class AABB
{
public:
	AABB operator+(const Point& p) const
	{
		AABB result = (*this);
		result.vecMin = p + vecMin;
		result.vecMax = p + vecMax;
	}

public:
	Vector vecMin;
	Vector vecMax;
};