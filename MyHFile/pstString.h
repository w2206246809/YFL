#ifndef __STDLIB_H__
#include <stdlib.h>
#endif // !STDLIB_H

#ifndef __STRING_H__
#include <string.h>
#endif // !STRING_H

#pragma once
class Str {
public:

	Str() {
		_length = 0;
		vals = (char*)malloc(1);
		vals[0] = 0;
	}

	Str(const char src[]) {
		int i = 0;
		while (0 != src[i++]) {}
		_length = i - 1;
		vals = (char*) malloc(i);
		memcpy(vals, src, i);
	}

	Str(const Str &src) {
		this->_length = src._length;
		free(this->vals);
		this->vals = (char*)malloc(src._length + 1);
		memcpy(this->vals, src.vals, src._length + 1);
	}

	~Str() {
		free(vals);
	}

	// normal method
	char* c() {
		return vals;
	}

	int size() {
		return _length + 1;
	}

	int length() {
		return _length;
	}

	// operator override
	Str& operator=(const char src[]) {
		int i = 0;
		while (0 != src[i++]) {}
		this->_length = i - 1;
		free(this->vals);
		this->vals = (char*)malloc(i);
		memcpy(this->vals, src, i);
		return *this;
	}

	Str& operator=(const Str &src) {
		this->_length = src._length;
		free(this->vals);
		this->vals = (char*)malloc(src._length + 1);
		memcpy(this->vals, src.vals, src._length + 1);
		return *this;
	}

	Str& operator+=(const Str &src) {
		char* old = this->vals;
		this->vals = (char*)malloc(this->_length + src._length + 1);
		memcpy(this->vals, old, this->_length);
		free(old);
		memcpy(this->vals + this->_length, src.vals, src._length + 1);
		this->_length += src._length;
		return *this;
	}

	Str& operator+(const Str &src) {
		Str *tmp = (Str*)malloc(sizeof(Str));
		tmp->_length = this->_length + src._length;
		tmp->vals = (char*)malloc(tmp->_length + 1);
		memcpy(tmp->vals, this->vals, this->_length);
		memcpy(tmp->vals + this->_length, src.vals, src._length + 1);
		return *tmp;
	}

	bool operator==(const char src[]) {
		int i = 0;
		while (vals[i] == src[i]) {
			if (i == _length && src[i] == 0) {
				return true;
			}
			++i;
		}
		return false;
	}

	bool operator==(const Str &src) {
		if (_length == src._length) {
			int i = 0;
			while (vals[i] == src.vals[i]) {
				++i;
				if (i >= _length) {
					return true;
				}
			}
		}
		return false;
	}

private:
	int _length;
	char* vals;
};
