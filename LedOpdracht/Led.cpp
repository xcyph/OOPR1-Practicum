#include "Led.h"
#include "gpiofuncties.h"

// #include <unistd.h>
// #include <iostream>
// #include "Led.h"

using namespace std;
// #define RODELED 135
// #define GROENELED 132
// #define GELELED 134

Led::Led(int nr, string k, string author) : pinNr(nr), kleur(k), eigenaar(author) {

}
Led::Led(int nr, string k) : pinNr(nr), kleur(k) {

}
Led::Led(int nr) : pinNr(nr) {

}

void Led::zetAan() {
    zetPinWaarde(pinNr, 1);
}

void Led::zetUit() {
    zetPinWaarde(pinNr,0);
}

int Led::isLedAan() const {
    return 0;
}

int Led::pinNummer() const
{
    return 0;
}

string Led::deEigenaar() const
{
    return string();
}
