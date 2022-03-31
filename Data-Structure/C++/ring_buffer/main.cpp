#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

template <class T> class ring_buffer{
public:
    explicit ring_buffer(unsigned int max_size);
    bool write_element(const T &element);
    bool read_elem(T &element);
    void write_element_blocking(const T &element);
    void read_elem_blocking(T &element);
    ~ring_buffer();
private:
    int max_size{};
    size_t current_size;
    T* buffer;
    T* write_ptr;
    T* read_ptr;
    std::mutex access_lock;
    std::mutex read_lock;
    std::mutex write_lock;
};


template<class T>
ring_buffer<T>::ring_buffer(unsigned int max_size) : max_size(max_size), current_size(0) {
    if(max_size != 0)
    {
        buffer = (T *)malloc(sizeof (T)*max_size);
        current_size = max_size;
    }
    else
    {
        buffer = (T *)malloc(sizeof (T)*10);
        current_size = 10;
    }
    write_ptr = read_ptr = buffer;
    read_lock.lock();
    write_lock.lock();
}

template<class T>
ring_buffer<T>::~ring_buffer() {
    free(buffer);
}

template<class T>
bool ring_buffer<T>::write_element(const T &element) {
    access_lock.lock();
    auto next_pos = buffer + ((write_ptr - buffer) + 1)%(max_size);
    if (next_pos == read_ptr && current_size == 0)
    {
        T* end_buffer = buffer + current_size;
        current_size = current_size + current_size * 0.5;
        buffer = (T*)realloc(buffer, current_size * sizeof (T));
        if (buffer == nullptr) {
            free(buffer);
            return false;
        }
        else {

            for(T* i = buffer; i < read_ptr; i++)
            {
                if(buffer + current_size > end_buffer) {
                   end_buffer = (end_buffer - current_size);
                }

                *end_buffer++ = *i;
            }
        }

        access_lock.unlock();
        return false;
    }
    *write_ptr = element;
    write_ptr = next_pos;
    access_lock.unlock();
    return true;
}

template<class T>
bool ring_buffer<T>::read_elem(T &element) {
    access_lock.lock();
    T *next_pos = buffer + ((read_ptr - buffer) + 1)%(max_size);
    if (read_ptr == write_ptr)
    {
        access_lock.unlock();
        return false;
    }
    element = *read_ptr;
    read_ptr = next_pos;
    access_lock.unlock();
    return true;
}

template<class T>
void ring_buffer<T>::write_element_blocking(const T &element) {
    while (!write_element(element))
        write_lock.lock();
    read_lock.unlock();
}

template<class T>
void ring_buffer<T>::read_elem_blocking(T &element) {
    while (!read_elem(element))
        read_lock.lock();
    write_lock.unlock();
}
using namespace std::chrono_literals;

void writer(ring_buffer<int> *rb)
{
    int i=0;
    while (true){
        std::this_thread::sleep_for(30ms);

        rb->write_element_blocking(i++);
    }
}
void reader(ring_buffer<int> *rb,std::string name)
{
    int i=0;
    while (true){
        std::this_thread::sleep_for(30ms);
        rb->read_elem_blocking(i);
        std::cout << name <<  "\t" << i<<std::endl;
    }
}
int main() {
    ring_buffer <int>rb (10);
    std::thread th1 (writer,&rb);
    std::thread th6(writer,&rb);
    std::thread th2 (writer,&rb);
    std::thread th3 (writer,&rb);
    std::thread th4 (writer,&rb);
    std::thread th5 (writer,&rb);
    std::thread th10 (reader,&rb,"a");
    std::thread th11 (reader,&rb,"b");
    std::thread th12 (reader,&rb,"c");
    std::thread th13 (reader,&rb,"d");
    std::thread th14 (reader,&rb,"e");
    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();
    th10.join();
    th11.join();
    th12.join();
    th13.join();
    th14.join();

    return 0;
}
