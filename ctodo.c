#include "ctodo.h"

int main(int argc, char **argv){
	int num = 4354;
	int num2;
	char *bytes = malloc(sizeof(int));

	num2bytes(bytes, num, sizeof(int));
	bytes2num(bytes, &num2, sizeof(int));
	printf("%d\n", num);
	printf("%d\n", num2);

	return 0;
}
