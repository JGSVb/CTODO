#include "ctodo.h"


int main(int argc, char **argv){
	// char text[60] = "Eia bué fixe ow mano";
	Todo *todo = new_todo(
		"Grande Todo",
		"Ah pá, sei lá meu\n coloca aqui qualquer coisa que seja porreira",
		time(NULL),
		time(NULL));
	
	TodoByte todobyte;
	todobyte.todo = *todo;
	
	TodoByte todobyte1;
	memcpy(todobyte1.bytes, todobyte.bytes, sizeof(Todo));
	printf("%s", todobyte1.todo.name);
	return 0;
}
