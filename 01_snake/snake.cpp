#include <iostream>

constexpr unsigned int FRAME_DIM_X = 10;
constexpr unsigned int FRAME_DIM_Y = 10;

void print_frame(int x, int y)
{
    for (unsigned int i = 0; i < FRAME_DIM_Y; ++i)
    {
        for (unsigned int j = 0; j < FRAME_DIM_X; ++j)
        {
            if (i == y && j == x)
            {
                std::cout << "O"; // Snake head
            }
            else if(i == 0 || i == FRAME_DIM_Y - 1 || j == 0 || j == FRAME_DIM_X - 1)
            {
                std::cout << "#"; // Wall
            }
            else
            {
                std::cout << " "; // Empty space
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    int init_x_pos = 1;
    int init_y_pos = 1;

    int x_pos = init_x_pos;
    int y_pos = init_y_pos;

    char input;

    while(true)
    {
        print_frame(x_pos, y_pos);
        // std::cout << "Enter direction (w/a/s/d): ";
        std::cin >> input;

        switch(input)
        {
            case 'w': // Up
                if(y_pos > 1)
                    y_pos--;
                break;
            case 's': // Down
                if(y_pos < FRAME_DIM_Y - 2)
                    y_pos++;
                break;
            case 'a': // Left
                if(x_pos > 1)
                    x_pos--;
                break;
            case 'd': // Right
                if(x_pos < FRAME_DIM_X - 2)
                    x_pos++;
                break;
            case 'q': // Quit
                return 0;
            default:
                std::cout << "Invalid input" << std::endl;
                continue;
        }
    }
}