class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        vector<int> s;
        height.push_back(0);

        int area = 0;
        int i = 0;
        while(i<height.size()) {
            if(s.empty() || height[i] > height[s.back()]) {
                s.push_back(i);
                ++i;
            }
            else if(height[i] < height[s.back()]) {
                int t = s.back();  //!!!back() can it be left value?
                //!!! http://blog.csdn.net/mjt_csdn/article/details/45341367
                //
                s.pop_back();  //!!!void pop_back()
                area = max(area, height[t] * (s.empty()?/*since we have not
                height.insert(height.begin(), 0) at the beginning*/ i : i - s.back() - 1) );
            } else {
                s.pop_back();
                // s[s.size()－1] = i; or s.back() = i;
            }
        }
        return area;
    }
};


1.vector<int>  vectorA; //声明空的容器， 不应该写成vector<int> vectorA()；
2.成员函数:

    front()  首元素  //可作为左值或者右值

    back()  尾元素 //可作为左值或者右值

    at() 某一位置元素  //可作为左值或者右值

    resize()  重新定义vector的大小

    copy()   //利用copy实现两个容器向一个容器的复制

    for_each   对遍历的数据进行处理

    sort  对遍历的数据进行排序

Example:
    //front,at,back作为左值
    vecIntA.front() = 4;
    vecIntA.at(1) = 5;
    vecIntA.back() = 6;


    //下面将vecIntA和vecIntB的内容复制到C中
    vector<int> vecIntB(4,8);
    vector<int> vecIntC;
    //重新定义大小
    vecIntC.resize(vecIntA.size()+vecIntB.size());

    //先将A拷贝到C中，并更新迭代器的值。这是的iClast指向iC末尾元素的下一个位置。
    vector<int>::iterator iClast = copy(vecIntA.begin(),vecIntA.end(),vecIntC.begin());
    //利用上次的迭代器，将B拷贝到C
    copy(vecIntB.begin(),vecIntB.end(),iClast);

    #include <algorithm>   //for_each
    void add(int& lhs) {//用于for_each
        lhs++;
    }
    for_each(vecIntC.begin(),vecIntC.end(),add);//for_each的第三个参数写函数名，即add

