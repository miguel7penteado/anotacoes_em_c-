    Strings::Strings(Strings &&tmp)
    :
        d_string(tmp.d_string),
        d_size(tmp.d_size),
        d_capacity(tmp.d_capacity)
    {
        tmp.d_string = 0;
        tmp.d_size = 0;
        tmp.d_capacity = 0;
    }
