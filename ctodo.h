#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MAX_NAMESIZE 64
#define MAX_DESCSIZE 1024
#define MAX_TODOS 128
#define VERSION 1
#define SIGNATURE "ctodo"

struct Todo{
	char name[MAX_NAMESIZE];
	char description[MAX_DESCSIZE];
	unsigned long int create_ts; // When was todo created
	unsigned long int deadline; // Deadline of the todo
};

typedef struct TodoFile{
	short int version;
	char signature[5];

	char tablename[MAX_NAMESIZE];

	long unsigned int create_ts; // When was file created
	long unsigned int change_ts; // Last change on file
	bool encrypted;
	char *rawdata;
};

int save_todo_file(const char *filename, struct TodoFile *todofile){
	FILE *fp;
	
	fp = fopen(filename, "w");
	ftruncate(fileno(fp), 0);
	
	fwrite(&todofile, sizeof(struct TodoFile), 1, fp);

	fclose(fp);

	return 0;
}
