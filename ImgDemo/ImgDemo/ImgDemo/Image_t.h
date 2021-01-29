#ifndef IMAGE_T__H
#define IMAGE_T__H

#include <vector>
#include <QImage>

template <class T>

class Image_t {
public:
	void resize(int size);
	void push(T const&);

	T begin() const;
	T back() const;

	bool empty() const { 
		return elems.empty();
	}

	T value();

	T const & operator[](int index)const;
	T operator[](int index);

	T mValue;
private:
	std::vector<T> mVectValue; 
};

template<class T>
inline void Image_t<T>::resize(int size)
{
	mVectValue.resize(size);
}

template<class T>
void Image_t<T>::push(T const& elem) { 
	mVectValue.push_back(elem);
}

template<class T>
T Image_t<T>::begin() const {
	if (mVectValue.empty()) {
		throw out_of_range("Stack<>::top(): empty stack");
	}
	return mVectValue.begin();
}

template<class T>
T Image_t<T>::back() const {
	if (mVectValue.empty()) {
		throw out_of_range("Stack<>::top(): empty stack");
	}
	return mVectValue.back();
}

template<class T>
inline T Image_t<T>::value()
{
	return mValue;
}

template<class T>
inline T const & Image_t<T>::operator[](int index) const
{
	// TODO: insérer une instruction return ici
	return mVectValue.at(index);
}

template<class T>
inline T Image_t<T>::operator[](int index)
{
	return mVectValue.at(index);
}

#endif // IMAGE_T__H
