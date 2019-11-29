#include <chrono>
#include <iostream>

using namespace std;
using namespace chrono;

int main()
{
    milliseconds amount(30);

    amount = seconds{5};

    minutes halfHour{ 30 };

    hours oneHour{ 1 };

    cout << (halfHour + oneHour).count() << '\n';   // displays 90

    halfHour += oneHour;        // halfHour.count() == 90
    // oneHour += halfHour;     // won't compile

    minutes min{ 1h };

    cout << min.count() << '\n';

    minutes fullHour = minutes{ 30 } + halfHour;

    halfHour = 2 * fullHour;
    halfHour = fullHour / 2;
    fullHour = halfHour + halfHour;

    halfHour /= 2;
    halfHour *= 2;

    cout << halfHour.count() << ' ' << fullHour.count() << '\n';
    cout << seconds::zero().count() << '\n';
    cout << minutes::min().count() << ' ' << minutes::max().count() << '\n';

}
