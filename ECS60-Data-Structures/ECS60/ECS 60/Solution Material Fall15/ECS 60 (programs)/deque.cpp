// Author: Sean Davis
#include <iostream>
template <typename T>
Deque<T>::Deque() 
{
	


	f = 0;
	b = -1;
	
	arrsize = 5000;
        arr = new T*[5000];

	
} // deque()


template <typename T>
T& Deque<T>::operator[] (int index)const
{
    int value = abs((-f+index+1)%1000);
  return arr[2500 + (-f-999 + index)/1000][value];
}  // operator[] read


template <typename T>
T& Deque<T>::operator[] (int index)
{
  return arr[2500 + (-f-999 + index)/1000][abs((-f+index+1)%1000)];   
} // operator[] write


template <typename T>
void Deque<T>::pop_back()
{
	
	b--;	

}  // pop_back()


template <typename T>
void Deque<T>::push_back(const T &value)
{
    	b++;
        if (!arr[2500+(b+999)/1000])
        {
            arr[2500+(b+999)/1000] = new T[1000]; 
        }

	

	/*if(b > arrsize/2)
	{
	resize();
	
	}*/	
	arr[2500 + (b+999)/1000][b%1000] = value;
} // push_back()

template <typename T>
void Deque<T>::pop_front()
{
	f --;

} // pop_front()


template <typename T>
void Deque<T>::push_front(const T &value)
{
		
	f++;
        if (!arr[2500 +(-f-999)/1000])
        {
            arr[2500 +(-f-999)/1000] = new T[1000]; 
        }
	/*if(f > arrsize/2)
	{
		resize();
	}
	arr[arrsize/2 - f] = value;*/
        arr[2500 + (-f-999)/1000][abs(f%1000)] = value;
	
}
template <typename T>
int Deque<T>::abs(int george)
{
    int value = george;
    if(value < 0)
    {
        return value *-1;
    }
    else
        return value;
}
// push_front()
/*template <typename T>
void Deque<T>::resize()
{
	
	T *oldarr = arr;
	arr = new T[arrsize*2];
	for(int i = -f;i <= b;i++)
	{ 
	  arr[arrsize+i] = oldarr[arrsize/2+i];
	}
	arrsize *=2;
	delete [] oldarr;
	
}
template<typename T>
void Deque<T>::print()
{
	std::cout << b << std::endl<<-f;		
	for(int i = -f; i <= b; i++)
	{
	 std::cout << arr[arrsize/2 -(f + i)/1000][(f+i)%1000]<<std::endl;
	}
	//for(int i =0; i <arrsize;i++)
	//{
	//	std::cout << arr[i];
	//}
}*/
