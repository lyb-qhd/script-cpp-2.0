#include"deps.cpp"
str argv1;
int main(int argc,char* argv[]) {
	if (argc!=2)
		goto HELP;
	a1=argv[1],a1.tolower();
	if (	a1=="r"	||
				a1=="run") 
		return run(),pause;		
	else if (	a1=="c"	||
				a1=="compile")
		return compile()?pause,1:pause;
	else if (	a1=="cr"||
				a1=="compile-run"	||
				a1=="rc")
		return compile()?pause,1:(run(),pause);
	return help(),pause,1;
}