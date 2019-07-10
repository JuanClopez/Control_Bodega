// Prototipo de Presentacion de Menus

// Se insertan las librerias necesarias
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<Math.h>
#include<string>
using namespace std;

/* Segmento de declaracion de estructuras y variables */
struct Articulo
{
	int Cod_Articulo;
	string Descripcion_Articulo;
	int Cantidad_Stock_Articulo;
	int Stock_minimo_Articulo;
	int Valor_Articulo;
	int Articulos_Dev;
	Articulo *sig;

};

struct Lista_Pendientes_Despachar
{
	int Cod_Articulo_Pend;
	int Cantidad_Pendiente;
	Lista_Pendientes_Despachar *sig;


};

struct Lista_Aux_Pedido
{
	int Cod_Articulo_Aux;
	string Descripcion_Articulo_Aux;
	int Cantidad_Pendido;
	Lista_Aux_Pedido *sig;


};

struct Ingreso_Inventario
{
	int Cod_Articulo_I;
	int Cantidad_Ingreso;
	Ingreso_Inventario *sig;


};




//Protocolos 
void Iniciar_Lista_Maestra(Articulo **CabArticulo);
void Eliminar_Articulo(Articulo **CabArticulo, int X);
void Adicionar_Articulo_Nuevo(Articulo **CabArticulo);

void Imprimir_Lista_Articulos_Parcial(Articulo *CabArticulo);
void Imprimir_Lista_Articulos_Completa(Articulo *CabArticulo);
void Devolucion_Articulo(Articulo **CabArticulo, int Cod_Dev, int Cant_Dev);
void Articulo_Mas_Devoluciones(Articulo *CabArticulo);
void Reporte_Proveedores_Ordenado(Articulo *CabArticulo);
void Traslado_Tienda(Articulo *CabArticulo, Lista_Pendientes_Despachar **CabDespa);
void Pendientes_Despachar(Articulo *CabArticulo, Lista_Pendientes_Despachar **CabDespa);
void Imprimir_Lista_pendientes(Lista_Pendientes_Despachar *CabDespa);


// Variables Globales
int sw_listaMaestra = 1;



// Programa principal
void main()
{
	// Area de declaracion de variables locales
	int opcion = 0, Cod_Dev, Cant_Dev, X;
	Articulo *CabArticulo = NULL;
	Lista_Pendientes_Despachar *CabDespa = NULL;
	system("color   60 ");

	while (opcion != 11)
	{
		system("cls");
		cout << "\n			       ---------------------------------- ";
		cout << "\n			  	MENU PRINCIPAL EMPRESA XYZ S.A. ";
		cout << "\n			       ---------------------------------- ";
		cout << "\n\n\n";
		cout << "			1. Ingresar lista Maestra\n";
		cout << "			2. Actualizar stock de lista maestra\n";
		cout << "			3. Adicionar nuevo articulo\n";
		cout << "			4. Eliminar articulo\n";
		cout << "			5. Solicitar salida de articulo hacia tienda\n";
		cout << "			6. Ingresar devoluciones de articulos\n";
		cout << "			7. Reporte ordenado por codigo de Articulo para pedido Proveedores\n";
		cout << "			8. Reporte de articulo con mayores devoluciones\n";
		cout << "			9. Imprimir lista maestra de articulos\n";
		cout << "			10. Imprimir lista de notas pendientes\n";
		cout << "			11. Salir\n\n";
		cout << "\n			Digite la opcion que desee: ";
		cin >> opcion;

		switch (opcion)
		{

		case 1:  //Opcion 1 ok
			system("cls");
			if (sw_listaMaestra == 1) // utilizo el switch para asegurarme que la lista maestra solo se crea una vez
			{
				
				Iniciar_Lista_Maestra(&CabArticulo);
				cout << endl;
			}
			else
			{
				
				cout << "\n La lista maestra ya fue creada por favor utilice la opcion 6 adicionar nuevo articulo \n";
				cout << endl;
			}
			system("pause");
			break;

		case 2: // Opcion 2
			system("cls");
			if (sw_listaMaestra == 1) // utilizo el switch para asegurarme que la lista maestra solo se crea una vez
			{
				
			}
			else
			{
				
				cout << "\n Por favor Primero Utilice la Opcion 1 / Crear Lista Maestra  \n";
				cout << endl;
			}

			system("pause");
			break;

		case 3:  //Opcion 3
			system("cls");
			if (sw_listaMaestra == 1) // utilizo el switch para asegurarme que la lista maestra solo se crea una vez
			{

			}
			else
			{

				cout << "\n Por favor Primero Utilice la Opcion 1 / Crear Lista Maestra  \n";
				cout << endl;
			}

			system("pause");
			break;
		case 4:	 // Opcion 4
			system("cls");
			if (sw_listaMaestra == 1) // utilizo el switch para asegurarme que la lista maestra solo se crea una vez
			{
				cout << "                              -------------------------- \n";
				cout << "                              Articulos en el Inventario \n";
				cout << "                              -------------------------- \n";
				cout << endl;
				Imprimir_Lista_Articulos_Parcial(CabArticulo);
				cout << endl;
			
				cout << "Digite el Codigo del Articulo que desea Eliminar: \n";
				cin >> X;				
				cout << endl;
				Eliminar_Articulo(&CabArticulo,X);
				cout << endl;
			}
			else
			{
				system("cls");
				cout << "\n Por favor Primero Utilice la Opcion 1 / Crear Lista Maestra \n";
				cout << endl;
			}

			
			system("pause");
			break;

		case 5: // Opcion 5 ok
			system("cls");
			if (sw_listaMaestra == 0) // valido que solo si ya se creo una lista maestra se puedan realizar movimientos
			{

				Traslado_Tienda(CabArticulo, &CabDespa);
				cout << endl;
			}
			else
			{
				cout << "\n Primero debe generar la lista maestra y realizar algun movimiento de articulos  \n";
				cout << endl;
			}


			system("pause");
			break;

		case 6: // Opcion 6 ok
			system("cls");
			if (sw_listaMaestra == 0) // valido que solo si ya se creo una lista maestra se puedan realizar movimientos
			{
				if (CabArticulo != NULL)
				{
					cout << "                              -------------------------- \n";
					cout << "                              Articulos en el Inventario \n";
					cout << "                              -------------------------- \n";
					cout << endl;
					Imprimir_Lista_Articulos_Parcial(CabArticulo);
					cout << endl;
				}
				cout << "Digite el Codigo del Articulo que desea devolver a bodega: \n";
				cin >> Cod_Dev;
				cout << "Digite la cantidad que desea devolver a bodega: \n";
				cin >> Cant_Dev;
				cout << endl;
				Devolucion_Articulo(&CabArticulo, Cod_Dev, Cant_Dev);
				cout << endl;
			}
			else
			{
				cout << "\n Primero debe generar la lista maestra y realizar algun movimiento de articulos  \n";
				cout << endl;
			}


			system("pause");
			break;

		case 7: // Opcion 7 
			system("cls");
			if (sw_listaMaestra == 0) // valido que solo si ya se creo una lista maestra se puedan realizar movimientos
			{

				Reporte_Proveedores_Ordenado(CabArticulo);
				cout << endl;
			}
			else
			{
				cout << "\n Primero debe generar la lista maestra y realizar algun movimiento de articulos  \n";
				cout << endl;
			}


			system("pause");
			break;


		case 8: // Opcion 8 ok
			system("cls");
			if (sw_listaMaestra == 0) // valido que solo si ya se creo una lista maestra se puedan realizar movimientos
			{

				Articulo_Mas_Devoluciones(CabArticulo);
				cout << endl;
			}
			else
			{
				cout << "\n Primero debe generar la lista maestra y realizar algun movimiento de articulos  \n";
				cout << endl;
			}


			system("pause");
			break;

		case 9: // Opcion 9 
			system("cls");
			if (sw_listaMaestra == 0) // valido que solo si ya se creo una lista maestra se puedan realizar movimientos
			{

				Imprimir_Lista_Articulos_Completa(CabArticulo);
				cout << endl;
			}
			else
			{
				cout << "\n Primero debe generar la lista maestra y realizar algun movimiento de articulos  \n";
				cout << endl;
			}


			system("pause");
			break;

		case 10: // Opcion 10 
			system("cls");
			if (sw_listaMaestra == 0) // valido que solo si ya se creo una lista maestra se puedan realizar movimientos
			{

				Imprimir_Lista_pendientes(CabDespa);
				cout << endl;
			}
			else
			{
				cout << "\n Primero debe generar la lista maestra y realizar algun movimiento de articulos  \n";
				cout << endl;
			}


			system("pause");
			break;

		case 11:
			system("cls");
			printf("\n !!! Adios !!!\n");
			break;

		default:  // Opcion invalida
			printf("\n                        ==============================");
			printf("\n                        ! **** Opcion Invalida ***** !");
			printf("\n                        ==============================\n");
			system("pause");

		}  // fin del case
	}	// fin del while
	system("pause");

}  // fin del main

// SUBPROGRAMAS

void Iniciar_Lista_Maestra(Articulo **CabArticulo)
{
	//Declaracion de Variables
	Articulo *Nuevo, *P, *Q = *CabArticulo;
	int Opcion = 1, Lectura;
	bool Sw1, Sw2;

	while (Opcion == 1) // while el ingreso de los articulos
	{
		Nuevo = new Articulo;
		cout << endl;
		cout << "Digite el codigo: ";
		cin >> Lectura;
		Sw1 = true;

		while (Sw1 == true) // mientras el usuario digite 1 para seguir ingresando articulos el while continua
		{
			P = *CabArticulo;
			Sw2 = false;

			while (P != NULL && Sw2 == false)
			{
				if (Lectura == P->Cod_Articulo) // valido si el codigo ingresado es igual a un codigo de la lista
				{
					Sw2 = true; // si es igual activo el sw
				}
				else
				{
					P = P->sig; // si no es igual avanzo la lista
				}

			}//Fin while
			if (Sw2 == true) // valido si el Sw2 se activo 
			{
				cout << "El articulo ya existe ingrese de nuevo o salga y utilice la opcion 6 del menu principal" << endl;
				cout << "Digite el codigo: ";
				cin >> Lectura;
			}
			else
			{
				Sw1 = false; // si no apago el Sw1 para que el proceso continúe con el ingreso de datos del articulo
			}// fin if


		}//fin while

		Nuevo->Cod_Articulo = Lectura;
		cout << "Digite la descripcion del articulo: ";
		cin.ignore();
		getline(cin, Nuevo->Descripcion_Articulo); // este getline evita que tenga errores al usar espacios en la descripcion
		cout << "Digite la cantidad de stock inicial del articulo: ";
		cin >> Nuevo->Cantidad_Stock_Articulo;
		cout << "Digite la cantidad minima en stock del articulo: ";
		cin >> Nuevo->Stock_minimo_Articulo;
		cout << "Digite el valor del articulo: ";
		cin >> Nuevo->Valor_Articulo;
		Nuevo->Articulos_Dev = 0; // inicializo la cantidad de unidades defectuosas devueltas en 0
		Nuevo->sig = NULL; //aterrizo el nodo
		if (*CabArticulo == NULL) // si esta vacia la lista la inaguro
		{
			*CabArticulo = Nuevo;
			Q = *CabArticulo;
		}
		else
		{
			while (Q->sig != NULL)
			{
				Q = Q->sig;
			}
			Q->sig = Nuevo;
			Q = Nuevo;
		}
		cout << "\n  El articulo se creo con exitosamente";
		cout << "\n  ¿Desea agregar un nuevo articulo? Digite 1. para SI - 2. para NO : ";
		cin >> Opcion;
		while (Opcion < 1 || Opcion>2)  // valido que la opcion digitada sea 1 o 2 y si no lo es vuelve a preguntar 
		{
			cout << "\n  Opción invalida ";
			cout << "\n  ¿Desea agregar un nuevo articulo? Digite 1. para SI - 2. para NO : ";
			cin >> Opcion;
		} // fin While
		cout << endl;
	}// Fin while
	sw_listaMaestra = 0; // activo el sw global para que en el menu principal ya no se pueda iniciar la lista maestra


}// Fin Iniciar_Lista_Maestra

void Eliminar_Articulo(Articulo **CabArticulo, int X)
{
	//Declaracion de Variables
	Articulo *P,*Q;
	bool sw = true;
	if (CabArticulo == NULL)
	{
		cout << "No existe el articulo";
	}
	else
	{
		P = *CabArticulo;
		Q = *CabArticulo;
		while (sw == true && Q != NULL)
		{
			if (Q->Cod_Articulo != X)
			{
				P = Q;
				Q = P->sig;
			}
			else
			{
				sw = false;
				if (P == Q)
				{
					*CabArticulo = (*CabArticulo)->sig;
					Q->sig = NULL;
					delete(Q);
					P = *CabArticulo;
					Q = *CabArticulo;
				}
				else
				{
					P->sig = Q->sig;
					Q->sig = NULL;
					delete(Q);
					Q = P->sig;
				}
			}

		}
		if (sw == true)
		{
			cout << "	No se encuentra el Articulo  " << endl;
		}
		else
		{
			cout << "	El Articulo fue eliminado exitosamente" << endl;
		}
	}


}

void Imprimir_Lista_Articulos_Parcial(Articulo *CabArticulo)
{
	//Declaracion de Variables
	Articulo *P;
	if (CabArticulo != NULL)
	{
		P = CabArticulo;
		while (P != NULL)
		{
			cout << "Codigo Articulo: " << P->Cod_Articulo;
			cout << " ! Descripcion Articulo: " << P->Descripcion_Articulo << endl;
			P = P->sig;
		}

	}

}//Fin Imprimir_Lista_Articulos_Parcial

void Imprimir_Lista_Articulos_Completa(Articulo *CabArticulo)
{
	//Declaracion de Variables
	Articulo *P;
	if (CabArticulo != NULL)
	{
		P = CabArticulo;
		while (P != NULL)
		{
			cout << "Codigo Articulo: " << P->Cod_Articulo;
			cout << " ! Descripcion Articulo: " << P->Descripcion_Articulo;
			cout << " ! Cantidad Stock Articulo: " << P->Cantidad_Stock_Articulo;
			cout << " ! Stock Minimo Articulo: " << P->Stock_minimo_Articulo;
			cout << " ! Valor Articulo: " << P->Valor_Articulo;
			cout << " ! Articulos Dev: " << P->Articulos_Dev << endl;

			P = P->sig;
		}

	}

}//Fin Imprimir_Lista_Articulos_Completa

void Imprimir_Lista_pendientes(Lista_Pendientes_Despachar *CabDespa)
{
	//Declaracion de Variables
	Lista_Pendientes_Despachar *P;
	if (CabDespa != NULL)
	{
		P = CabDespa;
		while (P != NULL)
		{
			cout << "Codigo Articulo: " << P->Cod_Articulo_Pend;
			cout << " ! Cantidad Pendiente: " << P->Cantidad_Pendiente<< endl;


			P = P->sig;
		}

	}

}//Imprimir_Lista_pendientes


void Reporte_Proveedores_Ordenado(Articulo *CabArticulo)
{
	//Declaracion de Variables
	Articulo *P;       // *Nuevo, *Temp_Lista = NULL, *Q = NULL, *J = NULL;
	Lista_Aux_Pedido *Nuevo, *Aux1, *Aux2, *CabTemp = NULL, *Q = NULL, *J = NULL;

	P = CabArticulo;


	if (CabArticulo == NULL)
	{
		cout << "No existe informacion en la lista maestra";
	}
	else
	{
		while (P != NULL)
		{
			Q = CabTemp;
			if ((P->Cantidad_Stock_Articulo) < (P->Stock_minimo_Articulo))
			{

				Nuevo = new Lista_Aux_Pedido;
				Nuevo->Cod_Articulo_Aux = P->Cod_Articulo;
				Nuevo->Descripcion_Articulo_Aux = P->Descripcion_Articulo;
				Nuevo->Cantidad_Pendido = (P->Stock_minimo_Articulo - P->Cantidad_Stock_Articulo);
				Nuevo->sig = NULL;
				if (CabTemp == NULL) // si esta vacia la lista la inaguro
				{
					CabTemp = Nuevo;
					Q = CabTemp;
				}
				else
				{
					while (Q->sig != NULL)
					{
						Q = Q->sig;
					}
					Q->sig = Nuevo;

				}

			}
			P = P->sig; // avanzo el puntero

		}

		//ordeno la lista
		Aux1 = CabTemp;
		Q = CabTemp;
		while (Q->sig != NULL)
		{
			Aux2 = Q;
			J = Q->sig;
			while (J != NULL)
			{
				if ((Q->Cod_Articulo_Aux) > (J->Cod_Articulo_Aux))
				{
					if (Q == CabTemp)
					{
						if (Q->sig != J)
						{
							Aux2->sig = J->sig;
							J->sig = Q->sig;
							CabTemp = J;
							Q->sig = Aux2->sig;
							Aux2->sig = Q;
							Q = J;
							J = Aux2->sig;
						}
						else
						{
							CabTemp = J;
							Q->sig = J->sig;
							J->sig = Q;
							Q = J;
							J = Q->sig;
						}
					}
					else
					{
						if (Q->sig != J)
						{
							Aux2->sig = J->sig;
							J->sig = Q->sig;
							Aux1->sig = J;
							Q->sig = Aux2->sig;
							Aux2->sig = Q;
							Q = J;
							J = Aux2->sig;
						}
						else
						{
							Q->sig = J->sig;
							Aux1->sig = J;
							J->sig = Q;
							Q = J;
							J = Q->sig;
							Aux2 = Q;
						}
					}
				}
				Aux2 = J;
				J = Aux2->sig;
			}
			Aux1 = Q;
			Q = Aux1->sig;
		}

		Q = CabTemp;
		while (Q != NULL)
		{
			cout << "	Codigo Articulo: " << Q->Cod_Articulo_Aux << "	";
			cout << " ! Descripcion Articulo: " << Q->Descripcion_Articulo_Aux << "	";
			cout << "	Cantidad a Pedir : " << Q->Cantidad_Pendido << "	" << endl;

			Q = Q->sig;
		}
		cout << endl;

	}

}

void Traslado_Tienda(Articulo *CabArticulo, Lista_Pendientes_Despachar **CabDespa)
{
	//Declaracion de Variables
	Lista_Pendientes_Despachar *Nuevo, *Q = *CabDespa;
	Articulo *P;
	int Opcion = 1, Sobrante, Codigo, CantD;
	bool sw = false;

	while (Opcion != 2) // Controla que si el usuario digita la opcion 2 que es salir el traslado termina
	{
		system("cls");
		cout << "                              -------------------------- \n";
		cout << "                              Articulos en el Inventario \n";
		cout << "                              -------------------------- \n";
		cout << endl;
		Imprimir_Lista_Articulos_Completa(CabArticulo);
		cout << endl;
		cout << "Digite el Codigo del Articulo que desea Trasladar a Tienda: \n";
		cin >> Codigo;
		cout << "Digite la cantidad que desea Trasladar a Tienda: \n";
		cin >> CantD;
		cout << endl;
		P = CabArticulo;
		sw = false;
		while (P != NULL && sw == false)
		{

			if (Codigo == P->Cod_Articulo)
			{
				sw = true;

			}
			else
			{
				P = P->sig;
			}
		}
		if (sw == false)
		{
			cout << "El codigo Ingresado no se encontro en la lista \n";
		}
		else
		{
			if (CantD > P->Cantidad_Stock_Articulo)
			{
				Sobrante = CantD - (P->Cantidad_Stock_Articulo);
				P->Cantidad_Stock_Articulo -= (CantD - Sobrante); // pone en 0 el Stock  
				Nuevo = new Lista_Pendientes_Despachar;    // Me guarda en una lista los despachos pendientes
				Nuevo->Cod_Articulo_Pend = P->Cod_Articulo;

				Nuevo->Cantidad_Pendiente = Sobrante;
				Nuevo->sig = NULL;
				if (*CabDespa == NULL) // si esta vacia la lista la inaguro
				{
					*CabDespa = Nuevo;
					Q = *CabDespa;
				}
				else
				{
					while (Q->sig != NULL)
					{
						Q = Q->sig;
					}
					Q->sig = Nuevo;
					Q = Nuevo;
				}
				cout << "\n La cantidad del Articulo era mayor al Stock y fue Registrado el faltante de " << Sobrante << " con exito \n";

			}
			else
			{
				P->Cantidad_Stock_Articulo -= CantD;
				cout << "\n	El traslado se realizo con exito\n";
				if (P->Cantidad_Stock_Articulo < P->Stock_minimo_Articulo);
				{
					cout << "\n El Stock del articulo quedo por debajo del Stock minimo \n ";
				}


			}

		}
		cout << "\n  ¿Desea trasladar un nuevo articulo? Digite 1. para SI - 2. para NO : ";
		cin >> Opcion;
		while (Opcion < 1 || Opcion>2)  // valido que la opcion digitada sea 1 o 2 y si no lo es vuelve a preguntar 
		{
			cout << "\n  Opcion invalida ";
			cout << "\n  ¿Desea trasladar un nuevo articulo? Digite 1. para SI - 2. para NO : ";
			cin >> Opcion;
		} // fin While


	}// fin While

}//fin  Traslado_Tienda

void Devolucion_Articulo(Articulo **CabArticulo, int Cod_Dev, int CantDev)
{
	Articulo *P;
	bool sw = false;
	P = *CabArticulo;
	while (P != NULL && sw == false)
	{

		if (Cod_Dev == P->Cod_Articulo)
		{
			P->Articulos_Dev += CantDev; // si el codigo coincide con uno de la lista le suma a los articulos devueltos
			sw = true;

		}
		else
		{
			P = P->sig; // avanzo el puntero
		}

	}
	if (sw == true)
	{
		cout << "	La devolucion del articulo codigo: " << Cod_Dev << " se realizo correctamente" << endl << endl;

	}
	else
	{
		cout << "	El articulo cogdigo: " << Cod_Dev << " No existe en el Inventario" << endl << endl;
	}


}

void Articulo_Mas_Devoluciones(Articulo *CabArticulo)
{
	Articulo *P, *Nuevo, *Temp_Max = NULL, *Q = NULL;
	int Dev_Mayor = 0;
	P = CabArticulo;

	while (P != NULL)
	{
		if ((P->Articulos_Dev) > Dev_Mayor)
		{
			Dev_Mayor = P->Articulos_Dev; // guardo el valor mayor
			Nuevo = new Articulo;
			Nuevo->Cod_Articulo = CabArticulo->Cod_Articulo;
			Nuevo->Descripcion_Articulo = CabArticulo->Descripcion_Articulo;
			Nuevo->Cantidad_Stock_Articulo = CabArticulo->Cantidad_Stock_Articulo;
			Nuevo->Stock_minimo_Articulo = CabArticulo->Stock_minimo_Articulo;
			Nuevo->Valor_Articulo = CabArticulo->Valor_Articulo;
			Nuevo->Articulos_Dev = CabArticulo->Articulos_Dev;
			Nuevo->sig = NULL;

			Temp_Max = Nuevo; // asigno a la lista auxiliar el nodo Nuevo


		}
		P = P->sig; // avanzo el puntero

	}
	cout << "                              ----------------------------- \n";
	cout << "                              Articulo con Mayor Devolucion \n";
	cout << "                              ----------------------------- \n";
	cout << endl;
	cout << "\n	Codigo Articulo:	" << Temp_Max->Cod_Articulo;
	cout << "	Descripcion:	" << Temp_Max->Descripcion_Articulo << "\n\n";

}