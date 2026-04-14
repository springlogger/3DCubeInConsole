#pragma once

#include "Vector3.h"
#include "Matrix4.h"
#include <vector>

class Object3D {
protected:
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;

    Matrix4 matrix;

public:
    Object3D();
    virtual ~Object3D() = default;

    void setPosition(const Vector3& pos);
    void setRotation(const Vector3& rot);
    void setScale(const Vector3& scl);

    Vector3 getPosition() const;
    Vector3 getRotation() const;
    Vector3 getScale() const;

    void updateMatrix();
    const Matrix4& getMatrix() const { return matrix; };

    // Геометрия по умолчанию отсутствует
    virtual bool hasGeometry() const;
    virtual const std::vector<Vector3>* getVertices() const;
    virtual const std::vector<std::pair<int, int>>* getEdges() const;
};
