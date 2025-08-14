#include "gwindow.h"
#include <string>

int rows = 8;
int cols = 8;
double square_size = 50; // The size of each square in pixels

// Function prototypes
void drawBoard(GWindow& gw);
void drawPieces(GWindow& gw);

int main() {
    // Calculate the total window size based on the board dimensions
    double windowWidth = cols * square_size;
    double windowHeight = rows * square_size;

    // Create the graphics window
    GWindow gw(windowWidth, windowHeight);
    gw.setTitle("Checkerboard");

    drawBoard(gw);
    drawPieces(gw);

    return 0;
}

// Draws the 8x8 grid of alternating light and dark squares.
void drawBoard(GWindow& gw) {
    // Loop through each row and column of the grid
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            double x = col * square_size;
            double y = row * square_size;

            // Determine if the square should be light or dark.
            // If the sum of row and col is even, the square is light.
            // If it's odd, the square is dark.
            if ((row + col) % 2 == 0) {
                gw.setColor("WHITE");
            } else {
                gw.setColor("LIGHT_GRAY");
            }

            // Draw a filled rectangle for the square
            gw.fillRect(x, y, square_size, square_size);
        }
    }
}

//Draws the initial setup of red and black pieces.
void drawPieces(GWindow& gw) {
    double pieceSize = square_size * 0.8;
    // Calculate the offset to center the piece inside the square
    double pieceOffset = (square_size - pieceSize) / 2.0;

    // Loop through each row and column to place the pieces
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            // Check if a piece should be placed here
            bool isDarkSquare = (row + col) % 2 != 0;

            if (isDarkSquare) {
                // Place "red" (top) pieces in the first 3 rows
                if (row < 3) {
                    gw.setColor("RED");
                    double x = col * square_size + pieceOffset;
                    double y = row * square_size + pieceOffset;
                    gw.fillOval(x, y, pieceSize, pieceSize);
                }
                // Place "black" (bottom) pieces in the last 3 rows
                else if (row > 4) {
                    gw.setColor("BLACK");
                    double x = col * square_size + pieceOffset;
                    double y = row * square_size + pieceOffset;
                    gw.fillOval(x, y, pieceSize, pieceSize);
                }
            }
        }
    }
}
