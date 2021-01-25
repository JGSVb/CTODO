#include "ctodo.h"

#define SIGNATURE_LEN 8
#define MAX_NAMELEN 32
#define MAX_DESCLEN 1024
#define KEY_HASH_LEN 60
#define MAX_TODOCOUNT sizeof(uint8_t)

#define SIGNATURE "ctodoAlx"
#define VERSION 0x01


typedef struct Header{
	byte signature[SIGNATURE_LEN];
	uint16_t version;
	byte name[MAX_NAMELEN];
	byte description[MAX_DESCLEN];
	byte todo_count;
	uint32_t create_ts;
	uint32_t change_ts;
	byte keyhash[KEY_HASH_LEN]; // Key hash should be bcrypt
	bool encrypted;
} Header;

typedef struct Todo{
	byte name[MAX_NAMELEN];
	byte description[MAX_DESCLEN];
	uint32_t create_ts;
	uint32_t deadline;
} Todo;

typedef struct File{
	Header header;
	Todo *todos;
} File;


typedef union HeaderByte{
	Header header;
	byte byte_arr[sizeof(Header)];
} HeaderByte;

typedef union TodoByte{
	Todo todo;
	byte byte_arr[sizeof(Todo)];
} TodoByte;


Todo *new_todo(char *name, char *description, uint32_t create_ts, uint16_t deadline){
	Todo *nt = malloc(sizeof(Todo));
	
	strncpy(nt->name, name, MAX_NAMELEN);
	strncpy(nt->description, description, MAX_DESCLEN);
	nt->create_ts = create_ts;
	nt->deadline = deadline;

	return nt;
};

Header *new_header(char *name, char *description, char todo_count, uint32_t create_ts, uint32_t change_ts, byte *keyhash, bool encrypted){
	Header *nh = malloc(sizeof(Header));
	
	strncpy(nh->signature, SIGNATURE, SIGNATURE_LEN);
	nh->version = VERSION;
	strncpy(nh->name, name, MAX_NAMELEN);
	strncpy(nh->description, description, MAX_DESCLEN);
	nh->todo_count = todo_count;
	nh->create_ts = create_ts;
	nh->change_ts = change_ts;
	strncpy(nh->keyhash, keyhash, KEY_HASH_LEN);
	nh->encrypted = encrypted;

	return nh;
}

File *new_file(Header *header){
	File *nf = malloc(sizeof(File));
	nf->todos = malloc(header->todo_count * sizeof(Todo));
	nf->header = *header;

	return nf;
}

byte *file2bytearr(File *file){
	// Start encoding the todo
	TodoByte tbt;
	HeaderByte hbt; hbt.header = file->header;
	int todocnt = file->header.todo_count;

	byte *btds = malloc((todocnt) * sizeof(Todo));
	byte *res = malloc(todocnt * sizeof(Todo) + sizeof(Header));

	for(int i=0; i<todocnt; i++){
		tbt.todo = file->todos[i];
		// Appends a todo bytes value to the todo bytes array
		memcpy(&btds[sizeof(Todo)*i], tbt.byte_arr, sizeof(Todo));
		// memcpy(&btds[sizeof(Todo)*i], file->todos[i], sizeof(Todo));
	}

	memcpy(res, hbt.byte_arr, sizeof(Header));
	memcpy(&res[sizeof(Header)], btds, sizeof(Todo)*todocnt);
	
	return res;
}

File *bytearr2file(byte *byte_arr){
	File *nf = malloc(sizeof(File));

	Header *header = malloc(sizeof(Header));
	memcpy(header, byte_arr, sizeof(Header));


	return nf;
}

