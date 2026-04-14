#include "Vector3.h"
#include <cmath>
#include "Plane.h"

// Общее уравнение плоскости Ax + By + Cz + D = 0
// нормализованная форма n·P + d = 0, где n — единичная нормаль (|n| = 1), P — любая точка на плоскости, d — расстояние от начала координат (0,0,0) до плоскости (со знаком), n·P — скалярное произведение
// в Данном случае я беру d за растояние, от начала координат до плоскости, в другом же варианте
// d = -n·P, а у меня d = n·P
Plane::Plane(const Vector3& normal, const Vector3& point) {
	normal_normalized = Vector3().copy(normal).normalized();

	distance = normal_normalized.dot(point);
}

Plane::Plane(const Vector3& point1, const Vector3& point2, const Vector3& point3) {
	Vector3 vec1 = point2.sub(point1);
	Vector3 vec2 = point3.sub(point1);

	normal_normalized = (vec1.cross(vec2)).normalized();

	distance = normal_normalized.dot(point1);
}

float Plane::distanceToPoint(const Vector3& point) const {
	return abs(normal_normalized.dot(point) - distance);
}

Vector3 Plane::getNormal() const {
	return normal_normalized;
}

float Plane::getDist() const {
	return distance;
}