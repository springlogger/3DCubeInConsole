//#include "Vector3.h"
//#include "Matrix4.h"
//#include "Object3D.h"
//#include "Camera.h"
//#include <iostream>
//#include <cmath>
//
//// Функция для сравнения чисел с плавающей точкой
//bool almostEqual(float a, float b, float epsilon = 0.0001f);
//
//// Функция для вывода результата теста
//void testResult(const char* testName, bool passed);
//
//void object_camera_pipeline_test() {
//    std::cout << "========== TEST OBJECT -> WORLD -> VIEW ==========\n";
//
//    // =========================================================
//    // TEST 1: Только перенос объекта
//    // local -> world
//    // =========================================================
//    {
//        std::cout << "\n--- Test 1: translation only ---\n";
//
//        Object3D obj;
//        obj.setPosition(Vector3(10, 20, 30));
//        obj.setRotation(Vector3(0, 0, 0));
//        obj.setScale(Vector3(1, 1, 1));
//        obj.updateMatrix();
//
//        Vector3 local(1, 2, 3);
//        Vector3 world = obj.getMatrix().transformPoint(local);
//
//        bool ok =
//            almostEqual(world.x, 11) &&
//            almostEqual(world.y, 22) &&
//            almostEqual(world.z, 33);
//
//        testResult("local (1,2,3) -> world (11,22,33)", ok);
//    }
//
//    // =========================================================
//    // TEST 2: Поворот объекта вокруг Z на 90 градусов
//    // (1,0,0) -> (0,1,0)
//    // =========================================================
//    {
//        std::cout << "\n--- Test 2: rotation around Z ---\n";
//
//        Object3D obj;
//        obj.setPosition(Vector3(0, 0, 0));
//        obj.setRotation(Vector3(0, 0, 3.1415926f / 2.0f)); // 90°
//        obj.setScale(Vector3(1, 1, 1));
//        obj.updateMatrix();
//
//        Vector3 local(1, 0, 0);
//        Vector3 world = obj.getMatrix().transformPoint(local);
//
//        bool ok =
//            almostEqual(world.x, 0) &&
//            almostEqual(world.y, 1) &&
//            almostEqual(world.z, 0);
//
//        testResult("(1,0,0) rotated around Z by 90 deg -> (0,1,0)", ok);
//    }
//
//    // =========================================================
//    // TEST 3: Камера в начале координат, смотрит вдоль -Z
//    // world -> view не должен менять точку на оси -Z
//    // =========================================================
//    {
//        std::cout << "\n--- Test 3: camera at origin looking -Z ---\n";
//
//        Camera cam(
//            Vector3(0, 0, 0),   // eye
//            Vector3(0, 0, -1),  // target
//            Vector3(0, 1, 0),   // up
//            60.0f * 3.1415926f / 180.0f,
//            1.0f,
//            0.1f,
//            100.0f
//        );
//
//        Vector3 world(0, 0, -5);
//        Vector3 view = cam.getMatrix().transformPoint(world);
//
//        bool ok =
//            almostEqual(view.x, 0) &&
//            almostEqual(view.y, 0) &&
//            almostEqual(view.z, -5);
//
//        testResult("world (0,0,-5) -> view (0,0,-5)", ok);
//    }
//
//    // =========================================================
//    // TEST 4: Камера в (0,0,5), смотрит в (0,0,0)
//    // Точка в мировом центре должна стать (0,0,-5) в view-space
//    // =========================================================
//    {
//        std::cout << "\n--- Test 4: translated camera ---\n";
//
//        Camera cam(
//            Vector3(0, 0, 5),   // eye
//            Vector3(0, 0, 0),   // target
//            Vector3(0, 1, 0),   // up
//            60.0f * 3.1415926f / 180.0f,
//            1.0f,
//            0.1f,
//            100.0f
//        );
//
//        Vector3 world(0, 0, 0);
//        Vector3 view = cam.getMatrix().transformPoint(world);
//
//        bool ok =
//            almostEqual(view.x, 0) &&
//            almostEqual(view.y, 0) &&
//            almostEqual(view.z, -5);
//
//        testResult("camera (0,0,5), world origin -> view (0,0,-5)", ok);
//    }
//
//    // =========================================================
//    // TEST 5: Полный путь local -> world -> view
//    // =========================================================
//    {
//        std::cout << "\n--- Test 5: full local -> world -> view ---\n";
//
//        Object3D obj;
//        obj.setPosition(Vector3(0, 0, 0));
//        obj.setRotation(Vector3(0, 0, 0));
//        obj.setScale(Vector3(1, 1, 1));
//        obj.updateMatrix();
//
//        Camera cam(
//            Vector3(0, 0, 5),
//            Vector3(0, 0, 0),
//            Vector3(0, 1, 0),
//            60.0f * 3.1415926f / 180.0f,
//            1.0f,
//            0.1f,
//            100.0f
//        );
//
//        Vector3 local(1, 2, 3);
//        Vector3 world = obj.getMatrix().transformPoint(local);
//        Vector3 view = cam.getMatrix().transformPoint(world);
//
//        bool ok =
//            almostEqual(world.x, 1) &&
//            almostEqual(world.y, 2) &&
//            almostEqual(world.z, 3) &&
//            almostEqual(view.x, 1) &&
//            almostEqual(view.y, 2) &&
//            almostEqual(view.z, -2);
//
//        testResult("local (1,2,3) -> world (1,2,3) -> view (1,2,-2)", ok);
//    }
//
//    std::cout << "\n========== END TESTS ==========\n";
//}