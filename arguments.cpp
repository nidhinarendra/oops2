#include <iostream>

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
	void *memcpy ((void*) contents , const (void*) Source.contents,
		      length_of_array);
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
  string* argument = NULL;
  bool shallow = false;
  bool deep = false;
  bool copy = false;
  bool reverse = false;

  for (long int i=1; i<=argc; i++)
    {
      *argument = argv[i];
      switch (argument)
	{
	case "-s": 
	  { length_of_array = argv[i+1];
	  break;
	  }
	case "-S": //Shallow copy
	  {
	    shallow = true;
	    break;
	  }
	case "-D": //Deep copy
	  {
	    deep = true;
	    break;
	  }
	case "-C": //copy previous vector to current vector
	  {
	    copy = true;
	    break;
	  }
	case "-R"://reverse the content of the current vector
	  {
	    Vector obj1;
	    //obj1.Rev();
	    reverse = true;
	    break;
	  }
	case "-O": //ouput the vector
	  {
	    //if (char a = 'p')
	      // ????
	      break;
	  }
	default :
	  {
	    cerr << "Unknown argument\n";
	  }
	}
    }

  return 0;
}
