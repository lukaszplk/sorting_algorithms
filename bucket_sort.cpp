#include <iostream>
#include<time.h>
#include<vector>

using namespace std;

void wypisz(int tab[], int size) {
    for(int i=0;i<size;i++)
        cout << tab[i] << " ";
    cout << endl;
}

void insert_sort(int tab[], int size){
    int counter=0;
    for(int i=0;i<size;i++){
        int tmp=tab[i];
        int j;
        for(j=i-1;j>=0;j--){
            counter++;
            if(tab[j]>tmp){
                tab[j+1]= tab[j];
            }else{
                break;
            }
        }
        tab[j+1]=tmp;
    }
}

void bucket_sort(int tab[], int size, int max) {
    int **buckets = new int *[10];
    //cout<<"1"<<endl;
    for(int i=0;i<10;i++){
        buckets[i] = new int [size];
    }
    //cout<<"2"<<endl;
    for(int i=0;i<10;i++){
        for(int j=0;j<size;j++){
            buckets[i][j] = -1;
        }
    }
    //cout<<"3"<<endl;
    for(int i=0;i<size;i++){
        buckets[max-tab[i]][i]=tab[i];
    }
    //cout<<"4"<<endl;
    for(int i=0;i<10;i++){
        insert_sort(buckets[i], size);
    }
    //cout<<"5"<<endl;
    int n=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<size;j++){
            if(buckets[i][j]>-1){
                tab[n] = buckets[i][j];
                n++;
            }
            
        }
    }
    //cout<<"6"<<endl;
}



int main()
{
    srand(time(NULL));
    int t[20];
    for(int i=0;i<20;i++)
        t[i] = rand() % 10;

    cout<<"Tablica wejsciowa:"<<endl;
    wypisz(t, 20);
    bucket_sort(t, 20, 9);
    cout<<"\nTablica wyjsciowa:"<<endl;
    wypisz(t, 20);

    return 0;
}