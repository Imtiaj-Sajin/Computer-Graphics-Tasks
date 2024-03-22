#ifndef GLUTIL_H
#define GLUTIL_H
#include <GL/glut.h>
#include <string.h>
#include <unistd.h>
#include<windows.h>
#include <cmath>




///////////////morphed text////
std::string _originalText = "asdf$!";
std::string _targetText = "Welcome!";
float _animationDuration = 5.0;
float _morphSpeed = 0.0;

std::string calculateMorphedText(float time) {
    float t = std::min(1.0f, std::max(0.0f, time / _animationDuration));
    std::string morphedText;

    size_t maxLength = std::max(_originalText.size(), _targetText.size());

    for (size_t i = 0; i < maxLength; ++i) {
        float c1 = (i < _originalText.size()) ? _originalText[i] : ' '; // Handle shorter original text
        float c2 = (i < _targetText.size()) ? _targetText[i] : ' ';       // Handle shorter target text
        float morphedChar = c1 * (1.0 - t) + c2 * t;
        morphedText += static_cast<char>(morphedChar);
    }

    return morphedText;
}


void mT_update(int value) {

    _morphSpeed += 0.2;
    glutPostRedisplay();
    glutTimerFunc(100, mT_update, 0);
}

void morphedText(std::string text, int posX, int posY, float scale, int fontWeight, float colorR, float colorG, float colorB) {
    _targetText=text;

    std::string morphedText = calculateMorphedText(_morphSpeed);

    glPushMatrix();
    glTranslatef(posX, posY, 0);
    glScalef(scale, scale, scale);
    glLineWidth(fontWeight);
    glColor3f(colorR, colorG, colorB);

    for (char &c : morphedText) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, c); 
    }

    glPopMatrix();
}

/////




//////static texxt/////

void staticText(std::string text, int posX, int posY, float scale, int fontWeight, float colorR, float colorG, float colorB) {
    glPushMatrix();
    glTranslatef(posX, posY, 0);
    glScalef(scale, scale, scale);
    glLineWidth(fontWeight);
    glColor3f(colorR, colorG, colorB);

    for (char &c : text) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, c);
    }

    glPopMatrix();
}

//////////////

///typed text/////

char* _tText = "wqer";
int _tTextLength = strlen(_tText);
int _tCurrentIndex = 0;
int _tDelay = 100;

void _drawString(float x, float y,  char* strings) {
    glRasterPos2f(x, y);
    for (int i = 0; i < strlen(strings); ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, strings[i]);
    }
}

void typedText(float x, float y,  char* strings) {
_tText = strings;
 _tTextLength = strlen(_tText);
    char currentText[_tTextLength + 1];
    strncpy(currentText, _tText, _tCurrentIndex);
    currentText[_tCurrentIndex] = '\0';
    _drawString(x, y, currentText);

}

void _keyboard_timer(int value) {
    if (_tCurrentIndex < _tTextLength) {
        _tCurrentIndex++;
        glutPostRedisplay();
        glutTimerFunc(_tDelay, _keyboard_timer, 0);
    }
}
/////////////////
#endif
