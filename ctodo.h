#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define SIGNATURE_LEN 8
#define MAX_NAMELEN 32
#define MAX_DESCLEN 1024

#define SIGNATURE "ctodoAlx"
#define VERSION 0x01


union IntByte{
	int64_t integer;
	char bytes[8];
};

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

typedef union TodoByte{
	Todo todo;
	char bytes[sizeof(Todo)];
} TodoByte;

Todo *new_todo(char *name, char *description, uint32_t create_ts, uint16_t deadline){
	Todo *nt = malloc(sizeof(Todo));
	
	strncpy(nt->name, name, sizeof(nt->name));
	strncpy(nt->description, description, sizeof(nt->description));
	nt->create_ts = create_ts;
	nt->deadline = deadline;

	return nt;
};

void header2bytes(char *bytes, Header *header){
}
