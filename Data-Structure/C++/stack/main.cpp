#include <iostream>

template <class T>
class Stack
{
public:
    explicit Stack(size_t max_size);
    ~Stack();

    bool push(const T &val);
    bool pop(T& val);
    size_t max_size;
    size_t current_size;
    T *buffer;
    T *top;
};

template<class T>
Stack<T>::~Stack() {
    free(buffer);
}

template<class T>
Stack<T>::Stack(size_t max_size): max_size(max_size), current_size(max_size), buffer(nullptr), top(nullptr)
{
    if(max_size == 0)
    {
        current_size = 10;
    }

    buffer = (T *)malloc(sizeof (T)*current_size);

    top = buffer;
}

template<class T>
bool Stack<T>::push(const T& val)
{
    if(buffer + current_size == top) {
        if(max_size == 0)
        {
            current_size = current_size + current_size * 0.5;
            auto offset = top - buffer;
            buffer = (T*)realloc(buffer,current_size * sizeof (T));
            if (buffer == nullptr) {
                free(buffer);
                return false;
            }

            top = buffer + offset;
        }
        else {
            return false;
        }
    }

    *top = val;
    top = top + 1;
    return true;
}

template<class T>
bool Stack<T>::pop(T& val)
{
    if(buffer == top) {
        return false;
    }

    top = top - 1;
    val = *top;
    return true;
}

int main()
{
    Stack<int> stack(0);

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    std::cout << stack.push(5)<<std::endl;
    std::cout << stack.push(6)<<std::endl;
    std::cout << stack.push(7)<<std::endl;
    std::cout << stack.push(8)<<std::endl;
    std::cout << stack.push(9)<<std::endl;
    std::cout << stack.push(10)<<std::endl;
    std::cout << stack.push(11)<<std::endl;
    std::cout << stack.push(12)<<std::endl;
    std::cout << stack.push(13)<<std::endl;
    std::cout << stack.push(14)<<std::endl;

    int a;
    stack.pop(a);
    std::cout << a << std::endl;
    stack.pop(a);
    std::cout << a << std::endl;
    stack.pop(a);
    std::cout << a << std::endl;
    stack.pop(a);
    std::cout << a << std::endl;
    stack.pop(a);
    std::cout << a << std::endl;
    std::cout << stack.pop(a) << std::endl;
    std::cout << a << std::endl;

    return 0;
}
