#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Music class
class Music {
private:
    string title;
    string artist;
    string album;
    int year;
public:
    //생성자 (Constructor)
    Music(string title, string artist, string album, int year) {
        this->title = title;
        this->artist = artist;
        this->album = album;
        this->year = year;
    }
    //소멸자 (Destructor)
    ~Music() {}
    
    // Getters
    string getTitle() { 
        return title; 
    }
    string getArtist() { 
        return artist; 
    }
    string getAlbum() { 
        return album; 
    }
    int getYear() { 
        return year;
    }
};

// MusicStreamingService class
class MusicStreamingService {
private:
    string serviceName; 
    vector<Music> musicList; //리스트를 만듦 리스트 하나에는 music객체가 있음 (year, album, artist, title)

public:
    MusicStreamingService(string serviceName) {
        this->serviceName = serviceName;
    }

    // Adds a music to the service
    void addMusic(string title, string artist, string album, int year) {
        Music newMusic(title, artist, album, year);
        musicList.push_back(newMusic); //pushback 리스트 맨 뒤에다가 추가
        cout << title << " by " << artist << " added to " << serviceName << endl;
    }

    // Searches for music by title 리스트 중에 내가 찾는 음악이 있는가
    Music* searchByTitle(string title) // * : 포인터 , 포인터는 주소를 저장한다.
    { 
        for (int i = 0; i < musicList.size(); i++) //musiclist는 벡터고 []: 특정 인덱스에 접근하는 법
        {
            if (musicList[i].getTitle() == title) //같으면 리턴 다르면 null로 리턴
            {
                return &musicList[i];
            }
        }
        return NULL;
    }

    // Searches for music by artist
    vector<Music>* > searchByArtist(string artist) 
    {
        vector<Music>* > result;
        for (int i = 0; i < musicList.size(); i++) 
        {
            if (musicList[i].getArtist() == artist) 
            {
                result.push_back(&musicList[i]); //result라는 list에 추가 artist가 같으면
            }
        }
        return result;
    }

};

