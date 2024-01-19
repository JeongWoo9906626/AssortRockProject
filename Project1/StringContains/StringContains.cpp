#include <iostream>
#include <cassert>

int StringCount(const char* const _Text)
{
	int Count = 0;
	if (nullptr == _Text)
	{
		return Count;
	}
	while (_Text[Count] != 0)
	{
		++Count;
	}
	return Count;
}

// Q1
enum class StringReturn
{
	Equal,	// 0
	NotEqual	// 1
};

StringReturn StringEqual(const char* const _Left, const char* const _Right)
{
	int LeftLength = StringCount(_Left);
	int RightLength = StringCount(_Right);

	if (LeftLength != RightLength)
	{
		return StringReturn::NotEqual;
	}

	for (int i = 0; i < LeftLength; i++)
	{
		if (_Left[i] != _Right[i])
		{
			return StringReturn::NotEqual;
		}
	}

	return StringReturn::Equal;
}

void StringAdd(char* _Dest, const char* const _Left, const char* const _Right)
{
	int LeftLength = StringCount(_Left);
	int RightLength = StringCount(_Right);

	int TotalLength = LeftLength + RightLength;

	for (int i = 0; i < TotalLength; i++)
	{
		if (i < LeftLength)
		{
			_Dest[i] = _Left[i];
		}
		else
		{
			_Dest[i] = _Right[i - LeftLength];
		}
	}
}

// Q2
int StringContains(const char* const _Dest, const char* const _Find)
{
	int Count = 0;
	
	int DestLength = StringCount(_Dest);
	int FindLength = StringCount(_Find);

	if (DestLength == 0)
	{
		printf_s("원본 데이터가 없습니다.\n");
		assert(nullptr);
	}

	if (FindLength == 0)
	{
		printf_s("찾을 데이터가 없습니다.\n");
		assert(nullptr);
	}

	for (int i = 0; i < DestLength; i++)
	{
		int IndexCount = 0;
		while (true)
		{
			if (_Dest[i + IndexCount] == _Find[IndexCount])
			{
				++IndexCount;
			}
			else
			{
				break;
			}

			if (IndexCount == FindLength)
			{
				++Count;
				break;
			}
		}
	}
	return Count;
}

int main()
{
	{
		StringEqual("AAAA", "AAAA");

		int a = 0;
	}

	{
		char Arr[100] = {};
		StringAdd(Arr, "abcd", "efghi");
		// Arr = "cccccddddd";

		int a = 0;
	}

	{
		int Result = StringContains("ababcccccabab", "ab");
		// Result = 4;
		int Result2 = StringContains("ababcccccabab", "c");
		// Result = 5;

		int a = 0;
	}
}