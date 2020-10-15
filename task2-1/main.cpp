#include<iostream>
#include<map>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
    setlocale(LC_ALL,"RUS");
    int n,counter=0;
    map <string,string> voc;
    map <string,string> :: iterator it;
    string key, val, input;
    voc.clear();
    freopen("input.txt","r",stdin);
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; ++i){
        getline(cin, input);
        int k = input.find("-");
        val.assign(input, 0, k - 1);
        k += 2;
        input.erase(0,k);
        while(input.size()){
            if (!(input.find(",") + 1)) {
                k = input.find(" ") - 1;
                key.assign(input, 0, k);
                if (!voc.count(key))
                    {
                        voc.insert (pair<string,string>(key,val));
                        counter++;
                    }
                    else
                        voc[key] += (", " + val);
                input.clear();
            }
            else {
            k = input.find(",");
            key.assign(input, 0, k);
            if (!voc.count(key))
                {
                    voc.insert (pair<string,string>(key,val));
                    counter++;
                }
                else
                    voc[key] += (", " + val);
            if(input.find(" ")==(k+1))
               k+=2;
            else
                k++;
            input.erase(0,k);
            }
        }
    }
    cout << counter<< endl;
    for (it = voc.begin(); it != voc.end(); it ++)
            cout << (*it).first << " - " << (*it).second << endl;
}
