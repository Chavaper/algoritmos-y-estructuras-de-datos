#include <iostream>
#include <vector>
using namespace std;

#define MAX_VALOR 999

vector<pair<int,int>> mov{
    {0,1},
    {1,1},
    {1,0},
    {1,-1},
    {0,-1},
    {-1,-1},
    {-1,0},
    {-1,1}
};

int esRango(int i,int j,int F,int C) {
    return i>=0 and i<F and j>=0 and j<C;
}

int trayecto(vector<vector<char>> &mapa,int i,int j,int iObj,int jObj) {
    if (not esRango(i,j,mapa.size(),mapa[0].size()))
        return MAX_VALOR;
    mapa[i][j] = 'V';
    if (i==iObj and j==jObj)
        return 0;

    int minimo = MAX_VALOR, iMin = MAX_VALOR, jMin = MAX_VALOR;
    int di,dj;
    bool hayMinimo = false;
    for (int m=0; m<mov.size(); m++) {
        di = mov[m].first;
        dj = mov[m].second;
        int tray = MAX_VALOR;
        if ( esRango(i+di,j+dj,mapa.size(),mapa[0].size()) )
            if ( mapa[i+di][j+dj]=='_' )
                tray = 1 + trayecto(mapa,i+di,j+dj,iObj,jObj);

        if (minimo > tray) {
            minimo = tray;
            iMin = i+di;
            jMin = j+dj;
            hayMinimo = true;
        }
    }
    if (hayMinimo==false) {
        mapa[i][j] = '_';
    }else {
        for (int m=0; m<mov.size(); m++) {
            di = mov[m].first;
            dj = mov[m].second;
            if ( !((i+di)==iMin and (j+dj)==jMin) )
                mapa[i][j] = '_';
        }
    }
    return minimo;
}

int main() {
    vector<vector<char>> mapa{
        {'_','_','_','*'},
        {'_','*','_','_'},
        {'_','_','_','_'},
        {'*','_','*','*'},
        {'_','_','_','_'},
        {'_','_','_','_'},
    };

    int minPasos = trayecto(mapa,0,0,5,3);
    cout<<"min pasos: "<<minPasos<<endl;
    cout<<endl;

    for (auto &f: mapa) {
        for (auto &c: f)
            cout<<c<<" ";
        cout<<endl;
    }

    return 0;
}