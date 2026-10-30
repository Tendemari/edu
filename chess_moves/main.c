#include <stdio.h>
#include <stdlib.h>

int check_chess_piece(char chess_piece, int x, int y)
{
    if (x == 0 && y == 0)
        return 0;

    if (chess_piece == 'k')
    {
        if (x <= 1 && y <= 1)
            return 1;
        return 0;
    }
    if (chess_piece == 'q')
    {
        if (x == 0 || y == 0 || x == y)
            return 1;
        return 0;
    }
    if (chess_piece == 'r')
    {
        if (x == 0 || y == 0)
            return 1;
        return 0;
    }  
    if (chess_piece == 'b')
    {
        if (x == y)
            return 1;
        return 0;
    }
    if (chess_piece == 'n')
    {
        if ((x == 1 && y == 2) || (x == 2 && y == 1))
            return 1;
        return 0;
    }
    return 0;
}

int main()
{
    printf("  a b c d e f g h\n");
    for(int i = 0; i < 8; ++i)
    {
        printf("%d ", 8-i);
        for (int j = 0; j < 8; ++j)
            printf((i+j)%2 ? ". " : "# ");
        printf("\n");
    }

    char k1_letter;
    char k1_number;

    char k2_letter;
    char k2_number;

    printf("Enter start tile K1: ");
    scanf(" %c%c", &k1_letter, &k1_number);

    printf("Enter end tile K2: ");
    scanf(" %c%c", &k2_letter, &k2_number);

    int x1 = k1_letter - 'a' + 1;
    int y1 = k1_number - '0';

    int x2 = k2_letter - 'a' + 1;
    int y2 = k2_number - '0';

    char user_chess_piece;

    printf("Choose chess piece(k - king, q - queen, r - rook, b - bishop, n - knight): ");
    scanf(" %c", &user_chess_piece);

    int x = abs(x1-x2);
    int y = abs(y1-y2);

    if (check_chess_piece(user_chess_piece, x, y))
    {
        switch (user_chess_piece)
        {
        case 'k': printf("King can reach this tile\n"); break;
        case 'q': printf("Queen can reach this tile\n"); break;
        case 'r': printf("Rook can reach this tile\n"); break;
        case 'b': printf("Bishop can reach this tile\n"); break;
        case 'n': printf("Knight can reach this tile\n"); break;
        }
    }
    else
    {
        printf("Your chess piece can't reach this tile\n");

        int any_chess_piece_can_reach = 0;
        if (check_chess_piece('k', x, y))
        {
            printf("King ");
            any_chess_piece_can_reach = 1;
        }
        if (check_chess_piece('q', x, y))
        {
            printf("Queen ");
            any_chess_piece_can_reach = 1;
        }
        if (check_chess_piece('r', x, y))
        {
            printf("Rook ");
            any_chess_piece_can_reach = 1;
        }
        if (check_chess_piece('b', x, y))
        {
            printf("Bishop ");
            any_chess_piece_can_reach = 1;
        }
        if (check_chess_piece('n', x, y))
        {
            printf("Knight ");
            any_chess_piece_can_reach = 1;
        }

        if (any_chess_piece_can_reach)
            printf("can reach this tile\n");
        else
            printf("None of the pieces\n");
        
    }

    return 0;
}