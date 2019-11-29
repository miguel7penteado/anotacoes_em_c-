#include "union.ih"

void Union::swapTextValue(Union &other)
{
    int value = other.u_value;       // save the int value

    new(&other.u_text) string{ std::move(u_text) }; // install string at other
    u_text.~string();                   // remove the old field's union

    u_value = value;                    // store the new field's union
}
