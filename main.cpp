#include <iostream>
#include <cstdlib>

using namespace std;

char a[20] = {'-', '-', '-', '-', '-', '-', '-', '-', '-'};
char jucator = 'X';
bool desfasurare = true;
int k=0;
int tip;

void afisare(){
    cout<<endl;
    cout<<a[0]<<" "<<a[1]<<" "<<a[2];
    cout<<endl;
    cout<<"-----";
    cout<<endl;
    cout<<a[3]<<" "<<a[4]<<" "<<a[5];
    cout<<endl;
    cout<<"-----";
    cout<<endl;
    cout<<a[6]<<" "<<a[7]<<" "<<a[8];
    cout<<endl;
    cout<<endl;
}

bool verificare(){
    if(a[0]==a[1] and a[1]==a[2] and a[1]!='-')
        return true;
    if(a[3]==a[4] and a[4]==a[5] and a[4]!='-')
        return true;
    if(a[6]==a[7] and a[7]==a[8] and a[7]!='-')
        return true;
    if(a[0]==a[3] and a[3]==a[6] and a[3]!='-')
        return true;
    if(a[1]==a[4] and a[4]==a[7] and a[4]!='-')
        return true;
    if(a[2]==a[5] and a[5]==a[8] and a[5]!='-')
        return true;
    if(a[0]==a[4] and a[4]==a[8] and a[4]!='-')
        return true;
    if(a[2]==a[4] and a[4]==a[6] and a[4]!='-')
        return true;
    return false;
}



int main()
{
    cout<<"Pentru PvP apasati tasta 1, iar pentru PvC tasta 0: ";
    cin>>tip;
    if(tip==1) cout<<"Modul Player vs Player"<<endl;
    else cout<<"Modul Player vs Computer"<<endl;
    while(desfasurare){
        afisare();
        cout<<"Jucatorul "<<jucator<<" alege o pozitie folosind un numar de la 1 la 9!"<<endl;
        unsigned poz;
        cout<<"Pozitia aleasa: ";
        cin>>poz;
        if(poz>=1 and poz<=9 and a[poz-1]=='-'){
                k++;
                a[poz-1] = jucator;
                if(jucator == 'X') jucator = '0';
                    else jucator = 'X';
        } else cout<<"\t\tPOZITIE GRESITA SAU DEJA OCUPATA!"<<endl;
        if(verificare()){
            afisare();
            if(jucator == 'X') jucator = '0';
                    else jucator = 'X';
            cout<<"\t\tCASTIGATORUL ESTE "<<jucator<<endl;
            cout<<"\t\t     FELICITARI!";
            cout<<endl;
            desfasurare = false;
            break;
        }
        if(k==9 and desfasurare){
            afisare();
            cout<<"\t\t\tEGALITATE!";
            cout<<endl;
            break;
        }
        if(tip==0){
        while(jucator == '0'){
            poz = rand()%10;
            if(poz<=8 and poz>=0 and a[poz]=='-'){
                a[poz]='0';
                jucator = 'X';
            }
        }
        if(verificare()){
            afisare();
            cout<<"\t\tCASTIGATORUL ESTE 0"<<endl;
            cout<<"\t\t     FELICITARI!";
            cout<<endl;
            desfasurare = false;
            break;
        }
        if(k==9 and desfasurare){
            afisare();
            cout<<"\t\t\tEGALITATE!";
            cout<<endl;
            break;
        }
        }
    }
    return 0;
}
