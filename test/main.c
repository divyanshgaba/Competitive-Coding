#include<conio.h>
#include<stdio.h>
#define MAX 10 // constants like these usually have capital letters, to distinguish from other variables.
struct stack
{
    int a[MAX];
    int top; // we can't initialize values inside struct as it requires memory and when we declare a structure like this it has no memory
            // thats why we are using function void stk();
};
void stk(struct stack *st) // we are using pointer to stack in functions as we are trying to change the value in that structure, it is same as function passing by reference
{
    st->top=-1;
}
//here
void push(struct stack *st) //remove int val, from function parameters to a variable define in function itself.
{
    int val;// val defined here
    if(st->top==MAX-1)
    {
        printf("overflow");
    }
    else // you did not use curly braces after else
    {
    printf("Enter element in stack: ");
    scanf("%d",&val);
        printf("Element %d has been pushed ",val);
    st->top+=1;
    st->a[st->top]=val;
    }
}
//here
int pop(struct stack *st)// same reason as earlier
{
    int val; //same reason
    if(st->top==-1)
    {
        printf("Underflow");
        return -1; //if it is underflow then return -1. if we do not return value here, the function will try to access val at a[st.top], and top is -1!
                    // and a[-1] doesn't exist!
    }
    val=st->a[st->top];
    st->top-=1;
    return val;
}
void disp(struct stack st) // no pointer to structure here as we only need to print or "read" values from structure instead of changing it. so passing by value not reference
{
    int i;
    /*if(st.top==-1)
    {
       //  printf("Underflow"); no need for this line , as we could have a empty stack and want to display to check if its empty :)

    }*/
    printf("stack is:\n");
    while(st.top>=0)       //when we are not using stack pointers we dont use "->" instead we use "." to access structure variables.
    {
        printf("%d\n",st.a[st.top]);
        st.top-=1;
    }
}
int main()
{
    struct stack st;
    int n,element,val,size,num,top;
    clrscr();
    printf("enter stack size: ");
    scanf("%d",&size);
    stk(&st); // we never initialized top , so doing it here!
    while(1)
    {
        system("cls"); // so we have clean screen after every action we do.
        printf("1. push\n"
               "2. pop\n"
               "3. display\n"
               "4. exit\n");
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch(n)
        {
                //here
            case 1:
                push(&st); // we don't need to put variable "val" here as we are not asking user for its value in main but in function itself.
                break;
            case 2:
                //here
                val=pop(&st); //same reason as above
                 /*
                    TODO
                    write some statements to check if something was actually pushed or was it underflow condition? we know we get val== -1 if its underflow.
                */
                printf("Element popped is %d \n",val);
                break;
            case 3:
                disp(st);
                break;
            case 4:
                exit(1);
            default:
                printf("Invalid\n");
        }
        printf("\n\nPress Any key to continue.");
        getch();//hold screen so user can see what has happened
    }
}
