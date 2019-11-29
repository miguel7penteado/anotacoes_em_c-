#include <iostream>
#include <system_error>
#include <string>

using namespace std;

int main()
{
    error_code ec( (int)errc::address_in_use, system_category() );

    cout << ec.value() << '\n';
    cout << ec.default_error_condition().value() << '\n';
    cout << ec.category().name() << '\n';
}
