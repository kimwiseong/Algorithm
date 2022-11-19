#include <iostream>
#include <string>
using namespace std;

int bcount, kcount, rcount;

void brutesearch(string p, string a) {
    bool notFound = true;
    int i, j, M = p.length(), N = a.length();
    for (i = 0; i <= N - M; i++) {
        for (j = 0; j < M; j++) {
            bcount++;
            if (a[i + j] != p[j])  break;
        }
        if (j == M) {
            notFound = false;
            cout << i << ", "; 
        }
    }
    if (notFound) cout << "not Found";
}

int *SP;
void initSP(string p) {
    int i, j, M = p.length();
    SP = new int[M];
    SP[0] = -1;
    for (i = 0, j = -1; i < M; i++, j++, SP[i] = j) {
        while((j >= 0) && (p[i] != p[j])) {
            kcount++;
            j = SP[j];
        }
    }
}

void kmpsearch(string p, string a) {
    int i, j, M = p.length(), N = a.length();
    initSP(p);
    bool notFound = true;
    
    for (i = -1, j = -1; j < M && i < N; i++, j++) {
        while ((j >= 0) && (a[i] != p[j])) {
            kcount++;
            j = SP[j];
        }
        if (j == M-1) { 
            notFound = false;
            cout << i - j << ", ";
            j = SP[j];
        }
    }
    if (notFound) cout << "not Found";
}

int index(char s) { return int(s); }

const int q = 33554393;
const int d = 32;
void rksearch(string p, string a) {
    int i, j, dM = 1, h1 = 0, h2 = 0;
    int M = p.length(), N = a.length();
    bool notFound = true;
    
    for (i = 1; i < M; i++) dM = (d*dM) % q;
    
    for (i = 0; i < M; i++) {
        h1 = (h1*d + index(p[i])) % q;
        h2 = (h2*d + index(a[i])) % q; 
    }

    for (i = 0; i < N-M+1; i++) {
        for (j = 0; j < M && h1==h2; j++) {
            rcount++;
            if (a[i+j] != p[j]) break;
        }
        if (j==M) {
            cout << i << ", ";
            notFound = false;
        }

        h2 = (h2+d*q - index(a[i]) * dM) % q;
        h2 = (h2*d + index(a[i+M])) % q;
        if (i > N-M) cout << N << '\n';
    }
    
    if(notFound) cout << "notFound"; 
}

int main() {
    string text = "A STRING SEARCHING EXAMPLE CONSISTING OF A GIVEN STING";

    string pattern = "STING"; // 있는 문자열 검사 
    cout << pattern << " : pattern index ";
    cout << "\nbrutesearch : "; brutesearch(pattern, text); 
    cout << "\nkmpsearch : "; kmpsearch(pattern, text);
    cout << "\nrksearch : "; rksearch(pattern, text);
    cout << "\n\nsearch count";
    cout << "\nbrutesearch : " << bcount << ", kmpsearch : " << kcount << ", rksearch : " << rcount << "\n\n";  
    bcount = kcount = rcount = 0;

    pattern = "STINA"; //최악의 경우
    cout << pattern << " : pattern index ";
    cout << "\nbrutesearch : "; brutesearch(pattern, text); 
    cout << "\nkmpsearch : "; kmpsearch(pattern, text);
    cout << "\nrksearch : "; rksearch(pattern, text);
    cout << "\n\nsearch count";
    cout << "\nbrutesearch : " << bcount << ", kmpsearch : " << kcount << ", rksearch : " << rcount << "\n";  
}