#include <stdio.h>
#include <malloc.h>
#include "bstree.h"

BSTree NewBSTree()
{
	// Novo prazno stablo
	return NULL;
}

void AddNode(BSTree* bst, char* word)
{
	// Rekurzivno se tra�i mjesto za novi �vor u stablu. Ako rije� postoji u stablu, ne dodaje se.
	// bst parametar je dvostruki pokaziva�.
	if (*bst == NULL) {
		BSTree noviNode = (BSTree)malloc(sizeof(Node));
		noviNode->word = _strdup(word);
		noviNode->left = NULL;
		noviNode->right = NULL;
		*bst = noviNode;
	}
	else {
		int compare = strcmp(word, (*bst)->word);
		if (compare < 0) {
			AddNode(&(*bst)->left, word);
		}
		else if (compare > 0) {
			AddNode(&(*bst)->right, word);
		}
		else {
			printf("Rijec %s vec postoji u stablu.\n", word);
		}
	}
}

int BSTHeight(BSTree bst)
{
	// Rekurzivno se prolazi cijelo stablo da bi se prona�la najdu�a grana (visina stabla).
	if (bst == NULL) return -1;
	
	int visinaLijevog = BSTHeight(bst->left);
	int visinaDesnog = BSTHeight(bst->right);
	return visinaLijevog > visinaDesnog ? visinaLijevog + 1 : visinaDesnog + 1;
}

void PrintBSTree(BSTree bst)
{
	// Ispisuje rije�i u stablu na ekran po abecednom redu.
	// In-order �etnja po stablu (lijevo dijete, �vor, desno dijete)
	if (bst == NULL) {
		return;
	}
	PrintBSTree(bst->left);
	printf("%s\n", bst->word);
	PrintBSTree(bst->right);
}

void SaveBSTree(BSTree bst, FILE* fd)
{
	// Snima rije� po rije� iz stabla u tekstualnu datoteku. Rije�i su odvojene razmakom.
	// Pre-order �etnja po stablu (ttenutni �vor pa djeca)
	if (bst == NULL) {
		return;
	}
	fprintf(fd, "%s ", bst->word);
	SaveBSTree(bst->left, fd);
	SaveBSTree(bst->right, fd);
}

void DeleteBSTree(BSTree bst)
{
	// Bri�e stablo (string word i sam �vor) iz memorije.
	// Post-order �etnja po stablu (prvo djeca pa trenutni �vor)
	if (bst == NULL) {
		return;
	}
	DeleteBSTree(bst->left);
	DeleteBSTree(bst->right);
	free(bst->word);
	free(bst);
}

BSTree LoadBSTree(FILE* fd)
{
	// U�itava rije� po rije� iz tekstualne datoteke i dodaje ih u stablo preko AddNode() funkcije.
	// Rije� duplicirati sa strdup().
	BSTree bst = NULL;
	char word[50];

	while (fscanf_s(fd, "%s", word) == 1) {
		AddNode(&bst, _strdup(word));
	}

	return bst;
}
