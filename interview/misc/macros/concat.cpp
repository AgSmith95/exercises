#define concat(x,y) x##y

int main() {
    concat(1,2);
    concat(2+2,3+3);
}