#define _CRT_SECURE_NO_WARNINGS
#include "stl.h"


int main() {
	
	Objekt3D* objekt1;
	Objekt3D* objekt2;

	objekt1 = citanjeBinarne("primjerbin.stl");
	objekt2 = citanjeBinarne("primjertxt.stl");

	zapisivanjeBinarne(objekt1, "novabinarna.stl");
	zapisivanjeTekstualne(objekt2, "novatxt.stl");

	obrisiObj3D(objekt1);
	obrisiObj3D(objekt2);

	return 0;
}