//Sorting_Marc

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using namespace System;
 
void merge( vector <int> &A, vector <int> R, vector<int> L) {
   
    int nL = L.size();
    int nR = R.size();
    int i=0 ,j=0, k = 0;
 
    while (i < nL && j < nR) {
        if (L.at(i) <= R.at(j)) {
            A.at(k) = L.at(i);
            i = i + 1;
        }
        else {
            A.at(k) = R.at(j);
            j = j + 1;
        }
        k = k + 1;
    }
 
    while (i < nL) {
        A.at(k) = L.at(i);
        i = i + 1;
        k = k + 1;
    }
 
    while (j < nR) {
        A.at(k) = R.at(j);
        j = j + 1;
        k = k + 1;
    }
       
}
 
void mergesort(vector<int> &A) {
 
    int n = A.size();
    if (n < 2)
        return;
 
    int mid = n / 2;
    vector <int> left; left.resize(mid);
    vector<int> right; right.resize(n-mid);
 
    for (int i = 0; i < mid; i++) {
        left.at(i) = A.at(i);
    }
    for (int i = mid; i < n; i++) {
        right.at(i-mid) = A.at(i);
    }
    mergesort(left);
    mergesort(right);
    merge(A, right,left);
 
 
 
}
 
 
 
int main()
{
 
    Random r;
    vector <int> caca;
    int aux;
    for (int i = 0; i < 10;i++) {
 
        caca.push_back(r.Next(0,51));
        cout << caca.at(i) << " ";
    }
 
 
 
    //BABEL SORT ----------------------------------------------------
    /*
   
    for (int i = 0; i < caca.size()-1; i++) {
        for (int j = i+1; j < caca.size();j++) {
 
            if (caca.at(i) > caca.at(j)) {
                aux = caca.at(j);
                caca.at(j) = caca.at(i);
                caca.at(i) = aux;
            }
 
        }
    }
    */
    //SELECTION SORT--------------------------------------------------------
    /*
    int min;
    int minpos;
    for (int i = 0; i < caca.size() - 1; i++) {
        min = caca.at(i+1);
        for (int j = i + 1; j < caca.size(); j++) {
 
            if (caca.at(j)<min) {
                min = caca.at(j);
                minpos = j;
               
            }
 
        }
        aux = caca.at(minpos);
        caca.at(minpos) = caca.at(i);
        caca.at(i) = aux;
    }
    */
 
    // INSERTION SORT-----------------------------------------------------------
    /*
    //int  pivot, j;
 
    for (int i = 1; i < caca.size()+1; i++)
    {
        //pivot = caca.at(i);
 
        for (int j = i - 1; j > 0; j--) {
 
            if (caca.at(j) < caca.at(j-1)) {
                aux = caca.at(j);
                caca.at(j) = caca.at(j-1);
                caca.at(j-1) = aux;
            }
 
        }
 
       
        j = i - 1;
 
        while (j >= 0 && caca.at(j) > pivot)
        {
            caca.at(j+1) = caca.at(j);
            j = j - 1;
        }
 
        caca.at(j + 1) = pivot;
       
    }*/
 
    _getch();
 
    cout << endl;
 
 
 
 
    mergesort(caca);
 
 
 
    //ESCRIBIR
    for (int i = 0; i < caca.size(); i++) {
        cout << caca.at(i) << " ";
    }
 
 
    _getch();
    return 0;
}