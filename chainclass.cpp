#include <iostream>
using namespace std;

class chainnode
{
	private:
		int s;
		chainnode *next,*before;
	public:
		chainnode()
		{
			this->s=0;
			this->next=NULL;
			this->before=NULL;
		}
		chainnode(int s,chainnode *next,chainnode *before)
		{
			this->s=s;
			this->next=next;
			this->before=before;
		}
		int getint()
		{
			return this->s;
		}
		void changeint(int s)
		{
			this->s=s;
		}
		chainnode* getnext()
		{
			return this->next;
		}
		chainnode* getbefore()
		{
			return this->before;
		}
		void changenext(chainnode *next)
		{
			this->next=next;
		}
		void changebefore(chainnode *before)
		{
			this->before=before;
		}
		friend istream& operator>>(istream &cin,chainnode *a)
		{
			cin>>a->s;
			return cin;
		}
		friend ostream& operator<<(ostream &cout,const chainnode *const a)
		{
			cout<<a->s;
			return cout;
		}
};
int main()
{
	int n,i;
	cin>>n;
	chainnode *head=new chainnode(0,new chainnode(),NULL),*s=head->getnext(),*end=new chainnode(0,NULL,NULL);
	for(i=0;i<n-1;i++)
	{
		s->changenext(new chainnode());
		cin>>s;
		s->getnext()->changebefore(s);
		s=s->getnext();
	}
	s->changenext(end);
	cin>>s;
	end->changebefore(s);
	for(s=head->getnext();s->getnext();s=s->getnext())
	    cout<<s;
	return 0;
}
