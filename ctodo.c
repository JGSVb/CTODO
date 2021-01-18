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
	
	TodoFile *todofile = create_todo_file(SIGNATURE, VERSION, "grandes todos bué nices", time(NULL), time(NULL));
	
	// todofile->todos[0] = todo;
	printf("%s", (char *) todofile);
	TodoFile *other_file = malloc(sizeof(TodoFile));
	read_todo_file("/home/asv/Scripts/Todo/testfile.ctodo", other_file);
	save_todo_file("/home/asv/Scripts/Todo/testfile.ctodo", todofile);

	return 0;
}
