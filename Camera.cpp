#include "Camera.h"

#include "Matrix4.h"
#include "Vector3.h"
#include <iostream>

Camera::Camera() {
	eye = Vector3();
	target = Vector3(0, 0, -1);
	up = Vector3(0, 1, 0);

	fovY = 60.0f * 3.1415926f / 180.0f;
	aspect = 1.0f;
	nearPlane = 0.1f;
	farPlane = 100.0f;

	viewMatrix = Matrix4();
}

Camera::Camera(
	const Vector3& eye,
	const Vector3& target,
	const Vector3& up,
	float fovY,
	float aspect,
	float nearPlane,
	float farPlane
) {

	this->eye = eye;
	this->target = target;
	this->up = up;

	this->fovY = fovY;
	this->aspect = aspect;
	this->nearPlane = nearPlane;
	this->farPlane = farPlane;

	updateViewMatrix4();
	updateProjectionMatrix();
}

void Camera::lookAt(const Vector3& targetNew) {
	target = targetNew;

	updateViewMatrix4();
}

void Camera::updateViewMatrix4() {

	// локальные
	Vector3 forward = target.sub(eye).normalized();
	Vector3 right = forward.cross(up).normalized();
	Vector3 trueUp = right.cross(forward);

	Matrix4 newView;

	// Минус, потому что при расчёте для вектора мы вычитаем уже существующее расстояние от начала координат до камеры и считаем только расстояние от камеры до объекта
	// forward -> -z

	newView[0] = right.x;   newView[1] = right.y;   newView[2] = right.z;   newView[3] = -right.dot(eye);

	newView[4] = trueUp.x;  newView[5] = trueUp.y;  newView[6] = trueUp.z;  newView[7] = -trueUp.dot(eye);

	newView[8] = -forward.x; newView[9] = -forward.y; newView[10] = -forward.z; newView[11] = forward.dot(eye);

	newView[12] = 0; newView[13] = 0; newView[14] = 0; newView[15] = 1;

	viewMatrix = newView;
}

void Camera::updateProjectionMatrix() {
	float f = 1.0f / std::tan(fovY * 0.5f);

	Matrix4 m;
	m[0] = f / aspect;  m[1] = 0;  m[2] = 0;   m[3] = 0;
	m[4] = 0;			m[5] = f;  m[6] = 0;   m[7] = 0;
	m[8] = 0;			m[9] = 0; 
	
	m[10] = (farPlane + nearPlane) / (nearPlane - farPlane);
	m[11] = (2.0f * farPlane * nearPlane) / (nearPlane - farPlane);

	m[12] = 0;			m[13] = 0; m[14] = -1; m[15] = 0;

	projectionMatrix = m;
}
