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
	uint64_t deadline_ts; // Deadline of the todo
} Todo;

typedef struct TodoFile{
	char signature[5];
	short int version;

	char name[MAX_NAMESIZE];

	uint64_t create_ts; // When was file created
	uint64_t change_ts; // Last change on file
	// bool encrypted; // Maybe in the future
	// char rawdata[sizeof(Todo) * MAX_TODOS];
	Todo todos[MAX_TODOS];
} TodoFile;


int save_todo_file(const char *filename, TodoFile *todofile){
	FILE *fp;
	
	fp = fopen(filename, "wb");
	ftruncate(fileno(fp), 0);
	
	fwrite(&todofile, sizeof(TodoFile), 1, fp);

	fclose(fp);

	return 0;
}

int read_todo_file(const char *filename, TodoFile *todofile){
	FILE *fp;

	fp = fopen(filename, "rb");
	fread(&todofile, sizeof(TodoFile), 1, fp);
	fclose(fp);

	return 0;
}

TodoFile *create_todo_file(char *signature, short int version, char *name, uint64_t create_ts, uint64_t change_ts){

	TodoFile *tf = malloc(sizeof(TodoFile));
	// TodoFile *tf;

	strcpy(tf->signature, signature);
	tf->version = version;
	strcpy(tf->name, name);
	tf->change_ts = change_ts;
	tf->create_ts = create_ts;
	// strcpy(tf->rawdata, rawdata);

	return tf;
}
