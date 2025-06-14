//
// Created by tiago-oliveira on 15-05-2025.
//
#include "Command/HMirror.hpp"
#include "Image.hpp"
#include <sstream>
#include <algorithm>

namespace prog {
    namespace command {

        HMirror::HMirror() : Command("h_mirror") {}

        HMirror::~HMirror() {}

        Image *HMirror::apply(Image *img) {
            if (!img) return nullptr;

            int width = img->width();
            int height = img->height();

            // Iterate through each row
            for (int y = 0; y < height; ++y) {
                // Only process the first half of columns to avoid double swapping
                for (int x = 0; x < width / 2; ++x) {
                    std::swap(img->at(x, y), img->at(width - 1 - x, y)); // Swap pixels from left and right symmetrically
                }
            }
            return img;
        }

        std::string HMirror::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }
    }
}
