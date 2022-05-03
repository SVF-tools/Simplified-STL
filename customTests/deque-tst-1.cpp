#include <deque>
 
using namespace std;

int main()
{
    deque<int> x = { 1, 3 };
    deque<int> y;
    x.push_back(5);
    y = x;
    int z = x.front();
    z = x.back();

    deque<int>::iterator it = x.begin();
    it = x.end();
    deque<int>::reverse_iterator rit = x.rbegin();
    rit = x.rend();
    return 0;
}

