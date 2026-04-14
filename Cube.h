#pragma once

#include "Object3D.h"
#include <vector>

class Cube : public Object3D {
private:
    std::vector<Vector3> vertices;
    std::vector<std::pair<int, int>> edges;

public:
    Cube();
    Cube(const Vector3& position, const Vector3& rotation, const Vector3& scale);
    
    bool hasGeometry() const override;
    const std::vector<Vector3>* getVertices() const override;
    const std::vector<std::pair<int, int>>* getEdges() const override;
};
