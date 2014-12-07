//
//  main.cpp
//  Substitution cipher
//
//  Created by Sergey Prischenko on 12/7/14.
//  Copyright (c) 2014 Sergey Prischenko. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string str;
char diction[27]="abcdefghijklmnopqrstuvwxyz";

int swap(char *c,int a,int b){
    char temp=c[a];
    c[a]=c[b];
    c[b]=temp;
    return 1;
}
int fish(char *a,int n,char *b){
    for (int j=0; j<n; j++) {
        char g=a[j];
        b[j]=g;
    }
    for (int i=n-1; i>=0; i--) {
        swap(b,i,rand()%n);
    }
    return 1;
}
int cipher(char *key_diction){
    int index;
    for (int i=0; i<str.length(); i++) {
        index=(int)str[i]-'a';
        str[i]=key_diction[index];
    }
    return 1;
}
int decipher (char *key_dection)
{
    for (int i=0; i<str.length(); i++) {
        for (int j=0; j<27; j++) {
            if (str[i]==key_dection[j]) {
                str[i]=diction[j];
                break;
            }
        }
    }
    return 1;
}
int main(){
    const int n=27;
    int l=0;
    char key[n];
    fish(diction,26, key);
    cout<<"Введите строку: "<<endl;
    getline(cin,str);
    while (!(l==1||l==2)) {
        cout<<"Шифруем(1) или дешифруем(2)? \n";
        cin>>l;
    }
    if (l==1) cipher(key);
    if (l==2) decipher(key);
    cout<<str;
    return 0;
}
