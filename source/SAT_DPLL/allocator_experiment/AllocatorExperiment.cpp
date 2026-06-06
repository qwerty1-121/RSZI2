#include "AllocatorExperiment.h"
#include "AllocatorTestObject.h"

#include <chrono>
#include <iostream>
#include <vector>

namespace
{
const int OBJECT_COUNT = 100000;

long long getElapsedMilliseconds(
    const std::chrono::high_resolution_clock::time_point& start,
    const std::chrono::high_resolution_clock::time_point& finish)
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        finish - start
    ).count();
}
}

void AllocatorExperiment::run()
{
    std::vector<AllocatorTestObject*> objects;
    objects.reserve(OBJECT_COUNT);

    const auto allocationStart = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < OBJECT_COUNT; ++i) {
        objects.push_back(new AllocatorTestObject(i, i % 10, i * 2));
    }

    const auto allocationFinish = std::chrono::high_resolution_clock::now();

    const auto deallocationStart = std::chrono::high_resolution_clock::now();

    for (AllocatorTestObject* object : objects) {
        delete object;
    }

    const auto deallocationFinish = std::chrono::high_resolution_clock::now();

    objects.clear();

    std::cout << "Allocator experiment" << std::endl;
    std::cout << "Objects count: " << OBJECT_COUNT << std::endl;
    std::cout << "Allocation time: "
              << getElapsedMilliseconds(allocationStart, allocationFinish)
              << " ms" << std::endl;
    std::cout << "Deallocation time: "
              << getElapsedMilliseconds(deallocationStart, deallocationFinish)
              << " ms" << std::endl;
}