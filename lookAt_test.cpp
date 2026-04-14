//#include "Camera.h"
//#include "Matrix4.h"
//#include "Vector3.h"
//#include <iostream>
//#include <cmath>
//
//// Вспомогательная функция для сравнения чисел с плавающей точкой
//bool almostEqual(float a, float b, float epsilon = 0.001f);
//
//// Функция для вывода результата теста
//void testResult(const char* testName, bool passed);
//
//void lookAt_test() {
//    std::cout << "========== ТЕСТЫ lookAt (OpenGL, -Z вперед) ==========" << std::endl;
//
//    // ========== ТЕСТ 1: Камера смотрит вдоль -Z ==========
//    std::cout << "\n--- Тест 1: Базовое направление взгляда ---" << std::endl;
//
//    Camera cam1(Vector3(0, 0, 5), Vector3(0, 0, 0), Vector3(0, 1, 0));
//    Matrix4 view1 = cam1.getMatrix();
//
//    // Точка ПЕРЕД камерой (в сторону target)
//    Vector3 pointFront(0, 0, 0);
//    Vector3 v1 = view1.transform(pointFront);
//
//    // В OpenGL: вперед = Z < 0
//    bool test1 = v1.z < 0;
//    testResult("Точка перед камерой имеет Z < 0", test1);
//
//    // Центр
//    bool test1b = almostEqual(v1.x, 0) && almostEqual(v1.y, 0);
//    testResult("Точка по центру (X=0, Y=0)", test1b);
//
//
//    // ========== ТЕСТ 2: Камера перемещается в (0,0,0) ==========
//    std::cout << "\n--- Тест 2: Камера становится началом координат ---" << std::endl;
//
//    Camera cam2(Vector3(5, -3, 2), Vector3(0, 0, 0), Vector3(0, 1, 0));
//    Matrix4 view2 = cam2.getMatrix();
//
//    Vector3 cameraPos(5, -3, 2);
//    Vector3 v2 = view2.transform(cameraPos);
//
//    bool test2 = almostEqual(v2.x, 0) &&
//        almostEqual(v2.y, 0) &&
//        almostEqual(v2.z, 0);
//
//    testResult("Позиция камеры -> (0,0,0)", test2);
//
//
//    // ========== ТЕСТ 3: Ортонормированность базиса ==========
//    std::cout << "\n--- Тест 3: Ортонормированность базиса ---" << std::endl;
//
//    Camera cam3(Vector3(2, 3, 4), Vector3(5, 6, 7), Vector3(0, 1, 0));
//    Matrix4 view3 = cam3.getMatrix();
//
//    Vector3 right(view3[0], view3[1], view3[2]);
//    Vector3 up(view3[4], view3[5], view3[6]);
//    Vector3 forward(view3[8], view3[9], view3[10]);
//
//    bool ortho =
//        almostEqual(right.dot(up), 0) &&
//        almostEqual(right.dot(forward), 0) &&
//        almostEqual(up.dot(forward), 0);
//
//    bool norm =
//        almostEqual(right.length(), 1) &&
//        almostEqual(up.length(), 1) &&
//        almostEqual(forward.length(), 1);
//
//    testResult("Оси перпендикулярны", ortho);
//    testResult("Оси нормализованы", norm);
//
//
//    // ========== ТЕСТ 4: Сохранение расстояний ==========
//    std::cout << "\n--- Тест 4: Изометрия (сохранение расстояний) ---" << std::endl;
//
//    Camera cam4(Vector3(1, 2, 3), Vector3(4, 5, 6), Vector3(0, 1, 0));
//    Matrix4 view4 = cam4.getMatrix();
//
//    Vector3 p1(1, 1, 1);
//    Vector3 p2(2, 3, 4);
//
//    float worldDist = p1.sub(p2).length();
//    float viewDist = view4.transform(p1).sub(view4.transform(p2)).length();
//
//    bool test4 = almostEqual(worldDist, viewDist);
//    testResult("Расстояние сохраняется", test4);
//
//
//    // ========== ТЕСТ 5: Направление forward совпадает с target ==========
//    std::cout << "\n--- Тест 5: Forward соответствует направлению взгляда ---" << std::endl;
//
//    Camera cam5(Vector3(0, 0, 0), Vector3(0, 0, -5), Vector3(0, 1, 0));
//    Matrix4 view5 = cam5.getMatrix();
//
//    // Берем forward из матрицы (в OpenGL он инвертирован!)
//    Vector3 forwardView(view5[8], view5[9], view5[10]);
//
//    // Ожидаем (0,0,1), потому что в матрице хранится -forward
//    bool test5 =
//        almostEqual(forwardView.x, 0) &&
//        almostEqual(forwardView.y, 0) &&
//        almostEqual(forwardView.z, 1);
//
//    testResult("Forward корректно инвертирован (-Z вперед)", test5);
//
//
//    // ========== ИТОГ ==========
//    std::cout << "\n========== ИТОГ ==========" << std::endl;
//    std::cout << "Проверь наличие [FAIL]" << std::endl;
//}