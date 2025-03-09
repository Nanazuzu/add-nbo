#include"phc.h"

uint32_t file_handler(char* argv)
{
	FILE* bin_file = fopen(argv, "rb");

	if(bin_file == NULL)
	{
		printf("file is not exist\n");
		return -1;
	}

	uint32_t res;
	size_t read = fread(&res, sizeof(uint32_t), 1, bin_file);
	if(read != 1)
	{
		printf("read failed\n");
		fclose(bin_file);
		return -1;
	}

	fclose(bin_file);
	return res;
}
