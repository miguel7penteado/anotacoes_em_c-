#include <iostream>
#include <filesystem>

using namespace std;
using namespace filesystem;

//demo
int main()
{
    path tmp{ "/tmp" };

    auto pod = space(tmp);

    cout << "The filesystem containing /tmp has a capacity of " <<
                                            pod.capacity << " bytes,\n"
        "i.e., " << pod.capacity / (1024 * 1024) << " MB.\n"
        "# free bytes: " << pod.free << "\n"
        "# available:  " << pod.available << "\n"
        "free + available:  " << pod.free + pod.available << '\n';
}
//=
