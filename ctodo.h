#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stdint.h>
#include <string.h>

#define MAX_NAMESIZE 64
#define MAX_DESCSIZE 1024
#define MAX_TODOS 128
#define VERSION 1
#define SIGNATURE "ctodo"


typedef struct Todo{
	char name[MAX_NAMESIZE];
	char description[MAX_DESCSIZE];
	uint64_t create_ts; // When was todo created
	uint64_t deadline; // Deadline of the todo
} Todo;

typedef struct TodoFile{
	short int version;
	char signature[5];

	char filename[MAX_NAMESIZE];

	uint64_t create_ts; // When was file created
	uint64_t change_ts; // Last change on file
	bool encrypted;
	char rawdata[];
} TodoFile;

int save_todo_file(const char *filename, TodoFile *todofile){
	FILE *fp;
	
	fp = fopen(filename, "w");
	ftruncate(fileno(fp), 0);
	
	fwrite(&todofile, sizeof(TodoFile), 1, fp);

	fclose(fp);

	return 0;
}


void serealize_todofile(char *dest, TodoFile *source){
	dest;
}
