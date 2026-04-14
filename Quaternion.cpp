#include "Quaternion.h"

#include "Vector3.h"
#include <cmath>

Quaternion::Quaternion() {
	x = 0;
	y = 0;
	z = 0;
	w = 1;
}

//Угол в радианах
Quaternion::Quaternion(const Vector3& axis, const float angle) {

	Vector3 normilizedAxis = axis.normalized();

	x = normilizedAxis.x * std::sin(angle / 2);
	y = normilizedAxis.y * std::sin(angle / 2);
	z = normilizedAxis.z * std::sin(angle / 2);
	w = std::cos(angle / 2);
}

// rotate: v' = v + 2*q.xyz×v * w + q.xyz×(2*q.xyz×v)
Vector3 Quaternion::rotate(const Vector3& vec) const {
	Vector3 qv(x, y, z);

	Vector3 t = qv.cross(vec).multiplyScalar(2.0f);
	return vec.add(t.multiplyScalar(w)).add(qv.cross(t));
}
