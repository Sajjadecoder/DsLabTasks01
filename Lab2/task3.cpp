#include <iostream>
using namespace std;
class Friends
{
    bool friendsArray[5][5] = {{0, 1, 0, 1, 1}, {1, 0, 1, 0, 1}, {0, 1, 0, 0, 0}, {1, 0, 0, 0, 1}, {1, 1, 0, 1, 0}};

public:
    Friends() {}
    void findCommonFriend(int friend1,int friend2)
    {
        
        bool found= false;
        for (int i = 0; i < 5; i++)
        {
            if (friendsArray[friend1][i] && friendsArray[friend2][i])
            {
                cout<<friend1<<" and " <<friend2<<" are common friends with "<<i<<endl;
                found = true;
            }
            
        }
        if (!found)
        {
            cout<<"No common friend found between "<<friend1<<" and "<<friend2;
        }
    }
};
int main()
{
    Friends friendsObj;
    friendsObj.findCommonFriend(0,4);
    friendsObj.findCommonFriend(1,2);
    return 0;
}