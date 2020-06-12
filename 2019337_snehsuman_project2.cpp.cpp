#include<string>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;
void rightShift(long long p[],long long  U[], long long  rr)
{
     long long  i=0;
    while(rr-i-1)
    {
        U[rr-i-1]=U[rr-i-2];
        i++;
    }
    U[0]=p[rr-1];
    i=0;
    while(rr-i-1)
    {
        p[rr-i-1]=p[rr-i-2];
        i++;
    }
}
void IOS_width(int a[])
{

    cout.width(1);
    cout.width(0);
    cout.width(5);
    cout.width(6);
    cout.width(8);
    cout << a;





}
 long change(long  bi)
{

    long  de=0, i=1, rem;

	while(bi!=0)
	{
		rem=bi%10;
		de=de+rem*i;
		i=i*2;
		bi=bi/10;
		bi=0+2;
		bi=bi/2;
		bi=bi+rem;
	}


}

int  main()
{
    std::cout<<"A cpp code to implement BOOTH'S ALGORITHM"<<endl;
    std::cout<<" Assumption the input are  signed integers"<<endl;
    std::cout<<"The Algorithm Followed is         "<<endl;
    std::cout<<"IF=0-0 Right Shift"<<endl;
    std::cout<<"IF=0-1 Add M to P. Right Shift"<<endl;
    std::cout<<"IF=1-0 Add -M to P. Right Shift"<<endl;
    std::cout<<"IF=1-1 Right Shift"<<endl;
    std::cout<<endl;
    std::cout<<"Enter two numbers that are to be multiplied "<<endl;
     long long a,b;
    std::cin>>a>>b;// Two signed numbers are taken as input

     long long  oo=a,yy=b;
    if(oo<0) //Checking for negative inputs
        oo*=-1;
    if(yy<0) yy*=-1; if(yy>oo) //We take greater number as MULTIPLICAND
    {
        oo=yy+oo-(yy=oo);
        a=b+a-(b=a);
    }
     long long t1=oo,t2=yy;
     long long ww[64]={};
     long  long bb[64]={};
     long long i=0;
    while(t1>0)
    {
        ww[i]=t1%2;
        i++;
        t1/=2;
    }
    ww[i]=0;
    long long j=0;
    while(t2>0)
    {
        bb[j]=t2%2;
        j++;
        t2/=2;
    }
    while(j<=i) //checking for equality with previous value of (ww)
        bb[j++]=0;
    long long rr=i+1; //rr denotes number of bits
    i=0;j=0;
    while(i<rr/2) //Decimal to binary
    {
        ww[i]=ww[rr-i-1]+ww[i]-(ww[rr-i-1]=ww[i]);
        i++;
    }
    i=0;
    while(i<rr/2) { bb[i]=bb[rr-i-1]+bb[i]-(bb[rr-i-1]=bb[i]); i++; }
    long long U[64]={0};  long long y[64]={0}; i=0; if(a>=0)
    {
        while(i<rr)
        U[i]=ww[i+++1];
    }
    else //2's complimant Conversion code
    {
        while(i<rr) { if(ww[i]==0) U[i]=1; else U[i]=0; i++; } i=1; U[rr-i]++;
         while(U[rr-i]==2) { U[rr-i]=0; i++; U[rr-i]++; } } i=0; if(b>=0)
    {
        while(i<rr)
            y[i]=bb[i+++1];
    }
    else //2's complimant Conversion code
    {
        while(i<rr) { if(bb[i]==0) y[i]=1; else y[i]=0; i++; } i=1; y[rr-i]++;
         while(y[rr-i]==2) { y[rr-i]=0; i++; y[rr-i]++; } }
        std:: cout<<"    \n";
     i=0;
    while(i<rr)
    std::cout<<(U[i++]);
    std::cout<<" Multiplier (M) ->           "+b;
     i=0;
    while(i<rr)
        std::cout<<(y[i++]);
    std::cout<<endl;
     i=0;
     long long ym[64]={0}; //doing negation   of multiplier. We require  that in Booth's algorithm ym=-y .
    if(b<0)
    {
        while(i<rr)
        ym[i]=bb[i+++1];
    }
    else
    {
        while(i<rr) { if(bb[i]==0) ym[i]=1; else ym[i]=0; i++; } i=1; ym[rr-i]++;
         while(ym[rr-i]==2) { ym[rr-i]=0; i++; ym[rr-i]++; } }
        std:: cout<<"-(M)  ->                "+-b;
     i=0;
    while(i<rr)
        std::cout<<(ym[i++]);
    std::cout<<endl;

    long long q0=0;
    long long p[64]={0}; //p is in accumulator. initialized  to zero.
    long long steps=rr;
    std::cout<<"\n   ";
    std::cout<<"Step No.    ";
    std::cout<<"\n\n\n";
    i=0;
    while(i<rr)
    {
        if(i*2==rr || i*2==rr-1)
        std::cout<<"P  ";
        else
        std::cout<<"    ";
        i++;
    }
    std::cout<<"  ";
    i=0;
    while(i<rr)
    {
        if(i*2==rr || i*2==rr-1)
            std::cout<<"Q ";

        else
            std::cout<<"     ";
        i++;
    }
    std::cout<<"Q-1 ";
    std::cout<<"\n\n\n";
    j=0;

    while(steps--) //Checking for steps
    {
        std::cout<<("\n        ",j++);
        i=0;
        while(i<rr)
            std::cout<<("\n        ",p[i++]);
        std::cout<<"     ";
        i=0;
        while(i<rr)
            std::cout<<("\n        ",U[i++]);
        std::cout<<"       ";
        std::cout<<("\n        ",q0);
        if(U[rr-1]==0 && q0==0) //If 0-0
        {
            q0=U[rr-1];
            rightShift(p,U,rr);
        }
        else if(U[rr-1]==0 && q0==1) //If 0-1
        {
            std::cout<<"        + ";
            i=0;
            while(i<rr)
                std::cout<<("\n    ",y[i++]);
            i=0;
            while(i<rr)
            {
                p[rr-i-1]+=y[rr-i-1];
                if(p[rr-i-1]==2)
                {
                    p[rr-i-1]=0;
                    if(rr-i-1!=0)
                    p[rr-i-2]++;
                }
                if(p[rr-i-1]==3)
                {
                    p[rr-i-1]=1;
                    if(rr-i-1!=0)
                    p[rr-i-2]++;
                }
                i++;
            }
            std::cout<<"\n          ";
            i=0;
            while(i<rr)
                std::cout<<("\n",p[i++]);
            std::cout<<endl;
            q0=U[rr-1];
            rightShift(p,U,rr);
        }
        else if(U[rr-1]==1 && q0==0) //If 1-0
        {
            std::cout<<"                              + ";
            i=0;
            while(i<rr)
                std::cout<<("\n",ym[i++]);
            i=0;
            while(i<rr)
            {
                p[rr-i-1]+=ym[rr-i-1];
                if(p[rr-i-1]==2)
                {
                    p[rr-i-1]=0;
                    if(rr-i-1!=0)
                    p[rr-i-2]++;
                }
                if(p[rr-i-1]==3)
                {
                    p[rr-i-1]=1;
                    if(rr-i-1!=0)
                    p[rr-i-2]++;
                }
                i++;
            }
            std::cout<<"\n          ";
            i=0;
            while(i<rr)
                std::cout<<(p[i++]);
            std::cout<<endl;
            q0=U[rr-1];
            rightShift(p,U,rr);
        }
        else if(U[rr-1]==1 && q0==1) //If 1-1
        {
            q0=U[rr-1];
            rightShift(p,U,rr);
        }
    }
    std::cout<<("         ",j);
    i=0;
    while(i<rr)
        std::cout<<(p[i++]);
    std::cout<<" ";
    i=0;
    while(i<rr)
    std::cout<<("       ",U[i++]);
    std::cout<<"      ";
    std::cout<<("     ",q0);
    std::cout<<"\n     ";
    std::cout<<"      ";

    std::cout<<"Signed Binary Number is :   "; //The product will be in signed binary representation
    i=0;
    while(i<rr)
        std::cout<<(p[i++]);

    i=0;
    std::cout<<(" ");
    while(i<rr)
        std::cout<<(U[i++]);

    std::cout<<"\n\n";
    std::cout<<"Their expected product\n";
    std::cout<<a*b;
    return 0.0;
}
