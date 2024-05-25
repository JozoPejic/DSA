#include <stdio.h>

typedef struct {
	char tabla[3][3];
	char red;
} Stanje;

typedef struct {
	int r, s;
} Potez;

void init(Stanje* stanje) {
	for (int r = 0; r < 3; r++) {
		for (int s = 0; s < 3; s++) {
			stanje->tabla[r][s] = '-';
		}
	}
	stanje->red = 'x';
}

int akcije(Stanje* stanje, Potez* akc) {
	int k = 0;
	for (int r = 0; r < 3; r++) {
		for (int s = 0; s < 3; s++) {
			if (stanje->tabla[r][s] == '-') {
				akc[k].r = r;
				akc[k].s = s;
				k++;
			}
		}
	}
	return k;
}

void napravi_akciju(Stanje* stanje, Potez* p) {
	stanje->tabla[p->r][p->s] = stanje->red;
	stanje->red = (stanje->red == 'x') ? 'o' : 'x';
}

void ponisti_akciju(Stanje* stanje, Potez* p) {
	stanje->tabla[p->r][p->s] = '-';
	stanje->red = (stanje->red == 'x') ? 'o' : 'x';
}

char game_over(Stanje* s) {
	for (int i = 0; i < 3; i++) {
		if (s->tabla[i][0] != '-' && s->tabla[i][0] == s->tabla[i][1] && s->tabla[i][1] == s->tabla[i][2])
			return s->tabla[i][0];
		if (s->tabla[0][i] != '-' && s->tabla[0][i] == s->tabla[1][i] && s->tabla[1][i] == s->tabla[2][i])
			return s->tabla[0][i];
	}

	if (s->tabla[0][0] != '-' && s->tabla[0][0] == s->tabla[1][1] && s->tabla[1][1] == s->tabla[2][2])
		return s->tabla[1][1];

	if (s->tabla[0][2] != '-' && s->tabla[0][2] == s->tabla[1][1] && s->tabla[1][1] == s->tabla[2][0])
		return s->tabla[1][1];

	for (int r = 0; r < 3; r++) {
		for (int st = 0; st < 3; st++) {
			if (s->tabla[r][st] == '-')
				return 't';
		}
	}
	return '-';
}

void print_stanje(Stanje* stanje) {
	for (int r = 0; r < 3; r++) {
		for (int s = 0; s < 3; s++) {
			printf("%c ", stanje->tabla[r][s]);
		}
		printf("\n");
	}
	printf("\n");
}

int count = 0;

int minimax(Stanje* s) {
	count++;
	char rez = game_over(s);
	if (rez != 't') {
		if (rez == 'x')
			return 100;
		if (rez == 'o')
			return -100;
		return 0;
	}

	Potez niz[9];
	if (s->red == 'x') { // MAX
		int n = akcije(s, niz);
		int maxv = -1000;
		for (int i = 0; i < n; i++) {
			napravi_akciju(s, niz + i);
			int v = minimax(s);
			ponisti_akciju(s, niz + i);
			if (v > maxv) {
				maxv = v;
			}
		}
		return maxv;
	}
	else { // MIN
		int n = akcije(s, niz);
		int minv = 1000;
		for (int i = 0; i < n; i++) {
			napravi_akciju(s, niz + i);
			int v = minimax(s);
			ponisti_akciju(s, niz + i);
			if (v < minv) {
				minv = v;
			}
		}
		return minv;
	}

}


void main() {
	Stanje s;
	
	init(&s);
	s.tabla[0][0] = 'o';
	s.tabla[0][2] = 'o';
	s.tabla[1][1] = 'x';
	s.tabla[2][1] = 'x';
	s.tabla[2][2] = 'x';
	print_stanje(&s);

	int v = minimax(&s);
	printf("count = %d, value = %d\n", count, v);
	/*
	Potez niz[9];
	while (game_over(&s) == 't') {
		print_stanje(&s);
		int n = akcije(&s, niz);
		napravi_akciju(&s, niz + 0);
	}
	print_stanje(&s);
	printf("rezultat %c\n", game_over(&s));
	*/
}