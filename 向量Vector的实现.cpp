# include <iostream>
using namespace std;
typedef int Rank;	//秩 
#define DEFAULT_CAPACITY 3
template <typename T> class Vector
{
private:
	Rank _size;		//规模 
	int _capacity;	//容量 
	T* _elem;		//数据区
protected:
	
public:
	Vector(int c = DEFAULT_CAPACITY)	//默认 
	{
		_elem = new T[_capacity = c];
		_size = 0;
	}
	Vector(T const *A,Rank lo,Rank hi)	//数据区间复制 
	{
		copyFrom(A,lo,hi);
	}
	Vector(Vector<T> const& V,Rank lo,Rank hi)	//向量区间复制 
	{
		copyFrom(V._elem,lo,hi);
	}
	Vector(Vector<T> const& V)	//向量整体复制 
	{
		copyFrom(V._elem,0,V._size);
	}
	~Vector()
	{
		delete [] _elem;
	}
	void copyFrom(T *const A,Rank lo,Rank hi);
	void expand();
	T& operator [](Rank)const;
	int remove(Rank lo,Rank hi);
	T remove(Rank r);
	Rank find(T const& e,Rank lo,Rank hi)const; 
	int deduplicate();
//	template <typename T>
	void traverse(void (*vist)(T&))
	{
		for(int i=0;i<_size;++i)
			vist(_elem[i]);
	}
//	template <typename T> 
	template <typename VST>
	void traverse(VST& vist)
	{
		for(int i=0;i<_size;++i)
			vist(_elem[i]);
	} 
};
template <typename T>
void Vector<T>::copyFrom(T *const A,Rank lo,Rank hi)
{
	_elem = new T[_capacity = 2*(hi-lo)];
	_size = 0;
	while(lo<hi)
		_elem[_size++] = A[lo++];
}
template <typename T>
int Vector<T>::remove(Rank lo,Rank hi)
{
	if(lo==hi)
		return 0;
	while(hi<_size)
		_elem[lo++] = _elem[hi++];
	_size = lo;
	shrink();
	return hi-lo;
}

template <typename T>
void Vector<T>::expand()
{
	if(_size < _capacity)
		return ;
	_capacity = max(_capacity,DEFAULT_CAPACITY);
	T* oldelem = _elem;
	_elem = new T[_capacity <<= 1];
	for(int i=0;i<_size;++i)
		_elem[i] = oldelem[i];
	delete [] oldelem; 
}
template <typename T>
T &Vector<T>::operator[](Rank r)const
{
	return _elem;
}
template <typename T>
T Vector<T>::remove(Rank r)
{
	T e = _elem[r];
	remove(r,r+1);
	return e;
}
template <typename T>
Rank Vector<T>::find(T const& e,Rank lo,Rank hi)const
{
	while((lo<hi--) && e!=_elem[hi]);	//逆向查找，在命中多个元素时可返回秩最大者 
	return hi;	//hi<lo意味着失败(因为是后自减)；否则hi即命中元素的秩 
}
template <typename T>
int Vector<T>::deduplicate()
{
	int oldSize = _size;
	Rank i = 1;
	while(i<_size)
		(find(_elem[i],0,i)<0)?	//在前缀中寻找雷同 
			i++					//若无雷同查找其后继 
			:remove(i);			//否则删除雷同 
	return oldSize-_size;
}
int main(void)
{
	return 0;
}  
