#include <iostream>

#include <algorithm>
#include <vector>

using namespace std;


//                      cout << "compare " << vectEl.val << ", " <<
//                              vectEl.ch << " to " <<
//                              value.val << ", " << value.ch << '\n';

int main()
{
    struct X
    {
        int val;
        char ch;
    };

    // lambda expression:
    //    1st parameter: fixed value,
    //    2nd parameter: element from the vector.
    //
    // sorted in ascending order: use 2nd-param. < 1st-param or
    //     2nd-param <= 2nd-param
    //
    // If the value to sort with (= the key) is not present in the
    //     sorted vector then all variants (upper_bound, lower_bound,
    //     using > or >= when descendingly sorted, using < or <= when
    //     ascendingly sorted return the iterator to the positing where
    //     the key should be inserted.
    //
    // If the value to sort with (= the key) already is present in the
    //     sorted vector then:
    //        * lower_bound with <= and upper_bound with < return the
    //     iterator to the first occurrence of the key in the sorted
    //     vector;
    //        * lower_bound with < and upper_bound with <= return the
    //     iterator beyond the last occurrence of the key in the sorted
    //     vector
    //
    // sorted in descending order: use 2nd-param. > 1st-param or
    //     2nd-param >= 2nd-param
    //
    // If the value to sort with (= the key) already is present in the
    //     sorted vector then:
    //        * lower_bound with >= and upper_bound with > return the
    //     iterator to the first occurrence of the key in the sorted
    //     vector;
    //        * lower_bound with > and upper_bound with >= return the
    //     iterator beyond the last occurrence of the key in the sorted
    //     vector

  {
      vector<X> values
          {
              { 4, 'X' },
              { 1, 'a' },
              { 2, 'a' },
              { 3, 'a' },
              { 4, 'b' },
              { 4, 'c' },
              { 5, 'a' },
              { 7, 'a' },
              { 9, 'a' }
          };



// UPDATE THE ABOVE TEXT ACCORDING TO THIS:
//  note that the 1st param. refers to the vector, the 2nd to the value
//      auto insert = upper_bound(
      auto insert = lower_bound(
                  values.begin() + 1, values.end(),
                  values[0],
                  [&](X const &vectEl, X const &value)
                  {
                      return vectEl.val <= value.val;
    // upper_bound: with <=  at the beginning, lower_bound with <
    // upper_bound: with <   at the end, lower_bound with <=

                  }
            );

      cout << "FIRST Insert at " << (insert - values.begin()) << '\n';

      // insert points at the 1st element <= value: the topmost
      // element should be moved there.

      rotate(values.begin(), values.begin() + 1, insert);

      for (X const &value: values)
          cout << value.val << ' ' << value.ch << ",  ";

      // upper_bound: 1 a,  2 a,  3 a,  4 X,  4 b,  4 c,  5 a,  7 a,  9 a,
      // or lower-bound with <=

      // lower bound: 1 a,  2 a,  3 a,  4 b,  4 c,  4 X,  5 a,  7 a,  9 a,
      // or upper_bound with <=
      cout << '\n';
  }

  {
      vector<X> values
          {
              { 4, 'X' },
              { 9, 'a' },
              { 7, 'a' },
              { 5, 'a' },
              { 4, 'b' },
              { 4, 'c' },
              { 3, 'a' },
              { 2, 'a' },
              { 1, 'a' }
          };


//    auto insert = upper_bound(
      auto insert = lower_bound(
                  values.begin() + 1, values.end(),
                  values[0],
                  [&](X const &vectEl, X const &value)
                  {
                      return vectEl.val >= value.val;
                  }
            );
    // upper_bound: with >=  at the beginning, lower_bound with >
    // upper_bound: with >   at the end, lower_bound with >=

      cout << "FIRST: Insert at " << (insert - values.begin()) << '\n';

      // insert points at the 1st element <= value: the topmost
      // element should be moved there.

      rotate(values.begin(), values.begin() + 1, insert);

      for (X const &value: values)
          cout << value.val << ' ' << value.ch << ",  ";

      // upper_bound: 9 a,  7 a,  5 a,  4 X,  4 b,  4 c,  3 a,  2 a,  1 a,
      // or lower_bound with >=

      // lower bound: 9 a,  7 a,  5 a,  4 b,  4 c,  4 X,  3 a,  2 a,  1 a,
      // or upper_bound with >=
      cout << '\n';
  }

return 0;

  {
      vector<X> values
          {
              { 4, 'X' },
              { 9, 'a' },
              { 7, 'a' },
              { 5, 'a' },
              { 3, 'a' },
              { 2, 'a' },
              { 1, 'a' }
          };


      auto insert = lower_bound(
                  values.rbegin(), values.rend() - 1,
                  values[0],
                  [&](X const &value, X const &vectEl)
                  {
                      return vectEl.val >= value.val;
                  }
            );

      cout << "Insert at " << (insert.base() - values.begin()) << '\n';

      // insert points at the 1st element <= value: the topmost
      // element should be moved there.

      rotate(values.begin(), values.begin() + 1, insert.base());

      for (X const &value: values)
          cout << value.val << ' ' << value.ch << ",  ";

      // all variants (upper_bound, lower_bound, >, >= :
      // 9 a,  7 a,  5 a,  4 X,  3 a,  2 a,  1 a,

      cout << '\n';
  }

}
