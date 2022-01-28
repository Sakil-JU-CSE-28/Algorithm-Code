#include<bits/stdc++.h>
using namespace std;

struct Trie
{
    Trie *child[26];

    Trie()
    {
        for(int i = 0; i < 26; i++)
        {
            child[i] = NULL;
        }
    }

    int IsEnd = 0;

};

void insrt(string s,Trie* root)
{

    for(int i = 0; i < s.size(); i++)
    {
        int idx = s[i] - 'a';
        if(root->child[idx] == NULL)
        root->child[idx] = new Trie();

        root = root->child[idx];
    }

    root->IsEnd++;
}

int srch(Trie* root,string s)
{
    for(int i = 0; i < s.size(); i++)
    {
        int idx = s[i] - 'a';

        if(root->child[idx] == NULL)
        {
            return false;
        }
        root = root->child[idx];
    }
    return root->IsEnd;

}

int main()
{
    Trie *root = new Trie();

    string line;
    cout<<"Enter the content : ";
    getline(cin,line);
    for(int i = 0;i < line.size();i++)
    {
        if(line[i] >= 'A' && line[i] <= 'Z')
        {
            line[i] += 32;
        }
        else if(line[i] >= 'a' && line[i] <= 'z')
        {
            continue;
        }
        else
        {
            line[i] = ' ';
        }
    }
    vector <string> tokens;

    stringstream check1(line);

    string intermediate;

    while(getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }

    for(auto it:tokens)
        insrt(it,root);

    int q;
    cout<<"Enter num of query : ";
    cin>>q;

    while(q--)
    {

        string word;

        cout<<"Enter your word : ";
        cin>>word;

        if(srch(root,word))
        {
            cout<<"Yep!!Got it : "<<srch(root,word)<<" Times\n";
        }
        else
        {
            cout<<"Try again (: !!\n";
        }
    }


}
