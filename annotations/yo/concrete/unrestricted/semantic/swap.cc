#include "semantic.ih"

void Semantic::swap(Semantic &other)
{
    char buffer[sizeof(Semantic)];

    memcpy(buffer, this, sizeof(Semantic));
    memcpy(reinterpret_cast<char *>(this), &other, sizeof(Semantic));
    memcpy(reinterpret_cast<char *>(&other), buffer, sizeof(Semantic));
}
