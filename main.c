#include "Seqlist.h"
int main() {
	Head* list = creatListHead(10);
	
	for (int i = 0; i < 3; i++) {
		append(list, 3);
	}

	ShowList(list);
	
	releaseListHead(list);
	return 0;
}