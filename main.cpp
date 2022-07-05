#include <iostream>
#include "System.h"


int main() {
    auto* system = new System("../202207030651.mp4", BLUE);
    system->start();
    delete system;
    return 0;
}
