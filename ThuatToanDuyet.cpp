#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>
 using namespace std;
//prototype
int a[100][100];
int tham[100];
int truoc[100];
void DocFile(int &n)
{
	ifstream ifs("data.txt");
	ifs >> n;
	int c, b;
	for(int i =1;i<=n;i++)
	{
		for(int j =1;j<=n;j++)
		{
			a[i][j] = 0;
		}
	}
	for(int i =1;i <=n;i++)
	{
		ifs >> c;
		ifs >> b;
		a[c][b] =1;
		a[b][c] =1;
	}
}
void xuatMT(int n)
{
	for(int i =1;i<=n;i++)
	{
		for(int j =1;j<=n;j++)
		{
		cout<<	a[i][j] <<  " ";
		}
		cout << endl;
	}
}
void DFS1(int start, int n)
{
	//cout << start << " ";
	tham[start]=1;
	for(int i =1;i<=n;i++)
	{
		if(tham[i] == 0&&a[start][i]==1) // neu nhu mang tham ma bang 0 va dinh truoc no voi j co duong di 
		// thi cho tham[i] = 1
		{
			truoc[i] =start;
			DFS1(i,n);
		}
	}
}
void DFS(int n)
{
	for(int i =1;i<=n;i++) tham[i] =0; // gan cho tat ca cac dinh tai mang tham =0 <chutham>
	for(int j =1;j<=n;j++) // duyet mang tham xem dinh nao chua tham 
		if(tham[j] == 0) DFS1(j,n); // neu chua thi xem thi goi DFS1;
	
}
void BFS1(int i,int n)
{
	int queue[100], c,b;
	b=c=0;
	// B1 tu dinh i chua tham cat i vao hang doi b danh dau tham[i] =1
	queue[b++] =i;  
	tham[i]=1;
	// cho mot vong lap duyet dem khi het dinh
	while(b!=c)
	{
		//B2: 
		i=queue[c++]; // lay mot dinh i tu hang doi b cho vao hang doi c
		//cout << i;
		// duyet mang tham
		for(int j =1;j<=n;j++)
		{
			if(tham[j] == 0&&a[i][j]==1) // neu j, i ke nhau thi 
			{
				truoc[j] =i;
				// cat j vao hang doi b
				queue[b++] = j;
				//  cho tham[j] =1
				tham[j] =1;
			}
		}
	}
}
void BFS(int n){
	for(int i =1;i<=n;i++)
		tham[i]=0;
		
	for(int j =1;j<=n;j++)
		if(tham[j]==0)
			BFS1(j,n);
}
int stack[100], CE[100];
int top =-1;
int top1 =-1;
int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}
   
int isfull() {

   if(top == 100)
      return 1;
   else
      return 0;
}

int peek() {
   return stack[top];
}


int pop() {
   int data;
	
   if(!isempty()) {
      data = stack[top];
      top = top - 1;   
      return data;
   }else {
      printf("Khong the thu thap du lieu, ngan xep (Stack) la trong.\n");
   }
}

int push(int data) {

   if(!isfull()) {
      top = top + 1;   
      stack[top] = data;
   }else {
      printf("Khong the chen du lieu, ngan xep (Stack) da day.\n");
   }
}
int isempty1() {

   if(top1 == -1)
      return 1;
   else
      return 0;
}
   
int isfull1() {

   if(top1 == 100)
      return 1;
   else
      return 0;
}
int popCE() {
	int data;
   if(!isempty()) {
      data = CE[top1];
      top = top1 - 1;   
      return data;
   }else {
      printf("Khong the thu thap du lieu, ngan xep (Stack) la trong.\n");
   }
}

int pushCE(int data) {

   if(!isfull()) {
      top1 = top1 + 1;   
      CE[top1] = data;
   }else {
      printf("Khong the chen du lieu, ngan xep (Stack) da day.\n");
   }
}
void Euler_Cycle(int n, int xp)
{
	push(xp);
	while(isempty()!=1)
	{
		int x = stack[top];
		for(int i=1;i<=n;i++)
		{
			if(a[x][i]==1)
			{
				push(i);
				a[x][i]=0;
				a[i][x] =0;
			}
			else
			{
				push(pop());
			}
		}
	}
	while(isempty1()!=1)
	{
		cout << pop() << "	";
	}
}
int main()
{
	int n,v,s,t;
	//cin >> s >> t;
	DocFile(n);
	xuatMT(n);
//	DFS(n);
//	BFS1(s,n); 
//	if (tham[t]==0) cout<<"khong co duong di";
//	else{	
//		cout<<t ; v=t ;
//		do{
//			v=truoc[v]; 
//			cout<< "<-"<<v ;
//		}while(v !=s);
//	}	
	Euler_Cycle(n,1);
}
    
