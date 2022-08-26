#include <iostream>
#include <memory>

#include <chrono>

class Timer
{
public:
    Timer()
    {
        m_StartTimepoint = std::chrono::high_resolution_clock::now();
    }

    ~Timer()
    {
        Stop();
    }

    void Stop()
    {
        auto endTimepoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endTimepoint).time_since_epoch().count();

        auto duration = end - start;
        double ms = duration * 0.001;

        std::cout << duration << "us (" << ms << "ms)\n";
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTimepoint;
};

int main()
{
    int value = 0;
    {
        Timer timer;
        for (int i = 0; i < 1000000; i++)
            value += 2;
    }
    system("chkdsk");
    std::cout << value << " ms is the benchmark time of the cpu"<< std::endl;
    std::cout << "Made by: Siddhartha Verma(Discord ID: GravityGenerator#7703), Ahaan Purohit(Discord ID: epikboi#3769) and Raaghav Sethi(Discord ID: Supernova#1230)" << std::endl;

    __debugbreak();
}
