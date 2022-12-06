#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wincon.h>
#include <string.h>
#include <corecrt_wstring.h>

#define ull unsigned long long
#define N 10

void insert_sort(int a[], int n[]);
void bubble_sort(int a[], int n[]);
void merge(int a[], int l, int r, int m);
void merge_sort(int a[], int n);







int main() {
	int i = 0;
	char* a = (char*)malloc(MAX_PATH - 3);
	char* a1 = (char*)malloc(MAX_PATH);

	int ind[N];
	for (i = 0; i < N; i++) {
		ind[i] = i;
	}

	WIN32_FIND_DATA names[1000];
	WIN32_FIND_DATA fdata;
	HANDLE hfile;
	wchar_t* path = (wchar_t*)malloc(MAX_PATH * sizeof(wchar_t));



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

	do {
		if (i == 0 || i == 1) {
			i++;
			continue;
		}



		names[i] = fdata;

		printf("Name:    ");
		wprintf(names[i].cFileName);
		//File size
		printf(" %10c    Size (bites): %u        ", ' ', names[i].nFileSizeLow);
		//File creation time
		time_t *time1 = filetime_to_timet(names[i].ftCreationTime);
		printf("%10c Created time:  %s     \n", ' ', ctime(&time1));
		i++;
	} while (FindNextFileW(hfile, &fdata) != NULL);

	//printf("\n !!!  I hope you knows that a folders is a links, they have no size. You need to input right path if u want to know size of folders.  !!!\n");


	char sr;
	printf("Input a sorted method: \n Input 1 for  insert sort \n Input 2 for bubble sort \n Input 3 for merge sort \n ");
	do {
		scanf("%c", &sr);
	} while ((sr != '1') && (sr != '2') && (sr != '3'));	


	switch (sr) {

		case 1:
		
		case 2:
		
		case 3:

	FindClose(hfile);
	printf("\n END \n");
	return 0;
}