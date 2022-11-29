#include <random>
#include <iostream>

using namespace std;

int main()
{
    default_random_engine gerador(1);
    int i;
    uniform_int_distribution<short> distrI(1, 4); //Utilizando template <tipo>
    for (i = 0; i < 10; i++)
        cout << distrI(gerador) << endl;
    uniform_real_distribution<float> distrR(1, 4);
    for (i = 0; i < 10; i++)
        cout << distrR(gerador) << endl;
    return 0;
}