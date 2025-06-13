#include <iostream>
using namespace std;
#include "Polygon.h"

float Polygon::getSignedArea() const {
    if (fNumberOfVertices < 3) return 0.0f;

    float sum = 0.0f;
    for (size_t i = 0; i < fNumberOfVertices; ++i) {
        const Vector2D& curr = fVertices[i];
        const Vector2D& next = fVertices[(i + 1) % fNumberOfVertices];
        sum += (curr.getX() * next.getY()) - (next.getX() * curr.getY()); //the fomula tho
    }
    return 0.5f * sum;
}
