#include <iostream>
#include <stdlib.h>
using namespace std;
char a[4][4];
int v[10],cnt=1,k,joc=1,s,so=0,sc=0;
void init()
{
    int i,j;
    for(i=1;i<=3;i++)
        for(j=1;j<=3;j++)
            a[i][j]=0;
    for(i=1;i<=9;i++)
        v[i]=0;
}
void afis()
{
    cout<<endl<<"                    X si O || Jocul nr. "<<cnt<<" || Scor: Jucator "<<so<<" vs "<<sc<<" CPU"<<endl;
    cout<<endl<<endl<<endl;
    int i,j;
    for(i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            if(j==1)
                cout<<"                                     ";
            cout<<a[i][j];
            if(j!=3)
                cout<<" | ";
        }
        if(i!=3)
        cout<<endl<<"                                    -----------"<<endl;
    }
    cout<<endl<<endl<<endl;
    cout<<"    HELP: Pozitiile din tabla sunt numerotate cu cifre de la 1 la 9 dupa cum urmeaza:"<<endl<<endl;
    cout<<"          1|2|3"<<endl;
    cout<<"          -----"<<endl;
    cout<<"          4|5|6"<<endl;
    cout<<"          -----"<<endl;
    cout<<"          7|8|9"<<endl<<endl;
    /*for(i=1;i<=9;i++)
        cout<<v[i]<<" ";
    */
}
void citire()
{
    int k;
    cout<<endl<<endl<<"       Efectuati mutarea...";
    cin>>k;
    while(v[k]!=0)
    {
        cout<<endl<<"Pozitia nu este libera!";
        cin>>k;
    }
    v[k]=1;
    if(k<=3)
        a[1][k]='X';
    else
    {
        if(k<=6)
            a[2][k-3]='X';
        else
            a[3][k-6]='X';
    }
}
void completare()
{
    int k,i;
    if(v[1]==0||v[3]==0||v[7]==0||v[9]==0)
    {
        if(v[1]==0&&a[1][2]=='X')
        {
            v[1]=1;
            a[1][1]='O';
        }
        else
        {

            if(v[3]==0&&a[1][2]=='X')
            {
                v[3]=1;
                a[1][3]='O';
            }
            else
            {
                if(v[7]==0&&a[3][2]=='X')
                {
                    v[7]=1;
                    a[3][1]='O';
                }
                else
                    if(v[9]==0&&a[3][2]=='X')
                    {
                        v[9]=1;
                        a[3][3]='O';
                    }
                    else
                    {
                         for(i=1;i<=9;i++)
                            if(v[i]==0)
                            {
                                k=i;
                                break;
                            }
                        v[k]=1;
                        if(k<=3)
                        a[1][k]='O';
                        else
                        {
                            if(k<=6)
                                a[2][k-3]='O';
                            else
                                a[3][k-6]='O';
                        }
                    }

            }
        }
    }
    else
    {
        for(i=1;i<=9;i++)
            if(v[i]==0)
            {
                k=i;
                break;
            }
        v[k]=1;
        if(k<=3)
            a[1][k]='O';
        else
        {
            if(k<=6)
                a[2][k-3]='O';
            else
                a[3][k-6]='O';
        }
    }
}
int verificare()
{
    int i;
    s=0;
    for(i=1;i<=9;i++)
        s=s+v[i];
    if(s==9)
        return 1;
    for(i=1;i<=3;i++)
        if((a[i][1]==a[i][2]&&a[i][2]==a[i][3])&&(a[i][1]=='X'||a[i][1]=='O'))
            return 1;
    for(i=1;i<=3;i++)
        if((a[1][i]==a[2][i]&&a[2][i]==a[3][i])&&(a[1][i]=='X'||a[1][i]=='O'))
            return 1;
    if((a[1][1]==a[2][2]&&a[2][2]==a[3][3])&&(a[1][1]=='X'||a[1][1]=='O'))
        return 1;
    if((a[1][3]==a[2][2]&&a[2][2]==a[3][1])&&(a[3][1]=='X'||a[3][1]=='O'))
        return 1;
    return 0;
}
int checklose()
{
    int i,j;
    for(i=1;i<=3;i++)
        if((a[i][1]=='X'&&a[i][2]=='X'&&a[i][3]!='O')||(a[i][1]=='X'&&a[i][3]=='X'&&a[i][2]!='O')||(a[i][2]=='X'&&a[i][3]=='X'&&a[i][1]!='O'))
            for(j=1;j<=3;j++)
                if(a[i][j]!='X')
                {
                    if(i==1)
                    {
                        a[i][j]='O';
                        v[j]=1;
                        return 1;
                    }
                    if(i==2)
                    {
                        a[i][j]='O';
                        v[j+3]=1;
                        return 1;
                    }
                    if(i==3)
                    {
                        a[i][j]='O';
                        v[j+6]=1;
                        return 1;
                    }
                }
    for(i=1;i<=3;i++)
        if((a[1][i]=='X'&&a[2][i]=='X'&&a[3][i]!='O')||(a[1][i]=='X'&&a[3][i]=='X'&&a[2][i]!='O')||(a[2][i]=='X'&&a[3][i]=='X'&&a[1][i]!='O'))
            for(j=1;j<=3;j++)
                if(a[j][i]!='X')
                {
                    if(j==1)
                    {
                        a[j][i]='O';
                        v[i]=1;
                        return 1;
                    }
                    if(j==2)
                    {
                        a[j][i]='O';
                        v[i+3]=1;
                        return 1;
                    }
                    if(j==3)
                    {
                        a[j][i]='O';
                        v[i+6]=1;
                        return 1;
                    }
                }
    if((a[1][1]=='X'&&a[2][2]=='X'&&a[3][3]!='O')||(a[1][1]=='X'&&a[3][3]=='X'&&a[2][2]!='O')||(a[2][2]=='X'&&a[3][3]=='X'&&a[1][1]!='O'))
    {
        if(a[1][1]!='X')
        {
            a[1][1]='O';
            v[1]=1;
            return 1;
        }
        if(a[2][2]!='X')
        {
            a[2][2]='O';
            v[5]=1;
            return 1;
        }
        if(a[3][3]!='X')
        {
            a[3][3]='O';
            v[9]=1;
            return 1;
        }
    }
    if((a[3][1]=='X'&&a[2][2]=='X'&&a[1][3]!='O')||(a[3][1]=='X'&&a[1][3]=='X'&&a[2][2]!='O')||(a[2][2]=='X'&&a[1][3]=='X'&&a[3][1]!='O'))
    {
       if(a[3][1]!='X')
        {
            a[3][1]='O';
            v[7]=1;
            return 1;
        }
        if(a[2][2]!='X')
        {
            a[2][2]='O';
            v[5]=1;
            return 1;
        }
        if(a[1][3]!='X')
        {
            a[1][3]='O';
            v[3]=1;
            return 1;
        }
    }
    return 0;
}
int checkwin()
{
    int i,j;
    for(i=1;i<=3;i++)
        if((a[i][1]=='O'&&a[i][2]=='O'&&a[i][3]!='X')||(a[i][1]=='O'&&a[i][3]=='O'&&a[i][2]!='X')||(a[i][2]=='O'&&a[i][3]=='O'&&a[i][1]!='X'))
            for(j=1;j<=3;j++)
                if(a[i][j]!='O')
                {
                    if(i==1)
                    {
                        a[i][j]='O';
                        v[j]=1;
                        return 1;
                    }
                    if(i==2)
                    {
                        a[i][j]='O';
                        v[j+3]=1;
                        return 1;
                    }
                    if(i==3)
                    {
                        a[i][j]='O';
                        v[j+6]=1;
                        return 1;
                    }
                }
    for(i=1;i<=3;i++)
        if((a[1][i]=='O'&&a[2][i]=='O'&&a[3][i]!='X')||(a[1][i]=='O'&&a[3][i]=='O'&&a[2][i]!='X')||(a[2][i]=='O'&&a[3][i]=='O'&&a[1][i]!='X'))
            for(j=1;j<=3;j++)
                if(a[j][i]!='O')
                {
                    if(j==1)
                    {
                        a[j][i]='O';
                        v[i]=1;
                        return 1;
                    }
                    if(j==2)
                    {
                        a[j][i]='O';
                        v[i+3]=1;
                        return 1;
                    }
                    if(j==3)
                    {
                        a[j][i]='O';
                        v[i+6]=1;
                        return 1;
                    }
                }
    if((a[1][1]=='O'&&a[2][2]=='O'&&a[3][3]!='X')||(a[1][1]=='O'&&a[3][3]=='O'&&a[2][2]!='X')||(a[2][2]=='O'&&a[3][3]=='O'&&a[1][1]!='X'))
    {
        if(a[1][1]!='O')
        {
            a[1][1]='O';
            v[1]=1;
            return 1;
        }
        if(a[2][2]!='O')
        {
            a[2][2]='O';
            v[5]=1;
            return 1;
        }
        if(a[3][3]!='O')
        {
            a[3][3]='O';
            v[9]=1;
            return 1;
        }
    }
    if((a[3][1]=='O'&&a[2][2]=='O'&&a[1][3]!='X')||(a[3][1]=='O'&&a[1][3]=='O'&&a[2][2]!='X')||(a[2][2]=='O'&&a[1][3]=='O'&&a[3][1]!='X'))
    {
       if(a[3][1]!='O')
        {
            a[3][1]='O';
            v[7]=1;
            return 1;
        }
        if(a[2][2]!='O')
        {
            a[2][2]='O';
            v[5]=1;
            return 1;
        }
        if(a[1][3]!='O')
        {
            a[1][3]='O';
            v[3]=1;
            return 1;
        }
    }
    return 0;
}
int main()
{
    while(joc!=0)
    {
    init();
    afis();
    citire();
    if(a[2][2]=='X')
    {
        a[3][1]='O';
        v[7]=1;
        system("CLS");
        afis();
        citire();
        if(a[1][3]=='X')
        {
            a[1][1]='O';
            v[1]=1;
            system("CLS");
            afis();
            citire();
        }
    }
    else
    {
        if(a[1][1]=='X'||a[1][3]=='X'||a[3][1]=='X'||a[3][3]=='X')
        {
            a[2][2]='O';
            v[5]=1;
            system("CLS");
            afis();
            citire();
            if(a[1][1]=='X'&&a[3][3]=='X')
            {
                a[1][2]='O';
                v[2]=1;
                system("CLS");
                afis();
                citire();
            }
            if(a[1][3]=='X'&&a[3][1]=='X')
            {
                a[1][2]='O';
                v[2]=1;
                system("CLS");
                afis();
                citire();
            }
        }
        else
        {
            a[2][2]='O';
            v[5]=1;
            system("CLS");
            afis();
            citire();
            if(checklose()==0)
            {
                if(a[1][1]!='X')
                {
                    a[1][1]='O';
                    v[1]=1;
                    system("CLS");
                    afis();
                    citire();
                }
                else
                {
                    if(a[1][3]!='X')
                    {
                        a[1][3]='O';
                        v[3]=1;
                        system("CLS");
                        afis();
                        citire();
                    }
                    else
                    {
                        if(a[3][1]!='X')
                        {
                            a[3][1]='O';
                            v[7]=1;
                            system("CLS");
                            afis();
                            citire();
                        }
                        else
                        {
                            if(a[3][3]!='X')
                            {
                                a[3][3]='O';
                                v[9]=1;
                                system("CLS");
                                afis();
                                citire();
                            }
                        }
                    }
                }
            }
            else
            {
                system("CLS");
                afis();
                citire();
            }
        }
    }
    do
    {
        if(verificare()==0)
            if(checkwin()==0)
                if(checklose()==0)
                    completare();
        if(verificare()==0)
        {
            system("CLS");
            afis();
            citire();
        }

    }while(verificare()==0);
    system("CLS");
    afis();
    if(s==9)
        cout<<endl<<"        Jocul s-a terminat la egalitate!"<<endl<<endl;
    else
    {
        cout<<"Ati pierdut!"<<endl<<endl;
        sc++;
    }
    cout<<endl<<endl<<"Continuati jocul? 1-Da   2-Nu ...";
    cin>>k;
    if(k==2)
    {
        joc=0;
        cnt++;
    }
    else
        cnt++;
    system("CLS");
    }
    return 0;
}
