#include<iostream>
using namespace std;
int a[20][20];

void print(int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if(a[i][j] != 0)
            cout <<j<< " ";
    }
    }
    cout<<endl;
}
bool isSafe(int c, int r, int n)
{
    int i;
    for (i = 0; i < r; i++)
    {
        if (a[i][c])
            return false;
    }
    return true;
}
bool solve(int n, int r)
{
    int i;
    if (n == r)
    {
        print(n);
        cout<<endl;
        return true;
    }
    bool ans = false;
    for (i = 0; i < n; i++)
    {
        if (isSafe(i, r, n))
        {
            a[r][i] = 1;
            ans = solve(n, r + 1) || ans;
            a[r][i] = 0;
        }
    }
    return ans;
}

int main()
{
    int n, i, j;
    cout<<"Enter the number of rooks\n";
    cin>>n;
    for(i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            a[i][j] = 0;
    }
    bool ans = solve(n, 0);
    if(ans == false)
        cout<<-1<<endl;
    else
        cout<<endl;
    return 0;
}
