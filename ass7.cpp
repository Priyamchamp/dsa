#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
struct node{
	char data;
	node*left;
	node*right;

};
class tree{
	char prefix[20];
	public:
		node*top;
		void expression(char[]);
		void display1(node*);
		void postorder(node*);
		void del(node*);
};
class stack1{
	node*data[30];
	int top;
	public:
	stack1()
	{
		top=-1;
	}
	int empty(){
		if(top==-1){
			return 1;
		}
		return 0;
	}
	void push(node*p){
		data[++top]=p;
	}
	node*pop(){
		return (data[top--]);
	}
};
void tree::expression(char prefix[])
{char c;
	stack1 s;
	node *t1,*t2;
	int len,i;
	len=strlen(prefix);
	for(i=len;i>=0;i--)
	{
		top=new node;
		top->left=NULL;
		top->right=NULL;
		if(isalpha(prefix[i]))
		{
			top->data=prefix[i];
			s.push(top);
		}
		else if(prefix[i]=='+'||prefix[i]=='*'||prefix[i]=='-'||prefix[i]=='/')
		{
			t2=s.pop();
			t1=s.pop();
			top->left=t2;
			top->right=t1;
			s.push(top);
		}
	}
	top=s.pop();
}
void tree::display1(node*root){
	if(root!=NULL){
		cout<<root->data;
		display1(root->left);
		display1(root->right);
	}
}
void tree::postorder(node *top)
{
	stack1 s1,s2;
	node*t=top;
	cout<<"\n";
	s1.push(t);
	while(s1.empty())
	{
		t=s1.pop();
		s2.push(t);
		if(t->left!=NULL){
			s1.push(t->left);
		}
		if(t->right!=NULL){
			s1.push(t->right);
		}
	}
	while(!s2.empty()){
		top=s2.pop();
		cout<<top->data;
	}
}
void tree::del(node*node){
	if(node==NULL)return;
	del(node->left);
	del(node->right);
	cout<<"deleting node:"<<node->data<<endl;
	free(node);
}
int main(){
	char exp[30];
	tree t;
	cout<<"enter prefix expression";
	cin>>exp;
	cout<<"Printing the EXpression as it is";
	cout<<exp;
	t.expression(exp);
	cout<<"/n printing the tree";
	t.display1(t.top);
	t.postorder(t.top);
	t.del(t.top);
	t.display1(t.top);
}
