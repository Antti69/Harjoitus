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
		out %= range;
		out += min;
	}
	NormalDistProbabilityRange r = GetRange((int)out, range);
	if (!NormalDistr || r == NormalDistProbabilityRange::HighProbability || countertest >= 2)
	{
		return (int)out;
	}
	else if (r == NormalDistProbabilityRange::MediumProbability)
	{
		countertest += 2;
		CreateInt(min, max, true);
	}
	else if (r == NormalDistProbabilityRange::LowProbability)
	{
		countertest++;
		CreateInt(min, max, true);
	}
	countertest = 0;
	return (int)out;

	//int out = GetRandomNumber(min, max);
	//int range = max - min + 1;
	//if (!NormalDistr)
	//{
	//	return out;
	//}
	//else
	//{
	//	NormalDistProbabilityRange r = GetRange(out, range);
	//	if (r == NormalDistProbabilityRange::HighProbability)
	//	{
	//		return out;
	//	}
	//	else
	//	{
	//		int counter = 0;
	//		switch (r)
	//		{
	//		case NormalDistProbabilityRange::MediumProbability:
	//			counter = 2;
	//			break;
	//		case NormalDistProbabilityRange::LowProbability:
	//			counter = 3;
	//			break;
	//		}
	//		for (int i = 0; i < counter; i++)
	//		{
	//			out = GetRandomNumber(min, max);
	//		}

	//	}

	//}
	//return out;
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

int Rng1::GetRandomNumber(int min, int max)
{
	//bool NormalDistr = false;
	//int range = max - min + 1;
	//uint64_t out = rg();
	//if (range == 0)
	//{
	//	out = 0;
	//}
	//else
	//{
	//	out %= range;
	//	out += min;
	//}
	//NormalDistProbabilityRange r = GetRange((int)out, range);
	//if (!NormalDistr || r == NormalDistProbabilityRange::HighProbability || countertest >= 4)
	//{
	//	return (int)out;
	//}
	//else if (r == NormalDistProbabilityRange::MediumProbability)
	//{
	//	countertest += 2;
	//	GetRandomNumber(min, max);
	//}
	//else if (r == NormalDistProbabilityRange::LowProbability)
	//{
	//	countertest++;
	//	GetRandomNumber(min, max);
	//}
	//countertest = 0;
	//return (int)out;
	return 0;
}

Rng1::NormalDistProbabilityRange Rng1::GetRange(int num, int range)
{
	NormalDistProbabilityRange r = NormalDistProbabilityRange::Invalid;
	int mid = range / 2;
	int highrange = range / 5;
	int mediumrange = (range / 5) * 2;

	if (num >= mid - highrange && num <= mid + highrange)
	{
		r = NormalDistProbabilityRange::HighProbability;
	}
	else if ((num > mid - mediumrange && num < mid - highrange) || (num > mid + highrange && num < mid + mediumrange))
	{
		r = NormalDistProbabilityRange::MediumProbability;
	}
	else if (num <= mid - mediumrange || num >= mid + mediumrange)
	{
		r = NormalDistProbabilityRange::LowProbability;
	}


	return r;
}
