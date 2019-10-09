#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 100010
struct node
{
    int next[26];
    int len;
    int sufflink;
    int num,start,end;
} tree[MAXN];

int len;
string s;
int num;
int suff;
long long ans;
bool addLetter(int pos)
{
    int cur = suff, curlen = 0;
    int let = s[pos] - 'a';

    while (true)
    {
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])
            break;
        cur = tree[cur].sufflink;
    }
    if (tree[cur].next[let])
    {
        suff = tree[cur].next[let];
        return false;
    }

    num++;
    suff = num;
    tree[num].len = tree[cur].len + 2;
    tree[cur].next[let] = num;
    tree[num].end=pos;
    tree[num].start = pos - tree[num].len + 1;
    if (tree[num].len == 1)
    {
        tree[num].sufflink = 2;
        tree[num].num = 1;
        return true;
    }

    while (true)
    {
        cur = tree[cur].sufflink;
        curlen = tree[cur].len;
        if (pos - 1 - curlen >= 0 && s[pos - 1 - curlen] == s[pos])
        {
            tree[num].sufflink = tree[cur].next[let];
            break;
        }
    }
    tree[num].num = 1 + tree[tree[num].sufflink].num;
    return true;
}

void initTree()
{
    num = 2;
    suff = 2;
    tree[1].len = -1;
    tree[1].sufflink = 1;
    tree[2].len = 0;
    tree[2].sufflink = 1;
}

int main()
{
    ll ts;
    cin>>ts;
    for(ll t=1; t<=ts; t++)
    {
        memset(tree,0,sizeof tree);
        ans=0;
        cin>>s;
        len = s.size();
        initTree();
        for (int i = 0; i < len; i++)
        {
            addLetter(i);
            ans += tree[suff].num;
        }
        //all types of  palindrome
        cout<<ans<<endl;

        // number of unique palindrome
        cout<<num-2<<endl;

        // print all the unique palindrome
        for (int i=3; i<=num; i++)
        {
            cout << i-2 << ") ";
            for (int j=tree[i].start; j<=tree[i].end; j++)
                cout << s[j];
            cout << endl;
        }
    }
}
