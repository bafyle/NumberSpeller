#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string.h>

using namespace std;
using namespace sf;

void playAnd(Sound &sound, SoundBuffer &buf)
{
    buf.loadFromFile("sounds/and.ogg");
    sound.setBuffer(buf);
    sound.play();
    while(sound.getStatus() == Sound::Playing)
    {
        sleep(milliseconds(1.f));
    }
}

bool isThereAChar(string & str)
{
    for(char &c : str)
    {
        if(isalpha(c))
            return true;
    }
    return false;
}
void playOneSound(char n, Sound &sound, SoundBuffer &buf)
{
    string gf = "sounds/";
    switch(n)
    {
        case '0': gf += "zero.ogg"; break;
        case '1': gf += "one.ogg"; break;
        case '2': gf += "two.ogg"; break;
        case '3': gf += "three.ogg"; break;
        case '4': gf += "four.ogg"; break;
        case '5': gf += "five.ogg"; break;
        case '6': gf += "six.ogg"; break;
        case '7': gf += "seven.ogg"; break;
        case '8': gf += "eight.ogg"; break;
        case '9': gf += "nine.ogg";
    }
    if(gf != "sounds/")
    {
        buf.loadFromFile(gf);
        sound.setBuffer(buf);
        sound.play();
        while(sound.getStatus() == Sound::Playing){sleep(milliseconds(1.f));}
    }
}

void playTowSound(const char* in, Sound &sound, SoundBuffer &buf)
{
    string gf = "sounds/";
    if(in[0] != '1')
    {
        if(in[1] != '0')
        {
            playOneSound(in[1], sound, buf);
            playAnd(sound, buf);
        }
        switch(in[0])
        {
            case '2': gf += "twenty.ogg"; break;
            case '3': gf += "thirty.ogg"; break;
            case '4': gf += "forty.ogg"; break;
            case '5': gf += "fifty.ogg"; break;
            case '6': gf += "sixty.ogg"; break;
            case '7': gf += "seventy.ogg"; break;
            case '8': gf += "eighty.ogg"; break;
            case '9': gf += "ninety.ogg";
        }
        if(gf != "sounds/")
        {
            buf.loadFromFile(gf);
            sound.setBuffer(buf);
            sound.play();
            while(sound.getStatus() == Sound::Playing){sleep(milliseconds(1.f));}
        }
    }
    else
    {
        gf += "special_case/";
        switch(in[1])
        {
            case '0': gf += "ten.ogg"; break;
            case '1': gf += "eleven.ogg"; break;
            case '2': gf += "twelve.ogg"; break;
            case '3': gf += "thirteen.ogg"; break;
            case '4': gf += "fourteen.ogg"; break;
            case '5': gf += "fifteen.ogg"; break;
            case '6': gf += "sixteen.ogg"; break;
            case '7': gf += "seventeen.ogg"; break;
            case '8': gf += "eighteen.ogg"; break;
            case '9': gf += "nineteen.ogg";
        }
        buf.loadFromFile(gf);
        sound.setBuffer(buf);
        sound.play();
        while(sound.getStatus() == Sound::Playing){sleep(milliseconds(1.f));}
    }
}

void playThreeSound(const char* in, Sound &sound, SoundBuffer &buf)
{
    string gf = "sounds/";
    switch(in[0])
    {
        case '1': gf += "hundred.ogg"; break;
        case '2': gf += "twohundred.ogg"; break;
        case '3': gf += "threehundred.ogg"; break;
        case '4': gf += "fourhundred.ogg"; break;
        case '5': gf += "fivehundred.ogg"; break;
        case '6': gf += "sixhundred.ogg"; break;
        case '7': gf += "sevenhundred.ogg"; break;
        case '8': gf += "eighthundred.ogg"; break;
        case '9': gf += "ninehundred.ogg";
    }
    if(gf != "sounds/")
    {
        buf.loadFromFile(gf);
        sound.setBuffer(buf);
        sound.play();
        while(sound.getStatus() == Sound::Playing){sleep(milliseconds(1.f));}
        if(((in[1] == '0' || in[1] == '1') && in[2] != '0') || ( in[1] != '0' && in[2] == '0'))
            playAnd(sound, buf);
    }
    if(in[1] != '0' || in[2] != '0')
    {
        if(in[1] == '0')
        {
            playOneSound(in[2], sound, buf);
        }
        else
        {
            char sg[3];
            sg[2] = 0;
            sg[0] = in[1];
            sg[1] = in[2];
            playTowSound(sg, sound, buf);
        }
    }
}

void playFourSound(const char* in, Sound &sound, SoundBuffer &buf)
{
    string gf = "sounds/";
    switch(in[0])
    {
        case '1': gf += "thousand.ogg"; break;
        case '2': gf += "twothousand.ogg"; break;
        case '3': gf += "threethousand.ogg"; break;
        case '4': gf += "fourthousand.ogg"; break;
        case '5': gf += "fivethousand.ogg"; break;
        case '6': gf += "sixthousand.ogg"; break;
        case '7': gf += "sevethousand.ogg"; break;
        case '8': gf += "eightthousand.ogg"; break;
        case '9': gf += "ninethousand.ogg";
    }
    if(gf != "sounds/")
    {
        buf.loadFromFile(gf);
        sound.setBuffer(buf);
        sound.play();
        while(sound.getStatus() == Sound::Playing){sleep(milliseconds(1.f));}
    }
    if(in[1] == '0' && in[2] != '1')
    {
        if(in[2] != '0' && in[3] != '0')
            playAnd(sound, buf);
    }
    char ss[4];
    ss[0] = in[1];
    ss[1] = in[2];
    ss[2] = in[3];
    playThreeSound(ss, sound, buf);
}

void playFiveSound(const char* in, Sound & sound, SoundBuffer &buf)
{
    if(in[0] != '0')
    {
        playTowSound(in, sound, buf);
        buf.loadFromFile("sounds/thousand.ogg");
        sound.setBuffer(buf);
        sound.play();
        while(sound.getStatus() == Sound::Playing){sleep(milliseconds(1.f));}
        playAnd(sound, buf);
        char ss[4];
        ss[0] = in[2];
        ss[1] = in[3];
        ss[2] = in[4];
        playThreeSound(ss, sound, buf);
    }
    else
    {
        char ss[4];
        for(int i = 0; i < 4; i++)
        {
            ss[i] = in[i+1];
        }
        playFourSound(ss, sound, buf);
    }
}
void playSixSound(const char* in, Sound & sound, SoundBuffer &buf)
{
    if(in[0] != '0')
    {
        playThreeSound(in, sound, buf);
        buf.loadFromFile("sounds/thousand.ogg");
        sound.setBuffer(buf);
        sound.play();
        while(sound.getStatus() == Sound::Playing){sleep(milliseconds(1.f));}
        playAnd(sound, buf);
        char ss[4];
        ss[0] = in[3];
        ss[1] = in[4];
        ss[2] = in[5];
        playThreeSound(ss, sound, buf);
    }
    else
    {
        char ss[6];
        for(int i = 0; i < 5; i++)
        {
            ss[i] = in[i+1];
        }
        playFiveSound(ss, sound, buf);
    }
}

void playSevenSound(const char* in, Sound &sound, SoundBuffer &buf)
{
    if(in[0] == '1')
    {
        buf.loadFromFile("sounds/million.ogg");
        sound.setBuffer(buf);
        sound.play();
        while(sound.getStatus() == Sound::Playing){sleep(milliseconds(1.f));}
        playAnd(sound, buf);
    }
    else if(in[0] != '0')
    {
        playOneSound(in[0], sound, buf);
        buf.loadFromFile("sounds/million.ogg");
        sound.setBuffer(buf);
        sound.play();
        while(sound.getStatus() == Sound::Playing){sleep(milliseconds(1.f));}
        playAnd(sound, buf);
    }
    char ss[7];
    for(int i = 0; i < 7; i++)
        ss[i] = in[i+1];
    playSixSound(ss, sound, buf);

}
int main()
{
    Sound sound;
    SoundBuffer buf;
    string input;
    size_t length;
    cout << "Type a number:\n";
    cin >> input;
    if(input.length() > 20 || isThereAChar(input))
    {
        cout << "Bad input!" << endl;
        return 0;
    }
    const char *c_string = input.c_str();
    length = input.length();
    switch(length)
    {
        case 1: playOneSound(c_string[0], sound, buf); break;
        case 2: playTowSound(c_string, sound, buf); break;
        case 3: playThreeSound(c_string, sound, buf); break;
        case 4: playFourSound(c_string, sound, buf); break;
        case 5: playFiveSound(c_string, sound, buf); break;
        case 6: playSixSound(c_string, sound, buf); break;
        case 7: playSevenSound(c_string, sound, buf); break;
        default:
            cout << "Unsupported." << endl;
    }
    return 0;
}
