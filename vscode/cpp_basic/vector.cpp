#include <iostream> 
#include <vector> 
#include <array> 
using namespace std;
int main()
{
    std::vector<int> demo{1,2};
    for (int i = 0; i < demo.size(); i++) {
        cout << demo[i] << " ";
    }
    cout<<endl;
    //第一种格式用法
    demo.insert(demo.begin() + 1, 3);//{1,3,2}
    for (int i = 0; i < demo.size(); i++) {
        cout << demo[i] << " ";
    }
    cout<<endl;
 
    //第二种格式用法
    demo.insert(demo.end(), 2, 5);//{1,3,2,5,5}
 
    //第三种格式用法
    std::array<int,3>test{ 7,8,9 };
    demo.insert(demo.end(), test.begin(), test.end());//{1,3,2,5,5,7,8,9}
 
    //第四种格式用法
    demo.insert(demo.end(), { 10,11 });//{1,3,2,5,5,7,8,9,10,11}
    for (int i = 0; i < demo.size(); i++) 
        cout << demo[i] << " ";
    cout<<endl;

    demo.pop_back();
    for (int i = 0; i < demo.size(); i++) 
        cout << demo[i] << " ";
    cout<<endl;

    demo.erase(demo.begin()+1);
    for (int i = 0; i < demo.size(); i++) 
        cout << demo[i] << " ";
    cout<<endl;
    // const char a='2';
    //demo.remove(a);

    demo.erase(demo.begin()+1,demo.begin()+3);
    for (int i = 0; i < demo.size(); i++) 
        cout << demo[i] << " ";
    cout<<endl;

    return 0;
}


// #include <vector>
// #include <iostream>
// using namespace std;
 
// int main()
// {
//     vector<int>demo{ 1,2,3,4,5 };
//     demo.pop_back();
//     //输出 dmeo 容器新的size
//     cout << "size is :" << demo.size() << endl;
//     //输出 demo 容器新的容量
//     cout << "capacity is :" << demo.capacity() << endl;
//     for (int i = 0; i < demo.size(); i++) {
//         cout << demo[i] << " ";
//     }
//     return 0;
// }