#include <bits/stdc++.h>
using namespace std;

// chap sfhe bazi
void chap(char zamin[7][13][3]){
    int i = 0 , j = 0;
    system("cls");

    for ( ; i<=6 ; i++){
        j = 0;
        for ( ; j<=12 ; j++){
            cout<<zamin[i][j][0] ;
        }
            cout<<endl;

    }

}

// mohre be kodam daste talogh darad
int mohreh(char x){

    if (x=='X' || x=='x' || x=='*')
        return 1;
    
    else if (x=='O' || x=='o' || x=='.')
        return 0;

    else{
        return 3;
    }

}

// dar soorat khata
void wrong(char zamin[7][13][3]){
    system("cls");
    cout<<"Wrong!" << endl;
    
    int i = 0 , j = 0;

    for ( ; i<=6 ; i++){
        j = 0;
        for ( ; j<=12 ; j++){
            cout<<zamin[i][j][0] ;
        }
            cout<<endl;

    }
}

// shart payan bazi
int judge(char zamin[7][13][3]){
    
    if (mohreh(zamin[1][2][0]) == mohreh(zamin[3][2][0]) && mohreh(zamin[3][2][0]) == mohreh(zamin[5][2][0]) && mohreh(zamin[1][2][0]) != 3){
        char x = zamin[1][2][0];
        mohreh(x);
    }
    else if (mohreh(zamin[1][6][0]) == mohreh(zamin[3][6][0]) && mohreh(zamin[3][6][0]) == mohreh(zamin[5][6][0]) && mohreh(zamin[1][6][0]) != 3){
        char x = zamin[1][6][0];
        mohreh(x);
    }
    else if (mohreh(zamin[1][10][0]) == mohreh(zamin[3][10][0]) && mohreh(zamin[3][10][0]) == mohreh(zamin[5][10][0]) && mohreh(zamin[1][10][0]) != 3){
        char x = zamin[1][10][0];
        mohreh(x);
    }
    else if (mohreh(zamin[1][2][0]) == mohreh(zamin[1][6][0]) && mohreh(zamin[1][6][0]) == mohreh(zamin[1][10][0]) && mohreh(zamin[1][2][0]) != 3){
        char x = zamin[1][2][0];
        mohreh(x);
    }
    else if (mohreh(zamin[3][2][0]) == mohreh(zamin[3][6][0]) && mohreh(zamin[3][6][0]) == mohreh(zamin[3][10][0]) && mohreh(zamin[3][2][0]) != 3){
        char x = zamin[3][2][0];
        mohreh(x);
    }
    else if (mohreh(zamin[5][2][0]) == mohreh(zamin[5][6][0]) && mohreh(zamin[5][6][0]) == mohreh(zamin[5][10][0]) && mohreh(zamin[5][2][0]) != 3){
        char x = zamin[5][2][0];
        mohreh(x);
    }
    else if (mohreh(zamin[1][2][0]) == mohreh(zamin[3][6][0]) && mohreh(zamin[3][6][0]) == mohreh(zamin[5][10][0]) && mohreh(zamin[1][2][0]) != 3){
        char x = zamin[1][2][0];
        mohreh(x);
    }
    else if (mohreh(zamin[1][10][0]) == mohreh(zamin[3][6][0]) && mohreh(zamin[3][6][0]) == mohreh(zamin[5][3][0]) && mohreh(zamin[1][10][0]) != 3){
        char x = zamin[1][10][0];
        mohreh(x);
    }
    else {
        return 3;
    }    

} 

// gharagiri mohre-ha rooy ham 
bool bartari(char a , char b){
    if ((a=='X' && b !='O') || ( a=='O' && b!='X'))
        return 1;
    else if ((a=='x' && b=='.') || (a=='o' && b=='*'))
        return 1;
    else{
        return 0;
    }
}

// sabt piroozi
void bord(string a, string b){
    ofstream file;

    file.open("games.txt", ios::app);
    file<<a<<" "<<b<<endl;
    file.close();
}

// tedad piroozi hay avali
int awins(string a, string b){
    int avali=0;
    string ab = a+" "+b;
    string matn; 
    ifstream files;
    files.open("games.txt");
    while(getline(files, matn)){
        if(matn == ab)
            avali++;
    }
    files.close();
    return avali;
}

// tedad piroozi hay dovomi
int bwins(string a, string b){
    int dovom=0;
    string ba = b+" "+a;
    string matn; 
    ifstream files;
    files.open("games.txt");
    while(getline(files, matn)){
        if(matn == ba)
            dovom++;
    }
    files.close();
    return dovom;
}

bool mosavi(char zamin[7][13][3]){
    int n=0;
    for(int i=1 ; i<7 ; i=i+2){
        for(int j=2 ; j<13 ; j=j+4){
            if (zamin[i][j][0] != ' ')
                n++;
        }
    }
    if ( n == 9)
        return 1;
    else{
    	return 0;
	}
}

int main(){
    string player1, player2 , move;
    char zamin[7][13][3];
    int i = 0 , j = 0 , nobat = 0;
    int x, y, x1, y1;
    char mohre;
    char poss_x[6] = {'X' , 'X' , 'x' , 'x' , '*' , '*' }; 
    char poss_o[6] = {'O' , 'O' , 'o' , 'o' , '.' , '.' }; 

    // daryaft asami
    cout<<"first player X : ";
    cin>>player1;
    cout<<"second player O : ";
    cin>>player2;

    // tedad bord-ha    
    cout<< player1 << " wins :" << awins(player1, player2) << " times" << endl;
    cout<< player2 << " wins :" << bwins(player1, player2) << " times" << endl;

    // jabejayi nobat
    string alaki;
    cout<<"press any key and enter to start the game ... : ";
    cin>> alaki;
    string q;
    if (awins(player1, player2) < bwins(player1, player2)){
        q = player2;
        player2 = player1;
        player1 = q;
    }

    // amade sazi zamin bazi
    for (int i = 6 ; i>=0 ; i--){
        for (int j = 12 ; j>=0 ; j--){

            if (i%2==0){
               zamin[i][j][0] = '-'; 
            }
            else if(j%4==0){
                zamin[i][j][0] = '|'; 
            }
            else {
                zamin[i][j][0] = ' ';
            }

            for (int k = 2 ; k>0 ; k--){
                zamin[i][j][k] = ' ';
            }

        }

    }
    
    chap(zamin);

 
    while(true){
    cout<<endl;

    // chap harkat hay mojaz va eelam nobat
    if (nobat%2==0){
        cout<< player1 << "`s turn : " ;
        for (int m=0; m<6 ; m++){
            cout<<poss_x[m] << ' ';
        }
        cout << endl;
    }
    else{
        cout<< player2 << "`s turn : " ;
        for (int m=0; m<6 ; m++){
            cout<<poss_o[m] << ' ';
        }
        cout << endl;
    }

// daryaft harket : enteghal ya jaygozai
    cin>>move;

// bazi dar soorat enteghal
    int ans=0;
    if (move == "move"){
        cin>>y1>>x1>>y>>x;
        
        // vorodi na motabr         
        if (x > 3 || y>3 || x<1 || y<1 || x1 > 3 || y1>3 || x1<1 || y1<1){
            wrong(zamin);
            nobat -- ;
            cout<<endl<<"numbers should be between 1 & 3"<<endl;
        }

        // tarif moteghayer-ha
        x = 2*x - 1;
        y = 4*y - 2;
        x1 = 2*x1 - 1;
        y1 = 4*y1 - 2;
        mohre = zamin[x1][y1][0];
        char mohre_feli; 
        mohre_feli = zamin[x][y][0];

        // mohre dorst entekhab shode ast ya na
        if((nobat%2==0 && mohreh(mohre)==1) || (nobat%2==1 && mohreh(mohre)==0)){ 
            ans = 1;
        }

        // mohre gheyr-mojaz
        if (ans == 0){
            wrong(zamin);
            cout<<endl<<"chosen bead is not yours"<<endl;
            nobat--;
        }

        // enteghal mohre
        else if (mohre_feli == ' ' || bartari(mohre, mohre_feli)==1) {
            for (int j=2 ; j>0 ; j--){
                zamin[x][y][j] = zamin[x][y][j-1];
            }
            zamin[x][y][0] = zamin[x1][y1][0];
            for (int i=0 ; i<2 ; i++){
                zamin[x1][y1][i] = zamin[x1][y1][i+1] ;
            }
            zamin[x1][y1][2] = ' ';

            chap(zamin);

        }
        // vorodi na motabr
        else{
            wrong(zamin);
            nobat--;
            cout<<endl<<" chosen bead is smaller";
        }

    }
    // bazi dar soorat jagozari
    else if (move == "put"){
        cin>>mohre;
        cin>>y>>x;

        // vorodi na motabr
        if (x > 3 || y>3 || x<1 || y<1){
            wrong(zamin);
            nobat -- ;
            cout<<endl<<"numbers should be between 1 & 3"<<endl;

        }

        // entekhab mohre mojaz
        if (nobat%2==0){
            for (int i=0 ; i<6 ; i++){
                if (mohre == poss_x[i]){
                    poss_x[i] = '-';
                    break;
                }
                else if (i == 5){
                    mohre = ' ';
                }
            }
        }
        if (nobat%2==1){
            for (int i=0 ; i<6 ; i++){
                if (mohre == poss_o[i]){
                    poss_o[i] = '-';
                    break;
                }
                else if (i == 5){
                    mohre = ' ';                    
                }
            }
        }

        // tarif moteghayer-ha
        x = 2*x - 1;
        y = 4*y - 2;
        char mohre_feli;
        mohre_feli = zamin[x][y][0];

        // gozashtan mohre jadid
        if ( zamin[x][y][0] == ' ' ){
            zamin[x][y][0] = mohre;
            chap(zamin);
    
        }
        
        // gozashtan dar soorat vojood mohre ghabli
        else if (zamin[x][y][0] != ' ' && bartari(mohre ,mohre_feli) == 1){

            for (int i=2 ; i>0 ; i--){
                zamin[x][y][i] = zamin[x][y][i-1] ;
            }
            zamin[x][y][0] = mohre;

            chap(zamin);
        }

        // vorodi na motabr
        else{
            wrong(zamin);
            nobat --;
            cout<<endl<<" chosen bead is smaller";            
        }
    }

    // vorodi na motabr
    else{
        wrong(zamin);
        nobat--;       
    }

    // bord player1
    if (judge(zamin) == 1){
        cout<<endl<<player1 << " is the winner!!!!!!"<<endl ;
        bord(player1 , player2);
        break;
    }

    // bord player2
    if (judge(zamin) == 0){
        cout<<endl<<player2 << " is the winner!!!!!!"<<endl ;
        bord(player2 , player1);
        break;
    }

    // shart tasavi
    if (mosavi(zamin) == 1){
        cout<<endl<<"equal!";
        break;
    }

    
    nobat ++ ; 
    
    } 

    return 0;

}