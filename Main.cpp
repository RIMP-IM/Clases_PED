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

	void InsAntes(int dato, int datoRef) {
		nodo* nuevo, * p, * q;

		nuevo = new nodo;
		nuevo->dato = dato;

		p = pInicio;
		q = NULL;
		while (p != NULL && p->dato != datoRef)
		{
			q = p;
			p = p->sig;
		}

		if (q == NULL)
		{
			if (p == NULL) {
				cout << "Insertaste el primero" << endl;
				pInicio = nuevo;
				pInicio->sig = NULL;
			}
			else
			{
				cout << "Dato de referencia esta al principio" << endl;
				pInicio = nuevo;
				pInicio->sig = p;
			}
		}
		else {
			if (p == NULL) {
				cout << "Dato de referencia no encontrado" << endl;
				q->sig = nuevo;
				nuevo->sig = NULL;
			}
			else
			{
				cout << "Dato insertado a la mitad de la lista" << endl;
				q->sig = nuevo;
				nuevo->sig = p;
			}
		}
	}

};

int main() {

	ListaSimple miLista;

	char respuesta;
	int dato,dRef;

	cout << "Desea meter un dato (s/n)? ";
	cin >> respuesta;

	while (respuesta == 's')
	{
		cout << "Digite el dato: ";
		cin >> dato;
		cout << "Antes de cual se va a insertar? "<<endl;
		cin >> dRef;
		miLista.InsAntes(dato, dRef);
		//miLista.insertarInicioLista(dato);
		//miLista.insFinal(dato);

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