#include "Renderer.h"
#include "Camera.h"
#include "Object3D.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <windows.h>

Renderer::Renderer(int screenWidth, int screenHeight)
    : screenWidth(screenWidth),
    screenHeight(screenHeight),
    buffer(screenHeight, std::string(screenWidth, ' ')) {
}

void Renderer::clearBuffer() {
    for (auto& row : buffer) {
        std::fill(row.begin(), row.end(), ' ');
    }
}

void Renderer::present() const {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD cursorPos{ 0, 0 };
    SetConsoleCursorPosition(hConsole, cursorPos);

    std::string frame;
    frame.reserve(screenHeight * (screenWidth + 1));

    for (const auto& row : buffer) {
        frame += row;
        frame += '\n';
    }

    DWORD written = 0;
    WriteConsoleA(hConsole, frame.c_str(), static_cast<DWORD>(frame.size()), &written, nullptr);
}

void Renderer::drawPoint(int x, int y, char symbol) {
    int height = static_cast<int>(buffer.size());
    int width = height > 0 ? static_cast<int>(buffer[0].size()) : 0;

    if (x >= 0 && x < width && y >= 0 && y < height) {
        buffer[y][x] = symbol;
    }
}

void Renderer::drawLine(int x0, int y0, int x1, int y1, char symbol) {
    int dx = std::abs(x1 - x0);
    int dy = std::abs(y1 - y0);

    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;

    int err = dx - dy;

    while (true) {
        drawPoint(x0, y0, symbol);

        if (x0 == x1 && y0 == y1) {
            break;
        }

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

std::vector<ScreenPoint> Renderer::projectVertices(const Object3D& scene, const Camera& camera) const {

    const auto& vertices = *scene.getVertices();
    const auto& edges = *scene.getEdges();

    std::vector<ScreenPoint> projected(vertices.size());

    for (size_t i = 0; i < vertices.size(); i++) {

        // Переводим локальные координадты вершины куба в мировые
        const Vector3 vertexLocal = vertices[i];

        Vector3 vertexWorld = scene.getMatrix().transformPoint(vertexLocal);

        // Получаем координаты вершины куба в локальных координатах камеры из мировых
        Vector3 vertexView = camera.getViewMatrix().transformPoint(vertexWorld);

        // Получаем координаты вершины куба на экране через переспективную проекцию
        Vector4 vertexClip = camera.
            getProjectionMatrix().
            transform(Vector4(vertexView.x, vertexView.y, vertexView.z, 1.0f))
            ;

        if (std::abs(vertexClip.w) < 1e-6f) {
            continue;
        }

        float xNdc = vertexClip.x / vertexClip.w;
        float yNdc = vertexClip.y / vertexClip.w;
        float zNdc = vertexClip.z / vertexClip.w;

        int xScreen = static_cast<int>((xNdc + 1.0f) * 0.5f * screenWidth);
        int yScreen = static_cast<int>((1.0f - yNdc) * 0.5f * screenHeight);

        projected[i] = { xScreen, yScreen, zNdc, true };
    }

    return projected;
}

void Renderer::drawWireframe(
    const std::vector<ScreenPoint>& projected,
    const std::vector<std::pair<int, int>>& edges
) {

    // Сначала рисуем рёбра
    for (const auto& edge : edges) {
        int a = edge.first;
        int b = edge.second;

        if (!projected[a].visible || !projected[b].visible) {
            continue;
        }

        drawLine(
            projected[a].x, projected[a].y,
            projected[b].x, projected[b].y,
            '#'
        );
    }

    // Потом вершины поверх рёбер
    for (const auto& p : projected) {
        if (!p.visible) {
            continue;
        }

        drawPoint(p.x, p.y, '*');
    }
}

void Renderer::render(const Object3D& scene, const Camera& camera) {

    const auto* verticesPtr = scene.getVertices();
    const auto* edgesPtr = scene.getEdges();

    if (!scene.hasGeometry() || verticesPtr == nullptr || edgesPtr == nullptr) {
        return;
    }

    clearBuffer();

    std::vector<ScreenPoint> projected = projectVertices(scene, camera);
    drawWireframe(projected, *edgesPtr);

    present();
}