#include <iostream>

using namespace std;

void suma(int a, int b)
{
	cout << "Enteros: " << a << " + " << b << " = " << a + b << endl;
}

void suma(double a, double b)
{
	cout <<"Dobles: " << a << " + " << b << " = " << a + b << endl;
}

int main()
{
    suma(2, 3);
    suma(4.1, 1.2);
    suma(3.2, double(7));
    //sin casting a double da error por no saber cuál elegir
    return 0;
}
