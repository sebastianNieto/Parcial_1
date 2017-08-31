/*
* Parcial #1 Estructura de datos2
* fecha: 30-08-2017
* Presentado por: Richard Ramirez
* presentado por: Sebastian Nieto
*/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

struct Productos
{
	int cantidad;
	float precio;
	float importe;
};


struct Proveedores
{
	char nombre[30];
	char telefono[10];
	char direccion[30];
	struct Productos productos[100]; //Declaramos vector de productos en este punto
} provedores[100], *pProvedores = provedores;

void datos_proveedor(int *);
void datos_producto(int *);
void imprimir_datos(int *);
void mayor(int *);
void menor(int *);
void imprimir_productos(int *);
void fibonacci();

int main () {
	
	int cantidad, opcion;
	int* pCantidad;
	
	pCantidad = &cantidad;
	
	do
	{
		printf("1 Estructura \n");
		printf("2 Fiboo \n");
		printf("Ingrese opcion: ");
		scanf("%d", &opcion);
		
		switch(opcion)
		{
		case 1:
			datos_proveedor(pCantidad);
			imprimir_datos(pCantidad);
			mayor(pCantidad);
			menor(pCantidad);
			imprimir_productos(pCantidad);
			break;
		case 2:
			fibonacci();
			break;
		default:
			opcion = 0;
			break;
		}
		system("pause");
		system("cls");
	} while(opcion!=0);
	
	return 0;
}

void datos_proveedor(int *pCantidad)
{
	
	
	printf("Ingrese la cantidad de proveedores: ");
	scanf("%d", pCantidad);
	system("cls");
	
	for(int i = 0; i < *pCantidad; i++){
		printf("Ingrese los datos del %d proveedor \n \n", i+1);
		printf("Ingrese el nombre: ");
		fflush(stdin);
		fgets((pProvedores+i)->nombre, 30, stdin);
		printf("Ingrese el numero de telefono: ");
		fflush(stdin);
		fgets((pProvedores+i)->telefono, 10, stdin);
		printf("Ingrese la direccion: ");
		fflush(stdin);
		fgets((pProvedores+i)->direccion, 30, stdin);
		printf("Ingrese la cantidad vendida: ");
		scanf("%d", &(pProvedores+i)->productos[i].cantidad);
		printf("Ingrese el precio unitario: ");
		scanf("%f", &(pProvedores+i)->productos[i].precio);
		(pProvedores+i)->productos[i].importe = (pProvedores+i)->productos[i].cantidad * (pProvedores+i)->productos[i].precio;
		system("cls");
	}
}


void imprimir_datos(int *pCantidad)
{
	for(int i = 0; i < *pCantidad; i++){
		printf("Datos del %d proveedor \n \n", i+1);
		printf("Nombre: %s \n", (pProvedores+i)->nombre);
		printf("Telefono: %s \n", (pProvedores+i)->telefono);
		printf("Nombre: %s \n", (pProvedores+i)->direccion);
		printf("Importe total: %.2f \n \n", (pProvedores+i)->productos[i].importe);
	}
}

void mayor(int *pCantidad)
{
	int mayor = 0, indice = 0;
	int* pMayor, * pIndice;
	pMayor = &mayor, pIndice = &indice;
	for(int i = 0; i < *pCantidad; i++){
		if((pProvedores+i)->productos[i].precio > *pMayor){
			*pMayor = (pProvedores+i)->productos[i].precio;
			*pIndice = i;
		}
	}
	
	printf(" \n El provedor mas caro es: %s", (pProvedores+(*pIndice))->nombre);
}

void menor(int *pCantidad)
{
	int menor = 0, indice = 0;
	int* pMenor, * pIndice;
	pMenor = &menor, pIndice = &indice;
	for(int i = 0; i < *pCantidad; i++){
		if((pProvedores+i)->productos[i].precio < *pMenor || *pMenor == 0){
			*pMenor = (pProvedores+i)->productos[i].precio;
			*pIndice = i;
		}
	}
	
	printf("\n El provedor mas barato es: %s", (pProvedores+(*pIndice))->nombre);
}

void imprimir_productos(int *pCantidad)
{
	float totalImporte = 0;
	float* pTotalImporte;
	
	pTotalImporte = &totalImporte;
	
	for(int i = 0; i < *pCantidad; i++){
		printf("\n Producto %d: \n \n", i+1);
		printf("Cantidad: %d \t ", (pProvedores+i)->productos[i].cantidad);
		printf("Precio: %f \t ", (pProvedores+i)->productos[i].precio);
		printf("Importe: %f \n ", (pProvedores+i)->productos[i].importe);
		
		*pTotalImporte = *pTotalImporte + (pProvedores+i)->productos[i].importe;
	}
	
	printf("\n Total importe: %f ", *pTotalImporte);
}

void fibonacci()
{
	int matriz[50][50], z = 0, numero = 0, primero = 0, actual = 1;
	int *pMatriz = &matriz[0][0], *pNumero = &numero, *pPrimero = &primero, *pActual = &actual;
	int filas, columnas;
	int* pFilas, *pColumnas;
	
	
	pFilas = &filas; pColumnas = &columnas;
	
	printf("Ingrese la cantidad de filas: ");
	scanf("%d", pFilas);
	
	printf("Ingrese la cantidad de Columnas: ");
	scanf("%d", pColumnas);
	
	for(int i = 0; i < *pFilas; i++){
		for(int j = 0; j < *pColumnas; j++){
			*pNumero = *pPrimero + *pActual;
			*pPrimero = *pActual;
			*pActual = *pNumero;
			*(pMatriz+z) = *pActual;
			z++;
		}
	}
	
	z=0;
	for(int i = 0; i < *pFilas; i++){
		for(int j = 0; j < *pColumnas; j++){
			printf("%d ",*(pMatriz+z));
			z++;
		}
		
		printf("\n");
	}
}




