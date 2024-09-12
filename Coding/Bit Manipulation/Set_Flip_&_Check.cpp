
// https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/description/

// sol : https://www.youtube.com/watch?v=ZKhOyAC4X6o&list=PL0G2Ga9ALv6kKWhJAkxU1ZUcwYu7ZFx5N&index=13

class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int ans = 0, i;
        for (i = 0; i < 32; i++)
        {
            int cnt = 0, x, y, z;
            x = ((a >> i) & 1); // 1 ase naki check korte si
            y = ((b >> i) & 1);
            z = ((c >> i) & 1);
            cnt = x + y;
            if (z == 0)
                ans += cnt;
            else
            {
                if (cnt == 0)
                    ans++;
            }
        }
        return ans;
    }
};

// 2nd approach

class Solution
{
public:
    int minFlips(int a, int b, int c)
    {
        int n = a | b;  // here we are taking the or of a and b
        int cnt = 0;
        //cout << n << " " << c << endl;
        for (int i = 0; i < 32; i++)
        {
            int t1 = (n >> i) & 1;
            int t2 = (c >> i) & 1;
            if (t1 != t2) // if the ith bit of n and c is not equal then we have to check if ith bit of c is 1 or 0, if 1 then it means we have to flip 1 time to make a | b = 1 and if not then we have to check both a and b if only one of them is 1 then wh have to flip 1 or if both are 1 then flip 2 times 
            {
                if (t2)
                {
                    cnt++;
                }
                else
                {
                    if ((a >> i) & 1)
                    {
                        cnt++;
                    }
                    if ((b >> i) & 1)
                    {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};