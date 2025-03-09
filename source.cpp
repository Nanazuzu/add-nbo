#include"phc.h"

int main(int argc, char* argv[])
{
	if(argc < 2)
	{
		printf("input error\n");
		return 1;
	}

	uint32_t sum = 0x00;
	for(int i = 1; i < argc; i++)
	{
		uint32_t input_num = file_handler(argv[i]);
		uint32_t ordered_num = byte_order(input_num);
		printf("%d(0x%08x) ", ordered_num, ordered_num);
		if(i - 1 != argc - 2)
			printf("+ ");
		sum += ordered_num;
	}
	printf("= %d(0x%08x)\n", sum, sum);
	return 0;
}
