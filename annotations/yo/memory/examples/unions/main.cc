#include "main.ih"

int main(int argc, char **argv)
{
    Data w1{ 0 };
    cout << "Value: " << w1.value() << '\n';

    Data w2{ "hello world" };
    cout << "Value: " << w2.text() << '\n';

    w1 = w2;

    cout << "Value: " << w1.text() << '\n';

    w1 = 10;

    cout << w1.field() << ": " << w1.value() << '\n';

    w1.swap(w2);

    cout << w1.field() << ": " << w1.text() << '\n' <<
            w2.field() << ": " << w2.value() << '\n';

}
