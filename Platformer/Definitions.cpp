#include "Definitions.hpp"
#include <iostream>

std::string JoinUrls(std::string url1, std::string url2){
    const char sep = '/';
    if(url1.back() == sep){
        url1.erase(url1.length() - 1);
    }
        
    if(url1.substr(url1.find_last_of(sep)).find(".") != std::string::npos)
        url1.erase(url1.find_last_of(sep));
            
    if(url2.substr(0, 2) == "..") {
        url1.erase(url1.find_last_of(sep));
        url2.erase(0, 2);
    }
    
    if(url2.front() != sep)
        url2 = sep + url2;
    return url1 + url2;
    //    assert(JoinUrls("C:/users/", "zellus/home"), "C:/users/zellus/home");
    //    assert(JoinUrls("C:/users", "zellus/home"), "C:/users/zellus/home");
    //    assert(JoinUrls("C:/users/", "/zellus/home"), "C:/users/zellus/home");
    //    assert(JoinUrls("C:/users/", "../zellus/home"), "C:/zellus/home");
    //    assert(JoinUrls("C:/users/map.tmx", "../sprites/sprite.png"), "C:/sprites/sprite.png");
}

static bool _error = false;



void Info(std::string info) {
    std::cout << "INFO:: " << info << std::endl;
}

void Warning(std::string info) {
    std::cout << "WARN:: " << info << std::endl;
}

void Error(std::string error) {
    _error = true;
    std::cerr << "ERR:: " << error << std::endl;
}

bool IsError() {
    return _error;
}
