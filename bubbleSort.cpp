#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1024, 768), "Bubble sort");

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

        window.clear();
        for (auto i = 0; i < size; i++) {
            window.draw(rects[i]);
        }
        window.display();

        if (!end) {
            for (int i = 0; i < size - 1; i++) {
                for (int j = 0; j < size - i - 1; j++) {
                    if (rects[j].getSize().y > rects[j + 1].getSize().y) {
                        RectangleShape temp;
                        temp.setSize(rects[j].getSize());
                        rects[j].setSize(rects[j + 1].getSize());
                        rects[j + 1].setSize(temp.getSize());
                    }
                }
            }
        }
        end = true;
    }

    return 0;
}
