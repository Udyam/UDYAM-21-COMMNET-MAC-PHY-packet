//m["000"]= 'i';m["0010"]= 'd';m["0011"]= 'o';m["0100"]= 'n';m["010100"]= 'q';m["010101"]= 'p';m["010110"]= 'v';m["010111"]= 'u';m["011"]= 's';m["10000"]= 'c';m["100010"]= 'm';m["100011"]= 'l';m["1001"]= 'r';m["101000"]= 'y';m["101001"]= 'w';m["10101"]= 'h';m["1011"]= 't';m["1100"]= 'e';m["1101"]= 'a';m["111"]= ' ';
//otdn dierrisdsuir hsdite evodsnum vtranhsndltdn nsdqtd mr tyds

#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;

class BinHeap{
    public:
    char data;
    BinHeap * left=nullptr;
    BinHeap * right=nullptr;
    BinHeap(){
        data='a'-1;
    }
    BinHeap(char ch){
        data=ch;
    }
    operator char(){
        return data;
    }
};
bool cmp(pair<BinHeap *, int>& a,
         pair<BinHeap *, int>& b)
{
    if(a.second>b.second){
        return true;
    }
    if(a.second==b.second){
        if(a.first->data<b.first->data){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
// bool cmp2(pair<BinHeap, int>& a,pair<BinHeap, int>& b)
// {
//     if(a.first.data==b.first.data){
//         return true;
//     }
//     else{
//         return false;
//     }
// }
vector<map<string,char>> m; 
// string result=string("");
void calcHuffmanCode(BinHeap * root,string str,int i){
    int count=i;
    if((root->left==nullptr)&&(root->right==nullptr)){
        // cout<<"m[\""<<str<<"\"]= \'"<<root->data<<"\';";
        // result=result+"m[\""+str+"\"]= \'"+root->data+"\';";
        char ch=root->data;
        string s2=string(str);
        m[count].insert(pair<string,char>(s2,ch));
    }
    if(root->left!=nullptr){
        // cout<<root->data<<" ";
        map<string,char> * temp=new map<string,char>();
        m.push_back(*temp);
        calcHuffmanCode(root->left,str+string("0"),count++);
        temp=new map<string,char>();
        m.push_back(*temp);
        calcHuffmanCode(root->left,str+string("1"),count++);
    }
    if(root->right!=nullptr){
        // cout<<root->data<<" ";
        map<string,char> * temp=new map<string,char>();
        m.push_back(*temp);
        calcHuffmanCode(root->right,str+string("0"),count++);
        temp=new map<string,char>();
        m.push_back(*temp);
        calcHuffmanCode(root->right,str+string("1"),count++);
    }
    str.erase();
}
int main(){
    string str="            aaaaaaccdddeeeeeehhhiiiiiiilmnnnnoooopqrrrrrsssssssssttttttuvwyz";
    vector<pair<BinHeap*,int>> ref;
    vector<pair<BinHeap*,int>>::iterator iter;
    char ch=' ';
    int count=0;
    for(int i=0;i<str.length();i++){
        if(str[i]==ch){
            count++;
        }
        else{
            BinHeap * cpy=new BinHeap(ch);
            ref.push_back(pair<BinHeap *,int>(cpy,count));
            ch=str[i];
            count=1;
        }
    }
    BinHeap * cpy=new BinHeap('z');
    ref.push_back(pair<BinHeap *,int>(cpy,count));
    sort(ref.begin(), ref.end(), cmp);
    
    iter=ref.begin();
    while(iter!=ref.end()){
        cout<<static_cast<char>(*(iter->first))<<" "<<iter->second<<":";
        iter++;
    }
    cout<<endl;

    pair<BinHeap*,int>  left,right;
    //making huffman tree
    while(ref.size()!=1){
        left=ref.back();
        ref.pop_back();
        right=ref.back();
        ref.pop_back();
        BinHeap * newNode=new BinHeap();
        newNode->left=left.first;
        newNode->right=right.first;
        ref.push_back(pair<BinHeap *,int>(newNode,left.second+right.second));
        sort(ref.begin(), ref.end(), cmp);
        // iter=ref.begin();
        // while(iter!=ref.end()){
        //     cout<<static_cast<char>(*iter->first)<<" "<<iter->second<<":";
        //     iter++;
        // }
        // cout<<endl;
    }

    //calculating values
    BinHeap* root=ref.back().first;
    str="";
    calcHuffmanCode(root,str,0);    
    cout<<endl;

    
    
    // map<string,char>::iterator iter2=m.begin();
    // while(iter2!=m.end()){
    //     cout<<iter2->first<<" "<<iter2->second<<":";
    //     iter2++;
    // }
    // cout<<m["0000"];
    cout<<endl;

    // map<string,char>::iterator iter2=m.begin();
    // while(iter2!=m.end()){
    //     cout<<iter2->first<<" "<<iter2->second<<":";
    //     iter2++;
    // }

    // string s,s1;
    // s="1100100001110001110001010100101011000111101100001100100101010110100010110110000110101001000100001110110110111110101111111011010111100011110110100000010100000011001000110100011100111101000111110000011010011101100011001000011100011100101100100101111001010101111011000001010000010001111111011101101111011";
    // for(int j=0;j<m.size();j++){

    //     str="";s1="";
    //     for(int i=0;i<s.length();i++){
    //         str=str+s[i];
    //         if(m[j].find(str)!=m[j].end()){
    //             s1=s1+m[j][str];
    //             str="";
    //             // cout<<s1;
    //         }
    //     }
    //     cout<<s1<<" Count= "<<j<<endl;

    // }
    
}