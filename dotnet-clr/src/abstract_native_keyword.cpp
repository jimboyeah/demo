// abstract_native_keyword.cpp
class X abstract {};

int main() {
    // C3622 cannot instantiate abstract class
    // X * MyX = new X;
}