/*
* ��������� ���������� ����� ���������. ������ ���������� ��� ���� � ������� ������, ������� �� �� �����.
* ������� ��������� ������� ��� ������ ��������, ������ ������ �������� � �������� � ��� �������� ��������� 
* � �������� ������ ��������� �������� ���������: ��� ��������� ������(������ ����) ����� ������ 0
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include<malloc.h>


char* name[30];
unsigned int price;
char* barcode[30];
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996

struct product* addProduct(char* name, unsigned int price, char* barcode);
int SearchProduct(char* BARCODE, const struct product* st[]);
void view_product_catalog(unsigned int product_counter, const struct product* st[]);


unsigned int product_counter = 5;//���������� ������ � ��������

//��������� ��������� ��� ������
struct product {
    char* name[100]; //���
    unsigned int price; //����
    char* barcode[100]; //�������� (� ����� ������� �������)
    int sale; //������
};

int main(void) {
    setlocale(LC_ALL, "Rus"); //���������� ������� ����
    char* BARCODE[100];
    float sum = 0;//����� ����� �������
    float sum_with_sale = 0;
    
    struct product* st[100];
    //������ ������ ������� �������������� � ������� � ��������� ���������.������� ��������� �� �����, �� ���-�� �� ����������.
    st[0] = addProduct("���������", 180, "0001",5);
    st[1] = addProduct("���������", 123, "0002",10);
    st[2] = addProduct("�����", 129, "0003",0);
    st[3] = addProduct("����", 121, "0004",15);
    st[4] = addProduct("�������", 128, "0005",0);
    
    int total_number_of_product[10] = {0};//� ������� ����� ��������� ���������� ������� ���������� ������: �� ��������� ���� 
   
    printf("����� ���������� � ��������� '����������� �����'\n");
    view_product_catalog(product_counter, st);//��������� �� ������� ������ �������� � ������� ���  
    
    printf("������� �������� ������\n");
    gets(BARCODE);
    int End_Products; // ����� ��� ������ ����!!!
    char fail[2] = "0";
    End_Products = strncmp(BARCODE, fail, 8);
    while (End_Products != 0) { //�������� ���� �� ����� 0 �� ����� 
        printf("�� ������� %-15s \t  ���� �� ������� %-15d ������ %-8d\t \n ", st[SearchProduct(BARCODE, st)]->name, st[SearchProduct(BARCODE, st)]->price, st[SearchProduct(BARCODE, st)]->sale);
        total_number_of_product[SearchProduct(BARCODE, st)] ++; // � ������ ������� ������ ����������  ����������� ������ ����������� 1

        printf("������� ��������� ��������  ��� 0 ��� ������ ����\n");
        gets(BARCODE);
        End_Products = strncmp(BARCODE, fail, 8);
    }
    //��� ������������� � ��������� �� ������� (��� ��������� � ������ ��� ������) � ���������� � ����� ��������� �� �����.
    printf("��� \n");
    printf("������������ ������  ���� �� ��. ������  ���-�� ��������� �� ������� \n");
    for (int i = 0; i < product_counter; ) {
        
        if (total_number_of_product[i] > 0) {
            float final_price_with_sale = (total_number_of_product[i])*((st[i]->price)*(100-(st[i]->sale))/100);
            printf("%-20s %-20d %-6d %-3f\n", st[i]->name, st[i]->price, total_number_of_product[i],final_price_with_sale);
            i++;
        }
        else {
            i++;
        }
        
        
    }
    //���� ������� ����� ����� ������� ��� ������
    for (int j = 0; j < product_counter; j++) {
        sum = sum + ((total_number_of_product[j]) * (st[j]->price));
    }
    //��� ������� ����� ������� �� �������
    for (int j = 0; j < product_counter; j++) {
        float final_price_with_sale = (total_number_of_product[j]) * ((st[j]->price) * (100 - (st[j]->sale)) / 100);
        sum_with_sale = sum_with_sale + (final_price_with_sale);
    }

    printf("����� ����� ��� ������:%f ���.\n", sum);
    printf("����� ������:%f %%\n", 100-(100*sum_with_sale)/sum);
    printf("���� �� �������:%f ���.\n",sum_with_sale);
    printf("�� �������!");

    //int res;
}


    

struct product* addProduct(char* name, unsigned int price, char* barcode,int sale) {
    struct product* res_st = malloc(sizeof(struct product));//�� ������ ����� ���������� ������!!!
    strcpy_s(res_st->name,30, name);
    res_st->price = price;
    strcpy_s(res_st->barcode, 30, barcode);
    res_st->sale = sale;
    return res_st;
}



//���� ����� ������� �������� �� ��������� ������ ������� � ���������� �����: st[������������ �����] 
//char* SearchProduct(char* BARCODE, const struct product* st[]) ��� ���� ������� ������
int SearchProduct(char* BARCODE,const struct product * st[]) {
    char* selected_product;
    int res;
    int bool = 0;
    while (bool != product_counter) {
        for (int i = 0; i < product_counter; i++) {
            res = strncmp(BARCODE, st[i]->barcode, 8); //���������� char �� ������ 8 �������� !!! �� ������ ��������� ������ 8 ������
            if (res == 0) {
                bool = product_counter;
                return i;//���������� �������� �������� ���������� (����� � ��������)

            }
            if (res != 0) {
                bool++;
            }
        }
        
    }
}

//������� ���������� ����������� ������
void view_product_catalog(unsigned int product_counter, const struct product* st[]) {
    printf("������� ������\n");
    for (int i = 0; i < product_counter; i++) {
        printf("%-12s \t ���� %-5d  \t  �������� %-6s ������  %-2d %% \n", st[i]->name, st[i]->price, st[i]->barcode, st[i]->sale);
    }
}


