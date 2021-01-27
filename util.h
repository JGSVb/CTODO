#include "ctodo.h"

static inline void print_bytearr(byte *byte_arr, size_t size){
	for(int i=0; i<size; i++)
		isprint(byte_arr[i]) ? printf("%c ", byte_arr[i]) : printf("%x ", byte_arr[i]);
	printf("\n");
}

