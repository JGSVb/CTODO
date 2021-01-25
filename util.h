#include "ctodo.h"

byte val;

static inline void show_bytearr(byte *byte_arr, size_t size){

	for(int i=0; i<size; i++){
		val = byte_arr[i];
		isprint(val) ? printf("%c ", val) : printf("%x ", val);}
	printf("\n");
}

