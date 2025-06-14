//
// Created by tiago-oliveira on 15-05-2025.
//
#include "Command/Replace.hpp"
#include "Image.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Replace::Replace(Color c1, Color c2) : Command("replace"), c1(c1), c2(c2) {}

        Replace::~Replace() {}

        Image *Replace::apply(Image *img) {
            if (!img) return nullptr;

            int width = img->width();
            int height = img->height();

            // Iterate through all pixels in the image
            for (int y = 0; y < height; ++y) {
                for (int x = 0; x < width; ++x) {
                    // Check if the current pixel matches the color to be replaced
                    if (img->at(x, y) == c1) {
                        // Replace with the new color
                        img->at(x, y) = c2;
                    }
                }
            }

            return img;
        }

        std::string Replace::toString() const {
            std::ostringstream ss;
            ss << name() << " " << c1 << " -> " << c2;
            return ss.str();
        }
    }
}
