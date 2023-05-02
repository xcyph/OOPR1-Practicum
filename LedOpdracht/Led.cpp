#include "Led.h"
#include "gpiofuncties.h"

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