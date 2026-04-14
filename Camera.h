#pragma once

#include "Vector3.h"
#include "Matrix4.h"

class Camera
{
private:
	Vector3 eye;
	Vector3 target;
	Vector3 up; // мировая, всегда (0, 1, 0)

	Matrix4 viewMatrix;
	Matrix4 projectionMatrix;

	float fovY;
	float aspect;
	float nearPlane;
	float farPlane;

public:

	Camera();
	Camera(
		const Vector3& eye,
		const Vector3& target,
		const Vector3& up,
		float fovY,
		float aspect,
		float nearPlane,
		float farPlane
	);

	// Перерасчитывает view матрицу либо когда мы двигаем камерой, либо когда напрямую вызываем из кода.
	void lookAt(const Vector3& targetNew);

	void updateViewMatrix4();
	void updateProjectionMatrix();

	const Matrix4& getViewMatrix() const { return viewMatrix; };
	const Matrix4& getProjectionMatrix() const { return projectionMatrix; };

	Vector3 getUp() { return up; };
	Vector3 getTarget() { return target; };
	Vector3 getEye() { return eye; };
};

