#include <iostream>
#include <vector>

class OverOperator
{
public:

    void operator()(const int &x) {
        std::cout << "numbers: " << x << std::endl;
    }

} overOperator;

int main()
{
    std::vector<int> v = {2, 1, 44, 33, 22, 11, 9, 7, 88, 99, 202, 672, 986};
    std::sort(v.begin(), v.end());
    std::for_each(v.begin(), v.end(), overOperator);

    return 0;
}
