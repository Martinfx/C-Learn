#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <random>

int main()
{
    std::vector<int32_t> vec1, vec2, result;
    std::list<int32_t> list_result;

    vec1.emplace_back(std::rand() % 100);
    vec2.emplace_back(std::rand() % 100);

    // std::vector havent push_front, only we use std::back_inserter
    std::transform(vec1.begin(), vec1.end(),
                   vec2.begin(), std::back_inserter(result),
                   [](int32_t i, int32_t j){ return i + j;});

    for(auto i : result) {
        std::cout << "Vector result: " << i << std::endl;
    }

    std::transform(vec1.begin(), vec1.end(),
                   vec2.begin(), std::front_inserter(list_result),
                   [](int32_t i, int32_t j){ return i + j;});

    for(auto i : list_result) {
        std::cout << "List result: " << i << std::endl;
    }

    return 0;
}
