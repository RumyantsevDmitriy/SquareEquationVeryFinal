#include <TXLib.h>
#include <stdio.h>
#include <assert.h>
#include <cctype>

#include "Functions.h"
#include "Constants.h"

void GetData(double *a, double *b, double *c)
{
    printf("������� �������� ��������� a: ");
	CheckData(a);

	printf("������� �������� ��������� b: ");
	CheckData(b);

	printf("������� �������� ��������� c: ");
	CheckData(c);
}

void CheckData(double *value)
{
    assert(value != NULL);

	int data = scanf("%lg", value);

    if(!isfinite(*value) || !isspace(getchar()))
    {
        int status_of_programm = BAD_ENTERED_DATA;
        printf("%s\n��������� ��������� ������", StatusOfErrorToString(status_of_programm));
        exit(0);
    }
}
