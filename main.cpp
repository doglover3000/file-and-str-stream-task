#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
int fpos = 0, loop = 0;
string str, word;
char S;
cout << "Enter search word: ";
cin >> word;
ifstream in("in.txt");
if (in)
{
in.unsetf(ios::skipws); //считывание с игнорированием пробелов, табуляций и пр.
while (in >> S)
{
str += S;
if (S == '.' || S == '!' || S == '?')
{
fpos = str.find(word);
if (loop == 0)
{
if (string::npos != fpos && !isalpha(str[fpos + word.length()]))
{
cout << loop + 1 << ") ";
cout << str << endl;
loop++;
}
}
else
{
if (string::npos != fpos && !isalpha(str[fpos - 1]) && !isalpha(str[fpos + word.length()]))
{
cout << loop + 1 << ") ";
str.substr(1, str.length()-1); // удаление "лишнего" пробела перед предложением
cout << str << endl;
loop++;
}
}
str.clear();
}
}
}
else
cout << "Can't open file!\n";
if (!loop)
cout << "Not found!\n";
in.close();
return 0;
}
