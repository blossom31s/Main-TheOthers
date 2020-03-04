#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class ChangeToTheNextLine
{
private:
    string _str;
    int _strLength = 0;
    int _preLength = 0;
    int _restLength = 0;
public:
    ChangeToTheNextLine();
    ~ChangeToTheNextLine();
    void NextLine(const int& lineLength, string& str);
};

int main(void)
{
    ChangeToTheNextLine tester;
    string str = "Software      that works.";

    tester.NextLine(8, str);
    // tester.NextLine(20, str);
    // tester.NextLine(5, str);
    // tester.NextLine(4, str);

    return 0;
}

ChangeToTheNextLine::ChangeToTheNextLine() { }
ChangeToTheNextLine::~ChangeToTheNextLine() { }

void ChangeToTheNextLine::NextLine(const int& lineLength, string& str)
{
    _str = str;
    _restLength = lineLength;

    cout << "Input :" << endl << lineLength << endl << str << endl;
    cout << "==============================" << endl;
    cout << "Output :" << endl;

    char *strC = new char[100];
    strcpy(strC, str.c_str());
    char *subStr = strtok(strC, " ");
    for(int i=0 ; subStr!=NULL ; ++i)
    {
        _strLength = strlen(subStr);

        if(_strLength < _restLength)
        {
            cout << subStr << " ";
        }
        else if(_strLength > lineLength)
        {
            for(int j=0 ; j<lineLength ; ++j) cout << subStr[j];
            cout << endl;
            for(int j=lineLength ; j<_strLength ; ++j) cout << subStr[j];
            cout << endl;
        }
        else if(_strLength < lineLength)
        {
            if((i != 0) && (_preLength % lineLength == 0)) cout << " " << subStr << endl;
            else cout << subStr << endl;
        }
        else
        {
            if(i == 0) cout << subStr << endl;
            else if(_preLength % lineLength == 0) cout << endl << subStr << endl << endl;
            else cout << subStr << endl;
        }

        _preLength = _strLength;
        _restLength -= _strLength;
        subStr = strtok(NULL, " ");
    }

    cout << endl << "==============================" << endl;
}
