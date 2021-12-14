#include "MathUtils.h"
#include <string>
#include <assert.h>
#include <regex>
struct token {
	int type;
	string str;
	token(int t, string s) : type(t), str(s) {}
};
vector<token> tokens;
struct rule {
	regex re;
	int token_type;
} rules[] = {
	{regex("-?[0-9]+[+-]-?[0-9]+i"),	256},
	{regex("\\+"),						'+'}, 
	{regex("-"),						'-'}, 
	{regex("\\*"), 						'*'},
	{regex("/"),						'/'}, 
	{regex("\\("),						'('}, 
	{regex("\\)"),						')'}
};
#define NR_REGEX (sizeof(rules) / sizeof(rules[0]))
bool preCheckParentheses(int l, int r)
{
	int p = 0;
	for (int i = l; i <= r; i++)
	{
		p += tokens[i].type == '(' ? 1 : (tokens[i].type == ')' ? -1 : 0);
		if (p < 0)
			return 0;
	}
	return p == 0;
}
bool checkParentheses(int l, int r)
{
	if (preCheckParentheses(l, r))
		return (tokens[l].type == '(' && tokens[r].type == ')') ? preCheckParentheses(l + 1, r - 1) : 0;
    assert(0);
}
int find_op(int l, int r)		// 返回不在括号内的、尽量靠后的、优先级尽量低的运算符的下标
{
	int op = r, p = 0;
	for (int i = r; i >= l; i--)
	{
		int t = tokens[i].type;
		p += t == '(' ? 1 : (t == ')' ? -1 : 0);
		if (p == 0)
		{
			if (t == '+' || t == '-')
				return i;
			if ((t == '*' || t == '/') && op == r)
				op = i;
		}
	}
	return op;
}
Complex stoc(string s)
{
	stringstream ss(s);
	int real, imag;
	char op;
	ss >> real >> op >> imag;
	return Complex(real, imag * (op == '+' ? 1 : -1));
}
Complex eval(int l, int r)
{
	if (l > r)
		return Complex(0, 0);
	else if (l == r)
		return stoc(tokens[l].str);	
	else if (checkParentheses(l, r) == 1)
		return eval(l + 1, r - 1);
	else
	{
		int op = find_op(l, r);
		Complex val1 = eval(l, op - 1);
		Complex val2 = eval(op + 1, r);
		switch (tokens[op].type)
		{
			case '+':
				return val1 + val2;
			case '-':
				return val1 - val2;
			case '*':
				return val1 * val2;
			case '/':
				return val1 / val2;
			default:
				assert(0); 
		}
	}
}
Complex MathUtils::calculator(string s)
{
	string backup = s;
	tokens.clear();
	regex space(" +");	
	s = regex_replace(s, space, "");
	smatch res;
	while (s.size())
	{
		bool flag = false;
		for (auto & r : rules)
			if (regex_search(s, res, r.re))
			{
				if (res.position(0))
					continue;
				tokens.push_back(token(r.token_type, res[0]));
				flag = true;
				break;
			}
		if (flag == false)
		{
			cout << "No match for " << backup << endl;
			exit(0);
		}
		s = s.substr(res[0].length());
	}
    return eval(0, tokens.size() - 1);
}