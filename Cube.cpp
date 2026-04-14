#include "Cube.h"

Cube::Cube() {
    vertices = {
        Vector3(-1, -1, -1),
        Vector3(1, -1, -1),
        Vector3(1,  1, -1),
        Vector3(-1,  1, -1),
        Vector3(-1, -1,  1),
        Vector3(1, -1,  1),
        Vector3(1,  1,  1),
        Vector3(-1,  1,  1)
    };

    edges = {
        {0,1}, {1,2}, {2,3}, {3,0},
        {4,5}, {5,6}, {6,7}, {7,4},
        {0,4}, {1,5}, {2,6}, {3,7}
    };
}

Cube::Cube(const Vector3& position, const Vector3& rotation, const Vector3& scale)
    : Cube() {
    setPosition(position);
    setRotation(rotation);
    setScale(scale);
    updateMatrix();
}

bool Cube::hasGeometry() const {
    return true;
}

const std::vector<Vector3>* Cube::getVertices() const {
    return &vertices;
}

const std::vector<std::pair<int, int>>* Cube::getEdges() const {
    return &edges;
}