/*����������� �������� ��������� ��������� � �������� ������ ������ � �������� ��������, ������������� �� ����������� / �������� �������.

������� ������ :
���� �� ����������, � ������� ���������� ������������� ����������.
����� ����������.
�������� ������ :
��������������� ������ ���� ������ � ��������� �������.
����� ����������.
��������� ������ ������������� ������������ ����������� ������� ����� ���������� � �������� ����������� �������� ������.

��������� ������ ������������� ������ � ������������� ����������� ����������, ������� �������� :
����������� ����� ���� �� ��������� ��������;
����������� ������ ������ ����������;
����������� ��������� ���������������� ������ ������ � ��������� �������.
C����� ������� ���������� :
1) ���������
2) �������
3) ���������
4) ��������
5) �����
6) �����
7) ���������*/
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>  
#include <stdlib.h>  
#include <io.h>  
#include <time.h>  
#include <locale.h>
#include <dos.h>
#include <string.h>
//����
char* menu[] = {
	"1. ���������� ���������",
	"2. ���������� �������",
	"3. ���������� ���������",
	"4. ���������� ��������",
	"5. ���������� �����",
	"6. ���������� �����",
	"7. ���������� ���������",
	"8. �����",
};
const int numberOfItemsInTheMenu = sizeof(menu) / sizeof(char*);//���������� ������� � ����
void retrievingInformationAboutFiles(hFile);

void showMenu() { //������� ���� � �������
	system("cls");
	printf("\t ����\n");
	for (int i = 0; i < numberOfItemsInTheMenu; i++) {
		printf("%s\n", menu[i]);
	}
}

int selectMenu(const int numberOfItemsInTheMenu) {
	//��������� ����� ���� � ��������� �� ������� ��������� ������ ��� ����� 
	//����� ��������� ������ ����� ������������� ������������ ���� 
	int selectedMenuItem;
	char userEnteredTheNumber[50];
	gets_s(userEnteredTheNumber, 50); // ��������� ������

	// ���� ���� �����������, �������� �� ���� � ������ ��������� ���
	while (sscanf(userEnteredTheNumber, "%d", &selectedMenuItem) != 1 || selectedMenuItem < 1 || selectedMenuItem > numberOfItemsInTheMenu) {
		printf("������ ������ ��� � ����: ��������� ���� ������!\n"); // ������� ��������� �� ������
		scanf("%s", userEnteredTheNumber); // ��������� ������ ��������
	}
	return selectedMenuItem;//���������� ��������� ����� � ����
}
//���������� ���������
void bubbleSort() {

}
//���������� ������� 
void selectionSort() {

}
//���������� ���������
void insertionSort() {

}
//���������� ��������
void mergeSort() {

}
//���������� �����
void quickSort() {

}
//���������� �����
void shellSort() {

}
//���������� ���������
void  countingSort() {

}



//���� ���� ���������� 
char directoryPath[250];
char enteringDirectoryPath() {
	printf("������� ���� ��  ���������� (�������� : C:\\\\temp\\\\*.*) : \n");
	gets_s(directoryPath, 250);
	printf("��������� ������� %s\n", directoryPath);
	strcat(directoryPath, "*");//�������� � ����� ������ ���������
	return directoryPath;
}
//��������� ����������� � ������
struct ftime {
	unsigned ft_tsec : 5; /* ������� */
	unsigned ft_min : 6; /* ������ */
	unsigned ft_hour : 5; /* ���� */
	unsigned ft_day : 5; /* ��� */
	unsigned ft_month : 4; /* ������ */
	unsigned ft_year : 7; /* ���� � 1980 */
};
//��������� ����������� � ������
void retrievingInformationAboutFiles(directoryPath) {//��������� ����������� � ������
	struct _finddata_t sortableFile; //����������� sortableFile.name sortableFile.size sortableFile.time
	printf("��������� ������� 1232113 %s\n", directoryPath);
	intptr_t hFile; //memsize ��� intptr_t ������ � ���� ��������� hFile
	//char path[200];//��� �������� 
	int numberOfFiles = 0; //������� 
	//int fd;
	if ((hFile = _findfirst(directoryPath, &sortableFile)) == -1L)//-1L ���� �� ����� ��������
		//���� �. _findfirst ��������� -1: � ��������� ���������� ��� �����. ���� 0 �� ����.
		printf("� ��������� ����� ��� ������ ��� ����� ������ �������!\n");
	else
	{
		printf("������ ������ � ��������� ����� (��� ����������)\n\n");
		printf("��� �����         ���� � ����� �������� �������� %16c   ������\n", ' ');
		printf("----         ---- %24c   ----\n", ' ');
		do { // ������ ���� ���� ������� � ����������
			char buffer[30];
			ctime_s(buffer, _countof(buffer), &sortableFile.time_write);
			if (numberOfFiles<=200)
				
				printf("%-14.14s %-5.22s      %16ld\n", sortableFile.name, buffer ,sortableFile.size);
			numberOfFiles ++;







			char bufferTime[30];//��� �������� ���� � ������� �������� �����
			// _countof(buffer) ��������� ���������� ���������� ��������� � ����������� ������� buffer[30].
			struct ftime p;
			int fd;
			//fd= open("TEST.TST")
			//getftime(hFile, &fd);
			//printf("%d", p.ft_year + 1980);
			//ctime_s(bufferTime, _countof(bufferTime), &sortableFile.time_write);//����������� �������� ������� � ������ � ����������� 
			//��� � ������������ � ����������� ���������� �������� �����
		} while (_findnext(hFile, &sortableFile) == 0);
		_findclose(hFile);
		printf("\ncount of files: %d", numberOfFiles);
	}

}

int main() {
	//system("pause");
	setlocale(LC_ALL, "Rus"); //���������� ������� ����
	enteringDirectoryPath();
	printf("��������� ������� %s\n", directoryPath);
	retrievingInformationAboutFiles(directoryPath);
	//showMenu();
	//selectMenu(numberOfItemsInTheMenu);
	//int selectedMenuItem;
	//void retrievingInformationAboutFiles(hFile);
	/*do {
		showMenu();

		selectedMenuItem = selectMenu(numberOfItemsInTheMenu); // �������� ����� ���������� ������ ����

		switch (selectedMenuItem) {
		case 1:

			break;

		case 2:

			break;

		case 3:

			break;

		case 4:

			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		}

		if (selectedMenuItem != 8)
			system("pause");
	} while (selectedMenuItem != 8); //����� ���� ������ 8 ����� � ����
	*/
}