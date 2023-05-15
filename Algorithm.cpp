#include"Algorithm.h"
#include<vector>
#include<stack>
#include<queue>
#include<string>
using namespace std;

//����ת��
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

//��׺���ʽת��׺���ʽ
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
        //��Ϊ����ֱ�ӳ�
        if(X >= '0' && X <= '9')
            Queue.push(X);
        else
        //��ջΪ�գ����� �ַ�Ϊ'('��ֱ����ջ
        if (Stack.size() == 0 || X == '(')
            Stack.push(X);
        else
        //��ջ�ǿգ����ַ�Ϊ')'����ջֱ��'('
        if(X == ')'){
            for(; Stack.top() != '('; Stack.pop())
                Queue.push(Stack.top());
            Stack.pop();
        }
        else 
        //��ջ�ǿգ���Ϊ�����������ջ��Ϊ'('��ֱ����
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
1. ����ֱ�ӳ�
2. ջΪ�ջ��� �ַ�Ϊ'('ֱ����
3. ���ַ�Ϊ')'���ջȫ���ַ���ֱ��'('
4. ���ַ�Ϊ����������ջ�����ȼ����ڵ����ַ�
        ��Ϊ'+','-', ���ջ��ֱ���ջ���'('��
        ��Ϊ'*','/', ����ַ�Ϊ'*','/'ֱ���ա�
*/
}