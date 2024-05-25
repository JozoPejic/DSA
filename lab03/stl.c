#include "stl.h"

Objekt3D* citanjeBinarne(const char* filename) {

	FILE* fptr;
	Objekt3D* objekt;

	objekt = (Objekt3D*)malloc(sizeof(Objekt3D));

	objekt->brTrokuta = 0;
	objekt->nizTrokuta = NULL;

	fptr = fopen(filename, "rb");

	if (fptr == NULL)
		return NULL;

	fseek(fptr, 80, SEEK_SET);
	fread(objekt->brTrokuta, sizeof(unsigned int), 1, fptr);

	objekt->nizTrokuta = (Trokut*)malloc((objekt->brTrokuta) * sizeof(Trokut));
	if (objekt->nizTrokuta == NULL) {
		free(objekt);
		fclose(fptr);
		return NULL;
	}

	for (int i = 0; i < objekt->brTrokuta; i++) {
		fread(objekt->nizTrokuta[i].normala, sizeof(float), 3, fptr);

		for (int j = 0; j < 3; j++) {
			fread(objekt->nizTrokuta[i].vrhovi[j], sizeof(float), 3, fptr);
		}

		fread(objekt->nizTrokuta[i].boja, sizeof(unsigned short), 1, fptr);
	}

	fclose(fptr);

	return objekt;
}

Objekt3D* citanjeTekstualne(const char filename) {

	FILE* fptr;
	Objekt3D* objekt;
	char buffer[256];
	char line[256];
	int brojLinija = 0;

	objekt = (Objekt3D*)malloc(sizeof(Objekt3D));

	objekt->brTrokuta = 0;
	objekt->nizTrokuta = NULL;

	fptr = fopen(filename, "r");

	if (fptr == NULL) {
		return NULL;
	}

	if (fgets(buffer, sizeof(buffer), fptr) != NULL) {
		while (fgets(line, sizeof(line), fptr) != NULL) {
			if (strstr(line, "endfacet") != NULL) {
				objekt->brTrokuta++;
			}
		}
	}

	objekt->nizTrokuta = (Trokut*)malloc(objekt->brTrokuta * sizeof(Trokut));

	fseek(fptr, 0, SEEK_SET);

	fgets(buffer, sizeof(buffer), fptr);

	for (int i = 0; i < objekt->brTrokuta; i++) {

		while (fgets(line, sizeof(line), fptr) != NULL) {
			if (strstr(line, "facet normal") != NULL) {
				sscanf(line, "facet normal %f %f %f", &objekt->nizTrokuta[i].normala[0],
													&objekt->nizTrokuta[i].normala[1],
													&objekt->nizTrokuta[i].normala[2]);
			}
			while (strstr(line, "\t\tvertex") != NULL) {
				sscanf(line, "\t\tvertex %f %f %f", objekt->nizTrokuta[i].vrhovi[brojLinija].x,
													objekt->nizTrokuta[i].vrhovi[brojLinija].y,
													objekt->nizTrokuta[i].vrhovi[brojLinija].z);
				brojLinija++;
			}
			if (strstr(line, "endfacet") != NULL) {
				brojLinija = 0;
			}
		}
	}
	fclose(fptr);
	return objekt;
}

void zapisivanjeBinarne(Objekt3D* objekt, char* filename) {

	FILE* fptr;

	fptr = fopen(filename, "wb");

	if (fptr == NULL) {
		return;
	}

	fwrite(objekt->zaglavlje, sizeof(long long), 10, fptr);
	fwrite(objekt->brTrokuta, sizeof(unsigned int), 1, fptr);

	for (int i = 0; i < objekt->brTrokuta; i++) {
		fwrite(objekt->nizTrokuta[i].normala, sizeof(float), 3, fptr);

		for (int j = 0; j < 3; j++) {
			fwrite(objekt->nizTrokuta[i].vrhovi[j], sizeof(float), 3, fptr);
		}

		fread(objekt->nizTrokuta[i].boja, sizeof(unsigned short), 1, fptr);
	}

	fclose(fptr);
}

void zapisivanjeTekstualne(Objekt3D* objekt, char* filename) {

	FILE* fptr;

	fptr = fopen(filename, "w");
	
	if (fptr == NULL) {
		return;
	}

	fprintf(fptr, "solid TekstualniFormat\n");

	for (int i = 0; i < objekt->brTrokuta; i++) {
		fprintf(fptr, "facet normal %f %f %f", objekt->nizTrokuta[i].normala);
		fprintf(fptr, "\touter loop");
		for (int j = 0; j < 3; j++) {
			fprintf(fptr, "\t\tvertex %f %f %f", objekt->nizTrokuta->vrhovi[j]);
		}
		fprintf(fptr, "\tendloop");
		fprintf(fptr, "endfacet");
	}

	fclose(fptr);
}

void obrisiObj3D(Objekt3D* objekt) {
	free(objekt->nizTrokuta);
	free(objekt);
}