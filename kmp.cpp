
//uva-10679
#include<bits/stdc++.h>
using namespace std;
typedef long long lli;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    lli s;
    cin>>s;

    while(s--)
    {
        string a;
        lli p;
        cin>>a>>p;
        lli s2=a.size();
        while(p--)
        {
            string b;
            cin>>b;

            lli s1=b.size();

            lli ara[1010]= {0};
            for(lli i=0; i<s1; i++)
            {
                for(lli j=i+1; j<s1; j++)
                {

                    if(b[i]==b[j])
                    {
                       if(j!=0) ara[j]=ara[j-1]+1;
                        i++;
                    }
                    else
                    {
read:
                       if(i!=0) i=ara[i-1];
                        if(b[i]==b[j])
                            ara[j]=i+1;

                        else if(i!=0) goto read;
                    }
                }
                break;
            }

            lli j=0;
            for(lli i=0; i<s2;)
            {

                if(j==s1) break;
                if(a[i]==b[j])
                {
                    i++;
                   j++;
                }
                else if(j!=0)  j=ara[j-1];

                else i++;
            }
            if(j!=s1) cout<<"n"<<endl;
            else cout<<"y"<<endl;
        }
    }
}


