#include "GameEngine.hpp"
#include "Definitions.hpp"
#include <string>

//void assert(std::string got, std::string exp) {
//    if(got != exp)
//        std::cout << "Error test got " << got << ", expected " << exp << std::endl;
//}

int main() {

    
    GameEngine app("Platformer");
    app.Run();
}
