//C. Jaden Roskelley
//CS 1410
//Lab 9

#include <iostream>
#include "String.h"
using namespace std;



int String::delta = 15;

const int String::MAX_STRING;

String::String() {
	
	chars = new char[delta];
	size = 0;
	capacity = delta;
}
String::String(int capacity) {
	
	this->capacity = capacity;
}
String::String(const char* s) {


	for (int i = 0; s[i] != '\0'; i++)
		size++;
	delta = size + 1;
	chars = new char[delta];
	capacity = size;

	for (int i = 0; i < size; i++) {
		chars[i] = s[i];
	}
	
}
String::String(const String& s) {
	
	chars = new char[delta];
	size = s.size;
	capacity = s.capacity;

	for (int i = 0; i < size; i++) {
		chars[i] = s.chars[i];
	}

}
String::~String() {
	delete[] chars;
}
int String::get_size() {
	
	return size;
}

int String::get_capacity() {
	
	return capacity;
}

void String::shrink() {

	capacity = size;
}

void String::clear() {

	for (int i = 0; i < size; i++)
		chars[i] = '\0';
	for (int i = 0; chars[i] == '\0'; i++)
		size--;
	
}

void String::print(const char* prologue, const char* epilogue) const
{
	for (int i = 0; i < size; i++)
		cout << chars[i];
}

void String::println(const char* prologue, const char* epilogue) const
{
	if (prologue == NULL && epilogue == NULL) {
		for (int i = 0; i < size; i++)
			cout << chars[i];
		cout << endl;
	}
	else if (epilogue == NULL) {
		cout << prologue;
		for (int i = 0; i < size; i++)
			cout << chars[i];
		cout << endl;
	}
}

void String::append(char c)
{
	if (size + 1 >= delta) {
		chars[size] = c;
		size += 1;
	}
}

void String::append(const String& s)
{
	if(s.size >= delta - size)
		grow(size);
	
	for (int i = size, j = 0; i < capacity; i++, j++)
		chars[i] = s.chars[j];
	size = capacity-1;
}

int String::find(const String& pattern)
{
	int* next = new int[pattern.size + 1]{};

	next[0] = -1;
	int i = 0;
	int j = -1;
	for (; i < pattern.size; i++, j++, next[i] = j)
		while (j >= 0 && pattern.chars[i] != pattern.chars[j])
			j = next[j];

	for (i = 0, j = 0; j < pattern.size && i < size; i++, j++)
		while (j >= 0 && chars[i] != pattern.chars[j])
			j = next[j];

	delete[] next;

	if (j == pattern.size)
		return i - pattern.size;	
	else
		return -1;					
}

void String::set_delta(int delta)
{
	delta = 15;
}

void String::shift_right(int offset, int index)
{
	for (int i = size + offset - 1; i > index; i--)
		chars[i] = chars[i - offset];
	size += offset;
}

void String::grow(int base)
{
	if (base + delta > MAX_STRING)
		throw "grow: String is too large!";

	char* temp = chars;
	capacity = base + delta;
	chars = new char[capacity];
	for (int i = 0; i < size && i < capacity; i++)
		chars[i] = temp[i];
	delete[] temp;
}

ostream& operator<<(ostream& out, String& me)
{
	

	return out;
}
