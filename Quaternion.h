#pragma once

#include "Vector3.h"

class Quaternion
{
public:
	float x;
	float y;
	float z;
	float w;

	Quaternion();

	//Угол в радианах
	Quaternion(const Vector3& axis, const float angle);

	Vector3 rotate(const Vector3& vec) const;
};

