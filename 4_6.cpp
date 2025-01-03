#include <iostream>
#include <algorithm>

using namespace std;

//I know this code is shit but idk how to do it anymore. don't care anymore if better approch tell me, I would be please.
int main() {
    // Example input
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    // Calculate the total number of digits
    int size = 0;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int digitCount = 0;
        while (num > 0) {
            digitCount++;
            num /= 10;
        }
        size += digitCount;
    }

    // Dynamically allocate memory for arr2
    int* arr2 = new int[size]; 

    // Convert from many digits into single digits
    int index = 0; 
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int temp[10];
        int digitCount = 0;
        while (num > 0) {
            temp[digitCount++] = num % 10;
            num /= 10;
        }

        for (int j = digitCount - 1; j >= 0; j--) {
            arr2[index++] = temp[j];
        }
    }

    // Print the resulting array (output 1)
    for (int i = 0; i < size; i++) {
        cout << arr2[i];
    }
    cout<<endl;


	int arr3[size];
	for(int i = 0;i<=size;i++){
		arr3[i] = arr2[i];
	}
	
	
    // Print mode (output 2)
    // need to fix this code doesn't work like i expect, but now i need to rest.
    int maxCount = -10000;
    int tempCount = 0;
    for(int i = 0;i<size;i++){
      tempCount = 0;
      for(int j = i;j<size;j++){
        if(arr2[i] == arr2[j]){
          tempCount++;
        }
        else{
          break;
        }

        if(tempCount >= maxCount){
          maxCount = tempCount;
        }
      }
    }

	sort(arr2, arr2+size);
	
    for(int i = 0;i<size;i++){
      tempCount = 0;
      for(int j = i;j<size;j++){
        if(arr2[i] == arr2[j]){
          tempCount++;
        }
        else{
          break;
        }
      }
      if(tempCount == maxCount){
          cout<<arr2[i]<<" ";
        }
    }
    cout<<endl;

    //output 3 (reduce same num)
    for(int i = 0; i <= size; i++){
      for(int j = i + 1; j <= size; j++){

        if(arr3[i] != arr3[j]){
          cout<<arr3[i];
          break;
        }
        else{
          break;
        }
      }
    }
    cout << endl;

    return 0;
}
