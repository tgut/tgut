#include <iostream>
using namespace std;
int main()
{
    #if test_long_cout_statement
    int v1,v2;
    std::cout << "The sum of " << v1 \
    << " and " << v2 \
    << " is " << v1 + v2 << std::endl;
    return 0;
    #endif

    #if test_sum_from_input_statement
    int int_num = 0;
    int sum = 0;
    while (cin >> int_num)
    {
        cout << sum << "+ " << int_num << ":";
        sum += int_num;
        cout << sum << endl;
    }
    return 0;
    #endif
}
