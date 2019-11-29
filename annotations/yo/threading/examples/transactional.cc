// compile with -fgnu-tm

#include <thread>
#include <chrono>
#include <iostream>
#include <mutex>

using namespace std;


void fun(int value)
{
    static mutex mut;
    for (size_t rept = 0; rept != 10; ++rept)
    {
        this_thread::sleep_for(chrono::seconds(1));
//        mut.lock();
//        synchronized
        atomic_noexcept
        {
            cout << "fun " << value << '\n';
        }
//        mut.unlock();
    }
};

int main()
{
    thread thr{ fun, 1 };
    fun(2);

    thr.join();

    cout << "done\n";
}
