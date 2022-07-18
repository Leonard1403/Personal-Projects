#include <bits/stdc++.h>


using namespace std;

ifstream fin("sudoku.in");
ofstream fout("sudoku.out");

const int CMAX = 15;
int mat[CMAX][CMAX] , n = 0;
vector < pair < int , int > > Q;
bool gasit = 0;

void afisare();
void afisare2();

void citire()
{
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            fin >> mat[i][j];
            if(mat[i][j]==0)
            {
                Q.push_back(make_pair(i,j));
                n++;
            }
        }
    }
    n = n-1;
}

bool verificare(int pi , int pj)
{
    for(int qi = 1;qi<=8;qi++)
    {
        if(pi+qi<=9)
        {
            if(mat[pi+qi][pj]==mat[pi][pj]) return false;
        }
        if(pi-qi>=1)
        {
            if(mat[pi-qi][pj]==mat[pi][pj]) return false;
        }
        if(pj+qi<=9)
        {
            if(mat[pi][pj+qi]==mat[pi][pj]) return false;
        }
        if(pj-qi>=1)
        {
            if(mat[pi][pj-qi]==mat[pi][pj]) return false;
        }
    }
    return true;
}

bool verificare2(int pi, int pj)
{
    int defi , defj , spori , sporj;
    defi = defj = spori = sporj = 3;
    for(int ssi=2;ssi<=3;ssi++)
    {
        if(spori<pi)
        {
            spori=defi*ssi;
        }
        else break;
    }
    for(int ssj=2;ssj<=3;ssj++)
    {
        if(sporj<pj)
        {
            sporj=defj*ssj;
        }
        else break;
    }
    for(int qi=spori-2;qi<=spori;qi++)
    {
        for(int qj = sporj-2;qj<=sporj;qj++)
        {
            if(mat[qi][qj]==mat[pi][pj]&&qi!=pi&&qj!=pj)
                return false;
        }
    }
    return true;
}

void rezolvare(int f)
{
    for(int so=1;so<=9&&gasit==0;so++)
    {
        int ci , cj;
        ci = Q[f].first;
        cj = Q[f].second;
        mat[ci][cj] = so;
        if(verificare(ci,cj)==true&&verificare2(ci,cj)==true&&gasit==0)
        {
            if(f==n&&gasit==0)
            {
                afisare2();
                //afisare();
                gasit = 1;
            }
            else if(gasit==0) rezolvare(f+1);
        }
        mat[ci][cj] = 0;
    }
}

void afisare()
{
    for(int j=1;j<=17;j++)
        cout << "_ ";
    cout << '\n';
    for(int i = 1;i<=9;i++)
    {
        cout << mat[i][1];
        for(int j=2;j<=9;j++)
        {
            cout << " | " << mat[i][j];
        }
        cout << '\n';
        for(int j=1;j<=17;j++)
            cout << "- ";
        cout << '\n';
    }
}

void afisare2()
{
    for(int i=1;i<=9;i++)
    {
        for(int j=1;j<=9;j++)
        {
            fout << mat[i][j] << " ";
        }
        fout << '\n';
    }
}
int main()
{
    citire();
    rezolvare(0);
    return 0;
}
