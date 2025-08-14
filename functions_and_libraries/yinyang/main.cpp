/*
 * Beyaz arkaplan üzerine siyah daire çizdim.
 * Dairenin yarısına beyaz bir dikdörtgen ile kapladım.
     * Kütüphane çizim için şekillerin merkezlerini değil,
     * bounding box'larının sol üst köşe noktasını referans alıyor.
     * Şekli bu noktadan başlayan bir dikdörtgen içerisine yerleştiriyor.
     * Sürekli Bbox kullanma sebebi bu. Bbox'lar sol-üst köşe koordinatları.
 * Sonra ana daire çapının yarısı çapta iki daireyi üst ve alta yerleştirdim.
 * içlerine 1/8 çap oranında küçük daireler (eye) ekledim.
 * Son olarak beyaz kısım ile arkaplanı birbirinden ayrılması için
 * ana daire çapında bir çember çizerek şeklin sınırlarını belli ettim.
 */

#include "gwindow.h"
#include <string>

// Function prototype
void drawYinYang(GWindow &gw);

int main()
{
    // Define the window dimensions
    const double WINDOW_SIZE = 400;

    // Create the graphics window
    GWindow gw(WINDOW_SIZE, WINDOW_SIZE);
    gw.setTitle("yin-yang");
    gw.setBackground("WHITE"); // Start with a white background

    drawYinYang(gw);

    return 0;
}

void drawYinYang(GWindow &gw)
{
    // --- Section 1: Define Geometry ---
    // All calculations are based on the window's center and a main radius.

    // Calculates the horizontal (x) and vertical (y) center coordinate of the window.
    double centerX = gw.getWidth() / 2.0;
    double centerY = gw.getHeight() / 2.0;
    // Sets the radius for the main outer circle of the symbol.
    double mainRadius = 150.0;

    // Calculates the top-left x-coordinate for the main circle's bounding box.
    double boundingBoxX = centerX - mainRadius;
    // Calculates the top-left y-coordinate for the main circle's bounding box.
    double boundingBoxY = centerY - mainRadius;
    // Calculates the full diameter of the main circle.
    double diameter = 2 * mainRadius;

    // Calculates the radius for the two medium-sized inner circles.
    double mediumRadius = mainRadius / 2.0;
    // Calculates the radius for the two small 'eye' dots.
    double smallRadius = mainRadius / 8.0;

    // --- Section 2: Draw the Main Halfs ---

    // Sets the drawing color to black for the next shape.
    gw.setColor("BLACK");

    // Draws the main, large, filled black circle that forms the outer boundary.
    gw.fillOval(boundingBoxX, boundingBoxY, diameter, diameter);
    // Sets the drawing color to white for the next shape.
    gw.setColor("WHITE");
    // Draws a large white rectangle that covers the right half of the black circle.
    // This creates the straight vertical dividing line.
    gw.fillRect(boundingBoxX, boundingBoxY, mainRadius, diameter);

    // --- Section 3: Draw the Overlapping Inner Circles ---

    // Calculates the top-left x-coordinate for the medium white circle.
    double mediumWhiteCircleBboxX = centerX - mediumRadius;
    // Calculates the top-left y-coordinate for the medium white circle (in the upper half).
    double mediumWhiteCircleBboxY = centerY - mainRadius;
    // Sets the drawing color to white.
    gw.setColor("WHITE");
    // Draws the medium white circle in the upper (black) area.
    gw.fillOval(mediumWhiteCircleBboxX, mediumWhiteCircleBboxY, 2 * mediumRadius, 2 * mediumRadius);

    // Calculates the top-left x-coordinate for the medium black circle.
    double mediumBlackCircleBboxX = centerX - mediumRadius;
    // Calculates the top-left y-coordinate for the medium black circle (in the lower half).
    double mediumBlackCircleBboxY = centerY;
    // Sets the drawing color to black.
    gw.setColor("BLACK");
    // Draws the medium black circle in the lower (white) area.
    gw.fillOval(mediumBlackCircleBboxX, mediumBlackCircleBboxY, 2 * mediumRadius, 2 * mediumRadius);

    // --- Section 4: Draw the "Eyes" ---

    // Calculates the top-left x-coordinate for the small black dot.
    double smallBlackEyeBboxX = centerX - smallRadius;
    // Calculates the top-left y-coordinate for the small black dot.
    double smallBlackEyeBboxY = centerY - mainRadius + mediumRadius - smallRadius;
    // Sets the drawing color to black.
    gw.setColor("BLACK");
    // Draws the small black dot inside the medium white circle.
    gw.fillOval(smallBlackEyeBboxX, smallBlackEyeBboxY, 2 * smallRadius, 2 * smallRadius);

    // Calculates the top-left x-coordinate for the small white dot.
    double smallWhiteX = centerX - smallRadius;
    // Calculates the top-left y-coordinate for the small white dot.
    double smallWhiteY = centerY + mediumRadius - smallRadius;
    // Sets the drawing color to white.
    gw.setColor("WHITE");
    // Draws the small white dot inside the medium black circle.
    gw.fillOval(smallWhiteX, smallWhiteY, 2 * smallRadius, 2 * smallRadius);
    gw.setColor("BLACK");

    // Draws the margin of the yin-yang
    gw.drawOval(boundingBoxX, boundingBoxY, diameter, diameter);
}
