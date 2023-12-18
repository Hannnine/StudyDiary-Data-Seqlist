#pragma once
#include <stdio.h>
#include <stdlib.h>

/*˳����ͷ*/
typedef int Element;
typedef struct {
	Element* data;	//�������򣨴��ĵ��ģ�
	int capacity;	//����
	int len;		//����ָ�룬����������
}Head;

/*ά����ͷ��������*/
Head *creatListHead(int n);	//������ͷ����ʼ��������
void releaseListHead(Head* listhead);	//�ͷű�

/*���ݲ�����Ϊ*/
//1.������Ϊ(β�巨��
void append(Head* head, Element val);
//2.����λ�ò���
int insert(Head* head, int pos, Element val);
//3.��ʾ���Ա�
void ShowList(const Head* list);
//4.ɾ��
int remove(Head* head, int pos);
//5.����
int find(Head* head, int val);