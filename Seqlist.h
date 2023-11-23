#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct  Head;

/*顺序表表头*/
typedef int Element;
typedef struct {
	Element* data;	//数据区域（从哪到哪）
	int capacity;	//容量
	int len;		//操作指针，插入索引号
}Head;

/*维护表头（堆区）*/
Head *creatListHead(int n);	//创建表头，初始化数据域
void releaseListHead(Head* listhead);	//释放表

/*数据操作行为*/
//1.插入行为(尾插法）
void append(Head* head, Element val);
//2.任意位置插入
int insert(Head* head, int n);

//3.显示线性表
void ShowList(const Head* list);