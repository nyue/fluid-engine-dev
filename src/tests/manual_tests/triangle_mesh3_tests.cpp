// Copyright (c) 2018 Doyub Kim
//
// I am making my contributions/submissions to this project solely in my
// personal capacity and am not conveying any rights to any intellectual
// property of any third parties.

#include <manual_tests.h>

#include <jet/triangle_mesh3.h>

using namespace jet;

JET_TESTS(TriangleMesh3);

JET_BEGIN_TEST_F(TriangleMesh3, PointsOnlyGeometries) {
    TriangleMesh3 triMesh;

    triMesh.addPoint({0, 0, 0});
    triMesh.addPoint({0, 0, 1});
    triMesh.addPoint({0, 1, 0});
    triMesh.addPoint({0, 1, 1});
    triMesh.addPoint({1, 0, 0});
    triMesh.addPoint({1, 0, 1});
    triMesh.addPoint({1, 1, 0});
    triMesh.addPoint({1, 1, 1});

    // -x
    triMesh.addPointTriangle({0, 1, 3});
    triMesh.addPointTriangle({0, 3, 2});

    // +x
    triMesh.addPointTriangle({4, 6, 7});
    triMesh.addPointTriangle({4, 7, 5});

    // -y
    triMesh.addPointTriangle({0, 4, 5});
    triMesh.addPointTriangle({0, 5, 1});

    // +y
    triMesh.addPointTriangle({2, 3, 7});
    triMesh.addPointTriangle({2, 7, 6});

    // -z
    triMesh.addPointTriangle({0, 2, 6});
    triMesh.addPointTriangle({0, 6, 4});

    // +z
    triMesh.addPointTriangle({1, 5, 7});
    triMesh.addPointTriangle({1, 7, 3});

    saveTriangleMeshData(triMesh, "cube.obj");
}
JET_END_TEST_F

JET_BEGIN_TEST_F(TriangleMesh3, PointsAndNormalGeometries) {
    TriangleMesh3 triMesh;

    triMesh.addPoint({0, 0, 0});
    triMesh.addPoint({0, 0, 1});
    triMesh.addPoint({0, 1, 0});
    triMesh.addPoint({0, 1, 1});
    triMesh.addPoint({1, 0, 0});
    triMesh.addPoint({1, 0, 1});
    triMesh.addPoint({1, 1, 0});
    triMesh.addPoint({1, 1, 1});

    triMesh.addNormal({-1, 0, 0});
    triMesh.addNormal({1, 0, 0});
    triMesh.addNormal({0, -1, 0});
    triMesh.addNormal({0, 1, 0});
    triMesh.addNormal({0, 0, -1});
    triMesh.addNormal({0, 0, 1});

    // -x
    triMesh.addPointTriangle({0, 1, 3});
    triMesh.addNormalTriangle({0, 0, 0});
    triMesh.addPointTriangle({0, 3, 2});
    triMesh.addNormalTriangle({0, 0, 0});

    // +x
    triMesh.addPointTriangle({4, 6, 7});
    triMesh.addNormalTriangle({1, 1, 1});
    triMesh.addPointTriangle({4, 7, 5});
    triMesh.addNormalTriangle({1, 1, 1});

    // -y
    triMesh.addPointTriangle({0, 4, 5});
    triMesh.addNormalTriangle({2, 2, 2});
    triMesh.addPointTriangle({0, 5, 1});
    triMesh.addNormalTriangle({2, 2, 2});

    // +y
    triMesh.addPointTriangle({2, 3, 7});
    triMesh.addNormalTriangle({3, 3, 3});
    triMesh.addPointTriangle({2, 7, 6});
    triMesh.addNormalTriangle({3, 3, 3});

    // -z
    triMesh.addPointTriangle({0, 2, 6});
    triMesh.addNormalTriangle({4, 4, 4});
    triMesh.addPointTriangle({0, 6, 4});
    triMesh.addNormalTriangle({4, 4, 4});

    // +z
    triMesh.addPointTriangle({1, 5, 7});
    triMesh.addNormalTriangle({5, 5, 5});
    triMesh.addPointTriangle({1, 7, 3});
    triMesh.addNormalTriangle({5, 5, 5});

    saveTriangleMeshData(triMesh, "cube_with_normal.obj");
}
JET_END_TEST_F

JET_BEGIN_TEST_F(TriangleMesh3, BasicIO) {
    TriangleMesh3 triMesh;

    std::ifstream file(RESOURCES_DIR "bunny.obj");
    if (file) {
        triMesh.readObj(&file);
        file.close();
    }
}
JET_END_TEST_F
