#pragma once

#include "Vector3.h"

class Plane {
private:
	float distance;
	Vector3 normal_normalized;

public:

	Plane(const Vector3& normal, const Vector3& point);
	Plane(const Vector3& point1, const Vector3& point2, const Vector3& point3);

	float distanceToPoint(const Vector3& point) const;

	Vector3 getNormal() const;
	float getDist() const;
};