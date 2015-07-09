#include <iostream>
using namespace std;

class stack
{
	private:
		int s;
		stack *next,*before;
	public:
		stack()
		{
			this->s=0;
			this->next=NULL;
			this->before=NULL;
		}
		stack(int s,stack *next,stack *before)
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
		stack* getnext()
		{
			return this->next;
		}
		stack* getbefore()
		{
			return this->before;
		}
		void changenext(stack *next)
		{
			this->next=next;
		}
		void changebefore(stack *before)
		{
			this->before=before;
		}
		friend istream& operator>>(istream &cin,stack *a)
		{
			cin>>a->s;
			return cin;
		}
		friend ostream& operator<<(ostream &cout,const stack *const a)
		{
			cout<<a->s;
			return cout;
		}
		void pop()
		{
			if(this->getnext()!=NULL&&this->getbefore()!=NULL)
			{
				cout<<this;
				this->getnext()->changebefore(this->getbefore());
				this->getbefore()->changenext(this->getnext());
				delete this;
				return ;
			}
			else
			{
				cout<<"error!";
				exit(-1);
			}
		}
		void push()
		{
			this->changenext(new stack(0,this->getnext(),this));
			cin>>this->getnext();
			this->getnext()->getnext()->changebefore(this->getnext());
		}
};

int main()
{
	int n,i;
	void push(stack*,stack*);
	cin>>n;
	stack *head=new stack(0,new stack(0,NULL,head),NULL),*end=head->getnext();
	for(i=0;i<n;i++)
	{
		head->push();
	}
	for(i=0;i<n;i++)
	{
		head->getnext()->pop();
	}
	return 0;
}
