#include "ctodo.h"

int main(int argc, char **argv){
	
	Todo todo = {
		"Sei lá meu",
		"eia bueda fixe ow man",
		(uint64_t)time(NULL),
		(uint64_t)0
	};

	char *todo_char;
	todo_char = (char *) &todo;
	
	TodoFile *todofile = malloc(sizeof(todofile) + sizeof(char [strlen(todo_char)]));
	/*	
	todofile->version = VERSION;
	todofile->signature = SIGNATURE;
	todofile->filename = "Grandes todos bue fixes";
	todofile->create_ts = (uint64_t)time(NULL);
	todofile->change_ts = (uint64_t)time(NULL);
	todofile->encrypted = false;
	todofile->rawdata = todo_char;
	*/
	
	*todofile = {
		VERSION,
		SIGNATURE,
		"Grandes todos bué fixes",
		(uint64_t)time(NULL),
		(uint64_t)time(NULL),
		false,
		todo_char
	};
	

	printf("%lu", sizeof(todo));
	//save_todo_file("/home/asv/Scripts/Todo/testfile.ctodo", (TodoFile *) &todofile);

	return 0;
}
