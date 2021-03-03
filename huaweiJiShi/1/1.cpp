#include <set>
#include <iostream>
#include <memory>
#include <string.h>

//deefd ---> def
//afafafaf ---> af
//ppppppp ---> p
void stringFilter(const char * pInputStr, long lInputLen, char * pOutputStr)
{
    std::set<int> letters;
    int j = 0;
    for (int i = 0; i < lInputLen; ++i)
    {
        if (letters.count(pInputStr[i]) == 0)
        {
            letters.insert(pInputStr[i]);
            pOutputStr[j++] = pInputStr[i];
        }
    }
}

int main(int argc, char **argv)
{
    char *pInputStr = "ppppppp";
    int lInputLen = strlen(pInputStr);
    char *pOutputStr = new char[lInputLen];
    memset(pOutputStr, 0, lInputLen);
    stringFilter(pInputStr, lInputLen, pOutputStr);
    printf("pOutputStr: %s", pOutputStr);
    delete[] pOutputStr;
    return 0;
}
