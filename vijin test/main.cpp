#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <sstream>
using namespace std; 
string convertInt(int num){
   stringstream ss;

   ss << num;

   return ss.str();

}
string symbol(int num){ //sets some numbers to letters for bases over 10 (Only works up to base 36)

    vector<char> letters(26);
    char curr_char = 'A';
    for(int i = 0; i < 26; i++){
        letters[i] = curr_char++;
    }
    if(num > 9){
        string letter = "";
        letter += letters[num - 10];
        return letter;
    }
    else{
        return convertInt(num);
    }
}
string from_10(int num, int base){ //converts FROM base 10 to specified base
    vector<string> con_digs;
    int size = 0;
    while(num / base != 0){
        con_digs.push_back(symbol(num % base));
        size++;
        num = num / base;
   }
    con_digs.push_back(symbol(num));
    size++;
    string con_num = "";
  for(int i = size - 1; i > -1; i--){
       con_num += con_digs[i];
   }

    return con_num;
}

 

string reverse(string s){

    string result;

    for(int i = s.length() - 1; i >= 0; i--){

        result += s[i];

    }

    return result;

}

 

int main(){

    ifstream in("palsquare.in");

    ofstream out("palsquare.out");

 

    int base;

    in >> base;

 

    for(int i = 1; i <= 300; i++){

        string new_base = from_10(i * i , base);

        if(new_base == reverse(new_base)){

            out << from_10(i, base) << " " << new_base << endl;

        }

    }

}
