//#include <iostream>
//#include <cmath>
//#include "Vector3.h"
//#include "Plane.h"
//
//// Функция для сравнения чисел с плавающей точкой
//bool almostEqual(float a, float b, float epsilon = 0.0001f);
//
//// Функция для вывода результата теста
//void testResult(const char* testName, bool passed);
//
//void Vector3_test() {
//    std::cout << "========== ТЕСТИРОВАНИЕ VECTOR3 ==========" << std::endl;
//
//    // === ТЕСТ 1: Конструкторы и printVector ===
//    std::cout << "\n--- Тест 1: Конструкторы ---" << std::endl;
//    Vector3 v1;
//    Vector3 v2(1, 2, 3);
//
//    testResult("Конструктор по умолчанию (0,0,0)",
//        almostEqual(v1.x, 0) && almostEqual(v1.y, 0) && almostEqual(v1.z, 0));
//    testResult("Конструктор с параметрами (1,2,3)",
//        almostEqual(v2.x, 1) && almostEqual(v2.y, 2) && almostEqual(v2.z, 3));
//
//    // === ТЕСТ 2: add() ===
//    std::cout << "\n--- Тест 2: add() ---" << std::endl;
//    Vector3 a(1, 2, 3);
//    Vector3 b(4, 5, 6);
//    Vector3 sum = a.add(b);
//    testResult("add: (1,2,3) + (4,5,6) = (5,7,9)",
//        almostEqual(sum.x, 5) && almostEqual(sum.y, 7) && almostEqual(sum.z, 9));
//
//    // === ТЕСТ 3: sub() ===
//    std::cout << "\n--- Тест 3: sub() ---" << std::endl;
//    Vector3 diff = a.sub(b);
//    testResult("sub: (1,2,3) - (4,5,6) = (-3,-3,-3)",
//        almostEqual(diff.x, -3) && almostEqual(diff.y, -3) && almostEqual(diff.z, -3));
//
//    // === ТЕСТ 4: dot() ===
//    std::cout << "\n--- Тест 4: dot() ---" << std::endl;
//    Vector3 vDot1(1, 0, 0);
//    Vector3 vDot2(0, 1, 0);
//    Vector3 vDot3(2, 0, 0);
//
//    testResult("dot: (1,0,0) · (0,1,0) = 0 (перпендикулярны)",
//        almostEqual(vDot1.dot(vDot2), 0));
//    testResult("dot: (1,0,0) · (2,0,0) = 2 (сонаправлены)",
//        almostEqual(vDot1.dot(vDot3), 2));
//    testResult("dot: (1,0,0) · (-2,0,0) = -2 (противоположны)",
//        almostEqual(vDot1.dot(Vector3(-2, 0, 0)), -2));
//
//    // === ТЕСТ 5: cross() ===
//    std::cout << "\n--- Тест 5: cross() ---" << std::endl;
//    Vector3 vCross1(1, 0, 0);
//    Vector3 vCross2(0, 1, 0);
//    Vector3 crossResult = vCross1.cross(vCross2);
//
//    testResult("cross: i × j = k (0,0,1)",
//        almostEqual(crossResult.x, 0) && almostEqual(crossResult.y, 0) && almostEqual(crossResult.z, 1));
//
//    Vector3 vCross3(2, 0, 0);
//    Vector3 vCross4(0, 3, 0);
//    crossResult = vCross3.cross(vCross4);
//    testResult("cross: (2,0,0) × (0,3,0) = (0,0,6)",
//        almostEqual(crossResult.x, 0) && almostEqual(crossResult.y, 0) && almostEqual(crossResult.z, 6));
//
//    // === ТЕСТ 6: length() ===
//    std::cout << "\n--- Тест 6: length() ---" << std::endl;
//    Vector3 vLen1(3, 0, 0);
//    Vector3 vLen2(1, 1, 0);
//    Vector3 vLen3(1, 1, 1);
//
//    testResult("length: (3,0,0) = 3", almostEqual(vLen1.length(), 3));
//    testResult("length: (1,1,0) = √2 ≈ 1.414", almostEqual(vLen2.length(), std::sqrt(2)));
//    testResult("length: (1,1,1) = √3 ≈ 1.732", almostEqual(vLen3.length(), std::sqrt(3)));
//
//    // === ТЕСТ 7: normalize() и normalized() ===
//    std::cout << "\n--- Тест 7: normalize() ---" << std::endl;
//    Vector3 vNorm1(3, 0, 0);
//    Vector3 normalized1 = vNorm1.normalized();
//    testResult("normalized: (3,0,0) → (1,0,0)",
//        almostEqual(normalized1.x, 1) && almostEqual(normalized1.y, 0) && almostEqual(normalized1.z, 0));
//
//    Vector3 vNorm2(1, 1, 0);
//    Vector3 normalized2 = vNorm2.normalized();
//    float expectedNorm = 1.0f / std::sqrt(2);  // ≈ 0.7071
//    testResult("normalized: (1,1,0) → (0.707,0.707,0)",
//        almostEqual(normalized2.x, expectedNorm) &&
//        almostEqual(normalized2.y, expectedNorm) &&
//        almostEqual(normalized2.z, 0));
//
//    // Проверка, что длина нормализованного вектора = 1
//    testResult("normalized: длина результата = 1",
//        almostEqual(normalized2.length(), 1));
//
//    // === ТЕСТ 8: copy() ===
//    std::cout << "\n--- Тест 8: copy() ---" << std::endl;
//    Vector3 vCopySrc(5, 6, 7);
//    Vector3 vCopyDst;
//    vCopyDst.copy(vCopySrc);
//    testResult("copy: (5,6,7) скопирован",
//        almostEqual(vCopyDst.x, 5) && almostEqual(vCopyDst.y, 6) && almostEqual(vCopyDst.z, 7));
//
//    std::cout << "\n========== ТЕСТИРОВАНИЕ PLANE ==========" << std::endl;
//
//    // === ТЕСТ 9: Plane из нормали и точки ===
//    std::cout << "\n--- Тест 9: Конструктор (нормаль + точка) ---" << std::endl;
//    Vector3 planeNormal1(0, 0, 1);
//    Vector3 pointOnPlane1(0, 0, 5);
//    Plane plane1(planeNormal1, pointOnPlane1);
//
//    Vector3 testPoint1(10, 20, 5);   // на плоскости
//    Vector3 testPoint2(10, 20, 10);  // выше на 5
//    Vector3 testPoint3(10, 20, 0);   // ниже на 5
//
//    testResult("Плоскость z=5: точка (10,20,5) расстояние = 0",
//        almostEqual(plane1.distanceToPoint(testPoint1), 0));
//    testResult("Плоскость z=5: точка (10,20,10) расстояние = 5",
//        almostEqual(plane1.distanceToPoint(testPoint2), 5));
//    testResult("Плоскость z=5: точка (10,20,0) расстояние = 5",
//        almostEqual(plane1.distanceToPoint(testPoint3), 5));
//
//    // Проверка signedDistance
//    //testResult("signedDistance: точка выше = +5",
//    //    almostEqual(plane1.signedDistanceToPoint(testPoint2), 5));
//    //testResult("signedDistance: точка ниже = -5",
//    //    almostEqual(plane1.signedDistanceToPoint(testPoint3), -5));
//
//    // === ТЕСТ 10: Plane из трёх точек ===
//    std::cout << "\n--- Тест 10: Конструктор (3 точки) ---" << std::endl;
//    Vector3 A(0, 0, 5);
//    Vector3 B(1, 0, 5);
//    Vector3 C(0, 1, 5);
//    Plane plane2(A, B, C);
//
//    testResult("3 точки (0,0,5),(1,0,5),(0,1,5) → плоскость z=5",
//        almostEqual(plane2.distanceToPoint(testPoint1), 0));
//    testResult("3 точки: нормаль должна быть (0,0,±1)",
//        almostEqual(std::abs(plane2.getNormal().z), 1));
//
//    // === ТЕСТ 11: Плоскость с наклоном ===
//    std::cout << "\n--- Тест 11: Наклонная плоскость ---" << std::endl;
//    // Плоскость x + y + z = 3
//    // Точки: A(3,0,0), B(0,3,0), C(0,0,3)
//    Vector3 A2(3, 0, 0);
//    Vector3 B2(0, 3, 0);
//    Vector3 C2(0, 0, 3);
//    Plane plane3(A2, B2, C2);
//
//    // Точка на плоскости: (1,1,1) должна дать 0
//    Vector3 pointOn(1, 1, 1);
//    // Расстояние до плоскости = |x+y+z-3|/√3
//    Vector3 pointOff(4, 0, 0);
//    // Для (4,0,0): |4+0+0-3|/√3 = 1/1.732 = 0.577
//
//    testResult("Наклонная плоскость: точка (1,1,1) на плоскости",
//        almostEqual(plane3.distanceToPoint(pointOn), 0));
//    testResult("Наклонная плоскость: точка (4,0,0) расстояние ≈ 0.577",
//        almostEqual(plane3.distanceToPoint(pointOff), 1.0f / std::sqrt(3)));
//
//    // === ТЕСТ 12: Проверка на вырожденную плоскость (коллинеарные точки) ===
//    std::cout << "\n--- Тест 12: Вырожденный случай ---" << std::endl;
//    Vector3 A3(0, 0, 0);
//    Vector3 B3(1, 0, 0);
//    Vector3 C3(2, 0, 0);  // все на оси X
//
//    Plane plane4(A3, B3, C3);  // Должна создать плоскость по умолчанию или словить ошибку
//
//    // Если ваша реализация обрабатывает вырожденный случай:
//    // (должна создать какую-то валидную плоскость, например горизонтальную)
//    testResult("Вырожденный случай: программа не упала (нормаль существует)",
//        !almostEqual(plane4.getNormal().length(), 0));
//
//    // === ТЕСТ 13: Производительность базовых операций ===
//    std::cout << "\n--- Тест 13: Производительность (простые операции) ---" << std::endl;
//    const int ITERATIONS = 1000000;
//    Vector3 perfA(1, 2, 3);
//    Vector3 perfB(4, 5, 6);
//    float result = 0;
//
//    for (int i = 0; i < ITERATIONS; ++i) {
//        result += perfA.dot(perfB);
//        Vector3 cross = perfA.cross(perfB);
//        result += cross.x;
//    }
//
//    testResult("1 млн операций dot + cross выполнен", true);
//    std::cout << "    (результат-заглушка: " << result << ")" << std::endl;
//
//    // === ИТОГОВЫЙ ОТЧЁТ ===
//    std::cout << "\n========== ИТОГИ ==========" << std::endl;
//    std::cout << "Все тесты выполнены. Проверьте вывод на наличие [✗]." << std::endl;
//
//    // Дополнительная ручная проверка
//    std::cout << "\n--- Ручная проверка (вывод значений) ---" << std::endl;
//    std::cout << "Вектор v2: ";
//    v2.print();
//
//    std::cout << "Плоскость z=5, нормаль: ";
//    plane1.getNormal().print();
//    std::cout << "  dist = " << plane1.getDist() << std::endl;
//}