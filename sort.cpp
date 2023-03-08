#include "main.h"
#include "sort.h"

CSort::CSort() {
    window.create(VideoMode(1024, 768), "Sort");
    end = false;
    draw();
}

void CSort::draw() {

    int numOfSort = 0;
    int countOfSorts = SortMax - 1;

    cout << "1. Bubble sort" << endl;
    cout << "2. Insertion sort" << endl;
    cout << "3. Selection sort" << endl;

    cout << "Choose sort: ";

    while(cin >> numOfSort) {
        if (numOfSort > 0 && numOfSort <= countOfSorts) {
            break;
        } else {
            cout << "Incorrect input! Try again." << endl;
            cout << "Choose sort: ";
        }
    }

    Sort sort;
    switch (numOfSort) {
    case 1:
        sort = SortBubble;
        break;
    case 2:
        sort = SortInsertion;
        break;
    case 3:
        sort = SortSelection;
        break;
    default:
        break;
    }

    //array
    srand(time(0));
    for (auto i = 0; i < size; i++) {
        arr[i] = rand() % 699 + 1;
    }

    //rectangles
    for (auto i = 0; i < size; i++) {
        rects[i].setSize(Vector2f(2, arr[i]));
        rects[i].setPosition(5 + 3 * i, 740);
        rects[i].setRotation(180);
    }

    end = false;
    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.key.code == Keyboard::Escape)
                window.close();
        }
        //selection sort
        if (sort == SortSelection) {
            if (!end) {
                RectangleShape tmp;
                for (int i = 1; i < size; i++) {
                    for (int j = i; j > 0 && rects[j - 1].getSize().y > rects[j].getSize().y; j--) {
                        tmp.setSize(rects[j].getSize());
                        rects[j].setSize(rects[j - 1].getSize());
                        rects[j - 1].setSize(tmp.getSize());
                        window.clear();
                        for (auto i = 0; i < size; i++) {
                            window.draw(rects[i]);
                        }
                        window.display();
                    }
                }
            }
        }

        //insertion sort
        if (sort == SortInsertion) {
            if (!end) {
                RectangleShape key;
                int i = 0;
                for (int j = 1; j < size; j++) {
                    key = rects[j];
                    i = j - 1;
                    while (i >= 0 && rects[i].getSize().y > key.getSize().y) {
                        rects[i + 1].setSize(rects[i].getSize());
                        i = i - 1;
                        rects[i + 1].setSize(key.getSize());
                        window.clear();
                        for (auto i = 0; i < size; i++) {
                            window.draw(rects[i]);
                        }
                        window.display();
                    }
                }
            }
        }

        //bubble sort
        if (sort == SortBubble) {
            if (!end) {
                for (int i = 0; i < size - 1; i++) {
                    for (int j = 0; j < size - i - 1; j++) {
                        if (rects[j].getSize().y > rects[j + 1].getSize().y) {
                            RectangleShape temp;
                            temp.setSize(rects[j].getSize());
                            rects[j].setSize(rects[j + 1].getSize());
                            rects[j + 1].setSize(temp.getSize());
                            window.clear();
                            for (auto i = 0; i < size; i++) {
                                window.draw(rects[i]);
                            }
                            window.display();
                        }
                    }
                }
            }
        }
        
        end = true;
    }
}
