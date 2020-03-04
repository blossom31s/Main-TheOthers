#include <iostream>
#include <string>
#include <string.h>
using namespace std;

class ChangeToTheNextLine
{
private:
    string _str; // 입력받은 문자열을 저장하기 위한 변수
    int _strLength = 0; // 현재 부분문자열(스페이스 공백으로 나누어지는 전체 문자열의 일부분)의 길이를 저장하기 위한 변수
    int _preLength = 0; // 이전 부분문자열의 길이를 저장하기 위한 변수
    int _restLength = 0; // 한 줄에서 부분문자열을 기록하고 남은 부분의 길이를 저장하기 위한 변수
public:
    ChangeToTheNextLine(); // 생성자
    ~ChangeToTheNextLine(); // 소멸자
    void NextLine(const int& lineLength, string& str); // 줄 바꿈 함수
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
    _str = str; // 입력받은 문자열을 저장함
    _restLength = lineLength; // 입력받은 문자열의 길이를 저장함

    cout << "Input :" << endl << lineLength << endl << str << endl;
    cout << "==============================" << endl;
    cout << "Output :" << endl;

    char *strC = new char[100]; // 입력받은 C++스타일의 문자열을 C스타일의 문자열로 변환하기 위한 변수
    strcpy(strC, str.c_str()); // 입력받은 C++스타일의 문자열을 C스타일의 문자열로 변환(복사)
    char *subStr = strtok(strC, " "); // 부분문자열을 C스타일로 저장하기 위한 변수
    for(int i=0 ; subStr!=NULL ; ++i)
    {
        _strLength = strlen(subStr); // 부분문자열의 길이를 저장함

        if(_strLength < _restLength) // 부분문자열의 길이가 한 줄의 남은 부분보다 작은 경우
        {
            cout << subStr << " ";
        }
        else if(_strLength > lineLength) // 부분문자열의 길이가 한 줄의 길이보다 긴 경우
        {
            for(int j=0 ; j<lineLength ; ++j) cout << subStr[j]; // 한 줄의 길이만큼 문자를 출력하고,
            cout << endl;
            for(int j=lineLength ; j<_strLength ; ++j) cout << subStr[j]; // 다음 줄에 나머지 문자들을 출력함
            cout << endl;
        }
        else if(_strLength < lineLength) // 부분문자열의 길이가 한 줄의 길이보다 작은 경우
        {
            if((i != 0) && (_preLength % lineLength == 0)) cout << " " << subStr << endl; // 첫 줄이 아니고, 이전 부분문자열의 길이가 한 줄의 길이의 배수인 경우
            else cout << subStr << endl;
        }
        else // 부분문자열의 길이가 한 줄의 길이와 같은 경우
        {
            if(i == 0) cout << subStr << endl; // 첫 줄인 경우
            else if(_preLength % lineLength == 0) cout << endl << subStr << endl << endl; // 이전 부분문자열의 길이가 한 줄의 길이의 배수인 경우
            else cout << subStr << endl;
        }

        _preLength = _strLength; // 현재 부분문자열의 크기를 이전 부분문자열의 크기로 저장함
        _restLength -= _strLength; // 한 줄의 남은 길이에서 현재 부분문자열의 길이를 뺌
        subStr = strtok(NULL, " "); // 다음 부분문자열을 가리킴
    }

    cout << endl << "==============================" << endl;
}
