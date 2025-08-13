#include "gwindow.h"
#include <string>

int main() {
    double window_width = 600;
    double window_height = 400;
    double band_thickness = 20;
    std::string sky_color = "CYAN";

    // Create the graphics window
    GWindow gw(window_width, window_height);
    gw.setTitle("Rainbow");
    gw.setBackground(sky_color);

    // Define the rainbow colors from the outer to the inner
    std::string rainbowColors[] = {
        "RED", "ORANGE", "YELLOW", "GREEN", "BLUE", "MAGENTA"
    };
    int numColors = sizeof(rainbowColors) / sizeof(rainbowColors[0]);

    // Define the bounding box for the outermost (red) arc
    double arcWidth = 1000;
    double arcHeight = 1000;
    double x = (window_width - arcWidth) / 2.0;
    double y = 100;

    // Loop through the colors and draw each colored arc
    for (int i = 0; i < numColors; ++i) {
        gw.setColor(rainbowColors[i]);
        gw.fillArc(x, y, arcWidth, arcHeight, 0, 180);

        // Prepare dimensions for the next, smaller arc
        x += band_thickness;
        y += band_thickness;
        arcWidth -= 2 * band_thickness;
        arcHeight -= 2 * band_thickness;
    }

    // This covers the center of the innermost (magenta) arc,
    // turning it from a semicircle into a proper arc like the others.
    gw.setColor(sky_color);
    gw.fillArc(x, y, arcWidth, arcHeight, 0, 180);

    return 0;
}
