#include<iostream>
using namespace std;

#include<vector>
#include<algorithm>
class orderArray {
private:
    vector<int> tmp;
public:
    /**
     * @param n: initial size of orderArray
     */
    orderArray(int n) {};

    /**
     * Add a number to the array.
     */
    void add(int x) {
        tmp.push_back(x);
    };

    /**
     * Return the ith smallest element.
     */
    int findnum(int i) {
        sortInClass();
        return tmp[i];
    };

    /**
     * Print all elements in ascending order.
     */
    void show() {
        sortInClass();
        int length = tmp.size();
        for (int i = 0; i < length-1; ++i) {
            cout << tmp[i] << ' ';
        }
        cout << tmp[length - 1] << endl;
    };

    void sortInClass() {
        sort(tmp.begin(), tmp.end());
    }
};
