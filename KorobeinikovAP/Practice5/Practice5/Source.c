#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wincon.h>
#include <string.h>
#include <corecrt_wstring.h>

typedef unsigned long long ull;
typedef long long ll;
#define N 100

void insert_sort(int a[], int n[]);
void bubble_sort(int a[], int n[]);
void merge(int a[], int l, int r, int m);
void merge_sort(int a[], int n);
void res(WIN32_FIND_DATA names[], ull* size, int *ind, int n, char hw);






int main() {
	int i = 0;
	char* a = (char*)malloc(MAX_PATH - 3);
	char* a1 = (char*)malloc(MAX_PATH);

	int ind[N];
	for (i = 0; i < N; i++) {
		ind[i] = i;
	}

	ull size[N];
	for (i = 0; i < N; i++) {
		size[i] = 0;
	}

	WIN32_FIND_DATA names[N];
	WIN32_FIND_DATA fdata;
	HANDLE hfile;
	wchar_t* path = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t));
	wchar_t* wnames = (wchar_t*)malloc(N * sizeof(wchar_t*));



	do {
		printf("Input a closed path: \n");
		printf("Be careful. If did not input a path like this: 'C:\\...\\...\\', you can have a problems \n");
		scanf("%s", a);
		strcat(a, "*.*");
		mbstowcs(path, a, strlen(a) + 1);

		hfile = FindFirstFileW(path, &fdata);

	} while (hfile == INVALID_HANDLE_VALUE);


	printf("Your path : %s \n", a);
	printf("Data in your directory: \n");
	i = 0;

	do {
		if (i == 0 || i == 1) {
			i++;
			continue;
		}
		names[i] = fdata;
		//File name
		printf("Name:    ");
		wprintf(names[i].cFileName);
		wnames[i] = names[i].cFileName;
		//File size
		printf(" %10c    Size (bites): %u        ", ' ', names[i].nFileSizeLow);
		size[i] = names[i].nFileSizeLow;
		i++;
	} while (FindNextFile(hfile, &fdata) != NULL);

	//printf("\n !!!  I hope you knows that a folders is a links, they have no size. You need to input right path if u want to know size of folders.  !!!\n");


	char sr;
	printf("Choose a sorting method:\n1 - Bubble\n2 - Inserts\n3 - Merge\n");
	do {
		scanf("%c", &sr);
	} while ((sr != '1') && (sr != '2') && (sr != '3'));


	switch (sr) {
	case 1: {
		clock_t begin = clock();
		bubble_sort(size, ind);
		clock_t end = clock();
	}
	case 2:;

	case 3:;
	}
		
	printf("Sort by:\n1 - ascending\n2- descending");

	char hw;
	do {
		scanf("%c", &hw);
	} while ((hw != '1') && (hw != '2'));

	res(names, size, ind, i, hw);
	FindClose(hfile);
	printf("\n END \n");
	return 0;
}

	void bubble_sort(int a[], int n[]) {
		int i, j, tmp;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N - i - 1; j++) {
				if (a[n[j + 1]] < a[n[j]]) {
					tmp = n[j + 1];
					n[j + 1] = n[j];
					n[j] = tmp;
				}
			}
		}
		
	}

	void res(WIN32_FIND_DATA names[], ull* size, int *ind, int n, char hw) {
		switch (hw) {
		case '1': {
			for (int i = 2; i < n; i++) {
				printf("%d.   ", i - 1);
				printf("Name:    ");
				int j = ind[i - 2];
				wprintf(names[j].cFileName);
				printf(" %10c    Size (bites): %u        ", ' ', names[j].nFileSizeLow);
				size[j] = names[j].nFileSizeLow;
			}
		}
		case '2': {
			for (int i = n - 1; i >= 0; i++) {
				printf("%d.   ", n - i + 2);
				printf("Name:    ");
				int j = ind[i];
				wprintf(names[j].cFileName);
				printf(" %10c    Size (bites): %u        ", ' ', names[j].nFileSizeLow);
				size[j] = names[j].nFileSizeLow;
			}
		}
		}
	}