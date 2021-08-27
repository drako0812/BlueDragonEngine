import bde.engine;
import <iostream>;

int main(int argc, char * argv[]) {
    return bde::Engine()(argc, argv).HandleError();
}
