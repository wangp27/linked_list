#include <stdlib.h>

#include "list.h"

void destory (void *data){
	free(data);
	return;
}

int main( int argc, char* argv[]){
	List *test_list;
	ListElmt *test_elmt;
	int a = 2;
	test_elmt->data = &a;
	list_init(test_list, destory);
	list_ins_next(test_list,test_elmt,&a);
}
