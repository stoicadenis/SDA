#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum{medii, superioare, doctorat}studii;

typedef struct {
	float mbac, mlic;
}stud_medii;

typedef union {
	float licenta;
	char tip_doct[20];
	stud_medii m;
}tip_studii;

typedef struct {
	char nume[20], prenume[20];
	float salariu;
	int zi, luna, an;
	studii s;
	tip_studii t;
	
}angajat;

void citire(angajat* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("Detalii angajat %d\n", i + 1);
		printf("Nume si Prenume angajat: ");
		getchar();
		scanf("%s", &a[i].nume);
		getchar();
		scanf("%s", &a[i].prenume);
		printf("Data nasterii D/M/Y: ");
		scanf("%d%d%d", &a[i].zi, &a[i].luna, &a[i].an);
		printf("Salariu angajat: ");
		scanf("%f", &a[i].salariu);
		printf("Ce studii are angajatul ( 0 - Medii / 1 - Superioare / 2 - Doctorat): ");
		scanf("%d", &a[i].s);
		if (a[i].s == 0) {
			printf("Media de la bac a angajatului: ");
			scanf("%f", &a[i].t.m.mbac);
			printf("Media din cei 4 ani de liceu: ");
			scanf("%f", &a[i].t.m.mlic);
		}
		else if (a[i].s == 1) {
			printf("Nota de la licenta: ");
			scanf("%f", &a[i].t.licenta);
		}
		else {
			printf("Tipul de doctorat ( tehnic / economic): ");
			getchar();
			scanf("%s", &a[i].t.tip_doct);
		}
	}
}

void afisare(angajat* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("Detalii Angajat %d\n", i + 1);
		printf("\t Nume si Prenume: %s %s\n", a[i].nume, a[i].prenume);
		printf("\t Data nasterii: %d.%d.%d\n", a[i].zi, a[i].luna, a[i].an);
		printf("\t Salariu angajat: %f\n", a[i].salariu);
		printf("\t Tip studii: %d\n", a[i].s);
		if (a[i].s == 0) {
			printf("\t Media de la bac a angajatului: %f\n", a[i].t.m.mbac);
			printf("\t Media din cei 4 ani de liceu: %f\n", a[i].t.m.mlic);
		}
		else if(a[i].s == 1)
			printf("\t Nota de la licenta: %f\n", a[i].t.licenta);
		else
			printf("\t Tipul de doctorat: %s\n", toupper(a[i].t.tip_doct));
	}
}

void caut_nume(angajat* a, int n, char nume[]) {
	for (int i = 0; i < n; i++)
		if (strcmp(a[i].nume, nume) == 0) {
			printf("Detalii Angajat %d\n", i + 1);
			printf("\t Nume si Prenume: %s %s\n", a[i].nume, a[i].prenume);
			printf("\t Data nasterii: %d.%d.%d\n", a[i].zi, a[i].luna, a[i].an);
			printf("\t Salariu angajat: %f\n", a[i].salariu);
			printf("\t Tip studii: %d\n", a[i].s);
			if (a[i].s == 0) {
				printf("\t Media de la bac a angajatului: %f\n", a[i].t.m.mbac);
				printf("\t Media din cei 4 ani de liceu: %f\n", a[i].t.m.mlic);
			}
			else if (a[i].s == 1)
				printf("\t Nota de la licenta: %f\n", a[i].t.licenta);
			else
				printf("\t Tipul de doctorat: %s\n", toupper(a[i].t.tip_doct));
			break;
		}
}

void caut_sa(angajat* a, int n, studii s, int an) {
	float suma = 0, k = 0;
	for (int i = 0; i < n; i++)
		if (a[i].s == s && a[i].an >= an) {
			suma += a[i].salariu;
			k++;
		}
	printf("Numarul de angajati cautati dupa studii si anul nasterii este de %f, iar media salariului este: %f", k, suma / k);
}

void delete(angajat* a, int *n, char nume[]) {
	for (int i = 0; i < n; i++)
		if (strcmp(a[i].nume, nume) == 0) {
			a[i] = a[*n - 1];
			(*n)--;
			break;
		}
}

int main() {
	angajat a[20];
	studii s;
	int n, opt, an;
	char nume[20];
	printf("Cati angajati sunt? R: ");
	scanf("%d", &n);
	do {
		printf("0. Iesire\n");
		printf("1. Citire angajati\n");
		printf("2. Afisare angajati\n");
		printf("3. Cauta un angajat dupa nume\n");
		printf("4. Afiseaza numarul si salariul mediu al angajatiilor dupa studii si varsta citite\n");
		printf("5. Sterge o persoana dupa nume\n");
		printf("Citeste optiune dorita? R: ");
		scanf("%d", &opt);
		switch (opt) {
		case 0: exit(0);
			break;
		case 1:
			citire(a, n);
			break;
		case 2:
			afisare(a, n);
			break;
		case 3:
			printf("Cititi numele pe care doriti sa il cautati: ");
			getchar();
			scanf("%s", &nume);
			caut_nume(a, n, nume);
			break;
		case 4:
			printf("Cititi studiile dupa care doriti sa cautati angajatii (0 - MEDII / 1 - SUPERIOARE / 2 - DOCTORAT): ");
			scanf("%d", &s);
			printf("Dati anul de nastere de la care sa caute angajatii: ");
			scanf("%d", &an);
			caut_sa(a, n, s, an);
			break;
		case 5:
			printf("Cititi numele pe care doriti sa il stergeti: ");
			getchar();
			scanf("%s", &nume);
			delete(a, &n, nume);
			break;
		default:
			printf("Valoare invalida!\n");
			break;
		}

	} while (1);
	system("pause");
	return 0;
}