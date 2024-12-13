#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
    int capacity = 4;
    int arr[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    deque<int> q;
    int page_faults = 0;

    for (int i : arr) {
        auto it = find(q.begin(), q.end(), i);

        if (it == q.end()) {
            ++page_faults;
            if (q.size() == capacity) {
                q.pop_back();
            }
        } else {
            q.erase(it);
        }
        q.push_back(i);
    }

    cout << "Total Page Faults: " << page_faults << endl;
    return 0;
}
