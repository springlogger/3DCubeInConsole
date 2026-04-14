#include "Vector3.h"
#include <iostream>
#include <cmath>

Vector3::Vector3() {
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3::Vector3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void Vector3::print() const {
	std::cout << "x = " << this->x << ", y = " << this->y << ", z = " << this->z << std::endl;
}


//Скалярное произведение(на сколько векторы сонаправлены)
// a · b = x₁·x₂ + y₁·y₂ + z₁·z₂
// a · b = |a| × |b| × cos(угол между векторами)
// Используется для:
//	 1) нахождения угла между векторами
//	 2) Проверка на столкновение(если dot < 0 то столкнутся)
//	 3) Длина проекции одного вектора на другой(при b.normilised())
float Vector3::dot(const Vector3& vec) const {
	return x * vec.x + y * vec.y + z * vec.z;
}

// вектор перпендикулярный двум изначальным
Vector3 Vector3::cross(const Vector3& vec) const {
	return Vector3(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x); // Векторное произведение;
}


Vector3 Vector3::add(const Vector3& vec) const {
	Vector3 result(x + vec.x, y + vec.y, z + vec.z);

	return result;
}

Vector3 Vector3::sub(const Vector3& vec) const {
	Vector3 result = add(Vector3(-vec.x, -vec.y, -vec.z));

	return result;
}

Vector3 Vector3::multiplyScalar(const float scalar) const {

	return Vector3(x * scalar, y * scalar, z * scalar);
}

float Vector3::length() const {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

void Vector3::normalize() {
	float len = length();
	if (len > 1e-6f) {
		x /= len;
		y /= len;
		z /= len;
	}
}

Vector3 Vector3::normalized() const {
	float len = length();
	if (len > 1e-6f) {
		return Vector3(x / len, y / len, z / len);
	}
	return Vector3(0, 0, 0);
}

Vector3 Vector3::copy(const Vector3& vec) {
	this->x = vec.x;
	this->y = vec.y;
	this->z = vec.z;

	return (*this);
}