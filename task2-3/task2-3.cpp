#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct diagon {
    int len = 0, sum = 0, maximal = 0, num;
};
bool sort_app(diagon a, diagon b) {
    return ((a.len < b.len) || (a.len == b.len && a.sum < b.sum) || (a.len == b.len && a.sum == b.sum && a.maximal < b.maximal));
}

int main() {
    setlocale(LC_ALL, "RUS");
    freopen("index.txt", "r",stdin);
    int n, m;
    cin >> n >> m;
    vector < vector <int> > M (n, vector<int>(m)) ;
    vector < vector <int> > :: iterator row;
    vector <int> :: iterator col;
    for (row = M.begin(); row != M.end(); row++) {
        for (col = row->begin(); col != row->end(); col++)
            cin >> *col;
    }

    vector <diagon> vec_diagon(n + m - 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            vec_diagon[i + j].num = i + j + 1;
            vec_diagon[i + j].len++;
            vec_diagon[i + j].sum += M[i][j];
            if (vec_diagon[i + j].maximal < M[i][j]) vec_diagon[i+ j].maximal = M[i][j];
        }

    sort(vec_diagon.begin(), vec_diagon.end(), sort_app);
    for (int i = 0; i < n + m - 1; i++) {
        cout << "Diagonal " << vec_diagon[i].num << ": " << "- length - " << vec_diagon[i].len<<", sum - " << vec_diagon[i].sum;
        if (vec_diagon[i].len != 1)
            cout << ", maximum - " << vec_diagon[i].maximal;
        cout<<endl;
    }
    return 0;
}
