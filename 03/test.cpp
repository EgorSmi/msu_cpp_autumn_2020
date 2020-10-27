#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v(6);
    vector<int> e;
    v.clear();
    if (v == e)
    {
        cout<<"K"<<endl;
    }
    return 0;
}