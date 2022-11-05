#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool isContains(vector<pair<string, int> >& data, string word) {
    for(auto& v : data)
        if (v.first == word) {
            v.second++;
            return true;
        }
    return false;
}

void tokenizing(vector<pair<string, int> >& data, string line) {
    istringstream iss(line);
    string word;
    while(getline(iss, word, ' ')) 
        if (isContains(data, word)) continue;
        else data.push_back({word, 1});
}

void swap(vector<pair<string, int> >& data, int i, int j) {
    pair<string, int> t = data[i]; data[i] = data[j]; data[j] = t;
}

int partition(vector<pair<string, int> >& data, int l, int r) {
    int i, j; pair<string, int> v;
    if (r > l) {
        v = data[l]; i = l; j = r + 1;
        while (true) {
            while(data[++i].first < v.first && i < r);
            while(data[--j].first > v.first && j > l);
            if (i >= j) break;
            swap(data, i, j);
        }
        swap(data, j, l);
    }
    return j;
}

void quicksort(vector<pair<string, int> >& data, int l, int r) {
    int j;
    if (r > l) {
        j = partition(data, l, r);
        quicksort(data, l, j - 1);
        quicksort(data, j + 1, r);
    }
}

void sortWordCount(vector<pair<string, int> >& data, int n) {
    cout << "count" << "\tword" << '\n';
    for(int i = 0; i < 30; i++) 
        cout << std::setw(8) << std::left << data[i].second << data[i].first << '\n';
}

int main() {
    ifstream file("datafile.txt");
    if(!file.is_open()) return 0;

    vector<pair<string, int> > data;
    string line;
    while(getline(file, line)) 
        tokenizing(data, line);
    file.close();

    quicksort(data, 0, data.size() - 1);
    sortWordCount(data, 30);
}