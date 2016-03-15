#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Vectorclass {
public:
  int length_vector_array;
  int * contents;

public:
  Vectorclass (int length)
  {
    length_vector_array = length;
    contents = new int[length];

    for (int i=0; i<=length_vector_array-1;i++)
      {
	contents[i] = i;
	//cout << "contents[" <<i << "]"<< "is" << contents[i] <<endl;
      }
  }
  int reverse()
  {
    int temp;
    int middle;
    if ((length_vector_array % 2) == 0)
      middle = length_vector_array/2;
    else
      middle = ((int)length_vector_array / 2);
	
    for (int i=0; i < middle; i++)
      {
	temp = contents[length_vector_array - i -1];
	contents[length_vector_array - i - 1] = contents[i];
	contents[i] = temp;
      }
    return *contents;
  }
  
  void print()
  {
    for (int i=0; i<=length_vector_array-1;i++)
      {
	if(i == length_vector_array - 1)
	  cout << contents[i];
	else
	  cout << contents[i] << ",";
      }
    cout << "\n";
  }

  void operator=(const Vectorclass& rhs)
  {
    for (int i=0; i<=length_vector_array-1;i++)
      {
	contents[i] = rhs.contents[i];
      }
  }
  
  /*
  istream & operator>>(istream &in)//const Vectorclass &obj)
  {
    for (int i=0; i<=length_vector_array-1;i++)
      {
	in>>contents[i];
	//cout << "content[" <<i << "]"<< "is" << contents[i] <<endl;
      }
    return in;
  }
  */
  
};

class ChildVectorclass : public Vectorclass
{
public:
  ChildVectorclass(const Vectorclass & Source) : Vectorclass(Source)
  {
    length_vector_array = Source.length_vector_array;
    if(Source.contents)
      {
	contents = new int[length_vector_array];
	memcpy ((void *) contents, (const void *)Source.contents,
		Source.length_vector_array * sizeof(*Source.contents));
      }
    else contents = 0;
  }
  
};


int main (int argc, char* argv[])
{
  int length_of_array = 0;
  char * argument = NULL;
  Vectorclass *cur = NULL;
  Vectorclass *prev = NULL;
  bool tracing = false;
  for (int i=1; i<argc; i++)
    {
      argument = argv[i];
      if(strcmp((const char *)argument, (const char *) "-s") == 0)
	{
	  if (tracing)
	    cout << "Inside -s\n";
	  
	  length_of_array = atoi((const char *) argv[i+1]);
	  Vectorclass obj1(length_of_array);
	  cur = &obj1;
	  (*cur).print();
	  i++;
	}
       else if(strcmp((const char *)argument,(const char *) "-S") == 0)
	{
	  if (!cur)
	    {
	      cerr << "current vector is NULL\n";
	      return -1;
	    }
	  
	  prev = cur;
	  Vectorclass obj2 = *prev;	 
	  cur = &obj2;

	  if (tracing)
	  {
	    cout << "\n" << "Inside -S\n";
	    
	    (*prev).print();
	    cout << "\n" << (*prev).contents <<"\n";
	    
	    (*cur).print();
	    cout <<  "\n" << (*cur).contents <<"\n";
	  }
	    
	}
      else if(strcmp((const char *)argument, (const char *) "-D") == 0)
	{
	  if (!cur)
	    {
	      cerr << "current vector is NULL\n";
	      return -1;
	    }
	  
	  
	  prev = cur;
	  ChildVectorclass obj3 = *cur;
	  cur = &obj3;
	  
	  if (tracing)
	  {
	    cout << "\n" << "Inside -D\n"; 
	    (*prev).print();
	    cout << "\n" << (*prev).contents <<"\n";
	    
	    (*cur).print();
	    cout <<  "\n" << (*cur).contents <<"\n";
	  }
	  
	}
      else if(strcmp ((const char *) argument, (const char*) "-C") == 0)
	{
	  if (!prev)
	    {
	      cerr << "previous vector is NULL\n";
	      return -1;
	    }

	  cur = prev;

	  Vectorclass obj(length_of_array);
	  obj = *prev;
	  cur = &obj;

	  
	  if (tracing)
	    {
	      cout << "Inside -C\n";
	      (*prev).print();
	      cout << "\n" << (*prev).contents <<"\n";
	      
	      (*cur).print();
	      cout << "\n" << (*cur).contents <<"\n";
	    }
	  
	}
      else if(strcmp ((const char *) argument, (const char*) "-R") == 0)
	{
	  if(cur) 
	    (*cur).reverse();
	  else
	    {
	      cerr << "current vector is NULL";
	      return -1;
	    }
	  
	  if (tracing)
	    {
	      cout << "Inside -R\n"; 
	      (*prev).print();
	      cout << "\n" << (*prev).contents <<"\n";
	      
	      (*cur).print();
	      cout << "\n" << (*cur).contents <<"\n"; 
	    }

 	}
      else if(strcmp ((const char *) argument, (const char*) "-O") == 0)
	{
	  if (tracing)
	    cout << "Inside -O\n";
	  
	  if(argv[i+1])
	    {
	      char* argument_c_or_p = argv[i+1];
	  
	      if(strcmp ((const char *)argument_c_or_p, (const char*) "p") == 0)
		{
		  if(!prev)
		    {
		      cerr << "previous is NULL";
		      return -1;
		    }	      
		  (*prev).print();
		  i++;
		}
	      else if(strcmp ((const char *)argument_c_or_p, (const char*) "c") == 0)
		{
		  if(!cur)
		    {
		      cerr << "previous is NULL";
		      return -1;
		    }		  
		  (*cur).print();
		  i++;
		}
	      else
		{
		  if(!cur)
		    {
		      cerr << "previous is NULL";
		      return -1;
		    }		  
		  (*cur).print();
		  continue;
		}
	    }	  
	  else /* this is called when "... -O" , that is the last argument*/
	    {
	      if(!cur)
		{
		  cerr << "previous is NULL";
		  return -1;
		}		  
	      (*cur).print();
	    }
	}      
      else 
	{cerr << "unknown argument" << argv[i];}
    }
  
  if (tracing)
    cout << "End of processing"; 
  return 0;
}
