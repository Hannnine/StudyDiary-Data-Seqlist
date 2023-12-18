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
/*���ݽӿ�*/
static int EnlargeCapacity(Head* head) {
	//1.���ٱ��ݿռ�
	Element* tmp = malloc(sizeof(Element) * head->capacity * 2);
	if (tmp == NULL) {
		fprintf(stderr, "malloc tmp error!\n");
		return -1;
	}
	//2.����
	for (int i = 0; i < head->len; i++) {
		tmp[i] = head->data[i];
	}
	free(head->data);
	//3.����data
	head->data = tmp;
	head->capacity *= 2;
	return 0;
}

/*���ݲ�����Ϊ*/
//1.������Ϊ(β�巨��
void append(Head* head, Element val) {
	//�ж����
	if (head->len >= head->capacity) {
		EnlargeCapacity(head);
	}
	head->data[head->len] = val;
	head->len++;
}

//2.����λ�ò���
int insert(Head* head, int pos, Element val) {
	//1.��ΧУ��
	if (pos < 0 || pos > head->len) {
		printf("pos invalid!\n");
		return -1;
	}
	//2.����
	if (head->len >= head->capacity && EnlargeCapacity(head)) {
		return -1; 
	}
	//3.�Ӻ���ǰ��������Ԫ��
	for (int i = head->len - 1; i >= pos; i--) {
		head->data[i + 1] = head->data[i];
	}
	//4.������Ԫ��
	head->data[pos] = val;
	head->len++;
}

//3.��ʾ���Ա�
void ShowList(const Head* head) {
	printf("[");
	for (int i = 0; i < head->len; i++) {
		printf("%d", head->data[i]);
		if (i != head->len - 1)
			printf(",");
	}
	printf("]");
	printf("\n");
}

//4.ɾ��
int remove(Head* head, Element val) {
	int pos = find(head, val);
	if (pos < 0) {
		printf("No find!\n");
		return -1;
	}
	for (int i = pos; i < head->len; i++) {
		head->data[i] = head->data[i + 1];
	}
	head->len--;
	return 0;
}

//5.����
int find(Head *head, int val) {
	//����
	for (int i = 0; i < head->len; i++) {
		if (head->data[i] == val) {
			return i;
		}
	}
	return -1;
}