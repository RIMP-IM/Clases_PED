#include <iostream>
//00156319 - Rodrigo Ignacio Martínez Pérez

using namespace std;

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