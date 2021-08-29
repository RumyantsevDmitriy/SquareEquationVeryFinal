#include <TXLib.h>
#include <stdio.h>

#include "Functions.h"
#include "Constants.h"

int main(void)
{
	printf("�� ������� ���������, �������� ���������� ���������\n"
	       "���������� ��������� ����� ���: a * x^2 + b * x + c = 0 , ��� a, b, c - �����\n\n"
           "���� �� ������ �������������� ��������� ������������� - ������� Y ");

    switch(getchar())
    {
        case 'Y': RunUnitTest();
                  break;
        default:  RunManualMode();
                  break;
    }

    return 0;
}

void RunManualMode()
{
    double a = NAN, b = NAN, c = NAN, root1 = NAN, root2 = NAN;

    GetData(&a, &b, &c);

    int status_of_programm = SolveSquareEquation(a, b, c, &root1, &root2);

    if(!IsSuccess(status_of_programm))
    {
        printf("%s", StatusOfErrorToString(status_of_programm));
    }
    else
    {
        switch(status_of_programm)
        {
            case NO_ROOT:    printf("\n������ ��������� �� ����� �������");
                             break;
            case ONE_ROOT:   printf("\n������ ��������� ����� ���� �������: x= %lg", root1);
                             break;
            case TWO_ROOT:   printf("\n������ ��������� ����� ��� �������: x1= %lg\n\t\t\t\t\t\b\b\b\bx2= %lg", root1, root2);
                             break;
            case INF_ROOT:   printf("\n������ ��������� ����� ���������� ������� ���������� �������");
                             break;
            default:         break;
        }
    }
}
