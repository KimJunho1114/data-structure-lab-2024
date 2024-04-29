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
    //������ (Constructor)
    Music(string title, string artist, string album, int year) {
        this->title = title;
        this->artist = artist;
        this->album = album;
        this->year = year;
    }
    //�Ҹ��� (Destructor)
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
    vector<Music> musicList; //����Ʈ�� ���� ����Ʈ �ϳ����� music��ü�� ���� (year, album, artist, title)

public:
    MusicStreamingService(string serviceName) {
        this->serviceName = serviceName;
    }

    // Adds a music to the service
    void addMusic(string title, string artist, string album, int year) {
        Music newMusic(title, artist, album, year);
        musicList.push_back(newMusic); //pushback ����Ʈ �� �ڿ��ٰ� �߰�
        cout << title << " by " << artist << " added to " << serviceName << endl;
    }

    // Searches for music by title ����Ʈ �߿� ���� ã�� ������ �ִ°�
    Music* searchByTitle(string title) // * : ������ , �����ʹ� �ּҸ� �����Ѵ�.
    { 
        for (int i = 0; i < musicList.size(); i++) //musiclist�� ���Ͱ� []: Ư�� �ε����� �����ϴ� ��
        {
            if (musicList[i].getTitle() == title) //������ ���� �ٸ��� null�� ����
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
                result.push_back(&musicList[i]); //result��� list�� �߰� artist�� ������
            }
        }
        return result;
    }

};

