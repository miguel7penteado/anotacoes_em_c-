#include "../htmlindex.h"

void display(unsigned idx)
{
    IndexEntry
        &ie = indexVector[idx];

    if (ie.firstChar() > indexSection && isalnum(ie.firstChar()))
    {
        indexSection = ie.firstChar();
        cout << "   <td>&nbsp;<br><h1 align=center>" << indexSection <<
                                                            "</h1></td>\n"
                "</tr>\n"
                "<tr>\n";
    }

    cout <<
        "   <td> " << ie.getKey() << " </td>\n" <<
        "   <td>\n";

    ie.showRefs();

    cout <<
        "   </td>\n";
}
