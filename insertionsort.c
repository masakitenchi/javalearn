#include <stdio.h>

int main()
{
	int k,i,j,a,b,c;
	scanf("%d",&k);
	int s[k];
	for(i=0;i<k;i++)
		scanf("%d",s+i);
	for(i=1;i<k;i++)
	{
		a=s[i];
		j=i-1;
		while(j>=0&&s[j]>a)
		{
			s[j+1]=s[j];
			j--;
		}
		s[j+1]=a;
	}
	for(i=0;i<k;i++)
		printf("%d ",*(s+i));
	printf("\n");
	return 0;
}