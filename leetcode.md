## leetcode.79.单词搜索
>给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。

```c++
//穷举回溯
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int len=word.length();
        char *word_c=new char [len+1];
        tochar(word,word_c,len);
        int m=board.size();
        int n=board[0].size();
        bool *visited =new bool[m*n];
        for(int i=0;i<m*n;i++)
            visited[i]=0;
        int pathlenth=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(haspathcore(board,word_c,i,j,m,n,visited,pathlenth))
                {
                    return true;
                }
            }
        }
        delete []visited;
        delete []word_c;
        return false;
    }

    void tochar(string s,char *word_c,int len)
    {
        for(int i=0;i<len;i++)
            word_c[i]=s[i];
        word_c[len]='\0';
    }
    bool haspathcore(vector<vector<char>>&board,char*word_c,int i,int j,int m,int n,bool *visited,int pathlenth)
    {
        if(word_c[pathlenth]=='\0')
            return true;
        bool haspath=0;
        if(i>=0 && i<m && j>=0 && j<n && board[i][j]==word_c[pathlenth] && !visited[i*n+j])
        {
            pathlenth++;
            visited[i*n+j]=1;
            haspath=haspathcore(board,word_c,i-1,j,m,n,visited,pathlenth)
                    ||haspathcore(board,word_c,i,j-1,m,n,visited,pathlenth)
                    ||haspathcore(board,word_c,i,j+1,m,n,visited,pathlenth)
                    ||haspathcore(board,word_c,i+1,j,m,n,visited,pathlenth);
            
            if(!haspath)
            {
                pathlenth--;
                visited[i*n+j]=0;
            }
        }
        return haspath;
    }
};
```
## leecode 剑指offer.11
>把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。  
>给你一个可能存在重复元素值的数组 numbers ，它原来是一个升序排列的数组，并按上述情形进行了一次旋转。请返回
>旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一次旋转，该数组的最小值为 1。  
```c++
//二分（特殊情况顺序）
class Solution {
public:
    int minArray(vector<int>& numbers) {
        int len=numbers.size();
        int p1=0,p2=len-1;
        int mid=p1;
        
        while(numbers[p1]>=numbers[p2])
        {
            if(p2==p1+1)
            {
                mid=p2;
                break;
            }
            int res=INT_MAX,flag;
            if(numbers[mid]==numbers[p1] && numbers[p1]==numbers[p2])
            {
                for(int i=p1;i<=p2;i++)
                {
                    if(numbers[i]<res)
                    {
                        flag=i;
                        res=numbers[i];
                    }
                }
                return numbers[flag];
            }

            mid=(p1+p2)>>1;

            if(numbers[mid]>=numbers[p1])
                p1=mid;
            else if(numbers[mid]<=numbers[p2])
                p2=mid;
        }
        return numbers[mid];
    }
};
```
## leecode 剑指offer.13: 机器人的运动范围
>地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
```c++
class Solution {
public:
    int movingCount(int m, int n, int k) {
        if(k==0) return 1;
        bool *visited=new bool[m*n];
        for(int i=0;i<m*n;i++)
            visited[i]=0;
        int count=movingcore(m,n,0,0,visited,k);
        return count;
        delete[]visited;
    }

    int movingcore(int m,int n,int i,int j,bool *visited,int k)
    {
        int count=0;
        if(check(m,n,i,j,visited,k))
        {
            visited[i*n+j]=1;
            count=1+movingcore(m,n,i-1,j,visited,k)
                   +movingcore(m,n,i,j-1,visited,k)
                   +movingcore(m,n,i+1,j,visited,k)
                   +movingcore(m,n,i,j+1,visited,k);
            //不用回溯
        }
        return count;
    }
    bool check(int m,int n,int i,int j,const bool* visited,int k)
    {
        if((i>=0 && i<m && j>=0 &&j<n && !visited[i*n+j] && getdigitsum(i)+getdigitsum(j)<=k))
            return true;
        return false;
    }
    int getdigitsum(int num)
    {
        int sum=0;
        while(num>0)
        {
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
};
```
## leetcode 剑指 Offer 47. 礼物的最大价值
> 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
```c++
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(m==1 && n==1) return grid[0][0];
        vector<vector<int>>dp(m,vector<int>(n));
        dp[0][0]=grid[0][0];
        for(int i=1;i<m;i++)
            dp[i][0]=dp[i-1][0]+grid[i][0];
        for(int i=1;i<n;i++)
            dp[0][i]=dp[0][i-1]+grid[0][i];

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
                dp[i][j]=grid[i][j]+max(dp[i-1][j],dp[i][j-1]);
        }
        return dp[m-1][n-1];
    }
};
```