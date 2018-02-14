#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>

double mean(std::vector<double> mean)
{
    double m_mean = 0.0;
    for(unsigned int i = 0; i < mean.size(); ++i)
    {
        m_mean += mean[i];
    }

    return m_mean / mean.size();
}

double median(std::vector<double> &median)
{
    double m_median = 0.0;
    std::sort(median.begin(), median.begin() + median.size());
    m_median = median[(median.size() / 2 ) - 1] + median[(median.size() / 2 )];

    if(median.size() % 2 == 0)
    {
       return (median[(median.size() / 2 ) - 1] + median[(median.size() / 2 )])  / 2.0;
    }

    return median[(median.size()  / 2) - 1];
}

double mode(std::vector<double> mode)
{
    std::map<double, int> m_numbers;
    for(unsigned int i = 0; i < mode.size(); ++i)
    {
        m_numbers.insert(std::pair<double, int>(mode[i], 0));
        if(mode[i])
        {
            m_numbers.at(mode[i]) += 1;
        }
    }

    auto x = std::max_element(m_numbers.begin(), m_numbers.end(),
    [](const std::pair<int, int>& p1, const std::pair<int, int>& p2) {
        return p1.second < p2.second; });

    return x->first;
}

int main() {
    int n = 0;
    std::vector<double> num;
    std::cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int numbers = 0;
        std::cin >> numbers;
        num.push_back(numbers);
    }

    std::cout << mean(num) << std::endl;
    std::cout << median(num) << std::endl;
    std::cout << mode(num) << std::endl;

    return 0;
}
