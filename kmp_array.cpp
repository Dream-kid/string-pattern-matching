#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
int main()
{
    string b;
    cin>>b;
    lli s1=b.size();
    lli ara[10000];
    for(lli i=0; i<s1; i++)
    {
        for(lli j=i+1; j<s1; j++)
        {

            if(b[i]==b[j])
            {
                ara[j]=ara[j-1]+1;
                i++;
            }
            else
            {
read:
                i=ara[i-1];
                if(b[i]==b[j])
                    ara[j]=i+1;

                else if(i!=0) goto read;
            }
        }
        break;
    }
    for(lli i=0; i<b.size(); i++) cout<<ara[i]<<" ";



}
