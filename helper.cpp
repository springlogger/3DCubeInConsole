#include <iostream>
#include <cmath>

// Вспомогательная функция для сравнения чисел с плавающей точкой
bool almostEqual(float a, float b, float epsilon = 0.001f) {
    return std::abs(a - b) < epsilon;
}

// Функция для вывода результата теста
void testResult(const char* testName, bool passed) {
    std::cout << (passed ? "[OK] " : "[FAIL] ") << testName << std::endl;
}