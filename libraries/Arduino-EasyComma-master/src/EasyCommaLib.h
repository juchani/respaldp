/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
****************************************************/


#ifndef _EASYCOMMALIB_h
#define _EASYCOMMALIB_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

typedef void(*Action)();

class EasyComma
{
 public:
	EasyComma(size_t capacity);
	~EasyComma();

	int& operator[](const size_t index);
	
	char Separator = ',';
	char EndSeparator = '\n';

	size_t Capacity();
	size_t LastIndex();
	size_t Count();
	bool IsOverflow();

	void Recieve(Action okCallback);

private:
	size_t _capacity;
	size_t _count;
	size_t _lastIndex;
	
	int* _items;
	size_t _currentItem;
	size_t _currentIndex;
	size_t _currentCount;
};


#endif

