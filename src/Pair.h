#pragma once

namespace libre_ds
{
    template <typename T_first, typename T_second>
    struct Pair
    {
        inline Pair() {}
        inline Pair(T_first first, T_second second)
        {
            this->first = first;
            this->second = second;
        }

        T_first first;
        T_second second;
    };
}
