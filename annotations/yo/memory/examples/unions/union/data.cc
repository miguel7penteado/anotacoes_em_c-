#include "union.ih"

void (Union::*Union::s_destroy[])() =
{
    &Union::destroyText,
    &Union::destroyValue
};

void (Union::*Union::s_copy[])(Union const &other) =
{
    &Union::copyText,
    &Union::copyValue
};

void (Union::*Union::s_swap[][2])(Union &other) =
{
  {  &Union::swap2Text,     &Union::swapTextValue},
  { &Union::swapValueText,  &Union::swap2Value},
};
