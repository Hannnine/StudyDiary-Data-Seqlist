#include "Seqlist.h"
/*ά����ͷ��������*/
Head *creatListHead(int n) {
	Head *listhead;

	listhead = (Head*)malloc(sizeof(Head));	//�����ͷ
	if (listhead == NULL) {
		fprintf(stderr, "malloc header faild!\n");
		return NULL;
	}

	/*��ʼ����Ա*/
	listhead->data = (Element*)malloc(sizeof(Element) * n);
	if (listhead->data == NULL) {
		fprintf(stderr, "malloc data faild!\n");
		free(listhead);
		return NULL;
	}
	listhead->capacity = n;
	listhead->len = 0;

	return listhead;
}

void releaseListHead(Head* head) {
	if (head) {					//���seq����
		if (head->data) {		//��ֹfree(nu
			free(head->data);	//�ͷ�����
		}
		free(head);
	}
}

/*���ݲ�����Ϊ*/
//1.������Ϊ(β�巨��
void append(Head* list, Element val) {
	//�ж����
	if (list->len >= list->capacity) {
		//1.����һ��ԭ�ռ�����ռ�
		Element *tmp = malloc(sizeof(Element) * list->capacity * 2);
		if (tmp == NULL) {
			fprintf(stderr, "malloc enlarger failed!\n");
			return -1;
		}
		//2.ԭ�ռ俽���¿ռ�
		for (int i = 0; i < list->len; i++){
			tmp[i] = list->data[i];
		}
		free(list->data);
		//3.����ָ��ռ�
		list->capacity *= 2;
		list->data = tmp;
	}
	list->data[list->len] = val;
	list->len++;
}

//3.��ʾ���Ա�
void ShowList(const Head* list) {
	for (int i = 0; i < list->len; i++) {
		printf("%d\t", list->data[i]);
	}
	printf("\n");
}