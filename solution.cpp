#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
using namespace sol77;
using namespace std;

/*takeaways
  - {1,2,3,4}
    - you pick 1 to produce all possible combinations recursivly
      that
      - you can produce {1,2}, {1,3}, and {1,4}
    - you pick 2 and don't pick anything smaller than 2
      - we use a loop to make sure we don't pick the numbers
        smaller than 2
      - this ensures we will not have duplicates
      - you can produce {2,3} and {2,4}
    - you pick 3 and don't pick anything smaller than 3
      - you can produce {3,4}
*/

void Solution::_find(int picked, int n,
                     int k, vector<int> &combination, vector<vector<int>> &result)
{
  if ((int)combination.size() == k)
  {
    result.push_back(combination);
    return;
  }

  /* let's say i start from 1, when it's 2
     we can't pick anything smaller than
     2 (which is 1) and hence we won't create
     any combinations that include 1 as its member
     - this is how we eliminate duplicates

  */
  for (auto i = picked; i <= n; i++)
  {
    combination.push_back(i);
    /* can only pick the numbers that are bigger than i */
    _find(i + 1, n, k, combination, result);
    combination.pop_back();
  }
}

vector<vector<int>> Solution::find(int n, int k)
{
  auto result = vector<vector<int>>();
  auto c = vector<int>();

  _find(1, n, k, c, result);

  return result;
}