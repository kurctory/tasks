#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    freopen("input.txt","r",stdin);
    string str, name;
    vector <pair<int,string> > num_str;
    map <int, string> roles;
    map <int, string> :: iterator it;
    map <string, vector<pair<int,string> > > replicas;
    int n = 0;
    getline(cin, str);//roles
    getline(cin, str);
    while ((str != "textLines: ")) {
        n++;
        roles.insert(make_pair<int, string>(n,str));
        getline(cin, str);
        }

    n = 0;
    getline(cin, str);
    while (!cin.eof()){
        n++;
        name.assign(str, 0, str.find(":"));
        str.erase(0, str.find(":") + 1);
        if (!replicas.count(name)){
            num_str.clear();
            num_str.push_back(make_pair(n,str));
            replicas.insert (pair<string, vector<pair<int, string> > > (name,num_str));
        }
        else
            replicas[name].push_back(make_pair(n,str));
        getline(cin, str);
    }
    freopen("output.txt","w",stdout);

    for (it = roles.begin(); it != roles.end(); it ++){
        n++;
        cout << (*it).second<<":"<<endl;
        for (unsigned int i = 0; i < replicas[(*it).second].size(); i++)
            cout << replicas[(*it).second][i].first << ") " <<replicas[(*it).second][i].second << " " << endl;
        cout << endl;
    }
}
