/*input
ProblemLink: http://codeforces.com/contest/842/problem/D
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <stack>
#include <deque>
#include <queue>
#include <cmath>
using namespace std;

// #define FASTIOALLOWED
#define Maxbit (int)19
#define MOD (long long)1e9+7
#define FIO ios_base::sync_with_stdio(false)
#define loop(i, a, b)   for(int i = a; i<b; ++i)
#define loopE(i, a, b)   for(int i = a; i<=b; ++i)
#define rloop(i, b, a) for(int i=b; i>a; --i)
#define rloopE(i, b, a) for(int i=b; i>=a; --i)
#define vectorOfVector(v, x, N, M) std::vector<std::vector<x> > v(N, (*new std::vector<x>(M, 0)))

char _str[10];
#define  printv(v) {     \
    for(int enigma=0; enigma<v.size(); ++enigma)   \
        cout<<v[enigma]<<" ";    \
    cout<<endl; \
}
#define findMax(v, x) { \
    for(int enigma = 0; enigma<v.size(); ++enigma) if(x < v[enigma]) x = v[enigma]; \
}
#ifdef FASTIOALLOWED
#define ReadInt(x) {   \
    register int ch = getchar_unlocked();   \
    int temp = 0;   \
    while(ch<'0' || ch>'9')         ch = getchar_unlocked();    \
    while(ch>='0' && ch<='9')   {   temp = (temp<<3) + (temp<<1) + ch-48;   ch = getchar_unlocked();    }   \
    x = temp;    \
}
#define WriteInt(_x){                     \
    register int _i = 0;            \
    int _tmp = (_x);                \
    do{                     \
        *(_str + _i++) = _tmp % 10 + 48;    \
        _tmp /= 10;             \
    }while (_tmp != 0);          \
    for (_i--; _i >= 0; _i--)           \
        putchar_unlocked(*(_str + _i));       \
}
#endif
#ifndef FASTIOALLOWED
#define ReadInt(x) {   \
    register int ch = getchar();   \
    int temp = 0;   \
    while(ch<'0' || ch>'9')         ch = getchar();    \
    while(ch>='0' && ch<='9')   {   temp = (temp<<3) + (temp<<1) + ch-48;   ch = getchar();    }   \
    x = temp;    \
}
#define WriteInt(_x){                     \
    register int _i = 0;            \
    int _tmp = (_x);                \
    do{                     \
        *(_str + _i++) = _tmp % 10 + 48;    \
        _tmp /= 10;             \
    }while (_tmp != 0);          \
    for (_i--; _i >= 0; _i--)           \
        putchar(*(_str + _i));       \
}
#endif

int gcdExtended(int a, int b, int *x, int *y){
    if (a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1; 
    int gcd = gcdExtended(b%a, a, &x1, &y1);
    *x = y1 - (b/a) * x1;
    *y = x1;
    return gcd;
}  

class TrieNode
{
public:
    TrieNode *left, *right;
    bool isLeaf;
    int size;
    bool isLeftFull, isRightFull;    
    TrieNode();
    ~TrieNode(){};
};
TrieNode::TrieNode(){
    left = NULL;
    right = NULL;
    isLeaf = false;
    size = 0;
    isLeftFull = isRightFull = false;
}

class Trie
{
    TrieNode *root;
    string decimalToBinary(long );
    bool insert(TrieNode **, string , int );
    void dfs(TrieNode *, int );
    int calMex(TrieNode *, string, int );
    int recurrHeight(TrieNode *head);
    bool isSubtreeFilledUpHelper(TrieNode * head);
public:
    Trie();
    ~Trie(){};
    void push(int);
    int print();
    int findMex(int );
    void assignHeight();
    void isSubtreeFilledUp();
};

Trie::Trie(){
    root = NULL;
}

void Trie::push(int N){
    insert(&(this->root), this->decimalToBinary(N), 0);
}

bool Trie::insert(TrieNode **head, string binary, int i){
    if((*head) == NULL)
        *head = new TrieNode();
    if(i == Maxbit) {
        (*head)->isLeaf = true;
        return true;
    }
    if(binary.at(i) == '0') {
        if((*head)->left == NULL)
            (*head)->left = new TrieNode();
        (*head)->isLeftFull = insert(&(*head)->left, binary, i+1);
    }
    else{
        if((*head)->right == NULL)
            (*head)->right = new TrieNode();
        (*head)->isRightFull = insert(&(*head)->right, binary, i+1);
    }
    return (*head)->isRightFull & (*head)->isLeftFull;
}

int Trie::findMex(int X){
    return calMex(root, decimalToBinary(X), 0);
}

int Trie::calMex(TrieNode *head, string binary, int i) {
    if(head == NULL)
        return 0;
    if(i==Maxbit)
        return 0;
    if(binary.at(i) == '0') {
        if(head->left==NULL)
            return 0;
        else if(!head->isLeftFull)
            return calMex(head->left, binary, i+1);
        else if(head->right == NULL)
            return pow(2, Maxbit-i-1);
        else
            return calMex(head->right, binary, i+1) + pow(2, Maxbit - i -1);
    }
    else if(binary.at(i)== '1'){
        if(head->right == NULL)
            return 0;
        else if(!head->isRightFull)
            return calMex(head->right, binary, i+1);
        else if(head->left == NULL)
            return pow(2, Maxbit-i-1);
        else
            return calMex(head->left, binary, i+1) + pow(2, Maxbit - i -1);
    }
}

int main(int argc, char const *argv[]){
    FIO;
    int N, M;
    ReadInt(N);
    ReadInt(M);
    Trie trie;
    loop(i, 0, N) {
        int x;
        ReadInt(x);
        trie.push(x);
    }
    int number = 0;
    loop(itre, 0, M){
        int x;
        ReadInt(x);
        number ^= x;
        WriteInt(trie.findMex(number));
        putchar('\n');
    }
}


void Trie::assignHeight() {
    root->size = recurrHeight(root);
}

void Trie::isSubtreeFilledUp(){
    if(root->left!=NULL)
        root->isLeftFull = isSubtreeFilledUpHelper(root->left);
    if(root->right!=NULL)
        root->isRightFull = isSubtreeFilledUpHelper(root->right);
}

bool Trie::isSubtreeFilledUpHelper(TrieNode * head){
    if(head->left == NULL && head->right == NULL)
        return true;
    if(head->left != NULL)
        head->isLeftFull = isSubtreeFilledUpHelper(head->left);
    if(head->right!= NULL)
        head->isRightFull = isSubtreeFilledUpHelper(head->right);
    return head->isLeftFull & head->isRightFull;
}

int Trie::recurrHeight(TrieNode *head) {
    if(head == NULL)
        return 0;
    head->size += 1 + recurrHeight(head->left) + recurrHeight(head->right);
    return head->size > 0 ? head->size : 0;
}

void Trie::dfs(TrieNode *head, int N) {
    if(head == NULL)
        return;
    cout<<N<<" ";
    if(head->isLeaf)
        cout<<endl;
    dfs(head->left, 0);
    dfs(head->right, 1);
}

int Trie::print(){
    if(this->root == NULL){
        cout<<"Root is empty"<<endl;
        return 0;
    }
    dfs(root->left, 0);
    dfs(root->right, 1);
}

string Trie::decimalToBinary(long n) {
    std::vector<int> binaryNum(Maxbit, 0);
    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    string binary = "";
    for (int j = Maxbit-1; j >= 0; j--)
        binary += binaryNum[j] == 1 ? "1" : "0";
    return binary;
}