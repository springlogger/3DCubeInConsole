#pragma once
#include "Vector3.h"
#include "Camera.h"
#include "Object3D.h"
#include <vector>
#include <string>

struct ScreenPoint {
    int x;
    int y;
    float z;
    bool visible;
};

class Renderer {
private:
    std::vector<std::string> buffer;

    std::vector<ScreenPoint> projectVertices(const Object3D& scene, const Camera& camera) const;

    void drawWireframe(
        const std::vector<ScreenPoint>& projected,
        const std::vector<std::pair<int, int>>& edges
    );

    void clearBuffer();
    void present() const;
    void drawPoint(int x, int y, char symbol);
    void drawLine(int x0, int y0, int x1, int y1, char symbol);

public:
    const int screenWidth;
    const int screenHeight;

    Renderer(int screenWidth, int screenHeight);
    void render(const Object3D& scene, const Camera& camera);
};