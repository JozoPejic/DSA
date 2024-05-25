#include "dictionary.h"

Dictionary create() {
	Dictionary dict = (Dictionary)malloc(sizeof(Word));

	dict->word = NULL;
	dict->next = NULL;
	dict->count = 0;


	return dict;
}

void add(Dictionary dict, char* str) {

	Dictionary novaRijec = (Dictionary)malloc(sizeof(Word));

	Dictionary tmp;

	novaRijec->word = _strdup(str);
	novaRijec->count = 1;
	novaRijec->next = NULL;

	if (dict->next == NULL) {
		novaRijec->next = dict->next;
		dict -> next= novaRijec;
		return;
	}


	tmp = dict;
	while (tmp->next != NULL && strcmp(str, tmp->next->word) > 0) {
		tmp = tmp->next;
	}

	if (tmp->next != NULL && strcmp(str, tmp->next->word) == 0) {
		tmp->next->count++;
		free(novaRijec->word);
		free(novaRijec);
		return;
	}

	novaRijec->next = tmp->next;
	tmp->next = novaRijec;
}

void print(Dictionary dict) {
	printf("Rjecnik:\n");
	while (dict != NULL) {
		printf("Rijec: %s, Broj pojavljivanja: %d\n", dict->word, dict->count);
		dict = dict->next;
	}
}

void destroy(Dictionary dict) {
	while (dict->next != NULL) {
		Dictionary temp = dict;
		dict = dict->next;
		free(temp->word); 
		free(temp); 
	}
}

int filter(Dictionary w) {
	if (w->count >= 3 || w->count <= 5 && strlen(w->word) > 3) {
		return 1;
	}
	else
		return 0;
}

Dictionary filterDictionary(Dictionary indict, int (*filter)(Dictionary w)) {
	Dictionary trenutna = indict;
	Dictionary prethodna = NULL;

	while (trenutna != NULL) {
		if (filter(trenutna)) {
			prethodna = trenutna;
			trenutna = trenutna->next;
		}
		else {
			Dictionary temp = trenutna;
			trenutna = trenutna->next;
			free(temp->word);
			free(temp);
			if (prethodna == NULL) {
				indict = trenutna;
			}
			else {
				prethodna->next = trenutna;
			}
		}
	}
	return indict;
}




