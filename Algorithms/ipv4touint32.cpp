#include <iostream>
#include <string>
#include <cstdlib>

std::string ipv4 = "8.8.8.8";


int main() {
    using std::cout;
    using std::string;

    char p[4] = {} ;
    ipv4 += '.';
    for(int i = 0; i < 4; ++i){
        int n = ipv4.find('.');
        string temp(ipv4.begin(), ipv4.begin() + n);
        ipv4.erase(ipv4.begin(), ipv4.begin() + n + 1);
        p[i] = atoi(temp.data());
    }
    cout<< *(reinterpret_cast<unsigned int*>(p)) << '\n';
    
}
