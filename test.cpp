#include <iostream>
#include <fstream>
int main()
{
    std::ofstream ofs("test.txt");
    ofs << "你好，这里是王溢学" << std::endl;
    system("pause");
    ofs.close();
    return 0;
}