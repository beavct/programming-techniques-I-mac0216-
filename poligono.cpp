#include <iostream>
#include <math.h>

using namespace std;

class Poligono
{
protected:
    int numeroDeLados;
    double *lados;

public:
    ~Poligono()
    {
        free(lados);
    }
};

void setNumeroDeLados(int numeroDeLados)
{
    this->numeroDeLados = numeroDeLados;
}

void setLados()
{
    lados = (double *)malloc(numeroDeLados * sizeof(int));

    for (int i = 0; i < numeroDeLados; i++)
    {
        cout << "Tamanho do lado " << i << ": ";
        cin >> lados[i];
    }
}

int getNumeroDeLados()
{
    return numeroDeLados;
}

double *getLados()
{
    return lados;
}

class Triangulo : public Poligono
{
public:
    Triangulo()
    {
        this->setNumeroDeLados(3);
        this->setLados();
    }
    /* Area de um triângulo = sqrt(s*(s-a)*(s-b)*(s-c))
     * a, b e c são os lados
     * s é o semiperímetro calculado por (a+b+c)/2 */
    double calculaArea()
    {
        double p = (lados[0] + lados[1] + lados[2]) / 2;
        return sqrt(p * (p - lados[0]) * (p - lados[1]) * (p - lados[2]));
    }
};

class Retangulo : public Poligono
{
public:
    Retangulo()
    {
        this->setNumeroDeLados(4);
        this->setLados();
    }
    double calculaArea()
    {
        return lados[0] * lados[1];
    }
};

int main()
{
    Poligono p;
    p.setNumeroDeLados(4);
    p.setLados();
    for (int i = 0; i < p.getNumeroDeLados(); i++)
        cout << p.getLados()[i] << " ";
    cout << endl;
    Triangulo t;
    for (int i = 0; i < t.getNumeroDeLados(); i++)
        cout << t.getLados()[i] << " ";
    cout << endl;
    cout << t.calculaArea() << endl;
    Retangulo r;
    for (int i = 0; i < r.getNumeroDeLados(); i++)
        cout << r.getLados()[i] << " ";
    cout << endl;
    cout << r.calculaArea() << endl;
    return 0;
}