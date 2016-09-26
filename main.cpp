#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <queue>
#include <vector>

#define SWAP 1
#define CHECK 2
#define MOVE 3
#define EXCHANGE 4
#define FIX 5
#define OPEN 6
#define REVERSE 7
using namespace std;



int whos_turn, nanido;
int player_cnt;
bool gameend=false;

int first_turn(int n)
{
    srand(time(NULL));
    return rand()%n;
}
void num_shuffle(queue<int> *q)
{
    vector< int> vec;
    for(int i=(nanido+3)*player_cnt;i>=1;i--)
    {
        vec.push_back(i);
    }
    for(int i=(nanido+3)*player_cnt;i>=1;i--)
    {
        int tmp=rand()%i;
        //cout<<vec[tmp]<<' ';
        q->push(vec[tmp]);
        vec[tmp]=vec[i-1];
    }
}

void special_shuffle(queue<int> *q)
{
    vector< int> vec;
    for(int i=0;i<10;i++)
    {
        vec.push_back(SWAP);
        vec.push_back(CHECK);
    }
    for(int i=0;i<4;i++)
    {
        vec.push_back(MOVE);
        vec.push_back(EXCHANGE);
        vec.push_back(FIX);
        vec.push_back(OPEN);
    }
    vec.push_back(REVERSE);
    vec.push_back(REVERSE);
    for(int i=vec.size();i>=1;i--)
    {
        int tmp=rand()%i;
        q->push(vec[tmp]);
        vec[tmp]=vec[i-1];
    }
}

int game()
{
    whos_turn=first_turn(2);
    queue<int> num_card_deck,special_card_deck;
    vector<int> player_cards, computer_cards;
    while(1)
    {
        cout<<"난이도 설정을 하십시오(1~3): ";
        cin>>nanido;
        if(nanido<=3&&nanido>=1)break;
        else cout<<"옳바른 숫자를 입력바랍니다."<<endl;
    }
    cout<<endl;
    num_shuffle(&num_card_deck);
    special_shuffle(&special_card_deck);
    while(!num_card_deck.empty())
    {
        int card=num_card_deck.front();
        num_card_deck.pop();
        if(whos_turn==0)
        {
            player_cards.push_back(card);
            whos_turn =1;
        }
        else
        {
            computer_cards.push_back(card);
            whos_turn =0;
        }
    }

    while(gameend){
        if(whos_turn==0)
        {
            cout<<"플레이어의 턴입니다."<<endl;
        }
        else
        {
            cout<<"컴퓨터의 턴입니다."<<endl;
        }
    }
    while(1)
    {
        cout<<"다시 하시겠습니까? (Y/N) : ";
        char c;
        cin>>c;
        if(c=='Y'||c=='y')return 1;
        else if(c=='N'||c=='n')return 0;
        else cout<<"옳바른 문자를 입력바랍니다."<<endl;
    }
    return 0;
}
int main(){
    player_cnt=2;
    while(game());
    return 0;
}
