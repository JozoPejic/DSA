#include<stdio.h>

#define MAX 10000


 struct clan{

	void* podatci;
	int prioritet;

};

struct prioritetniRed{

	struct clan hrpa[MAX];
	int velicina;

};

void popraviPremaVrhu(struct prioritetniRed* pr, int index);
void popraviPremaDnu(struct prioritetniRed* pr, int index);



void dodajClan(struct prioritetniRed* pr, struct clan n) {

	if (pr->velicina < MAX) {
		pr->hrpa[pr->velicina] = n;
		pr->velicina++;
		popraviPremaVrhu(pr, pr->velicina - 1);
	}
	else {
		printf("Prioritetni red je pun.\n");
	}
}

void popraviPremaVrhu(struct prioritetniRed* pr, int index) {
	while (index > 0) {
		int parent = (index - 1) / 2;
		if (pr->hrpa[parent].prioritet < pr->hrpa[index].prioritet) {
			struct clan temp = pr->hrpa[parent];
			pr->hrpa[parent] = pr->hrpa[index];
			pr->hrpa[index] = temp;

			index = parent;
		}
		else {
			break;
		}
	}
}


struct clan izvadiClan(struct prioritetniRed* pr) {

	if (pr->velicina <= 0) {
		printf("Prioritetni red je prazan");
	}

	struct clan najveciPrioritet = pr->hrpa[0];
	pr->hrpa[0] = pr->hrpa[pr->velicina - 1];
	pr->velicina--;
	popraviPremaDnu(pr, 0);

	return najveciPrioritet;
}

void popraviPremaDnu(struct prioritetniRed* pr, int index) {
	while (index < pr->velicina) {
		int left = 2 * index + 1;
		int right = 2 * index + 2;
		int max = index;

		if (left < pr->velicina && pr->hrpa[left].prioritet > pr->hrpa[max].prioritet) {
			max = left;
		}
		if (right < pr->velicina && pr->hrpa[right].prioritet > pr->hrpa[max].prioritet) {
			max = right;
		}

		if (max != index) {
			struct clan temp = pr->hrpa[max];
			pr->hrpa[max] = pr->hrpa[index];
			pr->hrpa[index] = temp;

			index = max;
		}
		else {
			break;
		}
	}
}

int main() {

	struct prioritetniRed pr;
	pr.velicina = 0;

	struct clan element1 = { NULL, 10 };
	struct clan element2 = { NULL, 20 };
	struct clan element3 = { NULL, 5 };
	struct clan element4 = { NULL, 45 };

	dodajClan(&pr, element1);
	dodajClan(&pr, element2);
	dodajClan(&pr, element3);
	dodajClan(&pr, element4);

	struct clan najveciPrioritet = izvadiClan(&pr);
	printf("Najvazniji element ima prioritet: %d\n", najveciPrioritet.prioritet);

	return 0;
}