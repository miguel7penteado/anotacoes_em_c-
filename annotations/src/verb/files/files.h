#ifndef INCLUDED_FILES_
#define INCLUDED_FILES_

#include <string>
#include <vector>

class Files
{
    std::vector<std::string> d_fname;
    size_t d_idx = 0;

    public:
        Files();

        explicit operator bool() const;
        std::string const &next();

    private:
        void fillArgs();                         // add arguments to d_fname
        void read(std::string const &fname);     // or fnames from file
};
        
inline Files::operator bool() const
{
    return d_idx < d_fname.size();
}

inline std::string const &Files::next()
{
    return d_fname[d_idx++];
}

#endif
