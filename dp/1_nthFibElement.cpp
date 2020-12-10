/**
 *      file    :  1_fibSeries.cpp
 *      author  :  techiedheeraj
 *      created :  2020 Dec 10 17:54:39
 *      lastMod :  Thu Dec 10 17:54:39 2020
 **/

#include <bits/stdc++.h>
using namespace std;

class FibElement {
  public:
    int elem = 0;
    vector<int>mem;
    FibElement(int n) {
      elem = n;
      mem.resize(elem+1);
    }

    /* In the recursion tree count all nodes created and count level by level
     * 1+2^1+2^2+2^3+2^4+2^5......2^n-1 ------> Sum of Geometric Progression(GP)
     * which is 1 * (2^n -1) / 2-1 ---> a*(r^n -1)/r-1
     * TC: O(2^n)
     * SC: O(n * stackSize)
     */
    int fibElement1(int n) {
      if (n <=2) return 1;
      return fibElement1(n-1) + fibElement1(n-2);
    }

    /*  TOP DOWN DP
     *
     * In this recursion we are memorizing the previous calculated values
     * In the recursion tree all nodes maximum have 2 childrens
     * TC: C*n = O(n)
     * SC: O(n+n) (stack size + array size)
     */
    int fibElement2(int n, vector<int>&aux) {
      if (n <= 2) return 1;
      if (aux[n] != 0) return aux[n];

      aux[n] = fibElement2(n-1, aux)+fibElement2(n-2, aux);
      return aux[n];
    }

    /*  BOTTOM UP DP
     *
     * In this recursion we are memorizing the previous calculated values
     * and just running iterative loop without need of recursion
     * TC: O(n) 
     * SC: O(n)
     */
    int fibElement3(int n, vector<int>&aux) {
      if (n <= 2) return 1;
      
      int res = 1;

      aux[1] = 1;
      aux[2] = 1;

      for(int i = 3; i <= n; ++i) {
        res = aux[i-1]+aux[i-2];
        aux[i] = res;
      }
      return res;
    }

    /* Optimizing fibElement3 for space
     *
     * As we just need previous two values why to take the array of n+1 elements
     *
     * TC: O(n)
     * SC: O(1)
     */
    int fibElement4(int n) {
      if (n <=2) return 1;

      int res = 1;

      int prev = 1;
      int pprev = 1;

      for (int i = 3; i <=n ; ++i) {
        res = prev+pprev;
        pprev = prev;
        prev = res;
      } 

      return res;
    }

    int findNthElement() {
      //return fibElement1(this->elem);
      //return fibElement2(this->elem, mem);
      //return fibElement3(this->elem, mem);
      return fibElement4(this->elem);
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int element = 0;
  cout << "Enter nth element" << "\n";
  cin >> element;

  FibElement fser = FibElement(element);

  cout << fser.elem << "th Element is " << fser.findNthElement() << "\n";

  return 0;
}    
