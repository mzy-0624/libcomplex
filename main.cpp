#include "MathUtils.h"
#include "Complex.h"
#include <string>
#include <regex>
using namespace std;
int main(void)
{
	string str;
	while (getline(cin, str))
	{
		if (str == "q")
			return 0;
		cout << MathUtils::calculator(str) << endl;
	}
	return 0;
}