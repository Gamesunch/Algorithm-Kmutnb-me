#include <iostream>

using namespace std;

void intersection(int A[],int B[],int n){
  for(int i = 0;i<n;i++){
    for(int j = 0;j<n;j++){
      if(A[i] == B[j]){
        cout << A[i] << " ";
      }
    }
  }
  cout<<endl;
}

void Union(int A[],int B[],int n){
  int U[n+n];
  int size = 0;
  //add first array
  for(int i = 0;i<n;i++){
    U[size] = A[i];
    size++;
  }
  //add second array
  for(int i = 0;i<n;i++){
    bool found = false;

    for(int j = 0;j<size;j++){
      if(U[j] == B[i]){
        found = true;
      }
    }

    if(!found){
      U[size] = B[i];
      size++;
    }
  }

  for (int i = 0; i < size; i++) {
      cout << U[i] << " ";
  }
  cout << endl;

}

int main(){
  int n;
  cin >> n;
  int A[n];
  int B[n];

  for(int i = 0;i<n;i++){
    cin >> A[i];
  }

  for(int i = 0;i<n;i++){
    cin >> B[i];
  }

  intersection(A,B,n);
  Union(A,B,n);


}