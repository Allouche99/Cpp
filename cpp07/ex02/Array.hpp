#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array
{
private:
	unsigned int    _len;
	T               *_adress;
public:
	Array(){
		_len = 0;
		_adress = NULL;
	}

	Array(unsigned int n){
		_len = n;
		_adress = new T[_len]();
	}

	Array(Array &o){
		_len = o._len;
		_adress = new T[_len]();
		for(unsigned int i = 0; i < _len; i++)
			_adress[i] = o._adress[i];
	}

	Array &operator=(const Array<T> &o)
	{
	    if (this != &o)
	    {
	        T *tmp = new T[o._len];
	        for (unsigned int i = 0; i < o._len; i++)
	            tmp[i] = o._adress[i];
	        delete[] _adress;
	        _adress = tmp;
	        _len = o._len;
	    }
	    return *this;
	}

	T &operator[](unsigned int index)
	{
	    if (index >= _len)
	        throw std::out_of_range("Index out of bounds");
	    return _adress[index];
	}

	const T &operator[](unsigned int index) const
	{
	    if (index >= _len)
	        throw std::out_of_range("Index out of bounds");
	    return _adress[index];
	}

	~Array()
	{
		delete []_adress;
	}
	unsigned int size() const{
		return _len;
	}
};
#endif