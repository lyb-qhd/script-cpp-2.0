#include<iostream>
#include<fstream>
#define pause (system(pause))
using namespace std;
using str=string,uint=unsigned int;

inline void help() {
    cout<<  "input c for compile, "
            "r for run, and cr for both.\n";
}

str toHex(uint x) {
	str ret;
	for(int i=1;i<=8;i++) {
		ret=str(1,digits[x&0xf])+ret;
		x>>=4;
    }
	return str("0x")+ret;
}

void run() {
    uint ret=system("head.exe");
    printf(
        "\n\n"
        "--------------------------------\n"
        "return %d(0x%s).\n"
    ,ret,toHex(ret).c_str());
}

uint compile() {
    ifstream fin("../set.txt");str comp;
    fin.getline(comp);
    comp=   str(1,'"')+comp+"\" ../util/head.cpp "
            "-o ../util/head.exe -std=c++14 -O2 -static";
    bool i=system(comp);
    return i;
}
