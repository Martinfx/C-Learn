#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

int main()
{
    std::vector<int32_t> num1 = {1,3,5,7,9,11,13,15,17,19};
    std::vector<int32_t> num2 = {2,4,6,8,10,12,14,16,18,20};
    std::vector<int32_t> vector_result;
    std::list<int32_t> list_result;

    // std::vector havent push_front, only we use std::back_inserter
    std::transform(num1.begin(), num1.end(),
                   num2.begin(), std::back_inserter(vector_result),
                   [](int32_t i, int32_t j){ return i + j;});

    for(auto i : vector_result)
    {
        std::cout << "Vector result: " << i << std::endl;
    }

    std::transform(num1.begin(), num1.end(),
                   num2.begin(), std::front_inserter(list_result),
                   [](int32_t i, int32_t j){ return i + j;});

    for(auto i : list_result)
    {
        std::cout << "List result: " << i << std::endl;
    }

    return 0;
}
