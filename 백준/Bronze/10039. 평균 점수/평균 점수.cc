#include <iostream>

using namespace std;

int main()
{
int score, summ;
score = 0;
summ = 0;

for (int i =0; i<5; i++){
cin >> score;
if(score < 40){
score = 40;
}
summ += score;
}

cout << summ/5;
return 0;
}