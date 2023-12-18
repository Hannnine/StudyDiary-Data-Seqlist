#include "Seqlist.h"
int main() {
	Head* list = creatListHead(10);
	
	for (int i = 0; i < 3; i++) {
		insert(list, 0, i+1);
	}

	insert(list, 2, 500);
	ShowList(list);

	remove(list, 500);
	ShowList(list);


	releaseListHead(list);
	return 0;
}