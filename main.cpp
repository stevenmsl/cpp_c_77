#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol77;

/*
Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

tuple<int, int, vector<vector<int>>>
testFixture1()
{
  auto output = vector<vector<int>>{
      {2, 4},
      {3, 4},
      {2, 3},
      {1, 2},
      {1, 3},
      {1, 4},
  };
  return make_tuple(4, 2, output);
}

void test1()
{
  auto f = testFixture1();
  cout << "Expect to see: " << Util::toString(get<2>(f)) << endl;
  Solution sol;
  cout << Util::toString(sol.find(get<0>(f), get<1>(f))) << endl;
}

main()
{
  test1();
  return 0;
}