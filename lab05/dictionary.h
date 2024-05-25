#ifndef DICTIONARY_HH
#define DICTIONARY_HH

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

typedef struct _Word{
	char *word; // rijec
	int count; // broj pojavljivanja rijeci
	struct _Word *next; 
} Word;

typedef Word* Dictionary;


// kreaira novi prazni rjecnik
Dictionary create();

// dodaje rijec ili uvecava broj pojavljivanja rijeci u rjecniku
// rijeci se dodaju u abecednom redu
void add(Dictionary dict, char *str);

// ispisuje sve rijeci i broj pojavljivanja svake rijeci
void print(Dictionary dict);
// briše cijeli rjeènik
void destroy(Dictionary dict);

Dictionary filterDictionary(Dictionary indict, int (*filter)(Dictionary w));
int filter(Dictionary w);
#endif