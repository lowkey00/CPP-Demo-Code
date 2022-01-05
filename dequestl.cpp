#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    deque<int> dq;
    for (int i = 0; i < k; i++) {
        while (!dq.empty()) {
            int back = dq.back();
            if (arr[back] < arr[i]) {
                dq.pop_back();
            } else break;
        }
        dq.push_back(i);
    }
    int idx;
    for (int i = k; i < n; i++) {
        idx = dq.front();
        cout << arr[idx] << " ";
        while (!dq.empty()) {
            int front = dq.front();
            if (front <= i - k) dq.pop_front();
            else break;
        }
        while (!dq.empty()) {
            int back = dq.back();
            if (arr[back] < arr[i]) {
                dq.pop_back();
            } else break;
        }
        dq.push_back(i);
    }
    idx = dq.front();
    cout << arr[idx];
    cout << '\n';
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}

