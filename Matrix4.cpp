#include "Matrix4.h"
#include <cmath>

Matrix4::Matrix4() {
	//val[0] = 0; val[1] = 0; val[2] = 0; val[3] = 0;
	//val[4] = 0; val[5] = 0; val[6] = 0; val[7] = 0;
	//val[8] = 0; val[9] = 0; val[10] = 0; val[11] = 0;
	//val[12] = 0; val[13] = 0; val[14] = 0; val[15] = 0;

	identity();
}

float& Matrix4::operator[](int index) {
	return val[index];
}

const float& Matrix4::operator[](int index) const {
	return val[index];
}

Matrix4 Matrix4::operator*(const Matrix4& other) const {
	Matrix4 result;

	for (int index = 0; index < 16; index++) {
		int row = index / 4;
		int col = index % 4;

		float sum = 0.0f;
		for (int k = 0; k < 4; k++) {
			sum += (*this)[row * 4 + k] * other[k * 4 + col];
		}

		result[index] = sum;
	}

	return result;
}

Matrix4& Matrix4::operator*=(const Matrix4& other) {
	*this = (*this) * other;
	return *this;
}

void Matrix4::identity() {
	val[0] = 1; val[1] = 0; val[2] = 0; val[3] = 0;
	val[4] = 0; val[5] = 1; val[6] = 0; val[7] = 0;
	val[8] = 0; val[9] = 0; val[10] = 1; val[11] = 0;
	val[12] = 0; val[13] = 0; val[14] = 0; val[15] = 1;
}

/**
 * @brief Преобразует точку с помощью аффинной матрицы 4x4.
 * 
 * Использует однородную координату w = 1, поэтому учитывает перенос.
 *
 * @param vec вектор к которому применяется транс
 * @return Vector3 вектор в локальных координатах камеры
 *
 * @note Аргумент viewPoint НЕ изменяется функцией
 * @warning Если w после проекции близко к 0, результат будет некорректным
 */
Vector3 Matrix4::transformPoint(const Vector3& vec) const {
	float x = val[0] * vec.x + val[1] * vec.y + val[2] * vec.z + val[3];
	float y = val[4] * vec.x + val[5] * vec.y + val[6] * vec.z + val[7];
	float z = val[8] * vec.x + val[9] * vec.y + val[10] * vec.z + val[11];
	 
	return Vector3(x, y, z);
}

Vector4 Matrix4::transform(const Vector4& vec) const {
	float x = val[0] * vec.x + val[1] * vec.y + val[2] * vec.z + val[3] * vec.w;
	float y = val[4] * vec.x + val[5] * vec.y + val[6] * vec.z + val[7] * vec.w;
	float z = val[8] * vec.x + val[9] * vec.y + val[10] * vec.z + val[11] * vec.w;
	float w = val[12] * vec.x + val[13] * vec.y + val[14] * vec.z + val[15] * vec.w;

	return Vector4(x, y, z, w);
}

Matrix4 Matrix4::makeTranslation(const Vector3& position) {
	Matrix4 m;

	m[0] = 1;  m[1] = 0;  m[2] = 0;  m[3] = position.x;
	m[4] = 0;  m[5] = 1;  m[6] = 0;  m[7] = position.y;
	m[8] = 0;  m[9] = 0;  m[10] = 1; m[11] = position.z;
	m[12] = 0; m[13] = 0; m[14] = 0; m[15] = 1;

	return m;
}

Matrix4 Matrix4::makeScale(const Vector3& scale) {
	Matrix4 m;

	m[0] = scale.x;  m[1] = 0;  m[2] = 0;  m[3] = 0;
	m[4] = 0;  m[5] = scale.y;  m[6] = 0;  m[7] = 0;
	m[8] = 0;  m[9] = 0;  m[10] = scale.z; m[11] = 0;
	m[12] = 0; m[13] = 0; m[14] = 0; m[15] = 1;

	return m;
}

Matrix4 Matrix4::makeRotationX(float angle) {
	Matrix4 m;

	float c = std::cos(angle);
	float s = std::sin(angle);

	m[0] = 1; m[1] = 0;  m[2] = 0;  m[3] = 0;
	m[4] = 0; m[5] = c;  m[6] = -s; m[7] = 0;
	m[8] = 0; m[9] = s;  m[10] = c; m[11] = 0;
	m[12] = 0; m[13] = 0; m[14] = 0; m[15] = 1;

	return m;
}

Matrix4 Matrix4::makeRotationY(float angle) {
	Matrix4 m;

	float c = std::cos(angle);
	float s = std::sin(angle);

	m[0] = c;  m[1] = 0; m[2] = s;  m[3] = 0;
	m[4] = 0;  m[5] = 1; m[6] = 0;  m[7] = 0;
	m[8] = -s; m[9] = 0; m[10] = c; m[11] = 0;
	m[12] = 0; m[13] = 0; m[14] = 0; m[15] = 1;

	return m;
}

Matrix4 Matrix4::makeRotationZ(float angle) {
	Matrix4 m;

	float c = std::cos(angle);
	float s = std::sin(angle);

	m[0] = c;  m[1] = -s; m[2] = 0; m[3] = 0;
	m[4] = s;  m[5] = c;  m[6] = 0; m[7] = 0;
	m[8] = 0;  m[9] = 0;  m[10] = 1; m[11] = 0;
	m[12] = 0; m[13] = 0; m[14] = 0; m[15] = 1;

	return m;
}

Matrix4& Matrix4::translate(const Vector3& position) {
	*this *= makeTranslation(position);
	return *this;
}

Matrix4& Matrix4::scale(const Vector3& scale) {
	*this *= makeScale(scale);
	return *this;
}

Matrix4& Matrix4::rotateX(float angle) {
	*this *= makeRotationX(angle);
	return *this;
}

Matrix4& Matrix4::rotateY(float angle) {
	*this *= makeRotationY(angle);
	return *this;
}

Matrix4& Matrix4::rotateZ(float angle) {
	*this *= makeRotationZ(angle);
	return *this;
}