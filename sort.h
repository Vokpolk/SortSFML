#pragma once

enum Sort {
    SortBubble = 1,
    SortInsertion,
    SortSelection,
    SortMax
};

class CSort {
public:
	CSort();
	void draw();
private:
	
	RenderWindow window;
	Event event;

	static const int size = 339;

	RectangleShape 	rects[size];
	int 			arr[size];
	bool 			end; 
};
