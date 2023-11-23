#include "Seqlist.h"
/*维护表头（堆区）*/
Head *creatListHead(int n) {
	Head *listhead;

	listhead = (Head*)malloc(sizeof(Head));	//申请表头
	if (listhead == NULL) {
		fprintf(stderr, "malloc header faild!\n");
		return NULL;
	}

	/*初始化成员*/
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
	if (head) {					//如果seq存在
		if (head->data) {		//防止free(nu
			free(head->data);	//释放整体
		}
		free(head);
	}
}

/*数据操作行为*/
//1.插入行为(尾插法）
void append(Head* list, Element val) {
	//判断溢出
	if (list->len >= list->capacity) {
		//1.申请一块原空间二倍空间
		Element *tmp = malloc(sizeof(Element) * list->capacity * 2);
		if (tmp == NULL) {
			fprintf(stderr, "malloc enlarger failed!\n");
			return -1;
		}
		//2.原空间拷贝新空间
		for (int i = 0; i < list->len; i++){
			tmp[i] = list->data[i];
		}
		free(list->data);
		//3.更新指针空间
		list->capacity *= 2;
		list->data = tmp;
	}
	list->data[list->len] = val;
	list->len++;
}

//3.显示线性表
void ShowList(const Head* list) {
	for (int i = 0; i < list->len; i++) {
		printf("%d\t", list->data[i]);
	}
	printf("\n");
}