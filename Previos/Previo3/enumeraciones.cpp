#include <iostream>
using namespace std;
//Recordar que no se declara con un igual omo una variable normal
enum seasons {spring =34, summer = 4, autumn = 9, winter =32};
enum week {sunday, monday, tuesday,wednesday,thursday, friday,saturday};
enum suit {
    club =0,
    diamonds =10,
    hearts =20,
    spades =3
} ;

int main(){
    //Tipo de dato de tipo enum
   seasons s;
   week today;
   suit card ;
   today=wednesday;
   s = summer;
   card = club;
   cout <<"Summer =" << s <<endl;
   cout <<"Day =" << today <<endl;
   cout <<"size of enums variables" << sizeof(card) << " bytes."<<endl;

    return 0;
}


