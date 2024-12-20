#include <iostream>
#include <map>
#include <climits>
using namespace std;

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = (left-1);
    for (int j = left; j <= right-1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[right]);
    return (i+1);
}

void quickSort(int arr[], int left, int right) {
    if (left >= right) return;
    int index = partition(arr, left, right);
    quickSort(arr, left, index-1);
    quickSort(arr, index+1, right);
}

int main() {
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    int diff = INT_MAX;
    map<pair<int,int>, int> m;
    for (int i = 1; i < n; i++) {
        diff = min(diff, arr[i] - arr[i-1]);
        m[{arr[i], arr[i-1]}] = arr[i] - arr[i-1];
    }
	map<pair<int,int>, int> :: iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        if ((*it).second == diff) {
            cout << (*it).first.second << " " << (*it).first.first << " ";
        }
    }
    return 0;
}