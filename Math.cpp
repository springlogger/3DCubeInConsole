#include "Vector3.h"
#include "Math.h"

// 1) Находим вектор от точки вне плоскости к точке на плоскости через разницу их векторов(Вектор будет направлен к точке вне плоскости)
// 2) Расчитываем скалярное произведение нормаль плоскости и полученному в первом пункте вектору(по сути получим проекцию вектора из пункта 1 к вектору нормали)
float pointToPlaneDistance(const Vector3& point, const Vector3& pointOnPlane, const Vector3& planeNormal) {
	Vector3 diff = point.sub(pointOnPlane);

	return diff.dot(planeNormal.normalized());
}