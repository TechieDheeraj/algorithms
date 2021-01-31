/**
 *      file    :  277_findTheCelebrity.cpp 
 *      author  :  techiedheeraj
 *      created :  2021 Feb 01 00:43:03 
 *      lastMod :  Mon Feb  1 00:43:03 2021 
 **/

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    bool iscelebrity(int i, int n) {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        if (knows(i, j) || !knows(j, i))
          return false;
      }
      return true;
    }

    int findCelebrity(int n) {
      //int gh[n][n];
      //memset(gh, -1, sizeof(gh));

      int celebCandidate = 0;
      for (int i = 0; i < n; ++i) {
        if (knows(celebCandidate, i))
          celebCandidate = i;
      }
      if (iscelebrity(celebCandidate, n)) {
        return celebCandidate;
      }
      return -1;

      /*
      vector<int>celeb(n);
    //  vector<int>out(n, 0);

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          auto res = knows(i, j);
          if (res && i!= j)
            celeb[i] = 1;
          if (!res && i!= j)
            celeb[j] = 1;
        }
      }

      int ret = -1;

      for (int i = 0; i< celeb.size(); ++i)
        if (!celeb[i]) ret = i;

      return ret;
      */
      /*
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          gh[i][j] = (int)knows(i, j);
        }
      }

      vector<int>in(n, 0);
      vector<int>out(n, 0);

      int ret = -1;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (gh[i][j] == 1 && i != j)
            out[i]++;
          if (gh[j][i] == 1 && i != j)
            in[i]++;
        }
        if (out[i] == 0 && in[i] == n-1)
          ret = i;
      }

      return ret;
      */
      /*
      int ret = -1;
      for(int i =0; i < n; ++i) {
        if (out[i] == 0 && in[i] == n-1)
          ret = i;
      }
      return ret;
      */
    }
};
