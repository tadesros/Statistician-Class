

/* 
 * File:   main.cpp
 * Author: Tom
 *
 */
#include <cstdlib>
#include "stats.h"

using namespace std;

int main(int argc, char** argv) {
    
    double meanResult;
    double sumResult;
    double maxResult;
    double minResult;
    double lengthResult;
    
    
    Statistician Stat1;
    Statistician Stat2;
    Statistician Stat3;
    
    //Set values for Stat1    
    Stat1.next(1);    
    Stat1.next(2);
    Stat1.next(3);
    Stat1.next(4);
    
    //Stats for stat1
    lengthResult = Stat1.length();
    meanResult = Stat1.mean();
    sumResult = Stat1.sum();
    maxResult = Stat1.maximum();
    minResult = Stat1.minimum();
    
    cout<<"Stat1"<<endl;
    cout<<"Length :"<<lengthResult<<endl;
    cout<<"Mean :"<<meanResult<<endl;
    cout<<"Sum: "<<sumResult<<endl;
    cout<<"Max: "<<maxResult<<endl;
    cout<<"Min: "<<minResult<<endl;
   
    //Stat2
    Stat2.next(5);
    Stat2.next(6);
    
    Stat3 = Stat1 + Stat2;
    
    maxResult = Stat3.maximum();
    
    cout<<"Largest of Stat3:  "<<maxResult<<endl;
    

    return 0;
}

