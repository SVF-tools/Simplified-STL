#include <vector>

using namespace std;

int main()
{
    vector<int> x, y;
    x.push_back(1);
    x.push_back(2);
    x.push_back(3);
    x.push_back(4);
    
    y=x;

    x.pop_back();

    int z = x.front();
    z= x.back();
    
    y[3] = x.at(0);

    vector<int>::const_iterator it = x.begin();
    it = x.end();

    vector<int>::reverse_iterator rit = x.rbegin();
    rit = x.rend();

    x.empty();
    x.size();
    x.resize(5, 3);
    x.resize(3);
    x.max_size();

    x.insert(x.begin()+1, 8);
    x.erase(x.begin()+1);
    x.swap(y);
    
    x.clear();


    return 0;
}

