#include <iostream>

using namespace std;
int max (const int list[], int start, int stop, int max_val)
{
    if (start == stop)
        return max_val;
    else
    {
        if (list[start] > max_val)
            max_val = list[start];
        start++;
        max(list,start,stop,max_val);
    }
}
int min(const int list[], int start, int stop, int min_val)
{
    if (start == stop)
        return min_val;
    else
    {
        if (list[start] < min_val)
            min_val = list[start];
        start++;
        max(list,start,stop,min_val);
    }
    return 0;
}
int main() {
    int nums [10];
    int num;
    int i = 0;
    while (i < 9){
        cin >> num;
        nums[i] = num;
        i++ ;
    }
    cout << max(nums,0,9,0) << endl;
    cout << min(nums,0,9,0) << endl;
    
    return 0;
}
