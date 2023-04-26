#include"Algorithm.h"
#include<vector>
#include<stack>
#include<queue>
#include<string>
using namespace std;

//进制转换
void BinHexOct(int N, int n)
{
    stack<int> Stack;
    //
    for(; N/n !=0; N = N/n)
        Stack.push(N%n);
    Stack.push(N % n);

    for(; Stack.size()>0; Stack.pop())
        printf("%d", Stack.top());

}

//中缀表达式转后缀表达式
void Infix_Postfix(char string[])
{
    
    stack<char> Stack;
    queue<char> Queue;
    //

    //Stack.push('#');
    int i = 0;
    for (i = 0; i < strlen(string); i++)
    {
        char X = string[i];
        //若为数字直接出
        if(X >= '0' && X <= '9')
            Queue.push(X);
        else
        //若栈为空，或者 字符为'('，直接入栈
        if (Stack.size() == 0 || X == '(')
            Stack.push(X);
        else
        //若栈非空，但字符为')'，出栈直到'('
        if(X == ')'){
            for(; Stack.top() != '('; Stack.pop())
                Queue.push(Stack.top());
            Stack.pop();
        }
        else 
        //若栈非空，若为运算符，并且栈顶为'('，直接入
        if(Stack.top() == '(')
            Stack.push(X);
        else
        if(X == '+' || X == '-'){
            for(; Stack.size() > 0 && Stack.top() != '(';Stack.pop())
                Queue.push(Stack.top());
            Stack.push(X);
        }
        else
        if (X == '*' || X == '/') {
            for (; Stack.size()>0 && Stack.top() == '*' || Stack.top() == '/'; Stack.pop())
                Queue.push(Stack.top());
            Stack.push(X);
        }
    }

    for (; Stack.size() > 0; Stack.pop())
        Queue.push(Stack.top());

    for(; Queue.size()>0;Queue.pop())
        printf("%c", Queue.front());
/*
1. 数字直接出
2. 栈为空或者 字符为'('直接入
3. 若字符为')'输出栈全部字符，直到'('
4. 若字符为运算符，输出栈顶优先级大于等于字符
        若为'+','-', 输出栈，直到空或者'('，
        若为'*','/', 输出字符为'*','/'直到空。
*/
}