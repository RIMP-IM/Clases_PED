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
	ListaSimple(void);

	void insertarInicioLista(int);
	void mostrarLista(void);
	void llamarMLO(void);
	void llamrMLRD(void);
	void mostrarListaOrden(nodo*);
	void mostrarListaRecD(nodo*);
	void insFinal(int);
	void InsAntes(int, int);
	void BuscarElemento(int);
	void InsDespues(int, int);
};

ListaSimple::ListaSimple(void) {
	pInicio = NULL;
}
//funcion de destructor.
//~ListaSimple(void);

void ListaSimple::insertarInicioLista(int dato) {
	nodo* nuevo;

	nuevo = new nodo;
	nuevo->dato = dato;

	nuevo->sig = pInicio;
	pInicio = nuevo;

}
void ListaSimple::mostrarLista(void) {
	nodo* s = pInicio;

	while (s != NULL)
	{
		cout << s->dato << " ";
		s = s->sig;
	}
	cout << endl;

}

void ListaSimple::llamarMLO(void) {
	mostrarListaOrden(pInicio);
	cout << endl;
}
void ListaSimple::llamrMLRD(void) {
	mostrarListaRecD(pInicio);
	cout << endl;
}

void ListaSimple::mostrarListaOrden(nodo* s) {
	if (s != NULL) {
		mostrarListaOrden((s->sig));
		cout << s->dato << " ";
	}
}
void ListaSimple::mostrarListaRecD(nodo* s) {
	if (s != NULL) {
		cout << s->dato << " ";
		mostrarListaRecD((s->sig));
	}
}

void ListaSimple::insFinal(int dato) {
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

void ListaSimple::InsAntes(int dato, int datoRef) {
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

void ListaSimple::BuscarElemento(int dato) {
	nodo* s = pInicio;

	while (s != NULL && s->dato != dato) {
		s = s->sig;
	}

	if (s != NULL)
		cout << "El dato si esta en la lista." << endl;
	else
		cout << "El dato no esta en la lista." << endl;
}

void ListaSimple::InsDespues(int dato, int datoRef) {
	nodo* q = pInicio, *nuevo,*p;

	nuevo = new nodo;
	nuevo->dato = dato;

	while (q != NULL && q->dato != dato) {
		q = q->sig;
	}
}

void ListaSimple::EliminarNodo(int datoRef){
	nodo *p = pInicio, *q = NULL;
	
	while(p != NULL && p->dato != datoRef){
		q = p;
		p = q;		
	}
	if (p != NULL){
		if (q != NULL){
			q->sig = p->sig;
		}else {
			pInicio = p->sig;
			delete p;
		}
		
	}else {
		cout << "El elemento no existe" << endl;
	}
	
}

int main() {

	ListaSimple miLista;

	char respuesta;
	int dato, dRef, datoBuscar;

	cout << "Desea meter un dato (s/n)? ";
	cin >> respuesta;

	while (respuesta == 's')
	{
		cout << "Digite el dato: ";
		cin >> dato;
		cout << "Antes de cual se va a insertar? " << endl;
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

	cout << "Digite el dato a buscar: ";
	cin >> datoBuscar;
	miLista.BuscarElemento(datoBuscar);

	return 0;
}