#include <iostream>

using namespace std;

struct VI                               // define the data structure to
{                                       // operate on
    static size_t s_count;
    typedef int value_type;

    VI() = default;

    VI(VI const &other)
    {
        (*this)[0] = other[0];
        cout << "CC, count = " << s_count << '\n';
    }

    VI(VI &&tmp)
    {
        (*this)[0] = tmp[0];
        cout << "MC, count = " << s_count << '\n';
    }

    int d_value = 0;

    size_t size() const
    {
        return 1;
    };

    VI &operator=(VI const &other)
    {
        cout << "op=\n";
        (*this)[0] = other[0];
        return *this;
    }

    VI &operator+=(VI const &other)
    {
        cout << "op+=\n";
        (*this)[0] += other[0];
        return *this;
    }

    int &operator[](size_t idx)
    {
        ++s_count;
        return d_value;
    }

    int const &operator[](size_t idx) const
    {
        ++s_count;
        return d_value;
    }
};

VI operator+(VI const &lhs, VI const &rhs)
{
    cout << "copy +\n";
    VI tmp{lhs};
    tmp += rhs;
    return tmp;
}

VI &&operator+(VI &&tmp, VI const &rhs)
{
    cout << "move +\n";
    tmp += rhs;
    return move(tmp);
}


size_t VI::s_count;


int main()
{
    VI a, b, c, d;

    VI e = a + b  + c + d;

    cout << "# index computations: " << VI::s_count << '\n';
}
