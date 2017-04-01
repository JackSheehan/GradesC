#include <stdio.h>
#include "string.h"
#include "stdlib.h"

typedef struct
{
	char firstName[50];
	char lastName[50];
	long id;
	char english, french, maths, philosophy;
} result;

result *results[100];

int numResults = 0;
int readFile(char *fileName);
int initialiseResults();
int printResult(result *aResult);
int main()
{
	char fileName[] = "/Users/jacksheehan/Desktop/dataweek18.txt";
	int i = 0;
	printf("%s %s %s %s %s %s %s\n\n","SURNAME", "FIRSTNAME", "ID", "MATHS", "ENGLISH", "FRENCH", "PHILOSOPHY");

	if (!readFile(fileName))
	{
		printf("File could not be opened !!\n");
		return 0;
	}

	while (results[i] != NULL)
	{
		printResult(results[i]);
		i++;
	}

	return 0;
}


int printResult(result *aResult)
{
	printf("%s %s %ld %c %c %c %c \n", aResult->lastName, aResult->firstName, aResult->id, aResult->maths, aResult->english, aResult->french, aResult->philosophy);
	return 0;
}

int initialiseResults()
{
	FILE *fptr;
	char temp[100];
	int i = 0;

	fptr = fopen("/Users/jacksheehan/Desktop/dataweek18.txt", "r");
	
		while (!feof(fptr))
		{
			results[i] = (result *)malloc(sizeof(result));
			strcpy((results[i])->firstName, NULL);
			fgets(temp, 100, fptr);
			i++;
		}
	return 0;
}

int readFile(char *fileName)
{
	FILE *fptr;
	char line[200];
	char firstline[100];
	int i = 0;

	fptr = fopen("/Users/jacksheehan/Desktop/dataweek18.txt", "r");

	fgets(firstline, 100, fptr);
		while (!feof(fptr))
		{
			fgets(line, 200, fptr);
			results[i] = (result *)malloc(sizeof(result));
			fscanf(fptr, "%ld\t%s\t%s\t%c\t%c\t%c\t%c", &(results[i])->id, (results[i])->firstName, (results[i])->lastName, &(results[i])->english, &(results[i])->french, &(results[i])->maths, &(results[i])->philosophy);
			i++;
		}
		fclose(fptr);
	return 1;
}
