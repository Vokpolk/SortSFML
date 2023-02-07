#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

void bubbleSort() {
    const int size = 5;
    int arr[size] = {2, 4, 1, 3, 5};

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    RenderWindow window(sf::VideoMode(1024, 768), "Bubble sort");

    //array
    srand(time(0));
    const int size = 5;
    int arr[size];
    for (auto i = 0; i < size; i++) {
        arr[i] = rand() % 699 + 1;
    }

    //rectangles
    RectangleShape rects[size];
    for (auto i = 0; i < size; i++) {
        rects[i].setSize(Vector2f(2, arr[i]));
        rects[i].setPosition(3 * i, 720);
        rects[i].setRotation(180);
    }

    bool end = false;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        window.clear();
        for (auto i = 0; i < size; i++) {
            window.draw(rects[i]);
        }
        window.display();

        if (!end) {
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - i - 1; j++) {
                    if (rects[j].getSize().y > rects[j + 1].getSize().y) {
                        // RectangleShape temp;
                        // temp.setSize(rects[j].getSize());
                        // rects[j].setSize(rects[j + 1].getSize());
                        // rects[j + 1].setSize(temp.getSize());
                        RectangleShape temp = rects[j];
                        rects[j] = rects[j + 1];
                        rects[j + 1] = temp;
                    }
                }
            }
        }
        end = true;
    }

    cout << "End" << endl;
    

    return 0;
}
