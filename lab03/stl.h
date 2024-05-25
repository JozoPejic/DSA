#ifndef STL_HH
#define STL_HH

#define size 10

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {

	VrhoviTrokuta vrhovi[3];
	float normala[3];
	unsigned short boja;

}Trokut;

typedef struct {

	Trokut* nizTrokuta;
	unsigned int brTrokuta;
	long long zaglavlje[size];

}Objekt3D;

typedef struct {

	float x, y, z;

}VrhoviTrokuta;

Objekt3D* citanjeBinarne(const char filename);

Objekt3D* citanjeTekstualne(const char filenames);

void zapisivanjeBinarne(Objekt3D* objekt, char* filename);

void zapisivanjeTekstualne(Objekt3D* objekt, char* filename);

void obrisiObj3D(Objekt3D* objekt);

#endif
