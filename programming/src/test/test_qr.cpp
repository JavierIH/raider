#include <iostream>
#include <zbar.h>

int main()
{

zbar::ImageScanner ok;

ok.enable_cache();

std::cout<<"it works!";

}
