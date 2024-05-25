#include "hash.h"
#include <malloc.h>
#include <stdio.h>
#include <string.h>

#define HCONST 3567892

HashTable* NewTable(int size)
{
	// kreira novu hash tablicu (alocira samu strukturu i niz pokaziva�a)
	HashTable* table = (HashTable*)malloc(sizeof(HashTable));

	if (table != NULL) {
		table->size = size;
		table->load = 0;
		table->table = (Bin**)calloc(size, sizeof(Bin*));

		if (table->table == NULL) {
			free(table);
			return NULL;
		}
	}
	
	return table;
}

unsigned int hash(char* word)
{
	// od kljuca generira hash kod
	unsigned int key = 0;
	while (*word != '\0')
	{
		key = key * HCONST + *word;
		word++;
	}
	return key;
}

void Insert(HashTable* ht, char* word)
{
	// dodaje novu rijec u listu na odgovarajucem pretincu
	if (ht == NULL || word == NULL) {
		return;
	}

	int index = hash(word) % ht->size;

	Bin* noviNode = (Bin*)malloc(sizeof(Bin));
	if (noviNode == NULL) {
		return;
	}
	noviNode->word = strdup(word);
	noviNode->next = NULL;

	if (ht->table[index] == NULL) {
		ht->table[index] = noviNode;
	}
	else {
		noviNode->next = ht->table[index];
		ht->table[index] = noviNode;
	}
	ht->load++;
}

int Get(HashTable* ht, char* word)
{
	// vraca 0 ili 1 ovisno o tome da li rijec postoji u tablici
	if (ht == NULL || word == NULL) {
		return 0;
	}

	unsigned int index = hash(word) % ht->size;

	Bin* currentNode = ht->table[index];

	while (currentNode != NULL) {
		if (strcmp(currentNode->word, word) == 0) {
			return 1;
		}
		currentNode = currentNode->next;
	}
	return 0;
}

void DeleteTable(HashTable* ht)
{
	// brise cijelu hash tablicu (liste na svim pretincima (rijec i element liste), pretince ...)
	if (ht == NULL) {
		return;
	}

	for (int i = 0; i < ht->size; i++) {
		Bin* currentNode = ht->table[i];

		while (currentNode != NULL) {
			Bin* temp = currentNode;
			currentNode = currentNode->next;
			free(temp->word);
			free(temp);
		}
	}

	free(ht->table);

	free(ht);
}