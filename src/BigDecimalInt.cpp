#include "BigDecimalInt.h"

BigDecimalInt::BigDecimalInt(string decStr)
{
    decimalnumber=decStr.length();
    Bigdec=new char[decimalnumber];
    for(int i=0;i<decimalnumber;i++)
    {
        Bigdec[i]=decStr.at(i);
    }
}

BigDecimalInt::BigDecimalInt (int decInt)
{   string decStr =to_string(decInt);
    decimalnumber=decStr.length();
    Bigdec=new char[decimalnumber];
    for(int i=0;i<decimalnumber;i++)
    {
        Bigdec[i]=decStr.at(i);
    }
}
BigDecimalInt BigDecimalInt ::operator + (BigDecimalInt anotherDec)
{
    int num1,num2;
    int carry=0;
    int maxdecimalnumber,mindecimalnumber;
    bool thisislonger;
    if(Bigdec[0]=='-' && anotherDec.Bigdec[0]=='-')
    {
        BigDecimalInt temp=removeminus(*this);
        BigDecimalInt temp1=removeminus(anotherDec);
        BigDecimalInt result=temp1+temp;
       BigDecimalInt newresult =addminus(result);
        return newresult;
    }
    if(Bigdec[0]=='-' && (anotherDec.Bigdec[0]!='-'))
    {
        BigDecimalInt temp=removeminus(*this);
        BigDecimalInt result= anotherDec-temp;
        return result;
    }
    if(anotherDec.Bigdec[0]=='-' && Bigdec[0]!='-')
    {
        BigDecimalInt temp=removeminus(anotherDec);
        BigDecimalInt result= *this-temp;
        return result;
    }
    if(decimalnumber>anotherDec.decimalnumber)
    {
        maxdecimalnumber=decimalnumber;
        mindecimalnumber=anotherDec.decimalnumber;
        thisislonger=true;
    }else
    {
        maxdecimalnumber=anotherDec.decimalnumber;
        mindecimalnumber=decimalnumber;
        thisislonger=false;
    }
    char* temparray=new char[maxdecimalnumber];

    for(int i=0;i<mindecimalnumber;i++)
    {
        num1= (int)Bigdec[decimalnumber-1-i]-48;
        num2=(int)anotherDec.Bigdec[anotherDec.decimalnumber-1-i]-48;
        if(num1+num2+carry>9)
        {
            num1=num1+num2+carry;
            num1=num1%10;
            carry=1;
            temparray[maxdecimalnumber-1-i]=num1+48;

        }
        else
        {
            temparray[maxdecimalnumber-1-i]=num1+num2+carry+48;

            carry=0;
        }

    }
    if(thisislonger)
    {
        for(int i=0;i<maxdecimalnumber-mindecimalnumber;i++)
        {
         num1= (int)Bigdec[maxdecimalnumber-mindecimalnumber-1-i]-48;
         if(num1+carry>9)
        {
            num1=num1+carry;
            num1=num1%10;
            carry=1;
            temparray[maxdecimalnumber-mindecimalnumber-1-i]=num1+48;

        }
        else
        {
            temparray[maxdecimalnumber-mindecimalnumber-1-i]=num1+carry+48;
            carry=0;
        }
        }
    }
    else
    {
        for(int i=0;i<maxdecimalnumber-mindecimalnumber;i++)
        {
            num2=(int)anotherDec.Bigdec[maxdecimalnumber-mindecimalnumber-1-i]-48;
            if(num2+carry>9)
            {
                num2=num2+carry;
                num2=num2%10;
                carry=1;
                temparray[maxdecimalnumber-mindecimalnumber-1-i]=num2+48;

            }
            else
            {
                temparray[maxdecimalnumber-mindecimalnumber-1-i]=num2+48+carry;
                carry=0;
            }
        }

    }
    string s = "";
    if(carry) s=s+'1';
    for (int i = 0; i < maxdecimalnumber; i++) {
        s = s + temparray[i];
    }

    BigDecimalInt temp(s);
    return temp;
}
BigDecimalInt BigDecimalInt ::removeminus (BigDecimalInt anotherDec)
{
         string s = "";
     //s=s+'-';
    for (int i = 1; i < anotherDec.decimalnumber; i++) {
        s = s + anotherDec.Bigdec[i];
    }

    BigDecimalInt temp(s);
    return temp;
}
BigDecimalInt BigDecimalInt ::addminus (BigDecimalInt anotherDec)
{
         string s = "";
     s=s+'-';
    for (int i = 1; i < anotherDec.decimalnumber; i++) {
        s = s + anotherDec.Bigdec[i];
    }

    BigDecimalInt temp(s);
    return temp;
}

BigDecimalInt BigDecimalInt ::operator - (BigDecimalInt anotherDec)
{
    if(Bigdec[0]=='-' && anotherDec.Bigdec[0]=='-')
    {
        BigDecimalInt temp=removeminus(*this);
        BigDecimalInt temp1=removeminus(anotherDec);
        BigDecimalInt result=temp1-temp;
        return result;
    }
    if(Bigdec[0]=='-' && (anotherDec.Bigdec[0]!='-'))
    {
        BigDecimalInt temp=removeminus(*this);
        BigDecimalInt result= temp+anotherDec;
        BigDecimalInt resultnew=addminus(result);
        return resultnew;
    }
    if(anotherDec.Bigdec[0]=='-' && Bigdec[0]!='-')
    {
        BigDecimalInt temp=removeminus(anotherDec);
        BigDecimalInt result= *this+temp;
        return result;
    }
   BigDecimalInt temp =turnNegativeIntoComplement(anotherDec);
    temp=temp+*this;
    if(temp.Bigdec[0]==49)
        temp.Bigdec[0]='0';
    else
    {
        temp=turnNegativeIntoComplement(temp);
    }
    return temp;
}
int BigDecimalInt:: operator[](int index) // to return value of specific index
{
    int x=(int)Bigdec[index]-48;
    return x;
}
ostream& operator<<(ostream& os, const BigDecimalInt& n1)
{
    for(int i=0;i<n1.decimalnumber;i++)
    {
        os<<n1.Bigdec[i];
    }
    os<<endl;
}
istream& operator>>(istream& is, BigDecimalInt& n1)
{
    string x;
    is>>x;
    BigDecimalInt n2(x);
}
BigDecimalInt BigDecimalInt::turnNegativeIntoComplement(BigDecimalInt anotherDec)
{
     int num1;
    char *complement=new char[anotherDec.decimalnumber];
    for(int i=0;i<anotherDec.decimalnumber;i++)
    {
         num1= (int)anotherDec.Bigdec[anotherDec.decimalnumber-1-i]-48;
         num1=9-num1;
         complement[anotherDec.decimalnumber-1-i]=num1+48;
    }
    string s = "";

    for (int i = 0; i < anotherDec.decimalnumber; i++) {
        s = s + complement[i];
    }

    BigDecimalInt temp(s);
    BigDecimalInt carryclass("1");
    temp=temp+carryclass;
    return temp;

}
