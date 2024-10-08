#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> ii;

const int MAXN = 1000;

int a[MAXN][MAXN], m, n, r, c, d[MAXN][MAXN];

int dx[] = {1, 0, -1, 0},
    dy[] = {0, 1, 0, -1};

queue<ii> qe;

int solve(){
    qe.push(ii(r,c));
    d[r][c] = 0;
    a[r][c] = 1;
    while(!qe.empty()){
        ii u = qe.front(); qe.pop();
        for(int i = 0; i < 4; i++){
            int x = dx[i] + u.first;
            int y = dy[i] + u.second;

            if(x < 1 || x > m || y < 1 || y > n){
                return d[u.first][u.second] + 1;
            }

            if(a[x][y] != 1){
                d[x][y] = d[u.first][u.second] + 1;
                qe.push(ii(x,y));
                a[x][y] = 1;
            }
        }
    }
    
    return -1;

}

int main(){
    cin >> m >> n >> r >> c;

    for (int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    int ans = solve();
    cout << ans;
    return 0;
}

