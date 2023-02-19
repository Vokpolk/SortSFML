#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

enum Sort {
    SortBubble = 1,
    SortInsertion
};

int main()
{
    RenderWindow window(VideoMode(1024, 768), "Sort");


    int numOfSort = 0;
    int countOfSorts = 2;

    cout << "1. Bubble sort" << endl;
    cout << "2. Insertion sort" << endl;

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
    default:
        break;
    }


    //array
    srand(time(0));
    const int size = 339;
    int arr[size];
    for (auto i = 0; i < size; i++) {
        arr[i] = rand() % 699 + 1;
    }

    //rectangles
    RectangleShape rects[size];
    for (auto i = 0; i < size; i++) {
        rects[i].setSize(Vector2f(2, arr[i]));
        rects[i].setPosition(5 + 3 * i, 740);
        rects[i].setRotation(180);
    }

    bool end = false;
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.key.code == Keyboard::Escape)
                window.close();
        }

        //quick sort
        


        //insertion sort
        if (sort == SortInsertion) {
            if (!end) {
                RectangleShape key;
                int i = 0;
                for(int j = 1; j < size; j++) {
                    key = rects[j];
                    i = j - 1;
                    while(i >= 0 && rects[i].getSize().y > key.getSize().y) {
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

    return 0;
}
