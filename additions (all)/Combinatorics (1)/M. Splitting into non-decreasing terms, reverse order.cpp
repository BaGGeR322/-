#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
std::string toString(T val)
{
    std::ostringstream oss;
    oss << val;
    return oss.str();
}

template <typename T>
T fromString(const std::string &s)
{
    std::istringstream iss(s);
    T res;
    iss >> res;
    return res;
}

vector<int> aaa(0);
vector<string> heh(0);
string s;

string reversee(string str1, string str2, string res)
{
    long sPos;
    while ((sPos = res.find(str1, 0)) != string::npos)
        res.replace(sPos, str1.length(), str2);
    return res;
}

void recurs(int x, int p)
{
    if (x == 0)
    {
        if (aaa.size() > 0)
            if (p > aaa[aaa.size() - 1])
                while (aaa.size() > 0 && p > aaa[aaa.size() - 1])
                    aaa.pop_back();
        aaa.push_back(p);

        for (int i = 0; i < aaa.size(); i++)
        {
            if (aaa[i] < 10)
                s += (char)(aaa[i] + 48);
            else
            {
                string temp = toString(aaa[i]);
                s += temp;
            }
            s += ' ';
        }
        heh.push_back(s);
        s = "";
        return;
    }

    if (x > 0)
    {
        if (aaa.size() > 0)
            if (p > aaa[aaa.size() - 1])
                while (aaa.size() > 0 && p > aaa[aaa.size() - 1])
                    aaa.pop_back();
        aaa.push_back(p);
        for (int q = 1; q <= p; q++)
            recurs(x - q, q);
    }
}

int main()
{
    aaa.clear();
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        recurs(n - i, i);
        aaa.clear();
    }
    for (int i = 0; i < heh.size(); i++)
    {
        reverse(heh[i].begin(), heh[i].end());
        heh[i] = reversee("01", "A", heh[i]);
        heh[i] = reversee("11", "B", heh[i]);
        heh[i] = reversee("21", "C", heh[i]);
        heh[i] = reversee("31", "D", heh[i]);
        heh[i] = reversee("41", "E", heh[i]);
        heh[i] = reversee("51", "F", heh[i]);
        heh[i] = reversee("61", "G", heh[i]);
        heh[i] = reversee("71", "H", heh[i]);
        heh[i] = reversee("81", "I", heh[i]);
        heh[i] = reversee("91", "J", heh[i]);
        heh[i] = reversee("02", "K", heh[i]);
        heh[i] = reversee("12", "L", heh[i]);
        heh[i] = reversee("22", "M", heh[i]);
        heh[i] = reversee("32", "N", heh[i]);
        heh[i] = reversee("42", "O", heh[i]);
        heh[i] = reversee("52", "P", heh[i]);

        heh[i] = reversee("62", "Q", heh[i]);
        heh[i] = reversee("72", "R", heh[i]);
        heh[i] = reversee("82", "S", heh[i]);
        heh[i] = reversee("92", "T", heh[i]);
        heh[i] = reversee("03", "U", heh[i]);
        heh[i] = reversee("13", "V", heh[i]);

        heh[i] = reversee("23", "W", heh[i]);
        heh[i] = reversee("33", "X", heh[i]);
        heh[i] = reversee("43", "Y", heh[i]);
        heh[i] = reversee("53", "Z", heh[i]);
        heh[i] = reversee("63", "a", heh[i]);
        heh[i] = reversee("73", "b", heh[i]);
        heh[i] = reversee("83", "c", heh[i]);
        heh[i] = reversee("93", "d", heh[i]);
        heh[i] = reversee("04", "e", heh[i]);
    }

    sort(heh.begin(), heh.end());

    for (int i = 0; i < heh.size(); i++)
    {
        heh[i] = reversee("A", "10", heh[i]);
        heh[i] = reversee("B", "11", heh[i]);
        heh[i] = reversee("C", "12", heh[i]);
        heh[i] = reversee("D", "13", heh[i]);
        heh[i] = reversee("E", "14", heh[i]);
        heh[i] = reversee("F", "15", heh[i]);
        heh[i] = reversee("G", "16", heh[i]);
        heh[i] = reversee("H", "17", heh[i]);
        heh[i] = reversee("I", "18", heh[i]);
        heh[i] = reversee("J", "19", heh[i]);
        heh[i] = reversee("K", "20", heh[i]);
        heh[i] = reversee("L", "21", heh[i]);
        heh[i] = reversee("M", "22", heh[i]);
        heh[i] = reversee("N", "23", heh[i]);
        heh[i] = reversee("O", "24", heh[i]);
        heh[i] = reversee("P", "25", heh[i]);
        heh[i] = reversee("Q", "26", heh[i]);
        heh[i] = reversee("R", "27", heh[i]);
        heh[i] = reversee("S", "28", heh[i]);
        heh[i] = reversee("T", "29", heh[i]);
        heh[i] = reversee("U", "30", heh[i]);
        heh[i] = reversee("V", "31", heh[i]);

        heh[i] = reversee("W", "32", heh[i]);
        heh[i] = reversee("X", "33", heh[i]);
        heh[i] = reversee("Y", "34", heh[i]);
        heh[i] = reversee("Z", "35", heh[i]);
        heh[i] = reversee("a", "36", heh[i]);
        heh[i] = reversee("b", "37", heh[i]);
        heh[i] = reversee("c", "38", heh[i]);
        heh[i] = reversee("d", "39", heh[i]);
        heh[i] = reversee("e", "40", heh[i]);
    }

    for (int i = heh.size() - 1; i >= 0; i--)
        cout << heh[i] << '\n';

    return 0;
}