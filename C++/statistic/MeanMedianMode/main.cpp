#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

template<typename T>
T mean(std::vector<T> mean) {
    T result = 0.0;
    for (auto i : mean) {
         result += mean[i];
    }
    return result / mean.size();
}


template<typename T>
T median(std::vector<T> &median) {
    T result;
    std::sort(median.begin(), median.end());
    result = median[(median.size() / 2 ) - 1] + median[(median.size() / 2 )];

    if(median.size() % 2 == 0) {
       return (median[(median.size() / 2 ) - 1] + median[(median.size() / 2 )])  / 2.0;
    }

    return median[(median.size()  / 2) - 1];
}

template <typename T>
T mode(std::vector<T> mode) {
    std::map<double, int> result;
    for(unsigned int i = 0; i < mode.size(); ++i) {
        result.insert(std::pair<double, int>(mode[i], 0));
        if(mode[i]) {
            result.at(mode[i]) += 1;
        }
    }

    auto x = std::max_element(result.begin(), result.end(),
    [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
        return p1.second < p2.second; });

    return x->first;
}

int main() {
    std::vector<double> numbers {11.0,222.0,2225.0,111.0,22.0,11.0,22.0};
    std::cout << mean(numbers) << std::endl;
    std::cout << median(numbers) << std::endl;
    std::cout << mode(numbers) << std::endl;

    return 0;
}
