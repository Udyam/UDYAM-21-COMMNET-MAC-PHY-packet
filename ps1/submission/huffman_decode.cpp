#include <bits/stdc++.h>
using namespace std;
int main()
{
    map <string,char> m;//map of all the bitstrings for each character
    m["0110"]='a';
    m["0111"]='e';
    m["1111110"]='l';
    m["111001"]='p';
    m["111010"]='q';
    m["1010"]='o';
    m["001"]='i';
    m["11010"]='c';
    m["111000"]='m';
    m["1111111"]='u';
    m["1001"]='n';
    m["111101"]='y';
    m["111110"]='z';
    m["111011"]='v';
    m["111100"]='w';
    m["1011"]='r';
    m["010"]='s';
    m["1100"]='t';
    m["1000"]='h';
    m["11011"]='d';
    m["000"]=' ';
    string s,s1,str;
    //s="00111011001001001110010000110010011001000011001001101011100010011111010101100100001011110011111000101100011001001101000101111000101110101101011100111010100101010110100001010001110110010010011101000110010010100101100101111000101001111101110100000100110";
    s="1100100001110001110001010100101011000111101100001100100101010110100010110110000110101001000100001110110110111110101111111011010111100011110110100000010100000011001000110100011100111101000111110000011010011101100011001000011100011100101100100101111001010101111011000001010000010001111111011101101111011";

    str="";
    s1="";//result
    for(int i=0;i<s.length();i++)
    {
        str=str+s[i];
        //cout<<str<<endl;
        if(m.find(str)!=m.end())
        {
            //comparing string with bitstring s , if match is found add the character to result
            s1=s1+m[str];
            str="";
           // cout<<s1;
            
        }
        
    }
    cout<<s1;
cout<<str;
}
