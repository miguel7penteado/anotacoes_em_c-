#include <utility>
#include <string>
#include <vector>
#include <queue>

template <typename Type>
concept bool BasicIterator =
    requires(Type type)
    {
        *type;
    }
    and requires (Type lhs, Type rhs)
    {
        { lhs == rhs; }
        { lhs != rhs; }
    }
;


template <typename Type>
concept bool ReadAndIncrementable =
    requires (Type type)
    {
        requires BasicIterator<Type>;
        ++type;
        type++;
    }
;


template <ReadAndIncrementable Type>
void copy(Type it1, Type it2);

using namespace std;

int main()
{
    copy(string{}.begin(), string{}.end());
}
