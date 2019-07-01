#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void playand(Sound &sound, SoundBuffer &buf)
{
    buf.loadFromFile("sounds/and.ogg");
    sound.setBuffer(buf);
    sound.play();
    while(sound.getStatus() == Sound::Playing)
    {
        sleep(milliseconds(1.f));
    }
}

size_t len(char s[])
{
    size_t reval = 0;
    for(size_t i = 0; s[i] != 0; i++)
    {
        reval++;
    }
    return reval;
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

void playTowSound(char ss[], Sound &sound, SoundBuffer &buf)
{
    string gf = "sounds/";
    if(ss[0] != '1')
    {
        if(ss[1] != '0')
        {
            playOneSound(ss[1], sound, buf);
            playand(sound, buf);
        }
        switch(ss[0])
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
        switch(ss[1])
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

void playThreeSound(char ss[], Sound &sound, SoundBuffer &buf)
{
    string gf = "sounds/";
    switch(ss[0])
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
        if((ss[1] == '0' || ss[1] == '1') && ss[2] != '0')
            playand(sound, buf);
    }
    if(ss[1] != '0' || ss[2] != '0')
    {
        if(ss[1] == '0')
        {
            playOneSound(ss[2], sound, buf);
        }
        else
        {
            char sg[3];
            sg[2] = 0;
            sg[0] = ss[1];
            sg[1] = ss[2];
            playTowSound(sg, sound, buf);
        }
    }
}

void playFourSound(char in[], Sound &sound, SoundBuffer &buf)
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
            playand(sound, buf);
    }
    char ss[4];
    ss[0] = in[1];
    ss[1] = in[2];
    ss[2] = in[3];
    playThreeSound(ss, sound, buf);
}

void playFiveSound(char in[], Sound & sound, SoundBuffer &buf)
{
    if(in[0] != '0')
    {
        playTowSound(in, sound, buf);
        buf.loadFromFile("sounds/thousand.ogg");
        sound.setBuffer(buf);
        sound.play();
        while(sound.getStatus() == Sound::Playing){sleep(milliseconds(1.f));}
        playand(sound, buf);
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
void playSixSound(char in[], Sound & sound, SoundBuffer &buf)
{
    if(in[0] != '0')
    {
        playThreeSound(in, sound, buf);
        buf.loadFromFile("sounds/thousand.ogg");
        sound.setBuffer(buf);
        sound.play();
        while(sound.getStatus() == Sound::Playing){sleep(milliseconds(1.f));}
        playand(sound, buf);
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

void playSevenSound(char in[], Sound &sound, SoundBuffer &buf)
{
    if(in[0] == '1')
    {
        buf.loadFromFile("sounds/million.ogg");
        sound.setBuffer(buf);
        sound.play();
        while(sound.getStatus() == Sound::Playing){sleep(milliseconds(1.f));}
        playand(sound, buf);
    }
    else if(in[0] != '0')
    {
        playOneSound(in[0], sound, buf);
        buf.loadFromFile("sounds/million.ogg");
        sound.setBuffer(buf);
        sound.play();
        while(sound.getStatus() == Sound::Playing){sleep(milliseconds(1.f));}
        playand(sound, buf);
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
    char in[8];
    cout << "Type a number:\n";
    cin >> in;
    size_t size = len(in);
    switch(size)
    {
        case 1: playOneSound(in[0], sound, buf); break;
        case 2: playTowSound(in, sound, buf); break;
        case 3: playThreeSound(in, sound, buf); break;
        case 4: playFourSound(in, sound, buf); break;
        case 5: playFiveSound(in, sound, buf); break;
        case 6: playSixSound(in, sound, buf); break;
        case 7: playSevenSound(in, sound, buf);
    }
    return 0;
}
