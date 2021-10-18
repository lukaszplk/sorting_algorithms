#include<iostream>
#include <ctime>
using namespace std;

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify( int i, int roz, int tab[10]){
    int l,p,m;
    l=2*i+1;
    p=2*i+2;
    m=i;
    if((l<roz) && (tab[l]>tab[i])) m = l;
    if((p<roz) && (tab[p]>tab[m])) m = p;
    if(i!=m){
        swap(tab[i],tab[m]);
        heapify(m,roz,tab);
    }
}

void buildheap(int roz, int tab[10]){
    for(int i=roz/2;i>=0;i--) heapify(i,roz,tab);
}

void heap_sort(){
    
}


int main(){
    srand(time(NULL));
    int t[10];
    for(int i=0;i<10;i++){
        t[i] = rand() % 10;
    }

    cout<<"Tablica wejsciowa:"<<endl;
    for(int i=0;i<10;i++){
        cout<<t[i]<<' ';
    }
    buildheap(10,t);
    cout<<"\nTablica wyjsciowa:"<<endl;
    for(int i=0;i<10;i++){
        cout<<t[i]<<' ';
    }

    return 0;
}