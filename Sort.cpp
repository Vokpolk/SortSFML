#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1024, 768), "Sort");

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


        //insertion sort
        if (!end) {
            RectangleShape key;
            int i = 0;
            for(int j = 1; j < size; j++) {
                key = rects[j];//.getSize().y;//data[j];
                i = j - 1;
                while(i >= 0 && rects[i].getSize().y > key.getSize().y) {
                    rects[i + 1].setSize(rects[i].getSize());
                    //data[i + 1] = data[i];
                    i = i - 1;
                    rects[i + 1].setSize(key.getSize());
                    //data[i + 1] = key;
                    window.clear();
                    for (auto i = 0; i < size; i++) {
                        window.draw(rects[i]);
                    }
                    window.display();
                }
            }
        }
        end = true;

        //bubble sort
        /*if (!end) {
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
        end = true;*/
    }

    return 0;
}
