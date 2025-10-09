#ifndef INTEREST_H
#define INTEREST_H

#define SIMPLE_INTEREST(P,R,T)(((P)*(R)*(T))/100)

#define AMOUNT(P,R,T)((P + SIMPLE_INTEREST(P,R,T)))

#endif // INTEREST_H
