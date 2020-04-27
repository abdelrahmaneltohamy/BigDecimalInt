#include <string>
#include <iostream>
#include <BigDecimalInt.h>
using namespace std;
int main()
{
    //first test add
    BigDecimalInt firstnumber("-55555555");
    BigDecimalInt secondnumber("-33333333");
    BigDecimalInt thirdnumber=firstnumber+secondnumber;
    cout<<thirdnumber<<endl;
    cout<<thirdnumber[2]<<endl;
    //secondd test sub
    BigDecimalInt firstnumber1("-111111111");
    BigDecimalInt secondnumber1("-333333333");
    BigDecimalInt thirdnumber1=firstnumber1-secondnumber1;
    cout<<thirdnumber1<<endl;
    //third test add with carry
    BigDecimalInt firstnumber2("1234567890");
    BigDecimalInt secondnumber2("1234567890");
    BigDecimalInt thirdnumber2=firstnumber2+secondnumber2;
    cout<<thirdnumber2<<endl;
    //forth test sub with borrow
    BigDecimalInt firstnumber3("333333333");
    BigDecimalInt secondnumber3("199999999");
    BigDecimalInt thirdnumber3=firstnumber3-secondnumber3;
    cout<<thirdnumber3<<endl;
    //fifth add two with different dimentions
    BigDecimalInt firstnumber4("9999999999");
    BigDecimalInt secondnumber4("1");
    BigDecimalInt thirdnumber4=firstnumber4+secondnumber4;
    cout<<thirdnumber4<<endl;
    //sixth test sub with negative number
   BigDecimalInt firstnumber5("-222222222");
    BigDecimalInt secondnumber5("444444444");
    BigDecimalInt thirdnumber5=firstnumber5-secondnumber5;
    cout<<thirdnumber5<<endl;
    //seventh test sub with negative number
    BigDecimalInt firstnumber6("-111111111");
    BigDecimalInt secondnumber6("-333333333");
    BigDecimalInt thirdnumber6=firstnumber6+secondnumber6;
    cout<<thirdnumber6<<endl;
    return 0;
}
