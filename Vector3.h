#pragma once
class Vector3
{
public:
	float x;
	float y;
	float z;

	Vector3();

	Vector3(float x, float y, float z);

	// Сложение векторов(self + vec)
	Vector3 add(const Vector3& vec) const;

	Vector3 multiplyScalar(const float scalar) const;

	// Разница векторов(self - vec)
	Vector3 sub(const Vector3& vec) const;

	//Скалярное произведение
	float dot(const Vector3& vec) const;

	float length() const;

	Vector3 cross(const Vector3& vec) const;

	void normalize();

	Vector3 normalized() const;

	Vector3 copy(const Vector3& vec);

	void print() const;

};

