#include "Global.h"

bool Global::HAS_UP_MAP = false;
bool Global::HAS_LEFT_MAP = false;
bool Global::HAS_RIGHT_MAP = false;
bool Global::HAS_DOWN_MAP = false;
double Global::TEXTURE_SCALE = 1;
int Global::SCREEN_WIDTH = 1024;
int Global::SCREEN_HEIGHT = 576;
int Global::PROJECTILE_SPEED = 200;
float Global::TIME_ELAPSED = 0;
std::string Global::FILE_DIRECTORY = "";

Global::Global(const double textureScale, const int screenWidth, const int screenHeight) {

}

Global::~Global() {
}
