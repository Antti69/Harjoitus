#include "Rng.h"

int Rng1::CreateInt(int min, int max, bool NormalDistr)
{
	int range = max - min + 1;
	uint64_t out = rg();
	if (range == 0)
	{
		out = 0;
	}
	else
	{
		if (NormalDistr)
		{
			range *= 2;
		}
		out %= range;
		if (out > max)
		{
			out /= 3;
		}
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

std::string Rng1::CreateString(int lenght)
{
	std::string out;
	for (int i = 0; i < lenght; i++)
	{
		char c = CreateChar();
		out.push_back(c);
	}
	return out;
}

void Rng1::ReSeed()
{
	seed = (unsigned int)std::chrono::high_resolution_clock::now().time_since_epoch().count();
	rg.seed(seed);
}