#include <iostream>
#include <cstring>
#include <cstdbool>

using namespace std;

class Vector 
{
public:
  int length_of_array;
  int* contents;

public:
  Vector (int in_length)
  {
    contents = new int[in_length];
    for(int i = 0; i<=in_length; i++)
      {
	contents[i] = i;
      }

    length_of_array = in_length;
  };

  ~Vector()
  {
    delete[] contents;
    contents =  0;
  };

  /*
  Rev()
  {
    for(int i=0; i<length_of_array-1; i++)
      {
	contents[i] = contents[length_of_array - i - 1];
      }
    
  };
  */

};

class ChildVector : public Vector
{
  ChildVector(const ChildVector & Source)
  { //Shallow copy as length_of_array is not a pointer
    length_of_array = Source.length_of_array;

    if (Source.contents)
      {
	contents = new int[length_of_array];
	memcpy ((void*) contents, (const void*)Source.contents,
		Source.length_of_array * sizeof(*Source.contents));
	  }
    else contents = 0;
  }

};
	
ChildVector& ChildVector:: operator >> (const ChildVector& obj1)
{
  for (int i = 0; i<= length_of_array; i++)
    {
      cout << obj1.contents[i];
    }
};


int main (int argc, char *argv[])
{
  int length_of_array=0;
  char* argument = NULL;
  bool shallow = false;
  bool deep = false;
  bool copy = false;
  bool reverse = false;
  bool print_prev_vec = false;
  bool print_current_vec = false; 

  for (int i=1; i<=argc; i++)
    {
      argument = argv[i];
      
      if(strcmp((const char *)argument, (const char *)"-s") == 0)
	{	
	  length_of_array = atoi((const char *) argv[i+1]); 
	  break;
	}
      else if(strcmp((const char *)argument, (const char *)"-S") == 0)
	{
	  shallow = true;
	}
      else if(strcmp((const char *)argument, (const char *)"-D") == 0)
	{
	}

      else if(strcmp((const char *)argument, (const char *)"-C") == 0)
	{
	  
	}
      else if(strcmp((const char *)argument, (const char *)"-R") == 0)
	{
	  //reverse the content of the current vector
	  Vector obj1;
	  //obj1.Rev();
	  reverse = true;
	}
      else if(strcmp((const char *)argument, (const char *)"-O") == 0)
	{
	  if (strcmp(argv[i+1],"p") == 0)
	    print_prev_vec = true;
	  else if (strcmp(argv[i+1],"c") == 0)
	    print_current_vec = true;
	  else 
	    print_current_vec = true;	
	}
      else
	{
	cerr << "Unknown bad argument provided, exiting ! \n";
	return -1;
	}
      
    }

  return 0;
}
