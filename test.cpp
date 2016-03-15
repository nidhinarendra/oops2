#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Vector {
private:
  int length_vector_array;
  int * contents;

public:
  Vector (int length)
  {
    length_vector_array = length;
    contents = new int[length];
    cout << "Length of array is " << length_vector_array <<endl;
  }

  int Create_array()
  {
    for (int i=0; i<=length_vector_array-1;i++)
      {
	contents[i] = i;
	cout << "content[" <<i << "]"<< "is" << contents[i] <<endl;
      }
    return *contents;
  }
  int deep_copy()
  {
    cout << "Performing deep copy\n";
    return 0;
  }

  int Copy (int length_array)
  {
    cout << "Assignment operation\n";
    return 0;
  }

  int Reverse(int length_vector_array)
  {
    for (int i=0; i<length_vector_array; i++)
      {
	contents[i] = contents[length_vector_array - i -1];
	cout << "Reverse" << contents[i] << endl;
      }
    return *contents;
  }

};

/*class ChildVector : public Vector
{
  ChildVector(const ChildVector & Source) : Vector(Source)
  {
    cout << "Entreing shallow copy" << endl;
    length_vector_array = Source.length_vector_array;
    if(Source.contents)
      {
	contents = new ont[length_vector_array];
	memcpy ((void *) contents, (const void *)Source.contents,
		Source.length_vector_array * sizeof(*Source.contents));
      }
    else contents = 0;
    }
    };*/


int main (int argc, char* argv[])
{
  int length_of_array = 0;
  char * argument = NULL;
  Vector *cur;
  Vector *prev;
  for (int i =1; i<=argc; i++)
    {
      argument = argv[i];
      if(strcmp((const char *)argument, (const char *) "-s") == 0)
	{
	  length_of_array = atoi((const char *) argv[i+1]);
	  Vector obj1(length_of_array);
	  obj1.Create_array();
	  cur = &obj1;
	}
      /* else if(strcmp((const char *)argument,(const char *) "-S") == 0)
	{
	  cout << "array lenght is " << length_of_array<<endl;
	 ChildVector obj2;	 
	 obj2.ChildVector();
	 }*/

      else if(strcmp((const char *)argument, (const char *) "-D") == 0)
	{
	  Vector obj3(length_of_array);
	  obj3.deep_copy();
	}

      else if(strcmp ((const char *) argument, (const char*) "-C") == 0)
	{
	  Vector obj4(length_of_array);
	  obj4.Copy(length_of_array);
	}
      else if(strcmp ((const char *) argument, (const char*) "-R") == 0)
	{
	  Vector obj5(length_of_array);
	  obj5.Reverse(length_of_array);
	  break;
	}
      else 
	{cout << "unknown argument" << argv[i];}
    }


  return 0;

}
