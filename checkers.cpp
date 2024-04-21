#include <bits/stdc++.h>
using namespace std;


class Piece
{
private:
	static int pieces_of_black;
	static int pieces_of_whites;

public:
    void Display(char checkerBoard[][8]);
    char startingPosition(int i, int j);
    int takemove(char a[][8], int x, int y, int pp);
    int checkmove(char a[][8], int x, int y, int ch, char p, int player);
    int whites(){
    	return pieces_of_whites;
	}
	int black(){
		return pieces_of_black;
	}
};
int Piece::pieces_of_black = 12;
int Piece::pieces_of_whites = 12;

void Piece::Display(char checkerBoard[][8])
    {
        for (int i = 0; i < 8; i++)
        {
            cout << "-------------------------------------------------------------------------\n    " << i << "\t|   ";
            for (int j = 0; j < 8; j++)
            {
                cout << checkerBoard[i][j] << "\t|   ";
            }
            cout << endl;
        }
        cout << "-------------------------------------------------------------------------\n";
        cout << "| INDEX\t|   0\t|   1\t|   2\t|   3\t|   4\t|   5\t|   6\t|   7   |\n";
        cout << "-------------------------------------------------------------------------\n";

    }


int Piece::checkmove(char a[][8], int x, int y, int ch, char p, int player)
    {
        int choice{0};
        if (player == 1)
        {
            if (p == 'K')
            {
                if (pieces_of_black == 1 && (a[x + 1][y + 1] == 'W' || a[x + 1][y + 1] == 'Q') && (a[x + 2][y + 2] == 'W' || a[x + 2][y + 2] == 'Q') && (a[x - 1][y - 1] == 'W' || a[x - 1][y - 1] == 'Q') && (a[x - 2][y - 2] == 'W' || a[x - 2][y - 2] == 'Q') && (a[x + 1][y - 1] == 'W' || a[x + 1][y - 1] == 'Q') && (a[x + 2][y - 2] == 'W' || a[x + 2][y - 2] == 'Q') && (a[x - 1][y + 1] == 'W' || a[x - 1][y + 1] == 'Q') && (a[x - 2][y + 2] == 'W' || a[x - 2][y + 2] == 'Q'))
                {
                    cout << "\nYou cannot move now hence You loose\n";
                    pieces_of_black--;
                    return 1;
                }
                if (ch == 2)
                {
                    if (a[x + 1][y + 1] == '\0' && x < 7 && y < 7)
                    {
                        a[x + 1][y + 1] = a[x][y];
                        a[x][y] = '\0';
                        return 1;
                    }
                    else if ((a[x + 1][y + 1] == 'W' || a[x + 1][y + 1] == 'Q') && x < 6 && y < 6)
                    {
                        if (a[x + 2][y + 2] == '\0')
                        {
                            a[x + 2][y + 2] = a[x][y];
                            a[x + 1][y + 1] = '\0';
                            a[x][y] = '\0';
                            pieces_of_whites--;
                            if ((a[x + 3][y + 3] == 'W' || a[x + 3][y + 3] == 'Q') && x < 4 && y < 4 && a[x + 4][y + 4] == '\0')
                            {
                                cout << endl << "Want to Jump Again?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x + 3][y + 3] = '\0';
                                    a[x + 4][y + 4] = a[x + 2][y + 2];
                                    a[x + 2][y + 2] = '\0';
                                    pieces_of_whites--;
                                }
                            }
                            else if ((a[x + 3][y + 1] == 'W' || a[x + 3][y + 1] == 'Q') && a[x + 4][y] == '\0' && x <= 3 && y <= 5)
                            {
                                cout << endl << "Do want to alternate Jump?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x + 3][y + 1] = '\0';
                                    a[x + 4][y] = a[x + 2][y + 2];
                                    a[x + 2][y + 2] = '\0';
                                    pieces_of_whites--;
                                }
                            }
                            return 1;
                        }
                        else
                        {
                            cout << "\nInvalid move";
                            return 0;
                        }
                    }
                    else if (a[x + 1][y + 1] == 'W' || a[x + 1][y + 1] == 'Q' && x == 6 && y == 6)
                    {
                        cout << "\nInvalid Command!Cannot Jump";
                        return 0;
                    }
                    else if (x >= 7 || y >= 7)
                    {
                        cout << "\nInvalid Move!";
                        return 0;
                    }
                    else if (a[x + 1][y + 1] == 'B' || a[x + 1][y + 1] == 'K' && x < 7 && y < 7)
                    {
                        cout << "Invalid Move!You cannot replace your own piece";
                        return 0;
                    }
                    else
                    {
                        cout << endl << "Invalid Command";
                        return 0;
                    }
                }
                else if (ch == 1)
                {
                    if (a[x + 1][y - 1] == '\0' && x < 7 && y <= 7 && y > 0)
                    {
                        a[x + 1][y - 1] = a[x][y];
                        a[x][y] = '\0';
                        return 1;
                    }
                    else if ((a[x + 1][y - 1] == 'W' || a[x + 1][y - 1] == 'Q') && x < 6 && y > 1)
                    {
                        if (a[x + 2][y - 2] == '\0')
                        {
                            a[x + 2][y - 2] = a[x][y];
                            a[x + 1][y - 1] = '\0';
                            a[x][y] = '\0';
                            pieces_of_whites--;
                            if ((a[x + 3][y - 3] == 'W' || a[x + 3][y - 3] == 'Q') && x < 4 && y > 3 && a[x + 4][y - 4] == '\0')
                            {
                                cout << endl << "Want to Jump Again?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x + 3][y - 3] = '\0';
                                    a[x + 4][y - 4] = a[x + 2][y - 2];
                                    a[x + 2][y - 2] = '\0';
                                    pieces_of_whites--;
                                }
                            }
                            else if ((a[x + 3][y - 1] == 'W' || a[x + 3][y - 1] == 'Q') && a[x + 4][y] == '\0' && x <= 3 && y >= 2)
                            {
                                cout << endl << "Do want to alternate Jump?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x + 3][y - 1] = '\0';
                                    a[x + 4][y] = a[x + 2][y - 2];
                                    a[x + 2][y - 2] = '\0';
                                    pieces_of_whites--;
                                }
                            }
                            return 1;
                        }
                        else
                        {
                            cout << "\nInvalid move";
                            return 0;
                        }
                    }
                    else if (a[x + 1][y - 1] == 'W' || a[x + 1][y - 1] == 'Q' && x == 6 && y == 6)
                    {
                        cout << "\nInvalid Command!Cannot Jump";
                        return 0;
                    }
                    else if (x >= 7 || y >= 7)
                    {
                        cout << "\nInvalid Move!";
                        return 0;
                    }
                    else if (a[x + 1][y - 1] == 'B' || a[x + 1][y - 1] == 'K' && x < 7 && y < 7)
                    {
                        cout << "Invalid Move!You cannot replace your own piece";
                        return 0;
                    }
                    else
                    {
                        cout << endl << "Invalid Command";
                        return 0;
                    }
                }
                else if (ch == 3)
                {
                    if (a[x - 1][y - 1] == '\0' && x >= 1 && y >= 1)
                    {
                        a[x - 1][y - 1] = a[x][y];
                        a[x][y] = '\0';
                        return 1;
                    }
                    else if ((a[x - 1][y - 1] == 'W' || a[x - 1][y - 1] == 'Q') && x > 1 && y > 1)
                    {
                        if (a[x - 2][y - 2] == '\0')
                        {
                            a[x - 2][y - 2] = a[x][y];
                            a[x - 1][y - 1] = '\0';
                            a[x][y] = '\0';
                            pieces_of_whites--;
                            if ((a[x - 3][y - 3] == 'W' || a[x - 3][y - 3] == 'Q') && x >= 4 && y >= 4 && a[x - 4][y - 4] == '\0')
                            {
                                cout << endl << "Want to Jump Again?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x - 3][y - 3] = '\0';
                                    a[x - 4][y - 4] = a[x - 2][y - 2];
                                    a[x - 2][y - 2] = '\0';
                                    pieces_of_whites--;
                                }
                            }
                            else if ((a[x - 3][y - 1] == 'W' || a[x - 3][y - 1] == 'Q') && a[x - 4][y] == '\0' && x >= 4 && y >= 2)
                            {
                                cout << endl << "Do want to alternate Jump?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x - 3][y - 1] = '\0';
                                    a[x - 4][y] = a[x - 2][y - 2];
                                    a[x - 2][y - 2] = '\0';
                                    pieces_of_whites--;
                                }
                            }
                            return 1;
                        }
                        else
                        {
                            cout << "\nInvalid move";
                            return 0;
                        }
                    }
                    else if (a[x - 1][y - 1] == 'W' || a[x - 1][y - 1] == 'Q' && x == 1 && y == 1)
                    {
                        cout << "\nInvalid Command!Cannot Jump";
                        return 0;
                    }
                    else if (x <= 0 || y <= 0)
                    {
                        cout << "\nInvalid Move!You loose your move";
                        return 0;
                    }
                    else if (a[x - 1][y - 1] == 'B' || a[x - 1][y - 1] == 'K' && x > 0 && y > 0)
                    {
                        cout << "Invalid Move!You cannot replace your own piece";
                        return 0;
                    }
                    else
                    {
                        cout << endl << "Invalid Command";
                        return 0;
                    }
                }
                else if (ch == 4)
                {
                    if (a[x - 1][y + 1] == '\0' && x >= 1 && y < 7)
                    {
                        a[x - 1][y + 1] = a[x][y];
                        a[x][y] = '\0';
                        return 1;
                    }
                    else if ((a[x - 1][y + 1] == 'W' || a[x - 1][y + 1] == 'Q') && x > 1 && y < 6)
                    {
                        if (a[x - 2][y + 2] == '\0')
                        {
                            a[x - 2][y + 2] = a[x][y];
                            a[x - 1][y + 1] = '\0';
                            a[x][y] = '\0';
                            pieces_of_whites--;
                            if ((a[x - 3][y + 3] == 'W' || a[x - 3][y + 3] == 'Q') && x >= 4 && y < 4 && a[x - 4][y + 4] == '\0')
                            {
                                cout << endl << "Want to Jump Again?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x - 3][y + 3] = '\0';
                                    a[x - 4][y + 4] = a[x - 2][y + 2];
                                    a[x - 2][y + 2] = '\0';
                                    pieces_of_whites--;
                                }
                            }
                            else if ((a[x - 3][y + 1] == 'W' || a[x - 3][y + 1] == 'Q') && a[x - 4][y] == '\0' && x >= 4 && y <= 5)
                            {
                                cout << endl << "Do want to alternate Jump?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x - 3][y + 1] = '\0';
                                    a[x - 4][y] = a[x - 2][y + 2];
                                    a[x - 2][y + 2] = '\0';
                                    pieces_of_whites--;
                                }
                            }
                            return 1;
                        }
                        else
                        {
                            cout << "\nInvalid move";
                            return 0;
                        }
                    }
                    else if ((a[x - 1][y + 1] == 'W' || a[x - 1][y + 1] == 'Q') && x == 1 && y == 1)
                    {
                        cout << "\nInvalid Command!Cannot Jump";
                        return 0;
                    }
                    else if (x <= 0 || y <= 0)
                    {
                        cout << "\nInvalid Move!";
                        return 0;
                    }
                    else if (a[x - 1][y + 1] == 'B' || a[x - 1][y + 1] == 'K' && x > 0 && y > 0)
                    {
                        cout << "Invalid Move!You cannot replace your own piece";
                        return 0;
                    }
                }
                else
                {
                    cout << endl << "Invalid Command";
                    return 0;
                }
            }
            else if (p == 'B')
            {
                if (pieces_of_black == 1 && (a[x + 1][y + 1] == 'W' || a[x + 1][y + 1] == 'Q') && (a[x + 2][y + 2] == 'W' || a[x + 2][y + 2] == 'Q') && (a[x + 1][y - 1] == 'W' || a[x + 1][y - 1] == 'Q') && (a[x + 2][y - 2] == 'W' || a[x + 2][y - 2] == 'Q'))
                {
                    cout << "\nYou cannot move now hence You loose\n";
                    pieces_of_black--;
                    return 1;
                }
                if (ch == 2)
                {
                    if (a[x + 1][y + 1] == '\0' && x < 7 && y < 7)
                    {
                        a[x + 1][y + 1] = a[x][y];
                        a[x][y] = '\0';
                        if (x == 6)
                        {
                            a[x + 1][y + 1] = 'K';
                        }
                        return 1;
                    }
                    else if ((a[x + 1][y + 1] == 'W' || a[x + 1][y + 1] == 'Q') && x < 6 && y < 6)
                    {
                        if (a[x + 2][y + 2] == '\0')
                        {
                            a[x + 2][y + 2] = a[x][y];
                            a[x + 1][y + 1] = '\0';
                            a[x][y] = '\0';
                            if (x == 5)
                            {
                                a[x + 2][y + 2] = 'K';
                            }
                            pieces_of_whites--;
                            if ((a[x + 3][y + 3] == 'W' || a[x + 3][y + 3] == 'Q') && x < 4 && y < 4 && a[x + 4][y + 4] == '\0')
                            {
                                cout << endl << "Want to Jump Again?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x + 3][y + 3] = '\0';
                                    a[x + 4][y + 4] = a[x + 2][y + 2];
                                    a[x + 2][y + 2] = '\0';
                                    pieces_of_whites--;
                                    if (x == 3)
                                    {
                                        a[x + 4][y + 4] = 'K';
                                    }
                                }
                            }
                            else if ((a[x + 3][y + 1] == 'W' || a[x + 3][y + 1] == 'Q') && a[x + 4][y] == '\0' && x < 4 && y < 6)
                            {
                                cout << endl << "Do want to alternate Jump?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x + 3][y + 1] = '\0';
                                    a[x + 4][y] = a[x + 2][y + 2];
                                    a[x + 2][y + 2] = '\0';
                                    pieces_of_whites--;
                                    if (x == 3)
                                    {
                                        a[x + 4][y] = 'K';
                                    }
                                }
                            }
                            return 1;
                        }
                        else
                        {
                            cout << "\nInvalid move";
                            return 0;
                        }
                    }
                    else if ((a[x + 1][y + 1] == 'W' || a[x + 1][y + 1] == 'Q') && x == 6 && y == 6)
                    {
                        cout << "\nInvalid Command!Cannot Jump";
                        return 0;
                    }
                    else if (x >= 7 || y >= 7)
                    {
                        cout << "\nInvalid Move!";
                        return 0;
                    }
                    else if ((a[x + 1][y + 1] == 'B' || a[x + 1][y + 1] == 'K') && x < 7 && y < 7)
                    {
                        cout << "Invalid Move!You cannot replace your own piece";
                        return 0;
                    }
                    else
                    {
                        cout << endl << "Invalid Command";
                        return 0;
                    }
                }
                else if (ch == 1)
                {
                    if (a[x + 1][y - 1] == '\0' && x < 7 && y > 0)
                    {
                        a[x + 1][y - 1] = a[x][y];
                        a[x][y] = '\0';
                        if (x == 6)
                        {
                            a[x + 1][y - 1] = 'K';
                        }
                        return 1;
                    }
                    else if ((a[x + 1][y - 1] == 'W' || a[x + 1][y - 1] == 'Q') && x < 6 && y > 1)
                    {
                        if (a[x + 2][y - 2] == '\0')
                        {
                            a[x + 2][y - 2] = a[x][y];
                            a[x + 1][y - 1] = '\0';
                            a[x][y] = '\0';
                            if (x == 5)
                            {
                                a[x + 2][y - 2] = 'K';
                            }
                            pieces_of_whites--;
                            if ((a[x + 3][y - 3] == 'W' || a[x + 3][y - 3] == 'Q') && x < 4 && y > 3 && a[x + 4][y - 4] == '\0')
                            {
                                cout << endl << "Want to Jump Again?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x + 3][y - 3] = '\0';
                                    a[x + 4][y - 4] = a[x + 2][y - 2];
                                    a[x + 2][y - 2] = '\0';
                                    pieces_of_whites--;
                                    if (x == 3)
                                    {
                                        a[x + 4][y - 4] = 'K';
                                    }
                                }
                            }
                            else if ((a[x + 3][y - 1] == 'W' || a[x + 3][y - 1] == 'Q') && a[x + 4][y] == '\0' && x < 4 && y > 1)
                            {
                                cout << endl << "Do want to alternate Jump?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x + 3][y - 1] = '\0';
                                    a[x + 4][y] = a[x + 2][y - 2];
                                    a[x + 2][y - 2] = '\0';
                                    pieces_of_whites--;
                                    if (x == 3)
                                    {
                                        a[x + 4][y] = 'K';
                                    }
                                }
                            }
                            return 1;
                        }
                        else
                        {
                            cout << "\nInvalid move";
                            return 0;
                        }
                    }
                    else if ((a[x + 1][y - 1] == 'W' || a[x + 1][y - 1] == 'Q') && x == 6 && y == 6)
                    {
                        cout << "\nInvalid Command!Cannot Jump";
                        return 0;
                    }
                    else if (x >= 7 || y >= 7)
                    {
                        cout << "\nInvalid Move!";
                        return 0;
                    }
                    else if ((a[x + 1][y - 1] == 'B' || a[x + 1][y - 1] == 'K') && x < 7 && y < 7)
                    {
                        cout << "Invalid Move!You cannot replace your own piece";
                        return 0;
                    }
                    else
                    {
                        cout << endl
                             << "Invalid Command";
                        return 0;
                    }
                }
                else
                {
                    cout << endl
                         << "Invalid Command";
                    return 0;
                }
            }
        }
        else if (player == 2)
        {
            if (p == 'Q')
            {
                if (pieces_of_whites == 1 && (a[x + 1][y + 1] == 'B' || a[x + 1][y + 1] == 'K') && (a[x + 2][y + 2] == 'B' || a[x + 2][y + 2] == 'K') && (a[x - 1][y - 1] == 'B' || a[x - 1][y - 1] == 'K') && (a[x - 2][y - 2] == 'B' || a[x - 2][y - 2] == 'K') && (a[x + 1][y - 1] == 'B' || a[x + 1][y - 1] == 'K') && (a[x + 2][y - 2] == 'B' || a[x + 2][y - 2] == 'K') && (a[x - 1][y + 1] == 'B' || a[x - 1][y + 1] == 'K') && (a[x - 2][y + 2] == 'B' || a[x - 2][y + 2] == 'K'))
                {
                    cout << "\nYou cannot move now hence You loose\n";
                    pieces_of_whites--;
                    return 1;
                }
                if (ch == 3)
                {
                    if (a[x + 1][y + 1] == '\0' && x < 7 && y > 7)
                    {
                        a[x + 1][y + 1] = a[x][y];
                        a[x][y] = '\0';
                        return 1;
                    }
                    else if ((a[x + 1][y + 1] == 'B' || a[x + 1][y + 1] == 'K') && x < 6 && y < 6)
                    {
                        if (a[x + 2][y + 2] == '\0')
                        {
                            a[x + 2][y + 2] = a[x][y];
                            a[x + 1][y + 1] = '\0';
                            a[x][y] = '\0';
                            pieces_of_black--;
                            if ((a[x + 3][y + 3] == 'B' || a[x + 3][y + 3] == 'K') && x < 4 && y < 3 && a[x + 4][y + 4] == '\0')
                            {
                                cout << endl << "Want to Jump Again?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x + 3][y + 3] = '\0';
                                    a[x + 4][y + 4] = a[x + 2][y - 2];
                                    a[x + 2][y + 2] = '\0';
                                    pieces_of_black--;
                                }
                            }
                            else if ((a[x + 3][y + 1] == 'B' || a[x + 3][y + 1] == 'K') && a[x + 4][y] == '\0' && x < 4 && y < 6)
                            {
                                cout << endl << "Do want to alternate Jump?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x + 3][y + 1] = '\0';
                                    a[x + 4][y] = a[x + 2][y + 2];
                                    a[x + 2][y + 2] = '\0';
                                    pieces_of_black--;
                                }
                            }
                            return 1;
                        }
                        else
                        {
                            cout << "\nInvalid move";
                            return 0;
                        }
                    }
                    else if ((a[x + 1][y + 1] == 'B' || a[x + 1][y + 1] == 'K') && x == 6 && y == 6)
                    {
                        cout << "\nInvalid Command!Cannot Jump";
                        return 0;
                    }
                    else if (x >= 7 || y >= 7)
                    {
                        cout << "\nInvalid Move!";
                        return 0;
                    }
                    else if ((a[x + 1][y + 1] == 'W' || a[x + 1][y + 1] == 'Q') && x < 7 && y < 7)
                    {
                        cout << "Invalid Move!You cannot replace your own piece";
                        return 0;
                    }
                    else
                    {
                        cout << endl << "Invalid Command";
                        return 0;
                    }
                }
                else if (ch == 4)
                {
                    if (a[x + 1][y - 1] == '\0' && x < 7 && y > 0)
                    {
                        a[x + 1][y - 1] = a[x][y];
                        a[x][y] = '\0';
                        return 1;
                    }
                    else if ((a[x + 1][y - 1] == 'B' || a[x + 1][y - 1] == 'K') && x < 6 && y > 1)
                    {
                        if (a[x + 2][y - 2] == '\0')
                        {
                            a[x + 2][y - 2] = a[x][y];
                            a[x + 1][y - 1] = '\0';
                            a[x][y] = '\0';
                            pieces_of_black--;
                            if ((a[x + 3][y - 3] == 'B' || a[x + 3][y - 3] == 'K') && x < 4 && y > 3 && a[x + 4][y - 4] == '\0')
                            {
                                cout << endl << "Want to Jump Again?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x + 3][y - 3] = '\0';
                                    a[x + 4][y - 4] = a[x + 2][y - 2];
                                    a[x + 2][y - 2] = '\0';
                                    pieces_of_black--;
                                }
                            }
                            else if ((a[x + 3][y - 1] == 'B' || a[x + 3][y - 1] == 'K') && a[x + 4][y] == '\0' && x < 4 && y > 2)
                            {
                                cout << endl << "Do want to alternate Jump?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x + 3][y - 1] = '\0';
                                    a[x + 4][y] = a[x + 2][y - 2];
                                    a[x + 2][y - 2] = '\0';
                                    pieces_of_black--;
                                }
                            }
                            return 1;
                        }
                        else
                        {
                            cout << "\nInvalid move";
                            return 0;
                        }
                    }
                    else if ((a[x + 1][y - 1] == 'B' || a[x + 1][y - 1] == 'K') && x == 6 && y == 6)
                    {
                        cout << "\nInvalid Command!Cannot Jump";
                        return 0;
                    }
                    else if (x >= 7 || y >= 7)
                    {
                        cout << "\nInvalid Move!You loose your move";
                        return 0;
                    }
                    else if ((a[x + 1][y - 1] == 'W' || a[x + 1][y - 1] == 'Q') && x < 7 && y < 7)
                    {
                        cout << "Invalid Move!You cannot replace your own piece";
                        return 0;
                    }
                    else
                    {
                        cout << endl << "Invalid Command";
                        return 0;
                    }
                }
                else if (ch == 2)
                {
                    if (a[x - 1][y - 1] == '\0' && x >= 1 && y >= 1)
                    {
                        a[x - 1][y - 1] = a[x][y];
                        a[x][y] = '\0';
                        return 1;
                    }
                    else if ((a[x - 1][y - 1] == 'B' || a[x - 1][y - 1] == 'K') && x > 1 && y > 1)
                    {
                        if (a[x - 2][y - 2] == '\0')
                        {
                            a[x - 2][y - 2] = a[x][y];
                            a[x - 1][y - 1] = '\0';
                            a[x][y] = '\0';
                            pieces_of_black--;
                            if ((a[x - 3][y - 3] == 'B' || a[x - 3][y - 3] == 'K') && x > 3 && y > 3 && a[x - 4][y - 4] == '\0')
                            {
                                cout << endl << "Want to Jump Again?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x - 3][y - 3] = '\0';
                                    a[x - 4][y - 4] = a[x - 2][y - 2];
                                    a[x - 2][y - 2] = '\0';
                                    pieces_of_black--;
                                }
                            }
                            else if ((a[x - 3][y - 1] == 'B' || a[x - 3][y - 1] == 'K') && a[x - 4][y] == '\0' && x > 3 && y > 1)
                            {
                                cout << endl << "Do want to alternate Jump?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x - 3][y - 1] = '\0';
                                    a[x - 4][y] = a[x - 2][y - 2];
                                    a[x - 2][y - 2] = '\0';
                                    pieces_of_black--;
                                }
                            }
                            return 1;
                        }
                        else
                        {
                            cout << "\nInvalid move";
                            return 0;
                        }
                    }
                    else if ((a[x - 1][y - 1] == 'B' || a[x - 1][y - 1] == 'K') && x == 1 && y == 1)
                    {
                        cout << "\nInvalid Command!Cannot Jump";
                        return 0;
                    }
                    else if (x <= 0 || y <= 0)
                    {
                        cout << "\nInvalid Move!";
                        return 0;
                    }
                    else if ((a[x - 1][y - 1] == 'W' || a[x - 1][y - 1] == 'Q') && x > 0 && y > 0)
                    {
                        cout << "Invalid Move!You cannot replace your own piece";
                        return 0;
                    }
                    else
                    {
                        cout << endl << "Invalid Command";
                        return 0;
                    }
                }
                else if (ch == 1)
                {
                    if (a[x - 1][y + 1] == '\0' && x >= 1 && y < 7)
                    {
                        a[x - 1][y + 1] = a[x][y];
                        a[x][y] = '\0';
                        return 1;
                    }
                    else if ((a[x - 1][y + 1] == 'B' || a[x - 1][y + 1] == 'K') && x > 1 && y > 1)
                    {
                        if (a[x - 2][y + 2] == '\0')
                        {
                            a[x - 2][y + 2] = a[x][y];
                            a[x - 1][y + 1] = '\0';
                            a[x][y] = '\0';
                            pieces_of_black--;
                            if ((a[x - 3][y + 3] == 'B' || a[x - 3][y + 3] == 'K') && x > 3 && y < 3 && a[x - 4][y + 4] == '\0')
                            {
                                cout << endl << "Want to Jump Again?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x - 3][y + 3] = '\0';
                                    a[x - 4][y + 4] = a[x - 2][y + 2];
                                    a[x - 2][y + 2] = '\0';
                                    pieces_of_black--;
                                }
                            }
                            else if ((a[x - 3][y + 1] == 'B' || a[x - 3][y + 1] == 'K') && a[x - 4][y] == '\0' && x > 3 && y < 6)
                            {
                                cout << endl << "Do want to alternate Jump?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x - 3][y + 1] = '\0';
                                    a[x - 4][y] = a[x - 2][y + 2];
                                    a[x - 2][y + 2] = '\0';
                                    pieces_of_black--;
                                }
                            }
                            return 1;
                        }
                        else
                        {
                            cout << "\nInvalid move";
                            return 0;
                        }
                    }
                    else if ((a[x - 1][y + 1] == 'B' || a[x - 1][y + 1] == 'K') && x == 1 && y == 1)
                    {
                        cout << "\nInvalid Command!Cannot Jump";
                        return 0;
                    }
                    else if (x <= 0 || y <= 0)
                    {
                        cout << "\nInvalid Move!";
                        return 0;
                    }
                    else if ((a[x - 1][y + 1] == 'W' || a[x - 1][y + 1] == 'Q') && x > 0 && y > 0)
                    {
                        cout << "Invalid Move!You cannot replace your own piece";
                        return 0;
                    }
                }
                else
                {
                    cout << endl << "Invalid Command";
                    return 0;
                }
            }
            else if (p == 'W')
            {
                if (pieces_of_whites == 1 && (a[x - 1][y - 1] == 'B' || a[x - 1][y - 1] == 'K') && (a[x - 2][y - 2] == 'B' || a[x - 2][y - 2] == 'K') && (a[x - 1][y + 1] == 'B' || a[x - 1][y + 1] == 'K') && (a[x - 2][y + 2] == 'B' || a[x - 2][y + 2] == 'K'))
                {
                    cout << "\nYou cannot move now hence You loose\n";
                    pieces_of_whites--;
                    return 1;
                }
                if (ch == 2)
                {
                    if (a[x - 1][y - 1] == '\0' && x >= 1 && y >= 1)
                    {
                        a[x - 1][y - 1] = a[x][y];
                        a[x][y] = '\0';
                        if (x == 1)
                        {
                            a[x - 1][y - 1] = 'Q';
                        }
                        return 1;
                    }
                    else if ((a[x - 1][y - 1] == 'B' || a[x - 1][y - 1] == 'K') && x > 1 && y < 6)
                    {
                        if (a[x - 2][y - 2] == '\0')
                        {
                            a[x - 2][y - 2] = a[x][y];
                            a[x - 1][y - 1] = '\0';
                            a[x][y] = '\0';
                            if (x == 2)
                            {
                                a[x - 2][y - 2] = 'Q';
                            }
                            pieces_of_black--;
                            if ((a[x - 3][y - 3] == 'B' || a[x - 3][y - 3] == 'K') && x > 3 && y > 3 && a[x - 4][y - 4] == '\0')
                            {
                                cout << endl << "Want to Jump Again?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x - 3][y - 3] = '\0';
                                    a[x - 4][y - 4] = a[x - 2][y - 2];
                                    a[x - 2][y - 2] = '\0';
                                    pieces_of_black--;
                                    if (x == 4)
                                    {
                                        a[x - 4][y - 4] = 'Q';
                                    }
                                }
                            }
                            else if ((a[x - 3][y - 1] == 'B' || a[x - 3][y - 1] == 'K') && a[x - 4][y] == '\0' && x > 3 && y > 1)
                            {
                                cout << endl << "Do want to alternate Jump?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x - 3][y - 1] = '\0';
                                    a[x - 4][y] = a[x - 2][y - 2];
                                    a[x - 2][y - 2] = '\0';
                                    pieces_of_black--;
                                    if (x == 4)
                                    {
                                        a[x - 4][y] = 'Q';
                                    }
                                }
                            }
                            return 1;
                        }
                        else
                        {
                            cout << "\nInvalid move";
                            return 0;
                        }
                    }
                    else if ((a[x - 1][y - 1] == 'B' || a[x - 1][y - 1] == 'K') && x == 1 && y == 1)
                    {
                        cout << "\nInvalid Command!Cannot Jump";
                        return 0;
                    }
                    else if (x <= 0 || y <= 0)
                    {
                        cout << "\nInvalid Move!";
                        return 0;
                    }
                    else if ((a[x - 1][y - 1] == 'W' || a[x - 1][y - 1] == 'Q') && x > 0 && y > 0)
                    {
                        cout << "Invalid Move!You cannot replace your own piece";
                        return 0;
                    }
                    else
                    {
                        cout << endl << "Invalid Command";
                        return 0;
                    }
                }
                else if (ch == 1)
                {
                    if (a[x - 1][y + 1] == '\0' && x >= 1 && y >= 0)
                    {
                        a[x - 1][y + 1] = a[x][y];
                        a[x][y] = '\0';
                        if (x == 1)
                        {
                            a[x - 1][y + 1] = 'Q';
                        }
                        return 1;
                    }
                    else if ((a[x - 1][y + 1] == 'B' || a[x - 1][y + 1] == 'K') && x > 1 && y < 6)
                    {
                        if (a[x - 2][y + 2] == '\0')
                        {
                            a[x - 2][y + 2] = a[x][y];
                            a[x - 1][y + 1] = '\0';
                            a[x][y] = '\0';
                            if (x == 2)
                            {
                                a[x - 2][y + 2] = 'Q';
                            }
                            pieces_of_black--;
                            if ((a[x - 3][y + 3] == 'B' || a[x - 3][y + 3] == 'K') && x > 3 && y < 4 && a[x - 4][y + 4] == '\0')
                            {
                                cout << endl << "Want to Jump Again?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x - 3][y + 3] = '\0';
                                    a[x - 4][y + 4] = a[x - 2][y + 2];
                                    a[x - 2][y + 2] = '\0';
                                    pieces_of_black--;
                                    if (x == 4)
                                    {
                                        a[x - 4][y + 4] = 'Q';
                                    }
                                }
                            }
                            else if ((a[x - 3][y + 1] == 'B' || a[x - 3][y + 1] == 'K') && a[x - 4][y] == '\0' && x > 3 && y < 6)
                            {
                                cout << endl << "Do want to alternate Jump?\n1)Yes\n2)No\n";
                                cin >> ch;
                                if (ch == 1)
                                {
                                    a[x - 3][y + 1] = '\0';
                                    a[x - 4][y] = a[x - 2][y + 2];
                                    a[x - 2][y + 2] = '\0';
                                    pieces_of_black--;
                                    if (x == 4)
                                    {
                                        a[x - 4][y] = 'Q';
                                    }
                                }
                            }
                            return 1;
                        }
                        else
                        {
                            cout << "\nInvalid move";
                            return 0;
                        }
                    }
                    else if ((a[x - 1][y + 1] == 'B' || a[x - 1][y + 1] == 'K') && x == 1 && y == 1)
                    {
                        cout << "\nInvalid Command!Cannot Jump";
                        return 0;
                    }
                    else if (x <= 0 || y <= 0)
                    {
                        cout << "\nInvalid Move!";
                        return 0;
                    }
                    else if ((a[x - 1][y + 1] == 'W' || a[x - 1][y + 1] == 'Q') && x > 0 && y > 0)
                    {
                        cout << "Invalid Move!You cannot replace your own piece";
                        return 0;
                    }
                }
                else
                {
                    cout << endl << "Invalid Command";
                    return 0;
                }
            }
        }
    }


char Piece::startingPosition(int i, int j)
    {
        if (j % 2 != 0 && i % 2 == 0 && i < 3)
        {
            return 'B';
        }
        else if (j % 2 == 0 && i % 2 != 0 && i < 3)
        {
            return 'B';
        }
        else if (j % 2 != 0 && i % 2 == 0 && i >= 5)
        {
            return 'W';
        }
        else if (j % 2 == 0 && i % 2 != 0 && i >= 5)
        {
            return 'W';
        }
        else if (i == 3 && j % 2 == 0)
        {
            return '\0';
        }
        else if (i == 4 && j % 2 != 0)
        {
            return '\0';
        }
        else
        {
            return '\0';
        }
    }
    
    
int Piece::takemove(char a[][8], int x, int y, int pp)
    {
        int rtn{0};
        int ch{0};
        if (pp == 1)
        {
            if (a[x][y] == 'K')
            {
                while (rtn != 1)
                {
                    cout << "\nEnter Move:";
                    cout << "\n1)Forward Right\n2)Forward Left\n3)Backward Right\n4)Backward Left\n5)Leave OR Select New Index\n6)Forfeit\n";
                    cin >> ch;
                    if (ch == 5)
                    {
                        return 0;
                    }
                    if (ch == 6)
                    {
                        return 2;
                    }
                    rtn = checkmove(a, x, y, ch, 'K', 1);
                }
                return 1;
            }
            else if (a[x][y] == 'B')
            {
                while (rtn != 1)
                {
                    cout << "\nEnter Move:";
                    cout << "\n1)Forward Right\n2)Forward Left\n3)Leave OR Select New Index\n4)Forfeit\n";
                    cin >> ch;
                    if (ch == 3)
                    {
                        return 0;
                    }
                    if (ch == 4)
                    {
                        return 2;
                    }
                    rtn = checkmove(a, x, y, ch, 'B', 1);
                }
                return 1;
            }
            else
            {
                cout << "\nInvalid Index,You cannot Move it!!!";
                return 0;
            }
        }
        else if (pp == 2)
        {
            if (a[x][y] == 'Q')
            {
                while (rtn != 1)
                {
                    cout << "\nEnter Move:";
                    cout << "\n1)Forward Right\n2)Forward Left\n3)Backward Right\n4)Backward Left\n5)Leave OR Select New Index\n6)Forfeit\n";
                    cin >> ch;
                    if (ch == 5)
                    {
                        return 0;
                    }
                    if (ch == 6)
                    {
                        return 2;
                    }
                    rtn = checkmove(a, x, y, ch, 'Q', 2);
                }
                return 1;
            }
            else if (a[x][y] == 'W')
            {
                while (rtn != 1)
                {
                    cout << "\nEnter Move:";
                    cout << "\n1)Forward Right\n2)Forward Left\n3)Leave OR Select New Index\n4)Forfeit\n";
                    cin >> ch;
                    if (ch == 3)
                    {
                        return 0;
                    }
                    if (ch == 4)
                    {
                        return 2;
                    }
                    rtn = checkmove(a, x, y, ch, 'W', 2);
                }
                return 1;
            }
            else
            {
                cout << "\nInvalid Index,You cannot Move it!!!";
                return 0;
            }
        }
    }



int main()
{
    char checkerBoard[8][8];
    Piece p[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            checkerBoard[i][j] = p[i][j].startingPosition(i, j);
        }
    }
    p[0][0].Display(checkerBoard);
    int ch{0}, x{0}, y{0}, rtn{0}, br{0};
    while (ch != 2)
    {
        ch = 0;
        rtn = 0;
        cout << "\nPlayer 1(BLACK):";
        cout << "\nEnter option:\n1)Take Move\n2)Want to leave\n";
        cin >> ch;
        if (ch != 2)
        {
            if (ch == 1)
            {
                while (rtn != 1)
                {
                    cout << "\nEnter index of piece you want to move:\n";
                    cin >> x >> y;
                    rtn = p[x][y].takemove(checkerBoard, x, y, 1);
                    if (rtn == 2)
                    {
                        cout << "\nPlayer 2(WHITE) wins";
                        br = 1;
                        break;
                    }
                }
                if (br == 1)
                {
                    break;
                }
                p[x][y].Display(checkerBoard);
            }
            else
            {
                cout << "\nEnter Valid Command!";
            }
        }
        else
        {
            cout << "\nPlayer 2 wins";
            break;
        }
        if (p[0][1].whites()== 0)
        {
            cout << "\nPlayer 1(BLACK) Wins";
        }
        cout << "\n\nPlayer 2(WHITE):";
        cout << "\nEnter option:\n1)Take Move\n2)Want to leave\n";
        cin >> ch;
        rtn = 0;
        if (ch != 2)
        {
            if (ch == 1)
            {
                while (rtn != 1)
                {
                    cout << "\nEnter index of piece you want to move:\n";
                    cin >> x >> y;
                    rtn = p[x][y].takemove(checkerBoard, x, y, 2);
                    if (rtn == 2)
                    {
                        cout << "\nPlayer 1(BLACK) wins";
                        br = 1;
                        break;
                    }
                }
                if (br == 1)
                {
                    break;
                }
                p[x][y].Display(checkerBoard);
            }
            else
            {
                cout << "\nEnter Valid Command!";
            }
        }
        else
        {
            
            cout << "\nPlayer 1(BLACK) wins";
            break;
        }
        if (p[0][1].black() == 0)
        {
            cout << "\nPlayer 2(WHITE) Wins";
        }
    }
    return 0;
}