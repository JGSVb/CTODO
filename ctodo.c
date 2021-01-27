#include "file.h"
#include "util.h"

#define TESTING true
	
#if TESTING
	void main_test(void){
		Todo *todo1 = new_todo(
			"Grande Todo",
			"Ah pá, sei lá meu\n coloca aqui qualquer coisa blablabla queijo é bué bom :sunglasses:",
			NOWTS,
			NOWTS);
	
		Header *header = new_header(
			"grandes todos bué fixes",
			"coloca-se aqui qualquer coisa que também serve",
			1,
			NOWTS,
			NOWTS,
			"Hash bué seguro pessoal",
			false);
		
		File *file1 = new_file(header);
		file1->todos[0] = *todo1;
	
		byte *filebytes = file2bytearr(file1);
		File *file2 = bytearr2file(filebytes);
	
		print_bytearr(filebytes, sizeof(Todo)*file1->header.todo_count + sizeof(Header));
	}
#else
	#define main_test() NULL
#endif

int main(int argc, char **argv){

	main_test();


	return 0;
}
