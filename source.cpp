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
		char* str = argv[i];
		FILE* bin_file = fopen(str, "rb");

		if(bin_file == NULL)
		{
			printf("file is not exist\n");
			return 1;
		}

		uint32_t* res = (uint32_t *)malloc(sizeof(uint32_t));
		if(res == NULL)
		{
			printf("malloc fail\n");
			fclose(bin_file);
			return 1;
		}

		size_t read = fread(res, sizeof(uint32_t), 1, bin_file);
		if(read != 1)
		{
			printf("read failed\n");
			free(res);
			fclose(bin_file);
			return 1;
		}

		uint32_t n1, n2, n3, n4, n;
		n1 = (*res & 0xff000000) >> 24;
		n2 = (*res & 0x00ff0000) >> 8;
		n3 = (*res & 0x0000ff00) << 8;
		n4 = (*res & 0x000000ff) << 24;
		n = n1 | n2 | n3 | n4;

		printf("%d(0x%08x) ", n, n);
		if(i - 1 != argc - 2)
			printf("+ ");
		sum += n;

		free(res);
		fclose(bin_file);
	}
	printf("= %d(0x%08x)\n", sum, sum);
	return 0;
}
