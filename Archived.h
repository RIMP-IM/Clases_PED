#pragma once
//void ullman(int);
//void llenarArreglo(int*, int);
//void mostrarArreglo(int*, int);
//void invertirArreglo(int*, int*);

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