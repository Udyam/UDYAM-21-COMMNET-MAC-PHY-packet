#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
//convert integer to binary
string integral_to_binary_string(int byte,int t)
{
    string bits="";
    while(byte!=0){
        int x=byte%2;
        byte=byte/2;
        bits=to_string(x)+bits;
    }
    while(bits.length()!=t){
        bits="0"+bits;
    }    
    return bits;
}

int countSub=1;
//heap to store the values for huffman code 
class BinHeap{
    public:
    char data;
    BinHeap * left=nullptr;
    BinHeap * right=nullptr;
    BinHeap(){
        countSub++;
        data='a'-countSub;
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
bool cmp2(pair<string, char>& a,
         pair<string, char>& b)
{
    if(a.first.length()<b.first.length()){
        return true;
    }
    if(a.first.length()==b.first.length()){
        if(a.second<b.second){
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
map<string,char> m; 
vector<pair<string,char>> cannon;
string result=string("");
//function to traverse via the heap and calculate values of 
void calcHuffmanCode(BinHeap * root,string str){
    if((root->left==nullptr)&&(root->right==nullptr)){
        // cout<<"m[\""<<str<<"\"]= \'"<<root->data<<"\';";
        result=result+"m[\""+str+"\"]= \'"+root->data+"\';";
        char ch=root->data;
        string s2=string(str);
        m.insert(pair<string,char>(s2,ch));
        cannon.push_back(pair<string,char>(s2,ch));
    }
    if(root->left!=nullptr){
        // cout<<root->data<<" ";
        calcHuffmanCode(root->left,str+string("1"));
    }
    if(root->right!=nullptr){
        // cout<<root->data<<" ";
        calcHuffmanCode(root->right,str+string("0"));
    }
    str.erase(); 
}
int main(){
    ///////////////////making a list of probalities///////////////////////////////////////////
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
            if(ch==' '){
                ch='a'-1;
            }
            BinHeap * cpy=new BinHeap(ch);
            ref.push_back(pair<BinHeap *,int>(cpy,count));
            ch=str[i];
            count=1;
        }
    }
    BinHeap * cpy=new BinHeap('z');
    ref.push_back(pair<BinHeap *,int>(cpy,1));
    sort(ref.begin(), ref.end(), cmp);
    
    iter=ref.begin();
    while(iter!=ref.end()){
        cout<<static_cast<char>(*(iter->first))<<" "<<iter->second<<":";
        iter++;
    }
    cout<<endl;
    ///////////////////////////huffman code///////////////////////////

    pair<BinHeap*,int>  left,right;
    //making huffman tree
    while(ref.size()!=1){
        //poping the minimum two probabilities and making a node then adding it again to the vectors
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
    calcHuffmanCode(root,str);    
    cout<<endl;

    
    map<string,char>::iterator iter2=m.begin();
    while(iter2!=m.end()){
        cout<<iter2->first<<" "<<iter2->second<<":";
        iter2++;
    }
    // cout<<m["0000"];
    cout<<endl;
    ////////////////////cannonical huffman////////////////////////////
//     map<string,char> res;
//     sort(cannon.begin(), cannon.end(), cmp2);
//     vector<pair<string,char>>::iterator iter3=cannon.begin();
    
//     // std::cout << integral_to_binary_string(0,cannon[0].first.length());
//     // std::cin.get();
//     // while more symbols do
//     // print symbol, code
//     // code := (code + 1) << ((bit length of the next symbol) − (current bit length))
//     // cout<<endl;
//     int byte = 0;
//     int len=iter3->first.length();
//     res.insert(pair<string,char>( integral_to_binary_string(byte,len),iter3->second));
//     iter3++;

//     while(iter3!=cannon.end()){
//         byte=(byte+1)<<(iter3->first.length()-len);
//         // cout<<" : "<<byte<<" ";
//         // cout<<" : "<<iter3->first<<" "<<iter3->second<<" : ";
//         res.insert(pair<string,char>( integral_to_binary_string(byte,iter3->first.length()),iter3->second));
//         // code := (code + 1) << ((bit length of the next symbol) − (current bit length))
//         len=iter3->first.length();
//         iter3++;
        
//     }
//     cout<<endl;
//     ///////////////////result///////////////////////
//     map<string,char>::iterator iter4=res.begin();
//     while(iter4!=res.end()){
//         cout<<iter4->first<<" "<<iter4->second<<":";
//         iter4++;
//     }
//     // cout<<m["0000"];
//     cout<<endl;

//     // cout<<m["0000"];
//     cout<<endl;
//     string s,s1;
//     s="1100100001110001110001010100101011000111101100001100100101010110100010110110000110101001000100001110110110111110101111111011010111100011110110100000010100000011001000110100011100111101000111110000011010011101100011001000011100011100101100100101111001010101111011000001010000010001111111011101101111011"
// ;
//     str="";s1="";
//     for(int i=0;i<s.length();i++){
//         str=str+s[i];
//         if(res.find(str)!=res.end()){
//             if(res[str]=='a'-1){
//                 s1=s1+" ";
//             }
//             else{
//                 s1=s1+res[str];
//             }
//             str="";
//             // cout<<s1;
//         }
//     }
//     cout<<"**"<<s1<<"**";
}