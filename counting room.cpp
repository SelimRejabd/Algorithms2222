#include<bits/stdc++.h>
#define REP(i,n) for (int i=1; i<=n; i++)
#define mod 10000007
#define pb push_back
#define ff first
#define ss second
#define pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define lli long long int
#define INF 1000000000
#define end1 '\n'
const double PI = 3.14159265;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

using namespace std;
char ar[1000][1000];
bool vis[1001][1001];
int N,M;

bool isValid(int x,int y)
{
    if(x<1 ||x>N || y<1 || y>M) return false;
    if(vis[x][y] == true || ar[x][y] =='#') return false;
    return true;
}

void dfs(int x, int y)
{
    vis[x][y] = true;
    if(isValid(x-1 , y))
        dfs(x-1 , y);

    if(isValid(x, y+1))
        dfs(x,y+1);

    if(isValid(x+1, y))
        dfs(x+1,y);

    if(isValid(x, y-1))
        dfs(x,y-1);

}

int main()
{
    cin>>N>>M;

    for(int i=1; i<=N; i++)
    {
        for(int j=1;j<=M;j++)
        {
            cin>>ar[i][j];
        }
    }

    int cnt=0;

    for(int i=1; i<=N;i++)
    {
        for(int j=1; j<=M;j++)
            if(ar[i][j] == '.' && vis[i][j] == false)
            dfs(i, j) , cnt++;
    }
    cout<<cnt;
}
