#pragma once

#include "Vector3.h"
#include "Vector4.h"

class Matrix4 {
private:
    float val[16];

public:
    Matrix4();

    float& operator[](int index);
    const float& operator[](int index) const;

    Matrix4 operator*(const Matrix4& other) const;

    Matrix4& operator*=(const Matrix4& other);

    void identity();

    Matrix4& translate(const Vector3& position);
    Matrix4& rotateX(float angle);
    Matrix4& rotateY(float angle);
    Matrix4& rotateZ(float angle);
    Matrix4& scale(const Vector3& scale);

    Vector3 transformPoint(const Vector3& vec) const;
    Vector3 transformVector(const Vector3& vec) const;

    Vector4 transform(const Vector4& vec) const;

private:
    static Matrix4 makeTranslation(const Vector3& position);
    static Matrix4 makeRotationX(float angle);
    static Matrix4 makeRotationY(float angle);
    static Matrix4 makeRotationZ(float angle);
    static Matrix4 makeScale(const Vector3& scale);
};

