#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

int main()
{
    std::vector<int> vec = {333, 222, 140, 23, 45, 66, 76, 88, 44, 7777};

    using mapsId = std::map<int, std::vector<int>>;
    mapsId maps;

    for(auto i : vec) {
        std::cout << "i: " << i << std::endl;
        maps[0].push_back(i);
        maps[1].push_back(i);
        maps[2].push_back(i);
        maps[3].push_back(i);
    }

    for(auto j : maps) {
        std::cout << "j.first: " << j.first << " j.second[0]: " << j.second[0] << std::endl;
    }

    std::for_each(maps.begin(), maps.end(), [](auto &n){
        std::cout << "std::sort: " << n.first << std::endl;
        std::sort(n.second.begin(), n.second.end());
    });

    for(auto j : maps) {
        std::cout          << "j.first: " << j.first << std::endl;
        std::cout          << " j.second[0]: " << j.second[0] <<std::endl;
        std::cout          << " j.second[1]: " << j.second[1] <<std::endl;
        std::cout          << " j.second[2]: " << j.second[2] <<std::endl;
        std::cout          << " j.second[3]: " << j.second[3] <<std::endl;
        std::cout          << " j.second[4]: " << j.second[4] <<std::endl;

    }

    return 0;
}
