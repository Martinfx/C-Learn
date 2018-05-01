#include <random>
#include <iostream>

int main()
{
    std::random_device device;
    std::mt19937 twister(device());
    std::uniform_real_distribution<double> dist(1.0, 10.0);

    for(double i = 0; i < 20; ++i)
    {
        std::cout << i << " random: " <<dist(twister) << std::endl;
    }

    return 0;
}
