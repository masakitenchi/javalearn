#include <iostream>
using namespace std;

int main()
{
    int n,i,j,k,q;
    cin>>n;
    int s[n];
    cin>>s[0];
    for(i=1;i<n;i++)
    {
                    cin>>s[i];
                    for(j=0;j<i;j++)
                                    if(s[i]<s[j])
                                    {
                                              q=s[i];
                                              for(k=i;k>j;k--)
                                                  s[k]=s[k-1];
                                              s[j]=q;
                                              break;
                                    }
    }
    for(i=0;i<n;i++)
        cout<<s[i]<<' ';
    system("pause");
    return 0;
}
