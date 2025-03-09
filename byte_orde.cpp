#include"phc.h"

uint32_t byte_order(uint32_t input)
{
	uint32_t n1, n2, n3, n4;
	n1 = (input & 0xff000000) >> 24;
	n2 = (input & 0x00ff0000) >> 8;
	n3 = (input & 0x0000ff00) << 8;
	n4 = (input & 0x000000ff) << 24;
	return n1 | n2 | n3 | n4;
}
