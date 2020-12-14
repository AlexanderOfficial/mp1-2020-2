#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <locale.h>


float degreesToRadians(long float degrees);
int choiceOfFunctionForDecomposition();
int choiceOfMode();
double getRealVariable();
void modeOne(void(*functionPointer)(double, double, long int), double rV, float etalon);
void modeTwo(void(*functionPointer)(double, double, long int), double rV, double etalon);
void sinX(double rV, double cA, long int nOF);
void cosX(double rV, double cA, long int nOF);
void expX(double rV, double cA, long int nOF);
void arcsinX(double rV, double cA, long int nOF);
double realVariable; //������������ ����� � ������� ������������� �������� 
float calculationAccuracy; //�������� ���������� (�������)
long int numberOfElements; //����� ��������� ���� ��� ���������� �������
main() {
	setlocale(LC_ALL, "RUS");
	printf("����� ���������� � ���������, ����������� ��������� ������ �������� ��� ���������� ������ ������� � �������� �����\n");
	printf("� �������� ������������ �� ���� ���������� ���� ������� � ��� �������!\n");
	printf("---------------------------------------------------------------------------------------------\n");
	printf("��������� �������� � 2 �������\n");
	printf("_��� ������ � ������ 1 ������������ ����� �����������:_\n");
	printf("-> ������� �������,\n");
	printf("-> ������ ����� x, � ������� ���������� ��������� ��������,\n");
	printf("-> ������ �������� ����������(>= 0.000001),\n");
	printf("-> ������ ����� ��������� ���� ��� ���������� �������(N - �� 1 �� 1000).\n");
	printf("������ ������ �������� ��������� ������� ����������� ���� �� ���������� �������� ��������,\n");
	printf("���� �� ���������� ���������� ����� ���������.\n");
	printf("__�� ����������� ������� ��������� ������� ��������� ����������:__\n");
	printf("-> ��������� ��������(���������� � �������������� ���������� �������������� ������� ����� ���������������� �),\n");
	printf("-> ����������� ������ �������� �������,\n");
	printf("-> ������� ����� ������� � ��������� ���������,\n");
	printf("-> ���������� ���������, ������� ���� ���������.\n");
	printf("__��� ������ � ������ 2 ������������ ����� �����������:__\n");
	printf("-> ������� �������,\n");
	printf("-> ������ ����� x, � ������� ���������� ��������� ��������,\n");
	printf("-> ������ ����� �������������(NMax - �� 1 �� 25).\n");
	printf("_�� ����������� ������� ��������� ������� ��������� ����������:_\n");
	printf("-> ��������� ��������(���������� � �������������� ���������� �������������� ������� ����� ���������������� �),\n");
	printf("-> ������� �� NMax ����� �� ���������� ��������� : ��� - �� ���������(�� 1 �� NMax),\n");
	printf("-> ����������� ������ �������� �������, ������� ����� ������� � ��������� ���������.\n");
	printf("\n");
	printf("---------------------------------------------------------------------------------------------\n");
	int funcNum;
	int mode;
	void(*functionPointer)(double, double, long int) = NULL;
	mode = choiceOfMode();//�������� ����� ������
	funcNum = choiceOfFunctionForDecomposition(); //�������� ������� 
	float rV;
	float cA;
	float nOF;
	rV = getRealVariable(); //�������� �������� ���
	float etalon = 0;
	switch (funcNum) {
	case 1:
		functionPointer = sinX;
		rV = degreesToRadians(rV);
		printf("� �������� %f\n", rV);
		etalon = sin(rV);
		break;
	case 2:
		functionPointer = cosX;
		rV = degreesToRadians(rV);
		printf("� �������� %f\n", rV);
		etalon = cos(rV);
		break;
	case 3:
		functionPointer = expX;
		etalon = exp(rV);
		break;
	case 4:
		functionPointer = arcsinX;
		etalon = asin(rV);
		break;
	}
	if (mode == 1) {
		modeOne(functionPointer, rV, etalon);
	}
	if (mode == 2) {
		modeTwo(functionPointer, rV, etalon);
	}
	getchar();
}
void modeOne(void(*functionPointer)(double, double, long int), double rV, float etalon) {
	printf_s("������� �������� ���������� (�������): ");
	scanf_s("%f", &calculationAccuracy);
	printf_s("������� ���������� ���������: n");
	scanf_s("%li", &numberOfElements);
	printf_s("��������� �������� (���������� � �������������� ���������� �������������� ������� ����� ����������������): %f\n", etalon);
	printf_s("����������� ������ �������   ������� ����� ������� � ��������    ����������� ����� ���������\n");
	functionPointer(rV, calculationAccuracy, numberOfElements);
	printf("�� �������!\n");
	getchar();


}
void modeTwo(void(*functionPointer)(double, double, long int), double rV, double etalon) {
	long int i;
	int numberOfExperement;

	double cA = -0.000001;
	printf("������� ���������� ������������� �� 1 �� 25?\n");
	scanf_s("%i", &numberOfExperement);
	printf_s("��������� �������� (���������� � �������������� ���������� �������������� ������� ����� ����������������): %f\n", etalon);
	printf("����������� ������ �������   ������� ����� ������� � ��������    ����������� ����� ���������\n ");
	for (i = 0; i < numberOfExperement; i++)
		functionPointer(rV, calculationAccuracy, i + 1);
	printf("�� �������!\n");
	getchar();
}
void sinX(double rV, double cA, long int nOF) {
	long int i;
	double sinInX = sin(rV);
	double function = rV;
	double delta = fabs(sinInX - function);
	double term = rV;
	for (i = 2; (i <= nOF) && (delta >= cA); i++)
	{
		term = (-1) * term * rV * rV / ((2 * i - 1) * (2 * i - 2));
		function = function + term;
		delta = fabs(sinInX - function);
	}
	//printf("����������� ������ �������   ������� ����� ������� � ��������    ����������� ����� ���������\n ");
	printf("%-30lf %-40lf  %-40d\n", function, delta, i - 1);
}
void cosX(double rV, double cA, long int nOF) {
	long int i;
	double cosInX = cos(rV);
	double function = 1;
	double delta = fabs(cosInX - function);
	double term = 1;
	for (i = 2; (i <= nOF) && (delta >= cA); i++)
	{
		term = (-1) * term * rV * rV / ((2 * i - 2) * (2 * i - 3));
		function = function + term;
		delta = fabs(cosInX - function);
	}
	printf("%-30lf %-40lf  %-40d\n", function, delta, i - 1);
}
void expX(double rV, double cA, long int nOF) {
	long int i;
	double expInX = exp(rV);
	double function = 1;
	double delta = fabs(expInX - function);
	double term = 1;
	for (i = 2; (i <= nOF) && (delta >= cA); i++)
	{
		term = term * rV / (i - 1);
		function = function + term;
		delta = fabs(expInX - function);
	}
	printf("%-30lf %-40lf  %-40d\n", function, delta, i - 1);
}
void arcsinX(double rV, double cA, long int nOF) {
	long int i;
	double arcsinInX = asin(rV);
	double function = rV;
	double delta = fabs(arcsinInX - function);
	double term = rV;
	for (i = 1; (i <= nOF) && (delta >= cA); i += 1)
	{
		//term = term * ((rV * rV * (2 * i + 1) * (2 * i + 1)) / (2 * (i + 1) * (2 * i + 3)));
		term *= ((rV * rV) * (2 * i - 1) * (2 * i - 1)) / ((2 * i) * (2 * i + 1));
		function = function + term;
		delta = fabs(arcsinInX - function);
	}
	printf("%-30lf %-40lf  %-40d\n\n", function, delta, i - 1);

}
float degreesToRadians(long float degrees) { //����������� ������� � ������� � ���������� �������� ��� � ���
	float radians;
	radians = ((degrees * M_PI) / 180);
	return radians;
}
double getRealVariable() { //�������� �����
	printf("������� x (� �������� ��� ������������������ �������), ��� ���������� � ��� �������:\n");
	scanf_s("%lf", &realVariable);
	printf("�� ����� %f\n", realVariable);
	return realVariable;
}
int choiceOfFunctionForDecomposition() { //�������� ������� ��� ���������� � ���������� �� �����: ����� ������ �������� �� ����
	int choice;
	printf("�������� ������ �������: �� ��������������� ����:\n");
	printf("1. sin(x)\n2. cos(x)\n3. exp(x)\n4. arcsin(x)\n");
	int z = 1;
	while (z != 0) { //�������� �� ������� ��������� ����� ����
		scanf_s("%i", &choice);
		if (choice > 4 || choice < 1) {
			printf("������ ��� � ����. �������� ������!\n");
			z = 1;
		}
		else {
			z = 0;
		}
	}
	return choice;
}
int choiceOfMode() { //���������� ����� ������ � ������ �������� �� ����
	int choice;
	printf("�������� ������ ����� ������\n");
	printf("1.����������� ������ ������� � �������� �����\n2.�������� �����������\n");
	int z = 1;
	while (z != 0) { //�������� �� ������� ��������� ����� ����
		scanf_s("%i", &choice);
		if (choice > 2 || choice < 1) {
			printf("������ ��� � ����. �������� ������!\n");
			z = 1;
		}
		else {
			z = 0;
		}
	}
	return choice;

}