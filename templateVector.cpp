#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<float> vetorReais; // Utilizando template vector<tipo>
    for (int i = 1; i <= 5; i++)
        vetorReais.push_back(i / 2.0);
    cout << "Varrendo o vetor: ";
    for (float f : vetorReais)
        cout << f << " ";
    cout << endl;
    return 0;
}