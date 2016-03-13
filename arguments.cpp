#include <iostream>

using namespace std;

class vector 
{
int length_of_array;
int* contents;

vector (int in_length)
{
contents = new int[in_length];
for(int i = 0; i<=in_length; i++)
 {
 contents[i] = i;
 }

length_of_array = in_length;
}

~vector()
{
delete[] length_of_array;
length_of_array = 0;
}


int main (int argc, char *argv[])
{
int length_of_array=0;
char* argument = NULL;
bool shallow = false;
bool deep = false;
bool copy = false;
bool reverse = false;

for (int i=0; i<=argc; i++)
{
argument = argv[i];
switch (argument)
{
case "-s": 
length_of_array = argv[i+1];
break;

case "-S": //Shallow copy
shallow = true;
break;

case "-D": //Deep copy
deep = true;
break;

case "-C": //copy previous vector to current vector
copy = true;
break;

case "-R"://reverse the content of the current vector
reverse = true;
break;

case "-O": //ouput the vector
if (char a = 'p')
????
break;

default :
cerr << "Unknown argument\n";
}
}



return 0;

}
