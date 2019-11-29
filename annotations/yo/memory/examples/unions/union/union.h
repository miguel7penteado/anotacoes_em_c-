#ifndef INCLUDED_UNION_
#define INCLUDED_UNION_

#include <string>

union Union
{
    enum Field                               // indicators for the used type(s)
    {
        TEXT,
        VALUE
    };

    struct Cp
    {
        Field current;
        Union const &other;
        Field next;
    };

    struct Mv
    {
        Field current;
        Union &&other;
        Field next;
    };

    private:
        std::string u_text;
        int u_value;

        static void (Union::*s_destroy[])();
        static void (Union::*s_swap[][2])(Union &other);
        static void (Union::*s_copy[])(Union const &other);

    public:
        Union(Union const &other) = delete;     // no std constructors and
        ~Union();                               // an empty destructor in
                                                // unrestrestricted unions

        Union(std::string const &text);     // init u_text      1.cc
        Union(int value);                   // init u_value     2.cc

        Union(Union const &other, Field type); // init from other, type 3.cc
        Union(Union &&tmp, Field type);        // init from tmp, type   4.cc

        Union operator=(Cp rhs);

            // acts like copy assignment. We never use sequential assignment
            // on unrestr. unions so void is returned
        void copy(Field current, Union const &other, Field next);  // 1.cc

            // like move assignment: same considerations.
        void move(Field current, Union &&tmp, Field next);         // 1.cc

        void swap(Field current, Union &other, Field next);

        void destroy(Field type);

        std::string const &text() const;
        int value() const;

    private:
        void destroyText();
        void destroyValue();                    // noOp

        void copyText(Union const &other);
        void copyValue(Union const &other);

        void swap2Text(Union &other);            // swaps equal types
        void swapTextValue(Union &other);

        void swapValueText(Union &other);        // (reverses operands)
        void swap2Value(Union &other);           // swaps equal types
};

inline void Union::destroyValue()
{}

inline std::string const &Union::text() const
{
    return u_text;
}

inline int Union::value() const
{
    return u_value;
}

#endif
