#include <iostream>
using namespace std;
int main()
{
    int arr[1000], n;
    for (int i = 0; i < 1000; i++)
    {
        arr[i] = 0;
    }
    cin >> n;
    int st, en;
    for (int i = 0; i < n; i++)
    {
        cin >> st >> en;
        arr[st] += 1;
        arr[en + 1] -= 1;
    }
    
    //Prefix
    for (int i = 1; i <= en; i++)
    {
        arr[i] += arr[i - 1];
    }


    int max = 0;
    int start = 0, end = 0;
    for (int i = 1; i <= en; i++)
    {
    	cout<<i<<endl;
        if (arr[i] > max)
        {
            max = arr[i];
            start = i;
            end = i;
        }
        else if (arr[i] == max && i == end + 1)
        {
            end++;
        }
    }
    cout << start << " " << end << " " << max << endl;
}
