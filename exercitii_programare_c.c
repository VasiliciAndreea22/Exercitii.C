//EX.1

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int prel_fis(int v[100], int* n) {
	int x, i = 0, er = 1;
	FILE* f = fopen("fisNou.txt", "r");
	if (f != NULL) {
		while (fscanf(f, "%d", &x) > 0)
		{
			v[i] = x;
			i++;
		}
		*n = i;
		fclose(f);
	}

	else
		er = 0;
	return er;
}

void afisare(int v[100], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%5d", v[i]);
	}
}

void scriere_fis_vector(int v[100], int n) {
	float x;
	FILE* f=fopen( "fis1.txt", "w");
	for (int i = 0; i < n; i++) {
		fprintf(f, "%5d", v[i]);
	}
	fclose(f);
}
int main() {
	int v[100];
	int n, er;
	char nume[20];
	printf("Numele este: ");
	//gets(nume);

	er = prel_fis(v, &n);

	if (er == 1)
	{
		printf("Fisierul exista!");
		afisare(v, n);
		scriere_fis_vector(v, n);
	}
	else
	{
		printf("Fisierul nu exista!");
	}


	return 0;
}

//EX.2

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
    int marca;
    char nume[20];
    char prenume[20];
    char profesie[20];
    char departament[20];
    float salariu[3];
} Angajat;
void populareAngajati() {
    Angajat ang;
    FILE* f = fopen("angajati.dat", "wb");
    if (!f) {
        printf("Eroare la deschiderea fisierului.\n");
    }
    else
    {
        printf("Marca: ");
        scanf_s("%d", &ang.marca);

        while (!feof(stdin)) {
            printf("Nume: "); getc(stdin);
            scanf_s("%s", ang.nume, sizeof(ang.nume));
            printf("Prenume: ");
            scanf_s("%s", ang.prenume, sizeof(ang.prenume));
            printf("Profesie: ");
            scanf_s("%s", ang.profesie, sizeof(ang.profesie));
            printf("Departament: ");
            scanf_s("%s", ang.departament, sizeof(ang.departament));
            printf("Salariile 3 valori: ");
            for (int i = 0; i < 3; i++) {
                scanf_s("%f", &ang.salariu[i]);
            }

            fwrite(&ang, sizeof(Angajat), 1, f);

            printf("Marca: ");
            scanf_s("%d", &ang.marca);
        }

        fclose(f);
    }
}
void adaugareAngajati() {
    Angajat ang;
    FILE* f = fopen("angajati.dat", "rb+");
    if (!f) {
        printf("Eroare la deschiderea fisierului.\n");
    }
    else
    {
        fseek(f, 0, 2);
        printf("Marca: ");
        scanf_s("%d", &ang.marca);

        while (!feof(stdin)) {
            printf("Nume: "); getc(stdin);
            scanf_s("%s", ang.nume, sizeof(ang.nume));
            printf("Prenume: ");
            scanf_s("%s", ang.prenume, sizeof(ang.prenume));
            printf("Profesie: ");
            scanf_s("%s", ang.profesie, sizeof(ang.profesie));
            printf("Departament: ");
            scanf_s("%s", ang.departament, sizeof(ang.departament));
            printf("Salariile 3 valori: ");
            for (int i = 0; i < 3; i++) {
                scanf_s("%f", &ang.salariu[i]);
            }

            fwrite(&ang, sizeof(Angajat), 1, f);

            printf("Marca: ");
            scanf_s("%d", &ang.marca);
        }

        fclose(f);
    }
}
int main() {
    //populareAngajati();
    adaugareAngajati();
    return 0;
}

//EX.3
// Scrieti un subprogram recursiv care calculeaza valoarea unui polinom intr-un punct
//dat. Scrieti un program care demonstreaza utilizarea acestui subprogram
#include <stdio.h>
#include <conio.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

float putere(float x, int n) {
    float rez;
    if (n == 0) rez = 1;
    else {
        rez = putere(x, n - 1) * x;
    }

    return rez;
}

float polinom(float coef[], int n, float x) {
    float rez;
    if (n == 0) rez = coef[0];
    else {
        rez = polinom(coef, n - 1, x) + coef[n] * putere(x, n);
    }

    return rez;
}
int main()
{
    int n, i;
    float coef[100], x, val;
    printf("Introduceti gradul polinomului, n=");
    scanf_s("%d", &n);
    printf("Coeficientii polinomului: \n");
    for (i = 0; i <= n; i++) {
        printf("coeficientul lui x la puterea %d=", i);
        scanf_s("%f", &coef[i]);
    }
    printf("Punctul pentru care se va calcula valoarea:");
    scanf_s("%f", &x);
    val = polinom(coef, n, x);
    printf("Valoarea polinomului in punctul %5.2f este %5.2f", x, val);
}

//EX.4

#include<stdio.h>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
//problema turnurilor hanoi

//ti - tija initiala
//tf - tija finala
//tint - tija intermediara
//nr - nr mutari
void hanoi(int n, int ti, int tf, int tint, int rez[][2], int* nr)
{
    if (n == 1)
    {
        rez[*nr][0] = ti;
        rez[*nr][1] = tf;
        (*nr)++;
    }
    else
    {
        hanoi(n - 1, ti, tint, tf, rez, nr);
        rez[*nr][0] = ti;
        rez[*nr][1] = tf;
        (*nr)++;
        hanoi(n - 1, tint, tf, ti, rez, nr);
    }
}

void main()
{
    int i, n, mutari[100][2], nrm;
    printf("numarul de discuri="); 
    scanf_s("%d", &n);
    nrm = 0;
    hanoi(n, 1, 3, 2, mutari, &nrm);
    for (i = 0; i < nrm; i++)
        printf("%d, %d\n", mutari[i][0], mutari[i][1]);
}

//EX.5
int citire(int a[10][2], int b[], int* n)
{
	FILE* f;
	fopen_s(&f, "fis.txt", "r");
	int i = 0, er = 1, h, m;
	if (f != NULL)
	{
		fscanf_s(f, "%d", &(*n));
		printf("Fisierul exista! \n");
		fscanf_s(f, "%d", &h);
		while (!feof(f))
		{
		    fscanf_s(f, "%d", &m); 
			a[i][0] = h * 60 + m; //ora de start
			fscanf_s(f, "%d", &h);		fscanf_s(f, "%d", &m);
			a[i][1] = h * 60 + m; //ora de sfarsit
			b[i] = i + 1;
			i++;
			fscanf_s(f, "%d", &h);
		}
		fclose(f);
	}
	else
	{
		printf("Fisierul nu exista!");
		er = 0;
	}
	return er;
}
void afisare(int a[10][2], int b[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\n%3d  ", b[i]);
		printf("%5d %5d", a[i][0], a[i][1]);
	}
}

//EX.6
#include <stdio.h>
int preluare(int* nrvarfuri, int *nrmuchii, int mat[10][3])
{
	FILE* f;
	int i, j, er = 1;
	int varf_initial, varf_final, cost;
	fopen_s(&f, "graf.txt", "r");
	if (f != NULL)
	{
		fscanf_s(f, "%d %d", &(*nrvarfuri), &(*nrmuchii));

		for (i = 0; i < *nrvarfuri; i++)
			for (j = 0; j < *nrvarfuri; j++)
				mat[i][j] = 0;
		i = 0;
		fscanf_s(f, "%d %d %d", &varf_initial, &varf_final,&cost);
		while (!feof(f))
		{

			mat[i][0] = varf_initial;
			mat[i][1] = varf_final;
			mat[i][2] = cost;
			i++;
			fscanf_s(f, "%d %d %d", &varf_initial, &varf_final, &cost);
		}
		fclose(f);
	}
	else
	{
		er = 0;
		printf("Nu exista!");
	}
	return er;
}
void afisare(int mat[10][3], int nrmuchii)
{
	int i, j;
	printf("Reprezentarea tabelara: \n");
	for (i = 0; i < nrmuchii; i++)
	{
		printf("\n");
		for (j = 0; j < 3; j++)
			printf("%4d", mat[i][j]);
	}
}
