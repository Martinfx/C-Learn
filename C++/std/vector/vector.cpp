#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> vec = {12,2333,4445,555,554433,6666,77888,55,5676};

    std::for_each(vec.begin(), vec.end(), [](auto &v) {
        std::cout << v << std::endl;
    });

    std::vector<std::string> vec_string { "trololooooooooo"};
    for(auto x : vec_string ) {
        std::cout << "x: " << x << std::endl;
    }

    std::vector<std::string> vec1 = {"go", "stable", "release", "configure"};
    for(auto v : vec1) {
       std::cout  << v << std::endl;
    }

    std::for_each(vec1.begin(), vec1.end(), [](const std::string& str) {
        //std::cout << "---------------" << std::endl;
        std::cout << "std::for_each: " << str << std::endl;
    });

    return 0;
}
