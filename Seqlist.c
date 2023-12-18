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
/*扩容接口*/
static int EnlargeCapacity(Head* head) {
	//1.开辟备份空间
	Element* tmp = malloc(sizeof(Element) * head->capacity * 2);
	if (tmp == NULL) {
		fprintf(stderr, "malloc tmp error!\n");
		return -1;
	}
	//2.备份
	for (int i = 0; i < head->len; i++) {
		tmp[i] = head->data[i];
	}
	free(head->data);
	//3.重做data
	head->data = tmp;
	head->capacity *= 2;
	return 0;
}

/*数据操作行为*/
//1.插入行为(尾插法）
void append(Head* head, Element val) {
	//判断溢出
	if (head->len >= head->capacity) {
		EnlargeCapacity(head);
	}
	head->data[head->len] = val;
	head->len++;
}

//2.任意位置插入
int insert(Head* head, int pos, Element val) {
	//1.范围校验
	if (pos < 0 || pos > head->len) {
		printf("pos invalid!\n");
		return -1;
	}
	//2.扩容
	if (head->len >= head->capacity && EnlargeCapacity(head)) {
		return -1; 
	}
	//3.从后往前遍历拷贝元素
	for (int i = head->len - 1; i >= pos; i--) {
		head->data[i + 1] = head->data[i];
	}
	//4.放入新元素
	head->data[pos] = val;
	head->len++;
}

//3.显示线性表
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

//4.删除
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

//5.查找
int find(Head *head, int val) {
	//遍历
	for (int i = 0; i < head->len; i++) {
		if (head->data[i] == val) {
			return i;
		}
	}
	return -1;
}