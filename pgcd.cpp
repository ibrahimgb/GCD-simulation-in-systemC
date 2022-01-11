#include "pgcd.h"
void pgcd::do_pgcd(){
gcd_tmp = 0; ready_tmp = 0;
X = 0; Y = 0;
//while(true) {
if(valid.read() == 1){ X = A.read(); Y = B.read(); }
else{
if(X > Y){ X = X - Y; }
else if(X < Y){ Y = Y - X;
}
else{
ready_tmp = X == 0 ? 0 : 1;
gcd_tmp = X == 0 ? gcd_tmp : X;
X = 0;
Y = 0;
}
}
GCD.write(gcd_tmp);
ready.write(ready_tmp);
//}
}