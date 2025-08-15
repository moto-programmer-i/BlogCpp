import std;
import Files;

constexpr std::string_view FILE_PATH = "./Test.txt";

int main()
{
    for (auto& line : Files::readAllLines(FILE_PATH)) {
        std::cout << line << std::endl;
    }
}