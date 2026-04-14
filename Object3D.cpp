#include "Object3D.h"


Object3D::Object3D()
	: position(0, 0, 0),
	rotation(0, 0, 0),
	scale(1, 1, 1),
	matrix() {
}

// Обратный порядок
// M=I⋅T⋅Rz​⋅Ry​⋅Rx​⋅S
void Object3D::updateMatrix() {
	matrix.identity();
	matrix.translate(position);
	matrix.rotateZ(rotation.z);
	matrix.rotateY(rotation.y);
	matrix.rotateX(rotation.x);
	matrix.scale(scale);
}

void Object3D::setPosition(const Vector3& pos) {
	position.x = pos.x;
	position.y = pos.y;
	position.z = pos.z;
}

void Object3D::setRotation(const Vector3& rot) {
	rotation.x = rot.x;
	rotation.y = rot.y;
	rotation.z = rot.z;
}

void Object3D::setScale(const Vector3& scl) {
	scale.x = scl.x;
	scale.y = scl.y;
	scale.z = scl.z;
}

bool Object3D::hasGeometry() const {
	return false;
}

const std::vector<Vector3>* Object3D::getVertices() const {
	return nullptr;
}

const std::vector<std::pair<int, int>>* Object3D::getEdges() const {
	return nullptr;
}
