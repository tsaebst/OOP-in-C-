template <int n>
struct power
{
    static constexpr int value = 2 * power<n - 1>::value;
};

template <>
struct power<0>
{
    static constexpr int value = 1;
};

template <int n>
void print_powers()
{
    std::cout << "Powers of 2 from 0 to " << n << " : ";
    int val = 1;
    for (int i = 0; i <= n; ++i)
    {
        std::cout << val;
        if (i < n)
        {
            std::cout << ", ";
        }
        val *= 2;
    }
    std::cout << '\n';
}