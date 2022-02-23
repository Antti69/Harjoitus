#include "Rng.h"

int Rng1::CreateInt(int min, int max)
{
	int range = max - min + 1;
	uint64_t out = rg();
	if (range == 0)
	{
		out = 0;
	}
	else
	{
		out %= range;
		out += min;
	}
	return (int)out;
}

float Rng1::CreateFloat(float min, float max) 
{
	float out = 0.0f;
	float range = max - min;
	float decimals = 0.0f;
	int firstnum = CreateInt(0, (int)range);
	float decimalrange = std::modff(range, &decimalrange);
	decimalrange *= 100.0f;
	int floatnumb = CreateInt(0, (int)decimalrange);
	if (floatnumb != 0)
	{
		decimals = (float)floatnumb / 100.0f;
	}
	out = firstnum + decimals + min;

	return out;
}

unsigned char Rng1::CreateChar()
{
	int random = CreateInt(33, 129);
	if (random == 126)
	{
		random = 132;
	}
	else if (random == 127)
	{
		random = 142;
	}
	else if (random == 128)
	{
		random = 149;
	}
	else if (random == 129)
	{
		random = 153;
	}
	unsigned char out = random;
	return out;
}
