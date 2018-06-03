#include<iostream>

using namespace std;

struct node{
    int base;
    int coef;
    struct node* next;

};
int main()
{
    node *polyOne = NULL;
	cout<<"First Polynomial: \n";
	int d1;
	cout<<"\tEnter number of non zero terms in polynomial: ";
	cin>>d1;
	cout<<"\tEnter terms in increasing degree: \n";
	for(int i = d1;i>0;i--)
    {
        node *x = new node;
        cout<<"\tEnter base: ";
        cin>>x->base;
        cout<<"\tEnter coeff :";
        cin>>x->coef;
        x->next = polyOne;
        polyOne = x;
    }
    node *polyTwo = NULL;
	cout<<"Second Polynomial: \n";
	int d2;
	cout<<"\tEnter number of non zero terms in polynomial: ";
	cin>>d2;
	cout<<"\tEnter terms in increasing degree: \n";
	for(int i = d2;i>0;i--)
    {
        node *x = new node;
        cout<<"\tEnter base: ";
        cin>>x->base;
        cout<<"\tEnter coeff :";
        cin>>x->coef;
        x->next = polyTwo;
        polyTwo = x;
    }
    node *polySum = NULL;
    node *cur1 = polyOne, *cur2 = polyTwo;
    while(cur1!=NULL && cur2!=NULL)
    {
        node *x = new node;
        if(cur1->base == cur2->base)
        {
            x->base = cur1->base;
            x->coef = cur1->coef + cur2->coef;
            cur1=cur1->next;
            cur2=cur2->next;
        }
        else if(cur1->base < cur2->base)
        {
            x->base = cur1->base;
            x->coef = cur1->coef;
            cur1=cur1->next;
        }
        else
        {
            x->base = cur2->base;
            x->coef = cur2->coef;
            cur2=cur2->next;
        }
        x->next = polySum;
        polySum = x;
    }
    while(cur1!=NULL)
    {
        node *x = new node;
        x->base = cur1->base;
        x->coef = cur1->coef;
        cur1=cur1->next;
        x->next = polySum;
        polySum = x;
    }
    while(cur2!=NULL)
    {
        node *x = new node;
        x->base = cur2->base;
        x->coef = cur2->coef;
        cur2=cur2->next;
        x->next = polySum;
        polySum = x;
    }
    int cnt = max(d1,d2);
    cout<<"Sum of polynomials is: ";
    node *curAns = polySum;
    while(curAns!=NULL)
    {
        cout<<""<<curAns->coef<<" (x^"<<curAns->base<<")";
        curAns = curAns->next;
        if(curAns!=NULL)
            cout<<" + ";
    }
    cout<<endl;
	return 0;
}
