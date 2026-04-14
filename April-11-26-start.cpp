#include <iostream>
#include <windows.h>
#include "Vector3.h"
#include "Camera.h"
#include "Cube.h"
#include "Renderer.h"
#include <windows.h>
#include <chrono>

int main() {
    SetConsoleOutputCP(CP_UTF8);

    const int screenWidth = 120;
    const int screenHeight = 40;

    float aspect = static_cast<float>(screenWidth) / static_cast<float>(screenHeight);

    Camera camera(
        Vector3(3.0f, 2.0f, 4.0f),
        Vector3(0.0f, 0.0f, 0.0f),
        Vector3(0.0f, 1.0f, 0.0f),
        60.0f * 3.1415926f / 180.0f,
        aspect,
        0.1f, 
        10.0f
    );

    Cube cube;
    cube.setPosition(Vector3(0, 0, 0));
    cube.setRotation(Vector3(0.4f, 0.6f, 0.0f));
    cube.setScale(Vector3(1, 1, 1));
    cube.updateMatrix();


    Renderer renderer(screenWidth, screenHeight);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    using clock = std::chrono::steady_clock;

    auto previousTime = clock::now();

    float angle = 0.0f;
    float angularSpeed = 3.1415926f / 6.0f;

    while (true) {
        auto currentTime = clock::now();
        std::chrono::duration<float> delta = currentTime - previousTime;
        previousTime = currentTime;

        float deltaTime = delta.count();

        angle += angularSpeed * deltaTime;

        cube.setRotation(Vector3(0.4f, angle, 0.0f));
        cube.updateMatrix();

        renderer.render(cube, camera);

    }

    return 0;
}