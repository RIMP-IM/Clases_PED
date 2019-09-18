#include <iostream>
//00156319 - Rodrigo Ignacio Martínez Pérez

using namespace std;

//void ullman(int);
//void llenarArreglo(int*, int);
//void mostrarArreglo(int*, int);
//void invertirArreglo(int*, int*);

//Lista Simple
struct nodo
{
	int dato;
	nodo* sig;
};

class ListaSimple
{
private:
	nodo* pInicio;
public:
	//funcion de constructor, se ejecuta automaticamente.
	ListaSimple(void) {
		//cout << "miLista ha sido inicializado." << endl;
		pInicio = NULL;
	}
	//funcion de destructor.
	~ListaSimple(void) {}

	void insertarInicioLista(int dato) {
		nodo* nuevo;

		nuevo = new nodo;
		nuevo->dato = dato;

		nuevo->sig = pInicio;
		pInicio = nuevo;

	}
	void mostrarLista() {
		nodo* s = pInicio;

		while (s != NULL)
		{
			cout << s->dato << " ";
			s = s->sig;
		}
		cout << endl;

	}

	void llamarMLO() {
		mostrarListaOrden(pInicio);
		cout << endl;
	}
	void llamrMLRD() {
		mostrarListaRecD(pInicio);
		cout << endl;
	}

	void mostrarListaOrden(nodo* s) {
		if (s != NULL) {
			mostrarListaOrden((s->sig));
			cout << s->dato << " ";
		}
	}
	void mostrarListaRecD(nodo* s) {
		if (s != NULL) {
			cout << s->dato << " ";
			mostrarListaRecD((s->sig));
		}
	}

	void insFinal(int dato) {
		nodo* p, * q;

		nodo* nuevo = new nodo;
		nuevo->dato = dato;
		nuevo->sig = NULL;
		if (pInicio == NULL)
			pInicio = nuevo;
		else {
			p = pInicio;
			q = NULL;

			while (p != NULL)
			{
				q = p;
				p = p->sig;
			}			
			q->sig = nuevo;
		}
	}

};

int main() {
	//Ullman y arreglos
	/**int n;
	cout << "Ingrese el numero a descomponer: ";
	cin >> n;
	ullman(n);


	int n, a[50];
	cout << "Cuantos elementos? ";
	cin >> n;
	llenarArreglo(a, n - 1);
	cout << endl;
	mostrarArreglo(a, n - 1);
	cout << endl;
	invertirArreglo(a, &a[n - 1]);
	cout << endl;
	mostrarArreglo(a, n - 1);
	**/

	ListaSimple miLista;

	char respuesta;
	int dato;

	cout << "Desea meter un dato (s/n)? ";
	cin >> respuesta;

	while (respuesta == 's')
	{
		cout << "Digite el dato: ";
		cin >> dato;
		//miLista.insertarInicioLista(dato);
		miLista.insFinal(dato);

		cout << "Desea ingresar un dato (s/n)? ";
		cin >> respuesta;
	}

	cout << "Mostrar lista iterativo (Sentido directo).\nLos elementos de la lista son:\n";
	miLista.mostrarLista();
	cout << "Mostrar lista recursivo (Sentido directo).\nLos elementos de la lista son:\n";
	miLista.llamarMLO();
	cout << "Mostrar lista recursivo (Sentido inverso).\nLos elementos de la lista son:\n";
	miLista.llamrMLRD();

	return 0;
}

//void llenarArreglo(int* p, int n) {
//	if (n >= 0) {
//		cin >> *p;
//		llenarArreglo(p + 1, n - 1);
//	}
//}
//void mostrarArreglo(int* p, int n) {
//	if (n >= 0) {
//		cout << *p << " ";
//		mostrarArreglo(p + 1, n - 1);
//	}
//}
//void invertirArreglo(int* p, int* q) {
//	int temp;
//	if (p < q) {
//		temp = *p;
//		*p = *q;
//		*q = temp;
//		invertirArreglo(p + 1, q - 1);
//	}
//}
//void ullman(int Numero) {
//	cout << Numero << " ";
//	if (Numero % 2 == 0)
//	{
//		ullman(Numero / 2);
//	}
//	else if (Numero == 1) {
//		return;
//	}
//	else {
//		ullman((Numero * 3) + 1);
//	}
//}