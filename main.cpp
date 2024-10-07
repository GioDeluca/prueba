#include <iostream>

using namespace std;

void mostrar(int vec[], int dim)
{
	for (int i = 0; i < dim; i++)
		cout << i << ": " << vec[i] << endl;
}
//Algoritmo de inserción
void ordenar_asc(int v[], int dim)
{
	int i, j, temp;

	for (i = 1; i < dim ; i++) {
		temp = v[i];
		j = i - 1;
		while (j >= 0 && v[j] > temp) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = temp;
	}
}

//Algoritmo de inserción pero cambio la comparación para que sea descendente
void ordenar_desc(int v[], int dim)
{
	int i, j, temp;

	for (i = 1; i < dim ; i++) {
		temp = v[i];
		j = i-1;
		while (j >= 0 && v[j] < temp) {
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = temp;
	}
}

//Algoritmo de inserción parametrizando la función criterio de comparación
void ordenar(int vec[], int dim, int (*criterio)(int, int))
{
	int i, j;
	int temp;

	for (i = 1; i < dim ; i++) {
		temp = vec[i];
		j = i - 1;

		//&& vec[j] > temp
		while (j >= 0 && criterio(vec[j], temp) > 0) {
			vec[j + 1] = vec[j];
			j--;
		}
		vec[j + 1] = temp;
	}
}
/*******************************************************************************
* La función criterio debe comparar los elementos que se le pasan como
* parámetros. Supongamos que al primer parámetro lo llamo a y al segundo b, y
* llamo r al valor retornado, entonces cumplir:
*         Si a > b  entonces r > 0
*         Si a < b  entonces r < 0
*         Si a == b entonces r == 0
*******************************************************************************/
//Criterios
int criterio_int_asc(int a, int b)
{
	if (a > b)
		return 1;
	else if (a < b)
		return -1;
	else
		return 0;
	//return a - b; OJO solo funciona con enteros, no con flotantes
}

int criterio_int_des(int a, int b)
{
	if (a > b)
		return -1;
	else
		return a < b ? 1 : 0;
	//return b - a; OJO solo funciona con enteros, no con flotantes
}

/*******************************************************************************
* Alterantivas
* Si y solo si son enteros
* return a - b;//ascendente
* return b - a;//descendente
* Para cualquier tipo numérico
* return (a > b) - (a < b);//ascendente
* return (a < b) - (a > b);//descendente
* Para cualquier tipo que pueda usar los comparadores < y >
* return (a < b) ? -1 : (a > b);//ascendente
* return (a > b) ? -1 : (a < b);//descendente
*******************************************************************************/

int main()
{
	const int dim {8};
	int vec_ent[dim] = {2, 5, 3, 7, 4, 1, 6, 7};

	// ============ Sin usar Criterios
	cout << "Vector enteros original:" << endl;
	mostrar(vec_ent, dim);
	cout << endl;

	cout << "Vector enteros Ascendente:" << endl;
	ordenar_asc(vec_ent, dim);
	mostrar(vec_ent, dim);

	cout << "Vector enteros Descendente:" << endl;
	ordenar_desc(vec_ent, dim);
	mostrar(vec_ent, dim);
	cout << endl << "===Presione enter para continuar:";

	// ============ Usando Criterios
	cin.get();
	cout << "Vector enteros Ascendente:" << endl;
	ordenar(vec_ent, dim, criterio_int_asc);
	mostrar(vec_ent, dim);
	cout << endl;

	cout << "Vector enteros Descendente:" << endl;
	ordenar(vec_ent, dim, criterio_int_des);
	mostrar(vec_ent, dim);
	cout << endl << "===Presione enter para continuar:";
	return 0;
}
