#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //linux
#include <string.h>

#include "gpiofuncties.h"
#include <fstream>
#include <string>

using namespace std;

#define GPIODIR "/sys/class/gpio/"


bool fileconsist(string s) {
    ifstream f(s);
    return f.good();

}

int zetPinMode(string m,int pnr) {
    string temp(GPIODIR);
    string dir("gpio");
    dir += to_string(pnr);
    temp +=dir;
    if(!fileconsist(temp)){
        temp = GPIODIR;
        temp += "export";
        ofstream of(temp);
        of<<to_string(pnr);
        of.close();
    }
    temp = GPIODIR; 
    temp += dir;
    temp += "/direction";

    ofstream of(temp);
    if(m=="out")
        of<<"out";
    else
        of<<"in";
    of.close(); 
    return 1;
}

int zetPinOpOutput(int pnr) {
     return zetPinMode("out",pnr);

}
int zetPinOpInput(int pnr) {
     return zetPinMode("in",pnr);
}

int zetPinWaarde(int pin,int w) {
    string fl(GPIODIR "gpio");
    fl += to_string(pin);
    fl += "/value";
    if(!fileconsist(fl)) 
        return 0;
    ofstream of(fl);
    of<<to_string(w);
    
    of.close(); 
    return 1; 
}
