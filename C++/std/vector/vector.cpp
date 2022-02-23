#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec;
    vec.emplace_back(std::rand() % 100000);

    std::for_each(vec.begin(), vec.end(), [](auto &v) {
        std::cout << v << std::endl;
    });

    std::vector<std::string> vec_string { "trololooooooooo"};
    for(auto x : vec_string ) {
        std::cout << "x: " << x << std::endl;
    }

    std::vector<std::string> vec1 = {"goto","go",
                                     "stable", "release",
                                     "configure"};

    for(auto v : vec1) {
       std::cout  << v << std::endl;
    }

    std::for_each(vec1.begin(), vec1.end(), [](const std::string& str) {
        std::cout << "std::for_each: " << str << std::endl;
    });

    return 0;
}
