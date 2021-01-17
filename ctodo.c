#include "ctodo.h"

int main(int argc, char **argv){
	
	struct Todo todo = {
		"Sei lá meu",
		"eia bueda fixe ow man",
		(unsigned long int)time(NULL),
		(unsigned long int)0
	};

	char *todo_char;
	todo_char = (char *) &todo;

	struct TodoFile todofile = {
		VERSION,
		SIGNATURE,
		"Grandes todos bue fixes",
		(u_int32_t)time(NULL),
		(u_int32_t)time(NULL),
		false,
		todo_char
	};

	save_todo_file("/home/asv/Scripts/Todo/testfile.ctodo", (struct TodoFile *) *todofile);
	return 0;
}
