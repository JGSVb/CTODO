#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define SIGNATURE_LEN 8
#define MAX_NAMELEN 32
#define MAX_DESCLEN 1024

#define SIGNATURE "ctodoAlx"
#define VERSION 0x01

typedef struct Header{
	char signature[SIGNATURE_LEN];
	uint16_t version;
	char name[MAX_NAMELEN];
	char description[MAX_DESCLEN];

	char todo_count;
	uint32_t create_ts;
	uint32_t change_ts;
	bool encrypted;
} Header;

typedef struct Todo{
	char name[MAX_NAMELEN];
	char description[MAX_DESCLEN];
	uint32_t create_ts;
	uint32_t deadline;
} Todo;

typedef struct File{
	Header header;
	Todo *todos;
} File;


/*Writes a numeric value to a char with its bytes*/
void num2bytes(char *bytes, int64_t value, size_t size){
	for(int i=0; i<size; i++)
		bytes[i] = value>>8*i & 0xFF;
}
/*Writes a numeric value from bytes*/
void bytes2num(char *bytes, int64_t *dest, size_t size){
	for(int i=0; i<size; i++)
		*dest += bytes[i] << 8*(i-size);
}

