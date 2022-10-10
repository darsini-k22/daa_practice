//fractional knapsack
#include<bits/stdc++.h>
using namespace std;

class Item{
  public:
  int profit;
  int weight;
  
  
  Item(int profit,int weight){
      this->profit=profit;
      this->weight=weight;
  }
};

bool cmp(Item a,Item b){
    double r1=(double)a.profit/(double)a.weight;
    double r2=(double)b.profit/(double)b.weight;
    return r1>r2;
}

void knapsack(int W,Item arr[],int n){
    sort(arr,arr+n,cmp);
    
    double finalResult=0.0;
    
    for(int i=0;i<n;i++){
        if(arr[i].weight<=W){
            W-=arr[i].weight;
            finalResult+=arr[i].profit;
        }
        else{
            finalResult+=arr[i].profit*((double)W/(double)arr[i].weight);
        }
    }
    cout<<"Max weight is: "<<finalResult;
}

int main(){
    int W = 50; //    Weight of knapsack
    Item arr[] = { { 60, 10 }, { 100, 20 }, { 120, 30 } };
    int N = sizeof(arr) / sizeof(arr[0]);
    knapsack(W, arr, N);
    return 0;
}
